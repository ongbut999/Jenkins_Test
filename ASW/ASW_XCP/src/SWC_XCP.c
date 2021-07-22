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

 * Project : ETAS_TMS570_AR422_4p0
 * Component: /XCP_SWC/XCP_SWC
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: GBI81HC
 * Date : Fri Jul 05 09:32:14 2019
 ****************************************************************************/
#include "Overlaymanager.h"
#include "Rte_ASW_XCP.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_XCP_SWC_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_XCP_SWC_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_XCP_SWC_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

#define XCP_CALIB_START_SEC_CONST_32
#include "Xcp_Memmap.h"
const volatile uint32 test_calib[2] =  {0x01};   /*16 KB data for calib in maximum */
#define XCP_CALIB_STOP_SEC_CONST_32
#include "Xcp_Memmap.h"


#define XCP_SWC_START_SEC_CODE
#include "ASW_XCP_MemMap.h"


uint32 Measured_Var[20];

/*locate a memory area for calib */


FUNC (void, XCP_SWC_CODE) RE_XCP_SWC_func/* return value & FctID */
(
		void
)
{

//	/* Local Data Declaration */
//
//	/*PROTECTED REGION ID(UserVariables :RE_XCP_SWC_func) ENABLED START */
//	/* Start of user variable defintions - Do not remove this comment  */
//	/* End of user variable defintions - Do not remove this comment  */
//	/*PROTECTED REGION END */
//	Std_ReturnType retValue = RTE_E_OK;
//	/*  -------------------------------------- Data Read -----------------------------------------  */
//
//	/*  -------------------------------------- Server Call Point  --------------------------------  */
//
//	/*  -------------------------------------- CDATA ---------------------------------------------  */
//
//	/*  -------------------------------------- Data Write ----------------------------------------  */
//
//	/*  -------------------------------------- Trigger Interface ---------------------------------  */
//
//	/*  -------------------------------------- Mode Management -----------------------------------  */
//
//	/*  -------------------------------------- Port Handling -------------------------------------  */
//
//	/*  -------------------------------------- Exclusive Area ------------------------------------  */
//
//	/*  -------------------------------------- Multiple Instantiation ----------------------------  */
//
//	/*PROTECTED REGION ID(User Logic :RE_XCP_SWC_func) ENABLED START */
//	/* Start of user code - Do not remove this comment */
//	/* End of user code - Do not remove this comment */
//	/*PROTECTED REGION END */
//
//
//	/*User code */
//
//
//    	//Measured_Var =   test_calib + 1 ;
	Measured_Var[0] =   test_calib[0] + 1 ;
	Measured_Var[1] =   test_calib[1] + 1;
}

#define XCP_SWC_STOP_SEC_CODE
#include "ASW_XCP_MemMap.h"
