
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

Std_ReturnType NvM_Rb_GetNvBlockLength(NvM_BlockIdType BlockId, uint16 *NvBlockLengthPtr)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2791] Service for getting the configured NV block length in bytes
    //                                               of an NvM block
    Std_ReturnType stReturn_uo = E_NOT_OK;

    if (NvM_Prv_ErrorDetection_IsBlockIdValid(NVM_SERVICE_ID_RB_GET_NV_BLOCK_LENGTH, BlockId, FALSE))
    {
        if (NvM_Prv_ErrorDetection_IsPtrValidForBlockLength(NVM_SERVICE_ID_RB_GET_NV_BLOCK_LENGTH,
                                                            BlockId,
                                                            NvBlockLengthPtr))
        {
            *NvBlockLengthPtr = NvM_Prv_GetBlockSize(BlockId);
            stReturn_uo = E_OK;
        }
    }

    return stReturn_uo;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
