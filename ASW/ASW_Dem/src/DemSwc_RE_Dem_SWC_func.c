/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: 
 * Description:
 * Version: 1.0
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : GAEI_HCU_ASR_2p0
 * Component: /Dem_SWC/Dem_SWC
 * Runnable : DemSwc_RE_Dem_SWC
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: had1hc
 * Date : Thu Dec 06 16:25:10 2018
 ****************************************************************************/

#include "Rte_ASW_Dem.h"
#include "SWC_Dem.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :DemSwc_RE_Dem_SWC_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :DemSwc_RE_Dem_SWC_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :DemSwc_RE_Dem_SWC_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
#include "ASW_Dem_MemMap.h"
uint8 Dem_Testcase = 0, genUint8 = 0;

#define RTE_STOP_SEC_Partition_Core0_Trusted_VAR_INIT_8
#include "ASW_Dem_MemMap.h"

#define RTE_START_SEC_Partition_Core0_Trusted_VAR_INIT_8
#include "ASW_Dem_MemMap.h"
uint8 isQualified = FALSE;
uint8 PfcQualified_Trigger = FALSE;
#define RTE_STOP_SEC_Partition_Core0_Trusted_VAR_INIT_8
#include "ASW_Dem_MemMap.h"
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

#define Dem_SWC_START_SEC_CODE                   
#include "ASW_Dem_MemMap.h"

FUNC(void, Dem_SWC_CODE)DemSwc_RE_Dem_SWC_func/* return value & FctID */
(
		void
)
{
    Std_ReturnType syncCall2;
    Std_ReturnType syncCall3;
    if( genUint8 == 0 )
    {
    	Rte_Call_RPort_OpCycle_DemOperationCycle_0_SetOperationCycleState(DEM_CYCLE_STATE_START);
        genUint8 = 1;
    }


    switch (Dem_Testcase)
    {
    case 0x01:
        syncCall2 = Rte_Call_Event_DemEventParameter_C110117_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
        Dem_Testcase = 0;
        break;
    case 0x02:
        syncCall2 = Rte_Call_Event_DemEventParameter_C110117_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
        Dem_Testcase = 0;
        break;
    case 0x03:
        syncCall3 = Rte_Call_Event_DemEventParameter_C110216_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
        Dem_Testcase = 0;
        break;
    case 0x04:
        syncCall3 = Rte_Call_Event_DemEventParameter_C110216_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
        Dem_Testcase = 0;
        break;
    default:
        break;
    }


}


FUNC(void, Dem_SWC_CODE) RunnableEntity_0_func(VAR(boolean, AUTOMATIC) ComponentFailedStatus)
{

}



#define Dem_SWC_STOP_SEC_CODE                       
#include "ASW_Dem_MemMap.h"
