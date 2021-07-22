
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "Rte_NvM.h"

#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/* MR12 RULE 8.3 VIOLATION: The parameter identifiers in Rte's generated declaration of this depend on Rte vendor */
Std_ReturnType NvM_GetErrorStatus(NvM_BlockIdType BlockId, NvM_RequestResultType *RequestResultPtr)
{
    // TRACE[NVM451] Service to read the block dependent error/status information
    Std_ReturnType stReturn_u8 = E_NOT_OK;

    // TRACE[NVM610] Report the DET error NVM_E_NOT_INITIALIZED when the NVM is not yet initialized
    if (NvM_Prv_ErrorDetection_IsNvmInitialized(NVM_SERVICE_ID_GET_ERROR_STATUS, BlockId))
    {
        // TRACE[NVM611] Report the DET error NVM_E_PARAM_BLOCK_ID when the passed BlockID is out of range
        // TRACE[NVM394] NvM_Prv_stRequestResult_rAwAM_au8[0] contains the status of multiblock operations
        if (NvM_Prv_ErrorDetection_IsBlockIdValid(NVM_SERVICE_ID_GET_ERROR_STATUS, BlockId, TRUE))
        {
            // TRACE[NVM612] Report the DET error NVM_E_PARAM_DATA when a NULL pointer is passed
            //               via the parameter RequestResultPtr
            if (NvM_Prv_ErrorDetection_IsPtrValidForRequestResult(NVM_SERVICE_ID_GET_ERROR_STATUS,
                                                                  BlockId,
                                                                  RequestResultPtr))
            {
                // Parameters are valid
                // TRACE[NVM015] Read out the selected block's state from the administrative block
                // TRACE[NVM394] NvM_Prv_stRequestResult_rAwAM_au8[0] contains the status of multiblock operations
                // No SchM lock can and should be done here to allow calling this function from NvM callbacks
                // without deadlocks
                *RequestResultPtr = NvM_Prv_Block_GetRequestResult(BlockId);
                stReturn_u8 = E_OK;
            }
        }
    }

    // Return whether this operation was successful
    return stReturn_u8;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
