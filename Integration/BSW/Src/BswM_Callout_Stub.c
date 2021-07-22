/*
 * BswM_Callout_Stub.c
 *
 *  Created on: July 4, 2019
 *      Author: AGT1HC
 */
#include "Platform_Types.h"
#include "BswM_PBcfg.h"
#include "BswM_Generic.h"
#include "EcuM.h"
#include "SchM_BswM_Type.h"
/**********************************************************************************
   Function name    :  CheckCondition
   Description      :  the software simulation of Checking the wake up source
   Parameter  (in)  :
   Parameter  (inout)  :  None
   Parameter  (out)  :  None
   Return value    :  None
   Remarks      :
 ***********************************************************************************/
/*by default the wake-up is valid */
uint8 Condition = 1;
uint8 active_wakeup = 0;
uint8 passive_wakeup = 0;
extern uint8 shutdown_b;
void CheckCondition(void)
{
    switch (Condition)
    {
    case 1 /* active wake up */:
        /* code */
        active_wakeup=1;
        BswM_RequestMode(BSWM_CFG_USERID_BSWMSWCMODEREQUEST,RTE_MODE_MDG_App_Mode_ECUM_WAKEUP);
        break;
    case 2 /* passive wake up */:
        /* code */
        passive_wakeup=1;
        BswM_RequestMode(BSWM_CFG_USERID_BSWMSWCMODEREQUEST,RTE_MODE_MDG_App_Mode_ECUM_WAKEUP);
        break;
    default: /*unknown wake up */
        BswM_RequestMode(BSWM_CFG_USERID_BSWMSWCMODEREQUEST,RTE_MODE_MDG_App_Mode_ECUM_NOWAKEUP);
        EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_OFF, ECUM_RESET_MCU);
        break; 
    }
    
}
