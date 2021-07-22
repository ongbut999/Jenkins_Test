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
 * Component: /COM_SWC/COM_SWC
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: AGT1HC
 * Date : Tue Mar 12 11:07:12 2019
 ****************************************************************************/

#include "Rte_ASW_COM.h"


/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_COM_SWC_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_COM_SWC_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_COM_SWC_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define COM_SWC_START_SEC_CODE
uint8 read1;
Std_ReturnType retRead1;
sint16 read2;
Std_ReturnType retRead2;
sint16 read3;
Std_ReturnType retRead3;

sint16 read4;
Std_ReturnType retRead4;
sint16 read5;
Std_ReturnType retRead5;
sint16 read6;
Std_ReturnType retRead6;


boolean write4 = TRUE;
Std_ReturnType retWrite4;
uint16 write5;
Std_ReturnType retWrite5;
boolean write6 = TRUE;
Std_ReturnType retWrite6;
boolean write7 ;
Std_ReturnType retWrite7;

#include "ASW_COM_MemMap.h"
FUNC (void, COM_SWC_CODE) RE_COM_SWC_func/* return value & FctID */
(
		void
)
{
	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :RE_COM_SWC_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	/*  -------------------------------------- Data Read -----------------------------------------  */

	retRead1 = Rte_Read_RPort_HCU01_Shift_HCU01_Shift(&read1);
	retRead2 = Rte_Read_RPort_HCU01_TqCmd_HCU01_Tq_Cmd(&read2);
	retRead3 = Rte_Read_RPort_HCU02_Poweroff_HCU02_Poweroff(&read3);
	retRead4 = Rte_Read_RPott_HCU03_Poweroff_HCU03_Poweroff(&read4);
	retRead5 = Rte_Read_RPort_HCU04_Poweroff_HCU04_Poweroff(&read5);
	retRead6 = Rte_Read_RPort_HCU05_Poweroff_HCU05_Poweroff(&read6);
	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */
	retWrite4 = Rte_Write_PPort_MCU01_EmergShutDown_MCU01_EmergShutDown(write4);
	retWrite5 = Rte_Write_PPort_MCU02_MaxTor_MCU02_MaxTor(write5);
	retWrite6 = Rte_Write_PPort_MCU03_NRF_IdcSamp_MCU03_NRF_IdcSamp(write6);
	retWrite7 = Rte_Write_PPort_MCU04_Test_MCU04_Test(write7);
	if (write4 == TRUE)
	{
		write4 = FALSE;
	}
	else
	{
		write4 = TRUE;
	}

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :RE_COM_SWC_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

#define COM_SWC_STOP_SEC_CODE
#include "ASW_COM_MemMap.h"

