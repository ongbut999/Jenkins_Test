
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"
#include "NvM_Prv_ExplicitSynchronization.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef void (*NvM_Prv_JobComplete_tpfct)(NvM_Prv_JobData_tst* JobData_pst);

/*
 **********************************************************************************************************************
 * Local declarations
 **********************************************************************************************************************
 */
static void NvM_Prv_JobComplete_Read(NvM_Prv_JobData_tst* JobData_pst);
static void NvM_Prv_JobComplete_Restore(NvM_Prv_JobData_tst* JobData_pst);
static void NvM_Prv_JobComplete_InvalidateAllDatasets(NvM_Prv_JobData_tst* JobData_pst);
static void NvM_Prv_JobComplete_Validate(NvM_Prv_JobData_tst* JobData_pst);
static NvM_Prv_JobComplete_tpfct NvM_Prv_GetFctJobComplete(NvM_Prv_idJob_ten idJob_en);

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */
#define NvM_Prv_JobComplete_Idle_pfct                               NULL_PTR
#define NvM_Prv_JobComplete_Read_pfct                               NvM_Prv_JobComplete_Read
#define NvM_Prv_JobComplete_Write_pfct                              NULL_PTR
#define NvM_Prv_JobComplete_Erase_pfct                              NULL_PTR
#define NvM_Prv_JobComplete_Restore_pfct                            NvM_Prv_JobComplete_Restore
#define NvM_Prv_JobComplete_Maintain_pfct                           NULL_PTR
#define NvM_Prv_JobComplete_Validate_pfct                           NvM_Prv_JobComplete_Validate
#define NvM_Prv_JobComplete_Invalidate_pfct                         NULL_PTR
#define NvM_Prv_JobComplete_ReadIdConfigForReadAll_pfct             NvM_Prv_JobComplete_Read
#define NvM_Prv_JobComplete_InvalidateForFirstInitAll_pfct          NvM_Prv_JobComplete_InvalidateAllDatasets
#define NvM_Prv_JobComplete_RestoreForImplicitRecovery_pfct         NvM_Prv_JobComplete_Restore
#define NvM_Prv_JobComplete_InvalidateForRemoveNonResistant_pfct    NvM_Prv_JobComplete_InvalidateAllDatasets
#define NvM_Prv_JobComplete_Invalid_pfct                            NULL_PTR

/**
 * Function-like macro: LIST_ENTRY_JOB_COMPLETE_FCT
 *
 * This macro generates an entry for a complete job function in a list of all jobs provided by NvM.
 * s.a. macro LIST_ID_JOB to generate a list for all jobs provided by NvM
 *
 * Paramater:
 * Name: name of the job for which a complete job function will be generated.
 */
#define LIST_ENTRY_JOB_COMPLETE_FCT(Name)   NvM_Prv_JobComplete_##Name##_pfct,

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

static NvM_Prv_JobComplete_tpfct const NvM_Prv_JobCompleteFcts_capfct[NvM_Prv_idJob_Count_e] =
{
    LIST_ID_JOB(LIST_ENTRY_JOB_COMPLETE_FCT)
};


#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
 */
LOCAL_INLINE void NvM_Prv_CopyBlockDataFromRom(NvM_BlockIdType idBlock_uo,
                                               uint8* RamBlock_pu8,
                                               uint8 idxDataset_u8);

/*
 **********************************************************************************************************************
 * NvM-private code
 **********************************************************************************************************************
 */

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
static void NvM_Prv_JobComplete_Read(NvM_Prv_JobData_tst* JobData_pst)
{
    // check whether MemIf has finished the read job successfully or explicit synchronization is ongoing
    if ((MEMIF_JOB_OK == JobData_pst->Result_en) || (MEMIF_JOB_PENDING == JobData_pst->Result_en))
    {
        // trigger the read callback for explicit synchronization
        JobData_pst->Result_en = NvM_Prv_ExplicitSync_CopyData(NvM_Prv_GetCopyFctForRead(JobData_pst->idBlock_uo),
                                                               JobData_pst->idBlock_uo);
    }
    else
    {
        // Check whether a read job for an NvM block having a ROM block did not finish successfully
        // -> if so, turn the read job into a restore job and start it ("implicit recovery")
        // Note: As opposed to NVM389, implicit recovery is (currently?) not supported for DATASET blocks
        if ((MEMIF_BLOCK_INVALID != JobData_pst->Result_en) &&
            (NvM_Prv_IsDefaultDataAvailable(JobData_pst->idBlock_uo)) &&
            (NVM_BLOCK_DATASET != NvM_Prv_GetBlockType(JobData_pst->idBlock_uo)))
        {
            // TRACE[NVM389] Recover an unsuccessful read operation by performing a Restore operation
            //               for all NvM block types
            // TRACE[NVM390] Same as NVM389 but for redundant NvM blocks
            // TRACE[NVM171] Provide implicit recovery to restore data from ROM to RAM if read data is found inconsistent
            // TRACE[NVM388] Same as NVM171 in case of NvM_ReadAll
            // TRACE[NVM172] The NV block is not modified during implicit recovery
            // TRACE[NVM657] Load default data if the read request fails in the underlying layers
            //               by doing the same actions as a restore operation
            // TRACE[NVM679] Same as NVM657 applied to NvM_ReadAll
            NvM_Prv_StartJob(NvM_Prv_idJob_RestoreForImplicitRecovery_e,
                             JobData_pst->idBlock_uo,
                             JobData_pst->RamBlock_pu8,
                             JobData_pst->idxDataset_u8);
        }
    }
}

