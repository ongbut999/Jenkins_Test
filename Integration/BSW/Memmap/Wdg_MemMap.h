/*
 * WDG_MemMap.h
 *
 *  Created on: Sep 7, 2017
 *      Author: puy1hc
 */

/* Used for global or static variables that are
    cleared to zero after every reset */
#if defined WDG_START_SEC_VAR_CLEARED_8
    /*  8 bit */
    #define SHARED_TRUSTED_START_SEC_RAM_CLEARED_8
	#undef WDG_START_SEC_VAR_CLEARED_8
#elif defined WDG_STOP_SEC_VAR_CLEARED_8
    #define SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_8
	#undef WDG_STOP_SEC_VAR_CLEARED_8
#elif defined WDG_START_SEC_VAR_CLEARED_16
    /* 16 bit */
    #define SHARED_TRUSTED_START_SEC_RAM_CLEARED_16
	#undef WDG_START_SEC_VAR_CLEARED_16
#elif defined WDG_STOP_SEC_VAR_CLEARED_16
    #define SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_16
	#undef WDG_STOP_SEC_VAR_CLEARED_16
#elif defined WDG_START_SEC_VAR_CLEARED_32
    /* 32 bit */
    #define SHARED_TRUSTED_START_SEC_RAM_CLEARED_32
	#undef WDG_START_SEC_VAR_CLEARED_32
#elif defined WDG_STOP_SEC_VAR_CLEARED_32
    #define SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_32
	#undef WDG_STOP_SEC_VAR_CLEARED_32
#elif defined WDG_START_SEC_VAR_CLEARED_BOOLEAN
    /* BOOLEAN size */
    #define SHARED_TRUSTED_START_SEC_RAM_CLEARED_BOOL
	#undef WDG_START_SEC_VAR_CLEARED_BOOLEAN
#elif defined WDG_STOP_SEC_VAR_CLEARED_BOOLEAN
    #define SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_BOOL
	#undef WDG_STOP_SEC_VAR_CLEARED_BOOLEAN
#elif defined WDG_START_SEC_VAR_CLEARED_UNSPECIFIED
    /* UNSPECIFIED */
    #define SHARED_TRUSTED_START_SEC_RAM_CLEARED_UNSPECIFIED
	#undef WDG_START_SEC_VAR_CLEARED_UNSPECIFIED
#elif defined WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    #define SHARED_TRUSTED_STOP_SEC_RAM_CLEARED_UNSPECIFIED
	#undef WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
/*For all the sections defined in RTE have included via WDG_MemMap.h file and redeclarations have been removed with the following mapping*/
#elif defined WDG_START_SEC_CODE
    #define  SHARED_START_SEC_CODE
	#undef WDG_START_SEC_CODE
#elif defined WDG_STOP_SEC_CODE
    #define  SHARED_STOP_SEC_CODE
	#undef WDG_STOP_SEC_CODE
#endif

#include "MemMap.h"

