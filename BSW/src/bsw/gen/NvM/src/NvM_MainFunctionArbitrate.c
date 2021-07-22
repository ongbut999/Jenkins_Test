
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "Rte_NvM.h"
#include "NvM_Cfg_SchM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_Queue.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"
#include "NvM_Prv_ProcessMultiBlock.h"

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
 */
LOCAL_INLINE NvM_Prv_idJob_ten NvM_Prv_GetNextJob(NvM_Prv_idQueue_tuo* idQueueActive_puo,
                                                  NvM_Prv_QueueEntry_tst* QueueEntry_pst);
LOCAL_INLINE void NvM_Prv_UpdateBlockStatus(NvM_BlockIdType idBlock_uo,
                                            NvM_Prv_idJob_ten idJob_en,
                                            void const* RamBlock_pcv);
LOCAL_INLINE uint8 NvM_Prv_GetIdxDatasetForJob(NvM_Prv_idJob_ten idJob_en,
                                               NvM_BlockIdType idBlock_uo);

/*
 **********************************************************************************************************************
 * NvM-private code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

void NvM_Prv_StartJob(NvM_Prv_idJob_ten idJob_en,
                      NvM_BlockIdType idBlock_uo,
                      uint8* RamBlock_pu8,
                      uint8 idxDataset_u8)
{
    // Initialize data of the job to be started
    NvM_Prv_Main_st.JobData_st.idJob_en = idJob_en;
    // TRACE[NVM338] The job of NvM_WriteBlock writes to the NV block which is selected by the data index
    //               when the block is of type DATASET
    // TRACE[NVM339] Same as NVM338, applied to NvM_WriteAll
    // TRACE[NVM340] The job of NvM_ReadBlock reads only the NV block selected by the data index
    //               for a block of type DATASET
    // (Fee/Ea block-ID for an NV-block of an NvM-block of type DATASET) = (Fee/Ea block-ID) + (NV-index)
    NvM_Prv_Main_st.JobData_st.idxDataset_u8 = idxDataset_u8;
    NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_PENDING;
    NvM_Prv_Main_st.JobData_st.idBlock_uo = idBlock_uo;
    NvM_Prv_Main_st.JobData_st.RamBlock_pu8 = RamBlock_pu8;

    NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_JOB_START;
}


/**
 * This function determines the next request to be executed by checking all queues for entries to be started.
 *
 * All prioritizations of requests is done here.
 * This function will be invoked by NvM_Mainfunction only if no other request is currently active.
 *
 * \param[global in,out] NvM_Prv_Main_st
 * Global structure with all state information which is not block-specific.
 *
 */
