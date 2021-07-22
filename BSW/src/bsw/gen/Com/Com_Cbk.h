




 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/


#ifndef COM_CBK_H
#define COM_CBK_H

#define COMCallback(CALLBACKROUTINENAME) FUNC(void,COM_CODE)(CALLBACKROUTINENAME)(void)

/************* Com Notification in Tx side ************************/


/* Start: ComNotification for Signals */


/* End: ComNotification for Signals */


/* Start: ComNotification for Signals Groups */


/* End: ComNotification for Signals Groups */

/* Start : IPDU notification for TX IPDUs */


/* End : IPDU notification for TX IPDUs */

/******************************************************************/


/************* Com Notification in Rx side ************************/


/* Start: ComNotification for Signals */


#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_HCU01_Shift(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_HCU01_TqCmd(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_HCU02_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_HCU03_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_HCU04_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbk_HCU05_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/* End: ComNotification for Signals */


/* Start: ComNotification for Signals Groups */



/* End: ComNotification for Signals Groups */


/* Start: ComNotification for Rx IPdus */


/* End: ComNotification for Rx IPdus */


/******************************************************************/

/************* Com Error Notification in Tx side ************************/


/* Start: ComErrorNotification For Ipdu's */



/* End: ComErrorNotification for Ipdu's */


/* Start: ComErrorNotification for Signals */



/* End: ComErrorNotification for Signals */


/* Start: ComErrorNotification for Signals Groups */


/* End: ComErrorNotification for Signals Groups */


/******************************************************************/

/************* Com Timeout Notification in Tx side ************************/


/* Start: ComTimeoutNotification for Signals */



/* End: ComTimeoutNotification for Signals */


/* Start: ComTimeoutNotification for Signals Groups */


/* End: ComTimeoutNotification for Signals Groups */

/******************************************************************/

/************* Com Notification in Rx side ************************/


/* Start: ComTimeoutNotification for Signals */


#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbkTOut_HCU01_Shift(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbkTOut_HCU01_TqCmd(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbkTOut_HCU02_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbkTOut_HCU03_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbkTOut_HCU04_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#define COM_START_SEC_CODE
#include "Com_MemMap.h"
FUNC(void,COM_CODE) Rte_COMCbkTOut_HCU05_Poweroff(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


/* End: ComTimeoutNotification for Signals */


/* Start: ComTimeoutNotification for Signals Groups */


/* End: ComTimeoutNotification for Signals Groups */


/******************************************************************/

/************* Com Invalid Notification for Rx************************/


/* Start: ComInvalidNotification for Signals */



/* End: ComInvalidNotification for Signals */


/* Start: ComInvalidNotification for Signals Groups */

/* End: ComInvalidNotification for Signals Groups */



/******************************************************************/

/************* Com Ipdu Callouts ************************/






/******************************************************************/

/*************Error Notification for Rx Ipdus *****************/

/* Start: ComErrorNotification For Ipdu's */



/******************************************************************/

#endif /* COM_CBK_H */

