/*
 * Os_Hooks.h
 *
 *  Created on: Jul 23, 2019
 *      Author: AGT1HC
 */
#include "Std_Types.h"
#include "Os.h"
#include "Gpt.h"
#include "Ifx_reg.h"
#include "Rte_Const.h"

#define TIMER_RTE_TICK  OSCYCLESPERSECOND /* system tick per second */\
		                  /1000000 /* system tick per us */\
						  * RTE_PERIODIC_COUNTER_TICK_INTERVAL_US /* system tick per RTE counter tick */\
		                  /2 /* PIT tick per RTE counter tick, because fPIT = fsys / 2*/\

#ifndef INTEGRATION_OS_INCLUDE_OS_HOOKS_H_
#define INTEGRATION_OS_INCLUDE_OS_HOOKS_H_

#define ERR_LOG_MAX 16

typedef struct Os_ErrorLog{
	uint32 errCount;
	StatusType errType;
	ISRType	isr;
	TaskType task;
}OsTrace_ErrorHookLog_t;
OsTrace_ErrorHookLog_t 		err_log[ERR_LOG_MAX];



#endif /* INTEGRATION_OS_INCLUDE_OS_HOOKS_H_ */
