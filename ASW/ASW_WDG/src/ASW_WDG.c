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

 * Project : ETAS_TMS570_AR422_3p0
 * Component: /ARPackage_0/ASW_WDG
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: AGT1HC
 * Date : Tue May 21 16:03:55 2019
 ****************************************************************************/

#include "Rte_ASW_WDG.h"
#include "ASW_WDG.h"
#include "WdgIf_Types.h"
#include "WdgIf_Cfg.h"
#include "WdgM.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_ASW_WDG_Alive_Supervision_Entity1_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_ASW_WDG_Alive_Supervision_Entity1_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_ASW_WDG_Alive_Supervision_Entity1_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define ASW_WDG_START_SEC_CODE                   
#include "ASW_WDG_MemMap.h"

Wdg_Test_t Wdg_TestCase_Local = WDG_NONE;

FUNC (void, ASW_WDG_CODE) RE_ASW_WDG_Alive_Supervision_Entity1_func/* return value & FctID */
(
		void
)
{

	WdgM_CheckpointIdType CheckpointID1=0;
	Std_ReturnType syncCall1;
	static uint16 Entity1_Count;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :RE_ASW_WDG_Alive_Supervision_Entity1_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	switch (Wdg_TestCase_Local)
	{
		case ALIVE_OK_LACKOF_ONE_CP_ALIVE_SUPERVISION_ENTITY1:
			Wdg_TestCase_Local=WDG_NONE;
			break;

		case ALIVE_OK_LACKOF_TWO_ALIVE_SUPERVISION_ENTITY1:
			/*lack of 2 CP*/
			if(Entity1_Count>0)
			{
				Wdg_TestCase_Local=WDG_NONE;
				Entity1_Count=0;
			}
			else
			{
				Entity1_Count++;
			}
			break;
		case ALIVE_NOTOK_LACKOF_THREE_ALIVE_SUPERVISION_ENTITY1:
			/*lack of 3 CPs*/
			if(Entity1_Count>1)
			{
				Wdg_TestCase_Local=WDG_NONE;
				Entity1_Count=0;
			}
			else
			{
				Entity1_Count++;
			}
			break;

		case ALIVE_NOTOK_ADDMORE_ALIVE_SUPERVISION_ENTITY1:
			syncCall1 = Rte_Call_RPort_Alive_Supervision_Entity1_CheckpointReached(CheckpointID1);
			/*add more checkpoint*/
			syncCall1 = Rte_Call_RPort_Alive_Supervision_Entity1_CheckpointReached(CheckpointID1);
			Wdg_TestCase_Local=WDG_NONE;
			break;

		case CHANGE_MODE:
			WdgM_SetMode(0, WDGIF_FAST_MODE);
			break;
		default:
			syncCall1 = Rte_Call_RPort_Alive_Supervision_Entity1_CheckpointReached(CheckpointID1);
			break;
	}

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :RE_ASW_WDG_Alive_Supervision_Entity1_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

#define ASW_WDG_STOP_SEC_CODE                       
#include "ASW_WDG_MemMap.h"