static void NvM_Prv_JobComplete_Restore(NvM_Prv_JobData_tst* JobData_pst)
{
    // TRACE[NVM392] Restore job is done without any MemIf interaction
    // TRACE[NVM392] Leave the NV block untouched
    // Determine the source of the block defaults
    if (NULL_PTR != NvM_Prv_GetRomBlockAddress(JobData_pst->idBlock_uo))
    {
        // A ROM block is configured for this block
        // TRACE[NVM267] Fill the block data buffer with ROM block data
        if (!NvM_Prv_ExplicitSync_IsOngoing())
        {
            NvM_Prv_CopyBlockDataFromRom(JobData_pst->idBlock_uo,
                                         JobData_pst->RamBlock_pu8,
                                         JobData_pst->idxDataset_u8);
        }

        // Copy data into the RAM block for explicit sync because data was restored from ROM
        // trigger the read callback for explicit synchronization
        JobData_pst->Result_en = NvM_Prv_ExplicitSync_CopyData(NvM_Prv_GetCopyFctForRead(JobData_pst->idBlock_uo),
                                                               JobData_pst->idBlock_uo);
    }
    else
    {
        // data was not restored from ROM -> restore data by calling the InitBlockCallback
        // InitBlockCallback shall be called only if available and only for non-auxiliary services
        if (!NvM_Prv_IsAuxServiceActive())
        {
            // Invoke the init block callback
            if (E_OK == NvM_Prv_InvokeInitBlockCallback(JobData_pst->idBlock_uo))
            {
                JobData_pst->Result_en = MEMIF_JOB_OK;
            }
            else
            {
                JobData_pst->Result_en = MEMIF_JOB_FAILED;
            }
        }
    }

    if (MEMIF_JOB_OK == JobData_pst->Result_en)
    {
        // Check if the restore job succeeded, which is the case if
        // - the copy operation from ROM to RAM was successful or
        // - the Init-Callback was successful
        // Notes:
        // - A finally failed explicit sync read callback sets the job result to MEMIF_JOB_FAILED,
        //   so we neither trigger an init block callback nor a write job in this case
        // - The init block callback doesn't need to be prohibited for jobs triggered by an auxiliary user here
        //   because we only come here if the current service is FirstInitAll
        if (NVM_SERVICE_ID_RB_FIRST_INIT_ALL == NvM_Prv_GetActiveService())
        {
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2834] If this restore job was part of a first initialization,
            //                                               trigger a write job
            NvM_Prv_StartJob(NvM_Prv_idJob_Write_e,
                             JobData_pst->idBlock_uo,
                             JobData_pst->RamBlock_pu8,
                             JobData_pst->idxDataset_u8);
        }
    }
}

