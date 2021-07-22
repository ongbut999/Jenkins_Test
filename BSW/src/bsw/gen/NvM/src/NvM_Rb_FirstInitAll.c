
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "NvM_Cfg_SchM.h"
#include "Rte_NvM.h"

#if (NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON)
# include "BswM_NvM.h"
// TRACE[NVM089] Check version compatibility of included header files
# if (!defined(BSWM_AR_RELEASE_MAJOR_VERSION) || (BSWM_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
#  error "AUTOSAR major version undefined or mismatched"
# endif
# if (!defined(BSWM_AR_RELEASE_MINOR_VERSION) || ((BSWM_AR_RELEASE_MINOR_VERSION != 0) && \
                                                  (BSWM_AR_RELEASE_MINOR_VERSION != 2)))
#  error "AUTOSAR minor version undefined or mismatched"
# endif
#endif

#include "NvM_Prv_Queue.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"

/*
 **********************************************************************************************************************
 * Declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

static boolean NvM_Prv_IsBlockPartOfFirstInitAll(NvM_BlockIdType idBlock_uo);
static void NvM_Prv_FindBlocksForFirstInitAll(void);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

void NvM_Rb_FirstInitAll(void)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2826] Service to trigger a multi block (re-) initialization operation

    // Report the DET error NVM_E_NOT_INITIALIZED when the NVM is not yet initialized
    // (similar to what is requested by NVM647 in the context of NvM_WriteAll)
    if (NvM_Prv_ErrorDetection_IsNvmInitialized(NVM_SERVICE_ID_RB_FIRST_INIT_ALL, NVM_PRV_MULTI_BLOCK))
    {
        boolean isRequestEnqueued_b;
        // put all service parameters in a structure for a queue entry
        NvM_Prv_QueueEntry_tst QueueEntry_st;
        QueueEntry_st.idService_uo = NVM_SERVICE_ID_RB_FIRST_INIT_ALL;
        QueueEntry_st.idBlock_uo = NVM_CFG_FIRST_USED_BLOCK;
        QueueEntry_st.ServiceBit_uo = NvM_Prv_ServiceBit_FirstInitAll_e;
        QueueEntry_st.BlockData_pv = NULL_PTR;

        SchM_Enter_NvM_Main();

        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2829] The queue for multiblock requests has only one entry
        //                                               so if other multi-block request is active then the queue is full
        //                                               and FirstInitAll will be rejected
        isRequestEnqueued_b = NvM_Prv_Queue_EnqueueRequest(NvM_Prv_idQueue_Multi_e, &QueueEntry_st);

        if (isRequestEnqueued_b)
        {
            // TRACE[NVM185] Set multi block request result to NVM_REQ_PENDING on successful enqueuing
            NvM_Prv_Block_SetRequestResult(NVM_PRV_MULTI_BLOCK, NVM_REQ_PENDING);
            // The actual initialization operation is not done here, just the request for doing it is signaled
            NvM_Prv_Block_SetRequest(NVM_PRV_MULTI_BLOCK, QueueEntry_st.ServiceBit_uo);

            NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NvM_Prv_IsBlockPartOfFirstInitAll);
        }
        SchM_Exit_NvM_Main();


        if (isRequestEnqueued_b)
        {
            NvM_Prv_FindBlocksForFirstInitAll();
            NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NULL_PTR);
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2804] If BswMMultiBlockJobStatusInformation is enabled,
            //                                               notify BswM about the state change of the multiblock operation.
            // Calling foreign BswM function is done out of the Schm lock
#if (NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION == STD_ON)
            BswM_NvM_CurrentJobMode(NVM_SERVICE_ID_RB_FIRST_INIT_ALL, NVM_REQ_PENDING);
#endif
        }
    }
}

static boolean NvM_Prv_IsBlockPartOfFirstInitAll(NvM_BlockIdType idBlock_uo)
{
    // The following conditions must be fulfilled for initializing a block during FirstInitAll:
    return (NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL));
}

static void NvM_Prv_FindBlocksForFirstInitAll(void)
{
    NvM_BlockIdType idBlock_uo;

    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2830] Iterate over all used blocks to find the blocks
    //                                               which can and shall be initialized
    for (idBlock_uo = NVM_CFG_FIRST_USED_BLOCK; idBlock_uo < NVM_CFG_NR_BLOCKS; ++idBlock_uo)
    {
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3033] Ignore blocks with length null
        if (NvM_Prv_GetBlockSize(idBlock_uo) > 0)
        {
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2830] Only initialize blocks which are selected for FirstInitAll
            // Further conditions are already checked in the configuration scripts
            if (NvM_Prv_IsBlockPartOfFirstInitAll(idBlock_uo))
            {
                // TRACE[NVM185] Set single block request result to NVM_REQ_PENDING on successful enqueuing
                // This is done right away to allow an immediate NvM_GetErrorStatus call returning a meaningful result
                NvM_Prv_Block_SetRequestResult(idBlock_uo, NVM_REQ_PENDING);

                // Internally signal that this block has been requested to be written
                NvM_Prv_Block_SetRequest(idBlock_uo, NvM_Prv_ServiceBit_FirstInitAll_e);
            }
            else
            {
                // Set job result to NVM_REQ_BLOCK_SKIPPED if not initialized
                // This is done right away to allow an immediate NvM_GetErrorStatus call returning a meaningful result
                // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2879] If a block is currently PENDING due
                //                                               to a queued/running single block operation,
                //                                               the request result shouldn't be set to SKIPPED
                if (NVM_REQ_PENDING != NvM_Prv_Block_GetRequestResult(idBlock_uo))
                {
                    NvM_Prv_Block_SetRequestResult(idBlock_uo, NVM_REQ_BLOCK_SKIPPED);
                }
            }
        }
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
