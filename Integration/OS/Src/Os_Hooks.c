/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2017. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Component 	: ProtectionHook.c
 * Created on	: Sep 23, 2019
 * Version   	: 1.0
 * Description  : This module provides ProtectionHook for Os
 * Author		 AGT1HC
 **********************************************************************************************************************
    This file contains sample code only. It is not part of the production code deliverables.

*/
#include "Os.h"
#include "Std_Types.h"
#include "EcuM.h"
#include "Rte_Const.h"
#include "Rte_Main.h"
#include "Ifx_reg.h"
#include "Os_Hooks.h"
#define OS_START_SEC_ERRORHOOK_CODE
#include "Os_MemMap.h"
/**********************************************************************************
  Function name		:	ErrorHook
  Description		:	Called during Error detected in ENTENDED Build.
  Parameter	(in)	:	None
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks			:   None.
***********************************************************************************/
FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error)
{
	 ISRType ISRInError = 0;
	 TaskType TaskInError = 0;
	 StatusType Status_Type;
	 OsTrace_ErrorHookLog_t* err;
	 static uint32 	   err_cnt;
	 /*
	  * This code sample shows how to determine which Task or
	  * ISR was running when the error occurred.
	  */
	 ISRInError = GetISRID();
	 if (ISRInError != INVALID_ISR)
	 {
	   /* The error occurred when ISR 'ISRInError' was running */
	 } else
	 {
		  Status_Type = GetTaskID(&TaskInError);
	   if (TaskInError != INVALID_TASK)
		{
	     /* The error occurred when Task 'TaskInError' was running */
	   } else
		{
	     /* The error occurred during StartOS, Os_Cbk_Idle or ShutdownOS */
	   }
	 }
	 err =  &err_log[err_cnt % (uint8)ERR_LOG_MAX];
	 err->errCount = err_cnt;
	 err->errType = Error;
	 err->isr = ISRInError;
	 err->task = TaskInError;
	 err_cnt++;

	/*
	 * This code sample shows how to determine which error
	 * was detected.
	 */
	switch (Error){
	case E_OS_ID:
	/* Handle illegal identifier error */
	break;
	case E_OS_VALUE:
	/* Handle illegal value error */
	break;
	case E_OS_STATE:
	/* Handle illegal state error */
	break;
	default:
	/* Handle all other types of error */
	break;
	}
}

#define OS_STOP_SEC_ERRORHOOK_CODE
#include "Os_MemMap.h"

#define OS_STOP_SEC_OS_CBK_CHECKMEMORYACCESS_CODE
#include "Os_MemMap.h"
FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void)
{
	/* GTM register OCS sets the fiels SUS ad 2:
	 * 	Soft suspend (GTM Halt Mode). In Soft suspend registers could be read or written
	 *
	 * 	suspend the GTM counters during the debug phase
	 *
	 */
	TargetEn_PeriodicInterrupt();
}
#define OS_STOP_SEC_STARTUPHOOK_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_SHUTDOWNHOOK_CODE
#include "Os_MemMap.h"
/**********************************************************************************
  Function name		:	ShutdownHook
  Description		:	Called during OS Shutdown by ShutdownOS.
  Parameter	(in)	:	Error - the error code passed which makes OS call ShutdownHook
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks			:   None.
***********************************************************************************/
FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Error)
{
    StatusType Status_Type;
    Status_Type = Error;
    EcuM_Shutdown();
}
#define OS_STOP_SEC_SHUTDOWNHOOK_CODE
#include "Os_MemMap.h"

#define OS_START_SEC_OS_CBK_CHECKMEMORYACCESS_CODE
#include "Os_MemMap.h"
/**********************************************************************************
  Function name		:	Os_Cbk_CheckMemoryAccess
  Description		:	Check if a memory region is read/write/execute/stack
                        accessible by a specified OS-Application.
  Parameter	(in)	:	Application - The OS-Application to which the task or ISR belongs.
                        TaskID      - The task for which the memory access is being checked.
                        ISRID       - The ISR for which the memory access is being checked.
                        Address     - The start address of the memory area.
                        Size        - The size in bytes of the memory area.
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks			:   None.
***********************************************************************************/

FUNC(AccessType, OS_OS_CBK_CHECKMEMORYACCESS_CODE) Os_Cbk_CheckMemoryAccess(ApplicationType Application, TaskType TaskID, ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size)
{
	return OS_ACCESS_EXECUTE;
}

#define OS_STOP_SEC_OS_CBK_CHECKMEMORYACCESS_CODE
#include "Os_MemMap.h"

