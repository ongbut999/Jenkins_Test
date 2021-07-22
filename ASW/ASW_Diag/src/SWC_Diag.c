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
 * Component: /ARPackage_0/Diag_SWC
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: gbi81hc
 * Date : Fri May 31 16:36:07 2019
 ****************************************************************************/

#include "Rte_ASW_Diag.h"

/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :Diag_IOControl_VacuumPumpPressure_freezeCurrentState_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :Diag_IOControl_VacuumPumpPressure_freezeCurrentState_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :Diag_IOControl_VacuumPumpPressure_freezeCurrentState_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */


#define START_ROUTINE 1
#define STOP_ROUTINE 2
#define REQUEST_ROUTINE 3

static Dcm_DataArrayTypeUint8_DcmDspData_SystemFaultRankType DID_2311;

static Dcm_DataArrayTypeUint8_DcmDspData_VehicleSpeedType DID_2310;

static Dcm_DataArrayTypeUint8_DcmDspData_VacuumPumpPressure_1100Type VacuumPumpPressure_Data;

static uint8 mode_routine;

#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_IOControl_VacuumPumpPressure_freezeCurrentState_func/* return value & FctID */
(
		CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_IOControl_VacuumPumpPressure_freezeCurrentState_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_IOControl_VacuumPumpPressure_freezeCurrentState_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
	VacuumPumpPressure_Data[0] = 0xBB;
	VacuumPumpPressure_Data[1] = 0xBB;
	*ErrorCode = 0;
	return retValue;

}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_IOControl_VacuumPumpPressure_shortTermAdjustment_func/* return value & FctID */
(
        P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) ControlStateInfo, CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_IOControl_VacuumPumpPressure_shortTermAdjustment_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_IOControl_VacuumPumpPressure_shortTermAdjustment_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
    VacuumPumpPressure_Data[0] = *ControlStateInfo;
    VacuumPumpPressure_Data[1] = *(ControlStateInfo+1);
    *ErrorCode = 0;
    return retValue;
    /* End of user code - Do not remove this comment */

}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_RoutineServices_DriveVacuumPump_Start_func/* return value & FctID */
(
		VAR(Dcm_StartDataIn_DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineInSignalType, AUTOMATIC) DataIn_DcmDspStartRoutineInSignal,
		VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
		CONSTP2VAR(Dcm_StartDataOut_DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineOutSignalType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStartRoutineOutSignal,
		CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_RoutineServices_DriveVacuumPump_Start_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_RoutineServices_DriveVacuumPump_Start_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

	mode_routine = START_ROUTINE;
	return retValue;
}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_RoutineServices_DriveVacuumPump_Stop_func/* return value & FctID */
(
		VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
		CONSTP2VAR(Dcm_StopDataOut_DcmDspRoutine_DriveVacuumPump_DcmDspStopRoutineOutSignalType, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspStopRoutineOutSignal,
		CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_RoutineServices_DriveVacuumPump_Stop_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_RoutineServices_DriveVacuumPump_Stop_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

	/*User integration code*/
	mode_routine = STOP_ROUTINE;
	return retValue;
}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_IOControl_VacuumPumpPressure_resetToDefault_func/* return value & FctID */
(
		CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_IOControl_VacuumPumpPressure_resetToDefault_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_IOControl_VacuumPumpPressure_resetToDefault_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
    VacuumPumpPressure_Data[0] = 0x10;
    VacuumPumpPressure_Data[1] = 0x10;
    *ErrorCode = 0;
    return retValue;

}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_RoutineServices_DriveVacuumPump_RequestRoutineResults_func/* return value & FctID */
(
		VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,
		CONSTP2VAR(Dcm_RequestDataOut_DcmDspRoutine_DriveVacuumPump_DcmDspRequestRoutineResultsOutSignal_0Type, AUTOMATIC, RTE_APPL_DATA) DataOut_DcmDspRequestRoutineResultsOutSignal_0,
		CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_RoutineServices_DriveVacuumPump_RequestRoutineResults_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_RoutineServices_DriveVacuumPump_RequestRoutineResults_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
	mode_routine = REQUEST_ROUTINE;
	return retValue;
}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_IOControl_VacuumPumpPressure_ReadData_func/* return value & FctID */
(
        CONSTP2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Data
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_IOControl_VacuumPumpPressure_ReadData_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_IOControl_VacuumPumpPressure_ReadData_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
	*Data = VacuumPumpPressure_Data[0];
	*(Data+1) = VacuumPumpPressure_Data[1];
	return retValue;
}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"


FUNC (void, Diag_SWC_CODE) RE_Diag_SWC_func/* return value & FctID */
(
		void
)
{

    Std_ReturnType retRead1;
    Std_ReturnType retRead2;
    Std_ReturnType retWrite3;
    Std_ReturnType retWrite4;

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :RE_Diag_SWC_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */
	retRead1 = Rte_Read_RPort_DataServices_DcmDspData_SystemFaultRank_Write_Data(&DID_2311);
	retRead2 = Rte_Read_RPort_DataServices_DcmDspData_VehicleSpeed_Write_Data(&DID_2310);

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */
	retWrite3 = Rte_Write_P_DataServices_DcmDspData_SystemFaultRank_Read_Data(DID_2311);
	retWrite4 = Rte_Write_P_DataServices_DcmDspData_VehicleSpeed_Read_Data(DID_2310);

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :RE_Diag_SWC_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
#define Diag_SWC_START_SEC_CODE                   
#include "ASW_Diag_MemMap.h"
FUNC (Std_ReturnType, AUTOMATIC) Diag_IOControl_VacuumPumpPressure_returnControlToECU_func/* return value & FctID */
(
		CONSTP2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :Diag_IOControl_VacuumPumpPressure_returnControlToECU_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :Diag_IOControl_VacuumPumpPressure_returnControlToECU_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

    VacuumPumpPressure_Data[0] = 0xAA;
    VacuumPumpPressure_Data[1] = 0xAA;
    *ErrorCode = 0;
    return retValue;

}

#define Diag_SWC_STOP_SEC_CODE                       
#include "ASW_Diag_MemMap.h"
