/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2017. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 ************************************************************************************************
 * Component : Wdg.h
 * Date      : Jan 28 2019
 * Version   : 1.0
 * Description  : This module implements header file for functions supplied for Wdg wrapper.
 *                Note: This file contains sample implementation only. It is not part of the
 *                      production deliverables.
 ***********************************************************************************************
*/

#ifndef _WDG_H_
#define _WDG_H_

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "Std_Types.h"
#include "WdgIf_Types.h"

#define WDG_AR_RELEASE_MAJOR_VERSION      (4U)
#define WDG_AR_RELEASE_MINOR_VERSION      (2U)
#define WDG_AR_RELEASE_REVISION_VERSION   (2U)

/*
 **********************************************************************************************************************
 * Define/Macros
 **********************************************************************************************************************
 */
#define MAINFUNCTION_WDG_TRIGGER 1 //ms
/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */


/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */


#define WDG_START_SEC_CODE
#include "Wdg_MemMap.h"
/* Function prototypes for Watchdog functionality */

FUNC(Std_ReturnType, WDG_CODE_FAST) Wdg_SetMode(VAR(WdgIf_ModeType, AUTOMATIC) l_WdgMode);

FUNC(void, WDG_CODE)Wdg_SetTriggerCondition(uint16 timeout);

#define WDG_STOP_SEC_CODE
#include "Wdg_MemMap.h"

#endif /* _WDG_H_ */

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */

