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
 * Runnable : DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: had1hc
 * Date : Fri Nov 30 19:24:34 2018
 ****************************************************************************/

#include "Rte_ASW_Dem.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define Dem_SWC_START_SEC_CODE                   
#include "ASW_Dem_MemMap.h"

FUNC (Std_ReturnType, AUTOMATIC) DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData_func/* return value & FctID */
(
		CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
)
{

//	Dcm_DataArrayTypeUint8_DcmDspData_VehicleSpeedType dRead1;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
//	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */
//	dRead1 = Rte_DRead_RPort_DataReceive_VehicleSpeed_Data();

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :DemSwc_RE_CSDataElementClass_VehicleSpeed_ReadData_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
//	*Data = dRead1;
//	return retValue;
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

#define Dem_SWC_STOP_SEC_CODE                       
#include "ASW_Dem_MemMap.h"