void NvM_Prv_MainFunctionArbitrate(void)
{
    // Perform request arbitration
    NvM_Prv_Main_st.idQueueActive_uo = NvM_Prv_Queue_GetEntryToProcess(&NvM_Prv_Main_st.QueueEntry_pst);

    if (NULL_PTR != NvM_Prv_Main_st.QueueEntry_pst)
    {
        NvM_Prv_idJob_ten idJob_en = NvM_Prv_GetNextJob(&NvM_Prv_Main_st.idQueueActive_uo,
                                                        NvM_Prv_Main_st.QueueEntry_pst);

        if (idJob_en != NvM_Prv_idJob_Idle_e)
        {
            NvM_BlockIdType idBlock_uo = NvM_Prv_Main_st.QueueEntry_pst->idBlock_uo;

            NvM_Prv_UpdateBlockStatus(idBlock_uo,
                                      idJob_en,
                                      NvM_Prv_Main_st.QueueEntry_pst->BlockData_pv);
            /* MR12 RULE 11.5 VIOLATION: The actual type of the RAM block varies from block to block and
                                         cast to byte pointer can always be done safely */
            NvM_Prv_StartJob(idJob_en,
                             idBlock_uo,
                             (uint8*)NvM_Prv_Main_st.QueueEntry_pst->BlockData_pv,
                             NvM_Prv_GetIdxDatasetForJob(idJob_en, idBlock_uo));
        }
    }
    else
    {
        // No request pending -> NvM is completely idle
        NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_IDLE;
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline code
 **********************************************************************************************************************
 */
LOCAL_INLINE NvM_Prv_idJob_ten NvM_Prv_GetNextJob(NvM_Prv_idQueue_tuo* idQueueActive_puo,
                                                  NvM_Prv_QueueEntry_tst* QueueEntry_pst)
{
    NvM_Prv_idJob_ten idJobNext_en = NvM_Prv_idJob_Idle_e;

    if ((NULL_PTR != idQueueActive_puo) && (NULL_PTR != QueueEntry_pst))
    {
        if (NvM_Prv_idQueue_Multi_e == *idQueueActive_puo)
        {
            // process multi block service
            idJobNext_en = NvM_Prv_Multi_Process(QueueEntry_pst);
        }
        else
        {
            // Check whether the service identified by the service bit is valid
            if (NvM_Prv_ErrorDetection_IsServiceBitValid(NVM_SERVICE_ID_MAIN_FUNCTION,
                                                         QueueEntry_pst->idBlock_uo,
                                                         QueueEntry_pst->ServiceBit_uo))
            {
                // process single block service
                idJobNext_en = NvM_Prv_GetJobId(QueueEntry_pst->ServiceBit_uo);
            }
            else
            {
                // Unknown/invalid singleblock service ID
                // (we should actually never get here; it's just there for robustness)
                // -> clear current request, stay in arbitration

                // Set scheduling lock
                SchM_Enter_NvM_Main();

                NvM_Prv_Queue_DequeueRequest(*idQueueActive_puo);
                NvM_Prv_Main_st.QueueEntry_pst = NULL_PTR;
                *idQueueActive_puo = NvM_Prv_idQueue_nrQueues_e;

                // Reset scheduling lock
                SchM_Exit_NvM_Main();

                idJobNext_en = NvM_Prv_idJob_Idle_e;
            }
        }
    }
    return idJobNext_en;
}

LOCAL_INLINE void NvM_Prv_UpdateBlockStatus(NvM_BlockIdType idBlock_uo,
                                            NvM_Prv_idJob_ten idJob_en,
                                            void const* RamBlock_pcv)
{
    if (RamBlock_pcv == NvM_Prv_GetPRamBlockAddress(idBlock_uo))
    {
        if ((NvM_Prv_idJob_Read_e == idJob_en) ||
            (NvM_Prv_idJob_ReadIdConfigForReadAll_e == idJob_en) ||
            (NvM_Prv_idJob_Restore_e == idJob_en) ||
            (NvM_Prv_idJob_RestoreForImplicitRecovery_e == idJob_en))
        {
            // set status of the permanent RAM block to INVALID
            NvM_Prv_Block_SetState(idBlock_uo, NVM_BLOCK_STATE_RAM_VALID, 0x0u);
        }
        else if (NvM_Prv_idJob_Write_e == idJob_en)
        {
            // set status of the permanent RAM block to VALID
            NvM_Prv_Block_SetState(idBlock_uo, NVM_BLOCK_STATE_RAM_VALID, NVM_BLOCK_STATE_RAM_VALID);
        }
        else
        {
            // all other jobs do not work on permanent RAM block so it is not required to update the status
        }
    }
}

LOCAL_INLINE uint8 NvM_Prv_GetIdxDatasetForJob(NvM_Prv_idJob_ten idJob_en,
                                               NvM_BlockIdType idBlock_uo)
{
    uint8 idxDataset_u8;
    if ((NVM_BLOCK_DATASET != NvM_Prv_GetBlockType(idBlock_uo)) ||
        (NvM_Prv_idJob_InvalidateForRemoveNonResistant_e == idJob_en))
    {
        idxDataset_u8 = 0;
    }
    else
    {
#if (NVM_RB_AUX_INTERFACE == STD_ON)
        if (NvM_Prv_IsAuxServiceActive())
        {
            idBlock_uo = NVM_PRV_AUX_ADMIN_BLOCK;
        }
#endif
        idxDataset_u8 = NvM_Prv_Block_GetIdxDataset(idBlock_uo);
    }
    return idxDataset_u8;
}
