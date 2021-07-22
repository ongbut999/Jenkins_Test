/***************************************************************************************************
 * Component : Startup.c
 * Date      : Mar 15 2019
 * Version   : 1.0
 * Description  : This module implements the stub functions when integrate an option feature unusage.
 *
 **************************************************************************************************/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dem.h"
#include "Fee.h"
#include "Fee_Cfg.h"
#include "rba_FeeFs1_Prv.h"
#include "Stubs.h"
#include "WdgIf_Types.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

FUNC(Std_ReturnType, WDG_CODE_FAST) Wdg_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) l_WdgMode)
{
	return E_OK;
}


/*******************************************************************************************
* Name              :   Wdg_SetTriggerCondition
* Description       :   Watchdog triggering routine in case it is called from a BSW task.
* Parameters[in]    :   uint16 timeout - Timeout value (milliseconds) for setting the trigger counter.
* Parameters[out]   :   None
* Limitations       :   Care has to be taken while calling this function as it is not reentrant.
* ReturnType        :   Void
*******************************************************************************************/
FUNC(void, WDG_CODE)Wdg_SetTriggerCondition(uint16 timeout)
{

}


#define MAX_BLANK_CHECK_SIZE (((FEE_SEC_HEADER_SIZE/FEE_NUM_MARKER_IN_HEADER) > FEE_PAGE_LEN) ? (FEE_SEC_HEADER_SIZE/FEE_NUM_MARKER_IN_HEADER) : FEE_PAGE_LEN)


Std_ReturnType Fls_BlankCheck(Fls_AddressType TargetAddress,
                                         Fls_LengthType Length)
{
	Std_ReturnType RetVal;
    uint8 compare_block[MAX_BLANK_CHECK_SIZE];
    uint32 blockIndex;
    for(blockIndex=0; blockIndex < Length; blockIndex++)
    {
    	compare_block[blockIndex] = (uint8)FEE_ERASE_PATTERN;
    }

    RetVal = Fls_Compare((Fls_AddressType)TargetAddress, &compare_block[0] , Length );
	return RetVal;

}
