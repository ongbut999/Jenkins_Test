/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2017. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Component 	: TimingCalculation.c
 * Created on	: Jan 7, 2020
 * Version   	: 1.0
 * Description  : This module provides APIs to calculate the elapsed time based on software counter.
 * Author		: HAD1HC
 **********************************************************************************************************************
    This file contains sample code only. It is not part of the production code deliverables.

*/

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "TimingCalculation.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
static uint32 Os_CurrentTime;

/**********************************************************************************
  Function name		:	IC_SetCurrentTime
  Description		:	Set the current time for timing calculation.
  Parameter	(in)	:	None
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks			:   None.
***********************************************************************************/
#define DEFAULT_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_INTEGRATION_CODE) IC_SetCurrentTime(void)
{
	GetCounterValue((CounterType)&(Os_const_counters[0]),(TickRefType)&Os_CurrentTime);
}


/**********************************************************************************
  Function name		:	IC_GetElapsedTime
  Description		:	Get elapsed time from base time.
  Parameter	(in)	:	None
  Parameter	(inout)	:	None
  Parameter	(out)	:	None
  Return value		:	None
  Remarks			:   None.
***********************************************************************************/
FUNC(uint32, OS_INTEGRATION_CODE) IC_GetElapsedTime(void)
{
	uint32 ElapsedTime;
	uint32 old_CurrentTime = Os_CurrentTime;
	GetElapsedCounterValue((CounterType)&(Os_const_counters[0]),(TickRefType)&Os_CurrentTime,(TickRefType)&ElapsedTime);
	Os_CurrentTime = old_CurrentTime;

	return ElapsedTime;
}

#define DEFAULT_STOP_SEC_CODE
#include "MemMap.h"

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */

