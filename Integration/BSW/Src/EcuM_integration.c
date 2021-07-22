/*
 * EcnM_integration.c
 *
 *  Created on: May 15, 2019
 *      Author: AGT1HC
 */


#include "EcuM_integration.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "VectorTable_Core0.h"
#include "VectorTable_Core1.h"
#include "VectorTable_Core2.h"
extern FUNC(void, ECUM_CODE) EcuM_MainFunction(void);

/**********************************************************************************
   Function name    :  Loop_EcuM_MainFunc
   Description      :   call Loop_EcuM_MainFunc in Shutdown sequence due to RTE was disable. And Core0 have
   	   	   	   	   	   	   to wait for Slave cores shutdown.
   Parameter  (in)  :
   Parameter  (inout)  :  None
   Parameter  (out)  :  None
   Return value    :  None
   Remarks      :
 ***********************************************************************************/
FUNC( void, ECUM_CALLOUT_CODE ) Loop_EcuM_MainFunc(void)
{
	uint8 timeout = 0;
	while (timeout < ECUM_MAINFUNCTION_TIMEOUT)
	{
		EcuM_MainFunction();
		timeout++;

	}
}

/**********************************************************************************
  Function name    :  VectorTable_Init
  Description    :  Wrapper for Os_InitializeVectorTable
  Parameter  (in)  :  None
  Parameter  (inout)  :  None
  Parameter  (out)  :  None
  Return value    :  None
  Remarks      :
***********************************************************************************/
FUNC(void, INIT_CODE) VectorTable_Init(sint8 coreID)
{
	Mcal_ResetCpuENDINIT(coreID);
	Os_InitializeVectorTable();
	Mcal_SetCpuENDINIT(coreID);
	return;
}

FUNC(void, INIT_CODE) VectorTable_Core0_Init(void)
{
	VectorTable_Init(0);
}

FUNC(void, INIT_CODE) VectorTable_Core1_Init(void)
{
	VectorTable_Init(1);
}

FUNC(void, INIT_CODE) VectorTable_Core2_Init(void)
{
	VectorTable_Init(2);
}
