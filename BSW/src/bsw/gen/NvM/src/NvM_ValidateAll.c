
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "NvM_Cfg_SchM.h"

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

static boolean NvM_Prv_IsBlockPartOfValidateAll(NvM_BlockIdType idBlock_uo);
static void NvM_Prv_FindBlocksForValidateAll(void);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**
 * This function initiates a multiblock validation request.
 *
 * A multiblock validation request will be initiated only if NvM has been initialized and no other multiblock request
 * is active. Furthermore this request will be initiated only for NVRAM-blocks which are valid
 * (citation from AR "not INVALID") and configured for auto validation.
 *
 * To signal a successful initiation this function sets the request result to pending state for each NVRAM-block and
 * sets the bit which globally represents the ValidateAll request in administrative-block of each NVRAM-block.
 */
void NvM_ValidateAll(void)
{
    // TRACE[NVM855] Initiates a multi block validation request

    if (NvM_Prv_ErrorDetection_IsNvmInitialized(NVM_SERVICE_ID_VALIDATE_ALL, NVM_PRV_MULTI_BLOCK))
    {
        boolean isRequestEnqueued_b;
        // put all service parameters in a structure for a queue entry
        NvM_Prv_QueueEntry_tst QueueEntry_st;
        QueueEntry_st.idService_uo = NVM_SERVICE_ID_VALIDATE_ALL;
        QueueEntry_st.idBlock_uo = NVM_CFG_FIRST_USED_BLOCK;
        QueueEntry_st.ServiceBit_uo = NvM_Prv_ServiceBit_ValidateAll_e;
        QueueEntry_st.BlockData_pv = NULL_PTR;

        SchM_Enter_NvM_Main();

        // TRACE[NVM380] The "queue" for multiblock requests has only one entry
        //               so only one multiblock operation is allowed
        isRequestEnqueued_b = NvM_Prv_Queue_EnqueueRequest(NvM_Prv_idQueue_Multi_e, &QueueEntry_st);

        if (isRequestEnqueued_b)
        {
            // TRACE[NVM185] Set multi block request result to NVM_REQ_PENDING on successful enqueuing
            // TRACE[NVM861] Same as NVM185, but specific to NvM_ValidateAll
            NvM_Prv_Block_SetRequestResult(NVM_PRV_MULTI_BLOCK, NVM_REQ_PENDING);
            // The position of request flag setting is different from other requests
            // because it does not matter
            // TRACE[NVM858] The actual autovalidation operation is not done here,
            //               just the request for doing it is signaled
            NvM_Prv_Block_SetRequest(NVM_PRV_MULTI_BLOCK, QueueEntry_st.ServiceBit_uo);

            NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NvM_Prv_IsBlockPartOfValidateAll);
        }

        SchM_Exit_NvM_Main();

        if (isRequestEnqueued_b)
        {
            NvM_Prv_FindBlocksForValidateAll();
            NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NULL_PTR);
        }
    }
}

static boolean NvM_Prv_IsBlockPartOfValidateAll(NvM_BlockIdType idBlock_uo)
{
    boolean IsBlockValid_b = NvM_Prv_Block_IsPRamBlockValid(idBlock_uo);
    // The following conditions must be fulfilled for validating a block during ValidateAll:
    return (
            // TRACE[NVM856] Only validate blocks which are selected for ValidateAll
            // TRACE[NVM860] Similar as NVM856
            NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_USE_AUTO_VALIDATION) &&
            IsBlockValid_b
           );
}

static void NvM_Prv_FindBlocksForValidateAll(void)
{
    NvM_BlockIdType idBlock_uo;

    // Iterate through all used blocks to find the blocks which can and shall be validated
    for (idBlock_uo = NVM_CFG_FIRST_USED_BLOCK; idBlock_uo < NVM_CFG_NR_BLOCKS; ++idBlock_uo)
    {
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3033] Ignore blocks with length null
        if (NvM_Prv_GetBlockSize(idBlock_uo) > 0)
        {
            if (NvM_Prv_IsBlockPartOfValidateAll(idBlock_uo))
            {
                //  TRACE[NVM861] Set the result for each proceeding block to NVM_REQ_PENDING
                NvM_Prv_Block_SetRequestResult(idBlock_uo, NVM_REQ_PENDING);
                // Internally signal that this block has been requested to be validated
                NvM_Prv_Block_SetRequest(idBlock_uo, NvM_Prv_ServiceBit_ValidateAll_e);
            }
        }
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
