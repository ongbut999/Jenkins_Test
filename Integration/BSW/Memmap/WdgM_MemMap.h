/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */






/* All the pragma definitions needed by RTE & SchM are provided in this file. */
/* Projects shall include this file irrespective of whether RTE is enabled / disabled in WdgM. */
/* MR12 RULE 1.2, DIR 4.10 VIOLATION: MemMap header concept - no protection against multiple inclusion intended */
/*
 *********************************************************************************************************
 * Defines/Macros
 *********************************************************************************************************
*/

#define MEMMAP_ERROR
/* MR12 RULE 20.5 VIOLATION: AUTOSAR MemMap concept requires #undef, AUTOSAR MemMap requirements are incompatible to MISRA */
#ifndef WdgM_START_SEC_CODE
	#if defined WDGM_START_SEC_CODE
		#define WdgM_START_SEC_CODE
		#undef 	WDGM_START_SEC_CODE
	#endif
#endif
#ifndef WdgM_STOP_SEC_CODE
	#if defined WDGM_STOP_SEC_CODE
		#define WdgM_STOP_SEC_CODE
		#undef 	WDGM_STOP_SEC_CODE
	#endif
#endif
#if defined WdgM_START_SEC_CODE
    #define  BSW_START_SEC_CODE
	#include "Bsw_MemMap.h"
    #undef WdgM_START_SEC_CODE
    #undef MEMMAP_ERROR
#elif defined WdgM_STOP_SEC_CODE
    #define  BSW_STOP_SEC_CODE
	#include "Bsw_MemMap.h"
    #undef WdgM_STOP_SEC_CODE
    #undef MEMMAP_ERROR

#elif defined MEMMAP_ERROR
    #error "WdgM_MemMap.h, wrong #pragma command"
#endif
