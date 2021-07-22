
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "NvM_Cfg_SchM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_Queue.h"
#include "NvM_Prv_Service.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
 */
LOCAL_INLINE  boolean NvM_Prv_Service_CheckPreconditions(NvM_Prv_idQueue_tuo idQueue_uo,
                                                         NvM_BlockIdType idBlock_uo,
                                                         NvM_Prv_idService_tuo idService_uo);
LOCAL_INLINE Std_ReturnType NvM_Prv_Service_CheckBlockData(NvM_Prv_idQueue_tuo idQueue_uo,
                                                           NvM_Prv_BlockData_tst const* BlockData_pcst,
                                                           NvM_Prv_Service_Configuration_tst const* ServiceConfiguration_pcst);
LOCAL_INLINE Std_ReturnType NvM_Prv_Service_SetBlockData(NvM_Prv_idQueue_tuo idQueue_uo,
                                                         NvM_Prv_BlockData_tst const* BlockData_pcst,
                                                         NvM_Prv_Service_SetBlockData_tpfct SetBlockData_pfct);

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

Std_ReturnType NvM_Prv_Service_Initiate(NvM_Prv_idQueue_tuo idQueue_uo,
                                        NvM_Prv_BlockData_tst const* BlockData_pcst,
                                        NvM_Prv_Service_Configuration_tst const* ServiceConfiguration_pcst)
{
    Std_ReturnType stReturn_uo = E_NOT_OK;

    // check whether passed service configuration and block data are valid
    if ((NULL_PTR != BlockData_pcst) &&
        (NULL_PTR != ServiceConfiguration_pcst))
    {
        if (NvM_Prv_Service_CheckPreconditions(idQueue_uo,
                                               BlockData_pcst->QueueEntry_st.idBlock_uo,
                                               BlockData_pcst->QueueEntry_st.idService_uo))
        {
            boolean isCheckParameterSuccessful_b = TRUE;

            if (NULL_PTR != ServiceConfiguration_pcst->CheckParameter_pfct)
            {
                isCheckParameterSuccessful_b = ServiceConfiguration_pcst->CheckParameter_pfct(BlockData_pcst);
            }

            if (isCheckParameterSuccessful_b)
            {
                stReturn_uo = NvM_Prv_Service_CheckBlockData(idQueue_uo,
                                                             BlockData_pcst,
                                                             ServiceConfiguration_pcst);
            }
        }
    }

    return stReturn_uo;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline code
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean NvM_Prv_Service_CheckPreconditions(NvM_Prv_idQueue_tuo idQueue_uo,
                                                        NvM_BlockIdType idBlock_uo,
                                                        NvM_Prv_idService_tuo idService_uo)
{
    boolean stReturn_b = FALSE;
    if (NvM_Prv_ErrorDetection_IsNvmInitialized(idService_uo, idBlock_uo))
    {
        if (NvM_Prv_ErrorDetection_IsBlockIdValid(idService_uo, idBlock_uo, FALSE))
        {
            if (idQueue_uo < NvM_Prv_idQueue_nrQueues_e)
            {
                // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3032] Ignore blocks with length null
                boolean isBlockLengthValid_b = NvM_Prv_IsBlockLengthValid(idBlock_uo);
                // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2999] Potentially incompatible blocks after layout changes
                //                                               shall be sanitized by ReadAll at first,
                //                                               then the current single block request is allowed
                //                                               to be accepted and executed
                boolean isSanitizedByReadAll_b = NvM_Prv_IsSanitizedByReadAll(idBlock_uo);

                if (isBlockLengthValid_b && isSanitizedByReadAll_b)
                {
                    stReturn_b = TRUE;
                }
            }
            else
            {
                stReturn_b = TRUE;
            }
        }
    }
    return stReturn_b;
}

LOCAL_INLINE Std_ReturnType NvM_Prv_Service_CheckBlockData(NvM_Prv_idQueue_tuo idQueue_uo,
                                                           NvM_Prv_BlockData_tst const* BlockData_pcst,
                                                           NvM_Prv_Service_Configuration_tst const* ServiceConfiguration_pcst)
{
    Std_ReturnType stBlockData_uo = E_NOT_OK;
    boolean isCheckBlockDataSuccessful_b = TRUE;
    // Variables used to report DET errors out of the scheduler lock
    boolean isBlockPending_b = FALSE;

    NvM_BlockIdType idBlockForPendingCheck_uo = BlockData_pcst->QueueEntry_st.idBlock_uo;
#if (NVM_RB_AUX_INTERFACE == STD_ON)
    if (NvM_Prv_idQueue_Aux_e == idQueue_uo)
    {
        idBlockForPendingCheck_uo = NVM_PRV_AUX_ADMIN_BLOCK;
    }
#endif

    SchM_Enter_NvM_Main();

    if (NULL_PTR != ServiceConfiguration_pcst->CheckBlockData_pfct)
    {
        isCheckBlockDataSuccessful_b = ServiceConfiguration_pcst->CheckBlockData_pfct(BlockData_pcst);
    }

    if (isCheckBlockDataSuccessful_b)
    {
        // TRACE[NVM181] Queue this request to allow multiple concurrent single block requests
        // TRACE[NVM385] Only queue this request if no operation on this block is requested or in progress
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2866] Exception to NVM385: A service can be queued for a block
        //                                               whose the only pending operation is a maintenance operation.
        // TRACE[NVM181] Queue this request to allow multiple concurrent single block requests
        if (ServiceConfiguration_pcst->CheckPendingBlock_b)
        {
            isBlockPending_b = NvM_Prv_Block_IsPending(idBlockForPendingCheck_uo);
        }

        if (!isBlockPending_b)
        {
            stBlockData_uo = NvM_Prv_Service_SetBlockData(idQueue_uo,
                                                          BlockData_pcst,
                                                          ServiceConfiguration_pcst->SetBlockData_pfct);
        }
    }

    SchM_Exit_NvM_Main();

    // Calling foreign DET function is done out of the scheduler lock
    NvM_Prv_ErrorDetection_IsBlockPending(BlockData_pcst->QueueEntry_st.idService_uo,
                                          BlockData_pcst->QueueEntry_st.idBlock_uo,
                                          isBlockPending_b);
    return stBlockData_uo;
}

LOCAL_INLINE Std_ReturnType NvM_Prv_Service_SetBlockData(NvM_Prv_idQueue_tuo idQueue_uo,
                                                         NvM_Prv_BlockData_tst const* BlockData_pcst,
                                                         NvM_Prv_Service_SetBlockData_tpfct SetBlockData_pfct)
{
    Std_ReturnType stBlockData_uo = E_NOT_OK;
    boolean isReqEnqueued_b = TRUE;

    // check whether service shall be enqueued
    if (idQueue_uo < NvM_Prv_idQueue_nrQueues_e)
    {
        // TRACE[NVM184] In case of a queue overflow, the return value is E_NOT_OK
        isReqEnqueued_b = NvM_Prv_Queue_EnqueueRequest(idQueue_uo, &BlockData_pcst->QueueEntry_st);

    }

    if (isReqEnqueued_b)
    {
        if (NULL_PTR != SetBlockData_pfct)
        {
            SetBlockData_pfct(BlockData_pcst);
        }
        stBlockData_uo = E_OK;
    }

    return stBlockData_uo;
}

