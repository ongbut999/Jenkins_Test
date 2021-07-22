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

 * Project : ETAS_TMS570_AR422_1p0
 * Component: /Base_SWC/Base_SWC
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: AGT1HC
 * Date : Tue Mar 12 11:10:11 2019
 ****************************************************************************/

#include "Rte_ASW_BASE.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_Base_SWC_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_Base_SWC_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_Base_SWC_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#include "Os.h"
#include "Os_CPUUtilization.h"
#define Base_SWC_START_SEC_CODE
#include "ASW_BASE_MemMap.h"
#define  TEN_SECOND 100


uint8 shutdown_b =0;
double CPU_Utilization_f;
uint32 SetOsTest=10;
uint32 count_base=0;
char Test_CPU_calculation;
char Test_ErrorHook;
FUNC (void, Base_SWC_CODE) RE_Base_SWC_func/* return value & FctID */
(
		void
)
{
	/* Local Data Declaration */
    uint32 Duration_u32;
    static char count_os_s;
    volatile float data_calculation;
	/*PROTECTED REGION ID(UserVariables :RE_Base_SWC_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Shutdown service -----------------------------------------  */

	if(shutdown_b)
	{

		Rte_Call_RPort_SelectShutdownTarget_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_OFF, ECUM_RESET_MCU);
		Rte_Write_PPort_SwcModeRequest_AppMode(SwcRequest_ECUM_STATE_APP_POST_RUN);

		shutdown_b=0;
	}
	/*  -------------------------------------- test CPU's Utilization -----------------------------------  */

	if(Test_CPU_calculation)
	{
		count_base = 0;

		for (count_base = 0;count_base<SetOsTest;count_base++)
		{
			data_calculation = (float)(data_calculation + count_base)/data_calculation;
		}

		if(count_os_s > TEN_SECOND)
		{
			/*Duration of calculation*/
			Duration_u32 = count_os_s * 100;
			CPU_Utilization_f = CPU_Utilization(Duration_u32);
			count_os_s =0;
			Test_CPU_calculation = 0;
		}
		else
		{
			count_os_s ++;
		}
	}

	/*  -------------------------------------- Test ErrorHook service -----------------------------------  */

	if(Test_ErrorHook)
	{
		ActivateTask(OsTask_ASW_100ms);
		Test_ErrorHook = 0;
	}

	/*PROTECTED REGION ID(User Logic :RE_Base_SWC_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

#define Base_SWC_STOP_SEC_CODE
#include "Rte_ASW_BASE.h"

#define ASW_BASE_START_SEC_CODE
#include "ASW_BASE_MemMap.h"
FUNC (void, ASW_BASE_CODE) RE_OsShell_TriggerBg_func/* return value & FctID */
(
		void
)
{
	TaskStateType stTaskState = SUSPENDED;

	/* Get Task State of background task.*/
	(void)GetTaskState(OsTask_Background_1ms, &stTaskState);

	if(stTaskState == SUSPENDED)
	{
		/* If back ground task terminate, just activate the background task. */
		(void)ActivateTask(OsTask_Background_1ms);
	}

}

#define ASW_BASE_STOP_SEC_CODE
#include "ASW_BASE_MemMap.h"
