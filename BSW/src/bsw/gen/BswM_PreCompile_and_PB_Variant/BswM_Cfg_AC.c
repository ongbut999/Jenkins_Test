
/***********************************************************************************************************************
 * Include files
 **********************************************************************************************************************/
#include "BswM.h"

#if (BSWM_RTE_IN_USE == TRUE)
#include "Rte_BswM.h"
#include "SchM_BswM.h"
#endif
#include "BswM_Prv.h"

/***********************************************************************************************************************
 * Type Definition
 **********************************************************************************************************************/
typedef void (*BswM_Cfg_vFunPtrv_t)(void);
typedef Std_ReturnType (*BswM_Cfg_u8FunPtrv_t)(void);

/* User Include Files */
#include "Mcu.h"

#include "Stubs.h"

#include "Rte_Main.h"

#include "CanSM_ComM.h"

#include "CanIf.h"

#include "Can.h"

/***********************************************************************************************************************
 * BswMComMAllowCom Action/s Object.
 * # ComMAllowed
 * # NetworkReference
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_ComMAllowComType_tst, BSWM_CONST) BswM_Cfg_AC_BswMComMAllowCom_cast[BSWM_NO_OF_AC_COMM_ALLOW_COM] =
{
	{
		/* BswM_AI_ComMCommAllowed_Can0 */
		TRUE,
		ComMConf_ComMChannel_ComMChannel_Can_Network_Channel
	},
	{
		/* BswM_AI_ComMCommAllowed_Can1 */
		TRUE,
		ComMConf_ComMChannel_ComMChannel_Can_Network_XCP_Channel
	},
	{
		/* BswM_AI_ComMCommNotAllowed_Can0 */
		FALSE,
		ComMConf_ComMChannel_ComMChannel_Can_Network_Channel
	},
	{
		/* BswM_AI_ComMCommNotAllowed_Can1 */
		FALSE,
		ComMConf_ComMChannel_ComMChannel_Can_Network_XCP_Channel
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

/***********************************************************************************************************************
 * BswMComMModeSwitch Action/s Object.
 * # ComMRequestMode
 * # ComUserReference
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_ComMModeSwitchType_tst, BSWM_CONST) BswM_Cfg_AC_BswMComMModeSwitch_cast[BSWM_NO_OF_AC_COMM_MODE_SWITCH] =
{
	{
		/* BswM_AI_ComMReqFullComm_User0 */
		BSWM_FULL_COM,
		ComMConf_ComMUser_ComMUser_Can_Network_Channel
	},
	{
		/* BswM_AI_ComMReqFullComm_User1 */
		BSWM_FULL_COM,
		ComMConf_ComMUser_ComMUser_Can_Network_XCP_Channel
	},
	{
		/* BswM_AI_ComMReqNoComm_User0 */
		BSWM_NO_COM,
		ComMConf_ComMUser_ComMUser_Can_Network_Channel
	},
	{
		/* BswM_AI_ComMReqNoComm_User1 */
		BSWM_NO_COM,
		ComMConf_ComMUser_ComMUser_Can_Network_XCP_Channel
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

/***********************************************************************************************************************
 * BswMNMControl Action/s Object.
 * # NMControl Action Type
 * # NetworkHandleRef
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_NmControlType_tst, BSWM_CONST) BswM_Cfg_AC_BswMNMControl_cast[BSWM_NO_OF_AC_NM_CNTRL] =
{
	{
		/* BswMAction_NM_Start */
		BSWM_NM_ENABLE,
		ComMConf_ComMChannel_ComMChannel_Can_Network_Channel
	},
	{
		/* BswMAction_NM_Stop */
		BSWM_NM_DISABLE,
		ComMConf_ComMChannel_ComMChannel_Can_Network_Channel
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

/***********************************************************************************************************************
 * IDs for SchMSwitch Functions.
 * # ID
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_SchMSwitchType_tst, BSWM_CONST) BswM_Cfg_AC_BswMSchMSwitch_cast[BSWM_NO_OF_AC_SCHM_SWITCH] =
{
	{
		/* BswMAction_SwitchAppMode_Dummy */
		0
	},
	{
		/* BswM_AI_BswMSwitchAppRun */
		1
	},
	{
		/* BswM_AI_BswMSwitchPostRun */
		2
	},
	{
		/* BswM_AI_BswMSwitchPrepShutdown */
		3
	},
	{
		/* BswM_AI_BswMSwitchRun */
		4
	},
	{
		/* BswM_AI_BswMSwitchShutdown */
		5
	},
	{
		/* BswM_AI_BswMSwitchStartupTwo */
		6
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"                
/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_0_BswMAction_SwitchAppMode_Dummy
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_0_BswMAction_SwitchAppMode_Dummy (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_MDG_App_Mode_MDG_App_Mode ( RTE_MODE_MDG_App_Mode_SwcRequest_ECUM_STATE_APP_POST_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_1_BswM_AI_BswMSwitchAppRun
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_1_BswM_AI_BswMSwitchAppRun (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_APP_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_2_BswM_AI_BswMSwitchPostRun
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_2_BswM_AI_BswMSwitchPostRun (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_POST_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_3_BswM_AI_BswMSwitchPrepShutdown
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_3_BswM_AI_BswMSwitchPrepShutdown (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_4_BswM_AI_BswMSwitchRun
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_4_BswM_AI_BswMSwitchRun (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_5_BswM_AI_BswMSwitchShutdown
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_5_BswM_AI_BswMSwitchShutdown (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_SHUTDOWN );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_SchMSwitch_6_BswM_AI_BswMSwitchStartupTwo
 * Description     :       SchMSwitch Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
static FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_AC_SchMSwitch_6_BswM_AI_BswMSwitchStartupTwo (void)
{
	VAR(Std_ReturnType, AUTOMATIC) dataRet_u8 = BSWM_NO_RET_VALUE;
	VAR(Std_ReturnType, AUTOMATIC) action_RetVal_pu8 = BSWM_NO_RET_VALUE;

	/*
	 SchM_Switch_p_o( mode )
	 P = Port name
	 O = Mode Group within the ModeSwitchInterface
	 */

	dataRet_u8 = SchM_Switch_BswM_MDGP_AUTOSAR_BswM_ModeDeclarationGroups_MDG_ECUM_STATE ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO );

	/* return whether the action was sucessful or not */
	switch( dataRet_u8 )
	{
		case RTE_E_OK:
		action_RetVal_pu8 = E_OK;
		break;
		case RTE_E_LIMIT:
		action_RetVal_pu8 = E_NOT_OK;
		break;
		default:
		action_RetVal_pu8 = BSWM_NO_RET_VALUE;
		break;
	}

	return action_RetVal_pu8;
}

#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"            

/***********************************************************************************************************************
 * Array of Functions Pointers
 * # FunctionNames
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"             
static CONST(BswM_Cfg_u8FunPtrv_t, BSWM_CONST) BswM_Cfg_AC_BswMSchMSwitch_FunPtr_cafct[BSWM_NO_OF_AC_SCHM_SWITCH] =
{
	&BswM_Cfg_AC_SchMSwitch_0_BswMAction_SwitchAppMode_Dummy,
	&BswM_Cfg_AC_SchMSwitch_1_BswM_AI_BswMSwitchAppRun,
	&BswM_Cfg_AC_SchMSwitch_2_BswM_AI_BswMSwitchPostRun,
	&BswM_Cfg_AC_SchMSwitch_3_BswM_AI_BswMSwitchPrepShutdown,
	&BswM_Cfg_AC_SchMSwitch_4_BswM_AI_BswMSwitchRun,
	&BswM_Cfg_AC_SchMSwitch_5_BswM_AI_BswMSwitchShutdown,
	&BswM_Cfg_AC_SchMSwitch_6_BswM_AI_BswMSwitchStartupTwo
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"         

/*****************************************************************************************
 * Function name   :       BswM_Cfg_ProcessSchMSwitchFunction
 * Description     :       Determine which SchMSwitch Function to be invoked.
 * Parameter       :       SchMSwitchId
 * Return value    :       Std_ReturnType
 * Remarks         :   
 *****************************************************************************************/
#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"
FUNC(Std_ReturnType, BSWM_CODE) BswM_Cfg_ProcessSchMSwitchFunction
(
		VAR(uint16, AUTOMATIC) idSchMSwitch_u16
)
{
	VAR(Std_ReturnType, AUTOMATIC) RetVal = BSWM_NO_RET_VALUE;

	/* Check if the idSchMSwitch_u16 is within the array boundary */
	if (idSchMSwitch_u16 < (sizeof(BswM_Cfg_AC_BswMSchMSwitch_FunPtr_cafct) / sizeof(BswM_Cfg_u8FunPtrv_t)))
	{
		RetVal = BswM_Cfg_AC_BswMSchMSwitch_FunPtr_cafct[idSchMSwitch_u16]();
	}
	else
	{
		/* Do Nothing */
	}
	return RetVal;
}
#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"

/***********************************************************************************************************************
 * UserIDs for UserCallout Functions.
 * # UserID
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"

CONST(BswM_Cfg_AC_UserCalloutType_tst, BSWM_CONST) BswM_Cfg_AC_BswMUserCallout_cast[BSWM_NO_OF_AC_USERCALLOUT] =
{
	{
		/* BswMAction_DemInit */
		0
	},
	{
		/* BswMAction_DemShutdown */
		1
	},
	{
		/* BswMAction_Dem_EndOperation */
		2
	},
	{
		/* BswMAction_EcuM_LoopMainFunc */
		3
	},
	{
		/* BswMAction_EcuM_SelectShutdownTarget_RESET_IO */
		4
	},
	{
		/* BswMAction_EcuM_SelectShutdownTarget_RESET_MCU */
		5
	},
	{
		/* BswMAction_FeeRbEndInit */
		6
	},
	{
		/* BswM_AI_CanIfInit */
		7
	},
	{
		/* BswM_AI_CanInit */
		8
	},
	{
		/* BswM_AI_CanNm_Init */
		9
	},
	{
		/* BswM_AI_CanSmInit */
		10
	},
	{
		/* BswM_AI_CanTp_Init */
		11
	},
	{
		/* BswM_AI_CheckCondition */
		12
	},
	{
		/* BswM_AI_ComInit */
		13
	},
	{
		/* BswM_AI_ComMInit */
		14
	},
	{
		/* BswM_AI_Dcm_Init */
		15
	},
	{
		/* BswM_AI_FeeInit */
		16
	},
	{
		/* BswM_AI_GoDown */
		17
	},
	{
		/* BswM_AI_Nm_Init */
		18
	},
	{
		/* BswM_AI_NvMInit */
		19
	},
	{
		/* BswM_AI_NvMReadAll */
		20
	},
	{
		/* BswM_AI_NvMWriteAll */
		21
	},
	{
		/* BswM_AI_PduRInit */
		22
	},
	{
		/* BswM_AI_RteStop */
		23
	},
	{
		/* BswM_AI_RteTimerStart */
		24
	},
	{
		/* BswM_AI_WdgMInit */
		25
	},
	{
		/* BswM_AI_XcpInit */
		26
	}
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"    

#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"                
/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_0_BswMAction_DemInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_0_BswMAction_DemInit (void)
{
	Dem_Init();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_1_BswMAction_DemShutdown
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_1_BswMAction_DemShutdown (void)
{
	Dem_Shutdown();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_2_BswMAction_Dem_EndOperation
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_2_BswMAction_Dem_EndOperation (void)
{
	Dem_SetOperationCycleState(0,DEM_CYCLE_STATE_END);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_3_BswMAction_EcuM_LoopMainFunc
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_3_BswMAction_EcuM_LoopMainFunc (void)
{
	Loop_EcuM_MainFunc();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_4_BswMAction_EcuM_SelectShutdownTarget_RESET_IO
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_4_BswMAction_EcuM_SelectShutdownTarget_RESET_IO (void)
{
	EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET,ECUM_RESET_IO);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_5_BswMAction_EcuM_SelectShutdownTarget_RESET_MCU
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_5_BswMAction_EcuM_SelectShutdownTarget_RESET_MCU (void)
{
	EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET,ECUM_RESET_MCU);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_6_BswMAction_FeeRbEndInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_6_BswMAction_FeeRbEndInit (void)
{
	Fee_Rb_EndInit();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_7_BswM_AI_CanIfInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_7_BswM_AI_CanIfInit (void)
{
	CanIf_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_8_BswM_AI_CanInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_8_BswM_AI_CanInit (void)
{
	Can_Init(Can_17_MCanP_ConfigRoot);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_9_BswM_AI_CanNm_Init
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_9_BswM_AI_CanNm_Init (void)
{
	CanNm_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_10_BswM_AI_CanSmInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_10_BswM_AI_CanSmInit (void)
{
	CanSM_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_11_BswM_AI_CanTp_Init
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_11_BswM_AI_CanTp_Init (void)
{
	CanTp_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_12_BswM_AI_CheckCondition
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_12_BswM_AI_CheckCondition (void)
{
	CheckCondition();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_13_BswM_AI_ComInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_13_BswM_AI_ComInit (void)
{
	Com_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_14_BswM_AI_ComMInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_14_BswM_AI_ComMInit (void)
{
	ComM_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_15_BswM_AI_Dcm_Init
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_15_BswM_AI_Dcm_Init (void)
{
	Dcm_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_16_BswM_AI_FeeInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_16_BswM_AI_FeeInit (void)
{
	Fee_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_17_BswM_AI_GoDown
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_17_BswM_AI_GoDown (void)
{
	EcuM_GoDown(0);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_18_BswM_AI_Nm_Init
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_18_BswM_AI_Nm_Init (void)
{
	Nm_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_19_BswM_AI_NvMInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_19_BswM_AI_NvMInit (void)
{
	NvM_Init();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_20_BswM_AI_NvMReadAll
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_20_BswM_AI_NvMReadAll (void)
{
	IC_BswM_NvM_ReadAll();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_21_BswM_AI_NvMWriteAll
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_21_BswM_AI_NvMWriteAll (void)
{
	IC_BswM_NvM_WriteAll();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_22_BswM_AI_PduRInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_22_BswM_AI_PduRInit (void)
{
	PduR_Init(&PduR_Config);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_23_BswM_AI_RteStop
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_23_BswM_AI_RteStop (void)
{
	Rte_Stop();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_24_BswM_AI_RteTimerStart
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_24_BswM_AI_RteTimerStart (void)
{
	IC_RteTimerStart();
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_25_BswM_AI_WdgMInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_25_BswM_AI_WdgMInit (void)
{
	WdgM_Init(NULL_PTR);
}

/*****************************************************************************************
 * Function name   :       BswM_Cfg_AC_UserCallout_26_BswM_AI_XcpInit
 * Description     :       UserCallout Function is invoked for Action.
 * Parameter       :       void
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
static FUNC(void, BSWM_CODE) BswM_Cfg_AC_UserCallout_26_BswM_AI_XcpInit (void)
{
	Xcp_Init(NULL_PTR);
}

#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"            

/***********************************************************************************************************************
 * Array of Functions Pointers
 * # FunctionNames
 ***********************************************************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"		     
static CONST(BswM_Cfg_vFunPtrv_t, BSWM_CONST) BswM_Cfg_AC_BswMUserCallout_FunPtr_cafct[BSWM_NO_OF_AC_USERCALLOUT] =
{
	&BswM_Cfg_AC_UserCallout_0_BswMAction_DemInit,
	&BswM_Cfg_AC_UserCallout_1_BswMAction_DemShutdown,
	&BswM_Cfg_AC_UserCallout_2_BswMAction_Dem_EndOperation,
	&BswM_Cfg_AC_UserCallout_3_BswMAction_EcuM_LoopMainFunc,
	&BswM_Cfg_AC_UserCallout_4_BswMAction_EcuM_SelectShutdownTarget_RESET_IO,
	&BswM_Cfg_AC_UserCallout_5_BswMAction_EcuM_SelectShutdownTarget_RESET_MCU,
	&BswM_Cfg_AC_UserCallout_6_BswMAction_FeeRbEndInit,
	&BswM_Cfg_AC_UserCallout_7_BswM_AI_CanIfInit,
	&BswM_Cfg_AC_UserCallout_8_BswM_AI_CanInit,
	&BswM_Cfg_AC_UserCallout_9_BswM_AI_CanNm_Init,
	&BswM_Cfg_AC_UserCallout_10_BswM_AI_CanSmInit,
	&BswM_Cfg_AC_UserCallout_11_BswM_AI_CanTp_Init,
	&BswM_Cfg_AC_UserCallout_12_BswM_AI_CheckCondition,
	&BswM_Cfg_AC_UserCallout_13_BswM_AI_ComInit,
	&BswM_Cfg_AC_UserCallout_14_BswM_AI_ComMInit,
	&BswM_Cfg_AC_UserCallout_15_BswM_AI_Dcm_Init,
	&BswM_Cfg_AC_UserCallout_16_BswM_AI_FeeInit,
	&BswM_Cfg_AC_UserCallout_17_BswM_AI_GoDown,
	&BswM_Cfg_AC_UserCallout_18_BswM_AI_Nm_Init,
	&BswM_Cfg_AC_UserCallout_19_BswM_AI_NvMInit,
	&BswM_Cfg_AC_UserCallout_20_BswM_AI_NvMReadAll,
	&BswM_Cfg_AC_UserCallout_21_BswM_AI_NvMWriteAll,
	&BswM_Cfg_AC_UserCallout_22_BswM_AI_PduRInit,
	&BswM_Cfg_AC_UserCallout_23_BswM_AI_RteStop,
	&BswM_Cfg_AC_UserCallout_24_BswM_AI_RteTimerStart,
	&BswM_Cfg_AC_UserCallout_25_BswM_AI_WdgMInit,
	&BswM_Cfg_AC_UserCallout_26_BswM_AI_XcpInit
};

#define BSWM_STOP_SEC_CONST_UNSPECIFIED 
#include "BswM_Cfg_MemMap.h"	     

/*****************************************************************************************
 * Function name   :       BswM_Cfg_ProcessUserCalloutFunction
 * Description     :       Determine which UserCallout Function to be invoked.
 * Parameter       :       UserId
 * Return value    :       void
 * Remarks         :   
 *****************************************************************************************/
#define BSWM_START_SEC_CODE 
#include "BswM_Cfg_MemMap.h"
FUNC(void, BSWM_CODE) BswM_Cfg_ProcessUserCalloutFunction
(
		VAR(uint16, AUTOMATIC) idUserCallout_u16
)
{
	/* Check if the idUserCallout_u16 is within the array boundary */
	if (idUserCallout_u16 < (sizeof(BswM_Cfg_AC_BswMUserCallout_FunPtr_cafct) / sizeof(BswM_Cfg_vFunPtrv_t)))
	{
		BswM_Cfg_AC_BswMUserCallout_FunPtr_cafct[idUserCallout_u16]();
	}
	else
	{
		/* Do Nothing */
	}
}
#define BSWM_STOP_SEC_CODE 
#include "BswM_Cfg_MemMap.h"

/**********************************************************************************************************************
 * End of file                                                                                                     
 **********************************************************************************************************************/
