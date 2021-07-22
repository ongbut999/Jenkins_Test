/*
 * Os_CPUUtilization.h
 *
 *  Created on: Sep 23, 2019
 *      Author: AGT1HC
 */

#include "Std_Types.h"
#include "Os.h"
#include "Gpt.h"
#include "Ifx_reg.h"

#ifndef INTEGRATION_OS_INCLUDE_OS_CPUUTILIZATION_H_
#define INTEGRATION_OS_INCLUDE_OS_CPUUTILIZATION_H_


double CPU_Utilization(uint32 ms);
Os_StopwatchTickType IdleTick(void);
FUNC(Os_StopwatchTickType, {memclass}) Os_Cbk_GetStopwatch(void);

#endif /* INTEGRATION_OS_INCLUDE_OS_CPUUTILIZATION_H_ */
