
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_ErrorDetection.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

Std_ReturnType NvM_Rb_GetStatus(NvM_Rb_StatusType *StatusPtr)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2750] Service to read the overall status of the NVRAM manager
    Std_ReturnType stReturn_uo = E_NOT_OK;

    // Check provided parameter
    if (NvM_Prv_ErrorDetection_IsPtrValidForNvmStatus(NVM_SERVICE_ID_RB_GET_STATUS, StatusPtr))
    {
        // Parameter is valid
        // -> translate internal activity status into public NvM status
        // No SchM lock can and should be done here to allow calling this function from NvM callbacks without deadlocks
        if (!NvM_Prv_IsNvmInitialized())
        {
            *StatusPtr = NVM_RB_STATUS_UNINIT;
        }
        else if (NvM_Prv_IsNvmIdle())
        {
            *StatusPtr = NVM_RB_STATUS_IDLE;
        }
        else
        {
            *StatusPtr = NVM_RB_STATUS_BUSY;
        }

        stReturn_uo = E_OK;
    }
    // Return whether this operation was successful
    return stReturn_uo;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
