/*
 * TimingCalculation.h
 *
 *  Created on: Jan 7, 2020
 *      Author: HAD1HC
 */

#include "Std_Types.h"
#include "Os.h"

#ifndef INTEGRATION_ECU_INCLUDE_TIMINGCALCULATION_H_
#define INTEGRATION_ECU_INCLUDE_TIMINGCALCULATION_H_

extern FUNC(void, OS_INTEGRATION_CODE) IC_SetCurrentTime(void);
extern FUNC(uint32, OS_INTEGRATION_CODE) IC_GetElapsedTime(void);

#endif /* INTEGRATION_OS_INCLUDE_OS_CPUUTILIZATION_H_ */