static void NvM_Prv_JobComplete_InvalidateAllDatasets(NvM_Prv_JobData_tst* JobData_pst)
{
    // check whether MemIf has finished the invalidate job successfully
    if (MEMIF_JOB_OK == JobData_pst->Result_en)
    {
        // Check whether the next DATASET block needs to be invalidated
        // -> if so, advance the current dataset index to the next DATASET instance and start another invalidation
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2850] Invalidate all the NV blocks of an NvM block of type DATASET
        //                                               which is selected for FirstInitAll
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2852] Remove all the NV blocks of a non-resistant NvM block
        //                                               of type DATASET during the removal phase
        if ((NVM_BLOCK_DATASET == NvM_Prv_GetBlockType(JobData_pst->idBlock_uo)) &&
            (JobData_pst->idxDataset_u8 < (NvM_Prv_GetNrNonVolatileBlocks(JobData_pst->idBlock_uo) - 1)))
        {
            if (NVM_SERVICE_ID_RB_FIRST_INIT_ALL == NvM_Prv_GetActiveService())
            {
                NvM_Prv_StartJob(NvM_Prv_idJob_InvalidateForFirstInitAll_e,
                                 JobData_pst->idBlock_uo,
                                 JobData_pst->RamBlock_pu8,
                                 JobData_pst->idxDataset_u8 + 1);
            }
            else
            {
                NvM_Prv_StartJob(NvM_Prv_idJob_InvalidateForRemoveNonResistant_e,
                                 JobData_pst->idBlock_uo,
                                 JobData_pst->RamBlock_pu8,
                                 JobData_pst->idxDataset_u8 + 1);
            }
        }
    }
}

static void NvM_Prv_JobComplete_Validate(NvM_Prv_JobData_tst* JobData_pst)
{
    // Note: Setting the job result to MEMIF_JOB_OK is done to simplify implementation.
    //       MemIf is not required for an auto validation operation.
    // The actual auto validation operation is done during result evaluation
    JobData_pst->Result_en = MEMIF_JOB_OK;
}

static NvM_Prv_JobComplete_tpfct NvM_Prv_GetFctJobComplete(NvM_Prv_idJob_ten idJob_en)
{
    if (idJob_en >= NvM_Prv_idJob_Count_e)
    {
        idJob_en = NvM_Prv_idJob_Invalid_e;
    }
    return NvM_Prv_JobCompleteFcts_capfct[idJob_en];
}

void NvM_Prv_MainFunctionJobComplete(void)
{

    NvM_BlockIdType idBlock_uo = NvM_Prv_Main_st.QueueEntry_pst->idBlock_uo;

    if (NvM_Prv_ErrorDetection_IsJobIdValid(NVM_SERVICE_ID_MAIN_FUNCTION,
                                            idBlock_uo,
                                            NvM_Prv_Main_st.JobData_st.idJob_en))
    {
        NvM_Prv_JobComplete_tpfct JobComplete_pfct = NvM_Prv_GetFctJobComplete(NvM_Prv_Main_st.JobData_st.idJob_en);
        if (NULL_PTR != JobComplete_pfct)
        {
            JobComplete_pfct(&NvM_Prv_Main_st.JobData_st);
        }
    }
    else
    {
        // This function may only be called with a known NvM_Prv_Main_st.idActiveJob_rMwM_en
        // (we should actually never get into this branch; it's just there for robustness)
        NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_FAILED;
    }

    // Determine the next state depending on the job start result
    if (MEMIF_JOB_PENDING != NvM_Prv_Main_st.JobData_st.Result_en)
    {
        // Polling needed
        NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_RESULT_EVAL;
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline code
 **********************************************************************************************************************
 */
LOCAL_INLINE void NvM_Prv_CopyBlockDataFromRom(NvM_BlockIdType idBlock_uo,
                                               uint8* RamBlock_pu8,
                                               uint8 idxDataset_u8)
{
    // A ROM block is configured for this block
    // TRACE[NVM267] Fill the block data buffer with ROM block data
    /* MR12 RULE 11.5 VIOLATION: The actual type of the ROM block varies from block to block (not under control of NvM) */
    uint8 const* adrSource_pcu8 = (uint8 const*)NvM_Prv_GetRomBlockAddress(idBlock_uo);
    uint16 nrRemainingBlockBytes_u16 = NvM_Prv_GetBlockSize(idBlock_uo);
    uint8 nrNonVolatileBlocks_u8 = NvM_Prv_GetNrNonVolatileBlocks(idBlock_uo);

    if (NVM_BLOCK_DATASET == NvM_Prv_GetBlockType(idBlock_uo))
    {
        // This DATASET block has its dataset-index pointing to a ROM block
        // (otherwise it wouldn't have been queued by NvM_RestoreBlockDefaults or by NvM_ReadBlock)
        // -> Move the source pointer to the start address of the indexed ROM block
        adrSource_pcu8 += nrRemainingBlockBytes_u16 * (idxDataset_u8 - nrNonVolatileBlocks_u8);
    }

    // Perform the restore job by copying data from the ROM-block to the RAM-block
    while (nrRemainingBlockBytes_u16 > 0)
    {
        *RamBlock_pu8 = *adrSource_pcu8;
        ++RamBlock_pu8;
        ++adrSource_pcu8;
        --nrRemainingBlockBytes_u16;
    }
}
