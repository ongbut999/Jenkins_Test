



 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/


#include "Com_Prv.h"
#include "Com_Prv_Inl.h"
#include "Com_Cbk.h"
#include "PduR_Com.h"
#include "Com_PBcfg_InternalId.h"



/**
 * Multiple MainFunction for the reception side
 */
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

FUNC(void, COM_CODE) Com_MainFunctionRx(void)
{
    Com_InternalMainFunctionRx( (Com_MainFuncType)ComMainFunction_Internal_MainFunctionRx );
}


#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/**
 * Multiple MainFunction for the transmission side
 */
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

FUNC(void, COM_CODE) Com_MainFunctionTx(void)
{
    Com_InternalMainFunctionTx( (Com_MainFuncType)ComMainFunction_Internal_MainFunctionTx );
}


#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/* START : Tx IPDU notification functions */
#ifdef COM_TxIPduNotification
#endif /* #ifdef COM_TxIPduNotification */
/* END : Tx IPDU notification functions */
/* START : Tx IPDU error notification functions */
/* END : Tx IPDU error notification functions */
/* START : Tx IPDU timeout  notification functions */
#ifdef COM_TxIPduTimeOutNotify
#endif /* #ifdef COM_TxIPduTimeOutNotify */
/* END : Tx IPDU timeout  notification functions */


/* START : Rx IPDU timeout  notification functions */
#ifdef COM_RxIPduTimeoutNotify
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : HCU_01_Can_Network_CANNODE_0 */
FUNC(void,COM_CODE) Com_RxTONotify_HCU_01_Can_Network_CANNODE_0(void)
{
    Rte_COMCbkTOut_HCU01_Shift();

    Rte_COMCbkTOut_HCU01_TqCmd();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : HCU_02_Can_Network_CANNODE_0 */
FUNC(void,COM_CODE) Com_RxTONotify_HCU_02_Can_Network_CANNODE_0(void)
{
    Rte_COMCbkTOut_HCU02_Poweroff();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : HCU_03_Can_Network_CANNODE_0 */
FUNC(void,COM_CODE) Com_RxTONotify_HCU_03_Can_Network_CANNODE_0(void)
{
    Rte_COMCbkTOut_HCU03_Poweroff();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : HCU_04_Can_Network_CANNODE_0 */
FUNC(void,COM_CODE) Com_RxTONotify_HCU_04_Can_Network_CANNODE_0(void)
{
    Rte_COMCbkTOut_HCU04_Poweroff();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* Rx Timeout Notification callback function for IPDU : HCU_05_Can_Network_CANNODE_0 */
FUNC(void,COM_CODE) Com_RxTONotify_HCU_05_Can_Network_CANNODE_0(void)
{
    Rte_COMCbkTOut_HCU05_Poweroff();

}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /* #ifdef COM_RxIPduTimeoutNotify */

/* END : Rx IPDU timeout  notification functions */

/* START: TMS NONE Details  */

#define COM_START_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_TransModeInfo, COM_CONST) Com_NONE_TransModeInfo =
{
    0, /* TimePeriodFact */
    0, /* TimeOffsetFact */

    0, /* RepetitionPeriodFact */
    0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
    COM_TXMODE_NONE, /* Mode */
    COM_FALSE   /* MixedPhaseShift status */
#else

    COM_TXMODE_NONE /* Mode */

#endif /* #ifdef COM_MIXEDPHASESHIFT */

};
#define COM_STOP_SEC_CONST_UNSPECIFIED
#include "Com_MemMap.h"

/* END: TMS NONE Details  */








#define COM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_IpduGroupVector, COM_VAR) Com_IpduGrpVector;

VAR(Com_IpduGroupVector, COM_VAR) Com_IpduGrpVector_DM;
#define COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Com_MemMap.h"


