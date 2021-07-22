/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the //#error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */
#ifndef NOT_READY_FOR_TESTING_OR_DEPLOYMENT
//#error The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#else
//#warning The content of this file is a template which provides empty stubs. The content of this file must be completed by the integrator accordingly to project specific requirements
#endif /* NOT_READY_FOR_TESTING_OR_DEPLOYMENT */

#if (DEM_CFG_OBD != DEM_CFG_OBD_OFF)


#include "rba_DemObdBasic_Dcm.h"
#include "rba_DemObdBasic_Prv.h"
#include "DcmDspObd_Mode1_Inf.h"


#define DEM_START_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

extern Std_ReturnType Dem_DcmReadDataOfPID21(uint8* PID21value)
{
    Std_ReturnType retVal;

    if (rba_DemObdBasic_IsObdMasterEcu())
    {
        (void)PID21value;
        retVal = E_OK;
    }
    else
    {
        /* PID 21 is calculated by MasterECU */
        retVal = E_NOT_OK;
    }

    return retVal;
}

extern Std_ReturnType Dem_DcmReadDataOfPID31(uint8* PID31value)
{
    Std_ReturnType retVal;

    if (rba_DemObdBasic_IsObdMasterEcu())
    {
        (void)PID31value;
        retVal = E_OK;
    }
    else
    {
        /* PID 31 is calculated by MasterECU */
        retVal = E_NOT_OK;
    }
    return retVal;
}

extern Std_ReturnType Dem_DcmReadDataOfPID4D(uint8* PID4Dvalue)
{
    Std_ReturnType retVal;

    if (rba_DemObdBasic_IsObdMasterEcu())
    {
        (void)PID4Dvalue;
        retVal = E_OK;
    }
    else
    {
        /* PID 4D is calculated by MasterECU */
        retVal = E_NOT_OK;
    }
    return retVal;
}

extern Std_ReturnType Dem_DcmReadDataOfPID4E(uint8* PID4Evalue)
{
    Std_ReturnType retVal;

    if (rba_DemObdBasic_IsObdMasterEcu())
    {
	(void) PID4Evalue;
        retVal = E_OK;
    }
    else
    {
        /* PID 4E is calculated by MasterECU */
        retVal = E_NOT_OK;
    }
    return retVal;
}



#define DEM_STOP_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

#endif