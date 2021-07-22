/***************************************************************************************************
 * Component : Os_Cbk_Idle.c
 * Date      : Sep 23, 2019
 * Version   : 1.0
 * Description: This module implements the Os_Cbk_Idle
 * Author	: AGT1HC
 *
 **************************************************************************************************/
/**************************************************************/
/* Idle Task  								                  */
/**************************************************************/
/*Test for return of maximum stack usage for each task/ISR */
#include "Std_Types.h"
#include "Os.h"
#include "Gpt.h"
#include "Rte_Const.h"

Os_StackSizeType testa100ms;
Os_StackSizeType testa10ms;
Os_StackSizeType testb10ms;
Os_StackSizeType testb1ms;
Os_StackSizeType testSWC;
Os_StackSizeType testECU;
Os_StackSizeType testIRSCAN;
Os_StackSizeType testIRSGpt;
Os_StackSizeType testa10ms_Core0;
Os_StackSizeType testb10ms_Core1;
Os_StackSizeType testb10ms_Core2;
Os_StackSizeType testIdle;
/*End of test code */
volatile uint32 Os_Task_Idle_Counter = 0;
FUNC(boolean, OS_CALLOUT_CODE) Os_Cbk_Idle(void)
{
	Os_Task_Idle_Counter++;
    /*Test for return of maximum stack usage for each task/ISR */
    testb10ms 	= Os_GetTaskMaxStackUsage(OsTask_BSW_10ms);
    testa100ms 	= Os_GetTaskMaxStackUsage(OsTask_ASW_100ms);
    testa10ms 	= Os_GetTaskMaxStackUsage(OsTask_ASW_10ms);
    testb1ms 	= Os_GetTaskMaxStackUsage(OsTask_BSW_1ms);
    testSWC 	= Os_GetTaskMaxStackUsage(BSW_OsTask_SwcRequest);
    testECU 	= Os_GetTaskMaxStackUsage(ECU_StartupTask);
    testa10ms_Core0= Os_GetTaskMaxStackUsage(Core1_OsTask_BSW_10ms);
	testb10ms_Core1= Os_GetTaskMaxStackUsage(Core1_OsTask_ASW_10ms);
    testb10ms_Core2= Os_GetTaskMaxStackUsage(Core2_OsTask_ASW_10ms);
    testIRSGpt 	= GetISRMaxStackUsage(GTMTOM0SR0_ISR);
    testIdle = Os_GetTaskMaxStackUsage((TaskType)Os_Cbk_Idle);
    /*End of test code*/
	return TRUE;
}


