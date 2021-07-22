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
 * Component: /ASW_NM/ASW_NM
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-AB 4.0.2
 * Author: AGT1HC
 * Date : Fri Jun 14 15:32:29 2019
 ****************************************************************************/

#include "Rte_ASW_NM.h"
#include "ComStack_Types.h"
#include "NmStack_Types.h"
#include "Rte_ComM_Type.h"
#include "Nm.h"
#include "ASW_NM.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :RE_ASW_NM_func) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :RE_ASW_NM_func) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :RE_ASW_NM_func) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */
#define ASW_NM_START_SEC_CODE    
#define FULFILLED 1
           
#include "ASW_NM_MemMap.h"


Nm_Test_t Nm_Test[NM_NUMBER_OF_CHANNELS];

FUNC (void, ASW_NM_CODE) RE_ASW_NM_func/* return value & FctID */
(
		void
)
{
	/* Local Data Declaration */
    char index_chanel;
	/*PROTECTED REGION ID(UserVariables :RE_ASW_NM_func) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */
	for(index_chanel=0;index_chanel<NM_NUMBER_OF_CHANNELS;index_chanel++)
	{

		if(Nm_Test[index_chanel].request_b)
		{
			Rte_Write_PP_BswMArbitration_BswM_MRP_Network_uint8(RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION);
			Nm_Test[index_chanel].request_b=0;
		}
        if(Nm_Test[index_chanel].release_b)
        {
            Rte_Write_PP_BswMArbitration_BswM_MRP_Network_uint8(RTE_MODE_ComMMode_COMM_NO_COMMUNICATION);
            Nm_Test[index_chanel].release_b=0;
        }

		if(Nm_Test[index_chanel].IsNmReceived)
		{
            Nm_GetUserData(index_chanel,Nm_Test[index_chanel].nm_rx_data);
            Nm_Test[index_chanel].IsNmReceived = 0;
		}
	}

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */

	/*PROTECTED REGION ID(User Logic :RE_ASW_NM_func) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */

}

extern FUNC(void, NM_CODE) Nm_RxIndicationCallback(CONST(NetworkHandleType, AUTOMATIC)   NetworkHandle )
{
	if (NetworkHandle < NM_NUMBER_OF_CHANNELS)
	{
		Nm_Test[NetworkHandle].IsNmReceived = TRUE;
	}
}

FUNC(void, NM_CODE) Nm_StateChangeIndication(CONST(NetworkHandleType, AUTOMATIC)  NetworkHandle,
                                               CONST(Nm_StateType, AUTOMATIC)   nmPreviousState,
                                               CONST(Nm_StateType, AUTOMATIC)   nmCurrentState)
{

	if (NetworkHandle<NM_NUMBER_OF_CHANNELS)
	{
		Nm_Test[NetworkHandle].nm_PreviousState=nmPreviousState;
		Nm_Test[NetworkHandle].nm_CurrentState=nmCurrentState;
		if ((Nm_Test[NetworkHandle].nm_PreviousState == NM_STATE_PREPARE_BUS_SLEEP)&&(Nm_Test[NetworkHandle].nm_CurrentState == NM_STATE_BUS_SLEEP))
		{
			shutdown_b = 1;
		}
		if (Nm_Test[NetworkHandle].nm_CurrentState == NM_STATE_REPEAT_MESSAGE)
		{
			Nm_Test[NetworkHandle].nm_tx_data[0]=0xAA;
			Nm_SetUserData(NetworkHandle,Nm_Test[NetworkHandle].nm_tx_data);
		}

		if (Nm_Test[NetworkHandle].nm_CurrentState == NM_STATE_PREPARE_BUS_SLEEP)
		{
			Nm_Test[NetworkHandle].nm_tx_data[0]=0xAA;
			Nm_SetUserData(NetworkHandle,Nm_Test[NetworkHandle].nm_tx_data);
		}
		if (Nm_Test[NetworkHandle].nm_CurrentState == NM_STATE_NORMAL_OPERATION)
		{
			Nm_Test[NetworkHandle].nm_tx_data[0]=0xBB;
			Nm_SetUserData(NetworkHandle,Nm_Test[NetworkHandle].nm_tx_data);
		}

	}
	else
	{
		/*do nothing*/
	}
}

extern FUNC(void, NM_CODE) TestNm_RemoteSleepCancellation(CONST(NetworkHandleType, AUTOMATIC)   NetworkHandle)
{

}

extern FUNC(void, NM_CODE) TestNm_RemoteSleepIndication(CONST(NetworkHandleType, AUTOMATIC)   NetworkHandle)
{

}

#define ASW_NM_STOP_SEC_CODE                       
#include "ASW_NM_MemMap.h"
