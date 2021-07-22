
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

Std_ReturnType NvM_Rb_GetActiveService(uint8 *ServiceIdPtr)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2827] Service to read the ID of the currently active service
    //                                               of the NVRAM manager
    Std_ReturnType stReturn_u8 = E_NOT_OK;

    if (NvM_Prv_ErrorDetection_IsPtrValidForServiceId(NVM_SERVICE_ID_RB_GET_ACTIVE_SERVICE, ServiceIdPtr))
    {
        NvM_Prv_idService_tuo idActiveService_uo = NvM_Prv_GetActiveService();

#if (NVM_PRV_MAINTAIN_REDUNDANT_BLOCKS)
        // The maintenance phase shall not be visible for an NvM user.
        // CAUTION: The following assignment has to be changed in the future if it is decided
        //          to make the maintenance operation visible for an NvM user.
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2865] If the maintenance operation is currently being executed
        //                                               then NvM_Rb_GetActiveService indicates WRITE_ALL as active service
        if (idActiveService_uo == NVM_PRV_SERVICE_ID_MAINTAIN_BLOCK)
        {
            *ServiceIdPtr = NVM_SERVICE_ID_WRITE_ALL;
        }
        else
#endif
        {
            *ServiceIdPtr = idActiveService_uo ;
        }

        stReturn_u8 = E_OK;
    }

    return stReturn_u8;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
