/*
 * main.h
 *
 *  Created on: Aug 15, 2017
 */

#ifndef TARGETS_TC275_MCAL_API_MAIN_H_
#define TARGETS_TC275_MCAL_API_MAIN_H_

/* Global variables */
#define BSW_START_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"
volatile uint32 Millisecond_count;
unsigned long OS_Counter_1ms;
#define BSW_STOP_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"

#define STARTUP_START_SEC_CODE
#include "MemMap.h"
extern void TargetEn_PeriodicInterrupt(void);
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* TARGETS_TC275_MCAL_API_MAIN_H_ */
