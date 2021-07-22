/*
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, ETAS GmbH, 2018. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 ************************************************************************************************
 * Component : Wdg_SWC.h
 * Date      : Aug 09, 2018
 * Version   : 1.0
 * Description  : This module implements header file for NvM SWC.
 *                Note: This file contains sample implementation only. It is not part of the
 *                      production deliverables.
 ***********************************************************************************************
*/

#ifndef APPLICATIONSOFTWARE_WDG_SWC_API_WDG_SWC_H
#define APPLICATIONSOFTWARE_WDG_SWC_API_WDG_SWC_H


/*
 **********************************************************************************************************************
 * Type Define
 **********************************************************************************************************************
 */
typedef enum Wdg_Test_t{
	WDG_NONE,
	ALIVE_OK_LACKOF_ONE_CP_ALIVE_SUPERVISION_ENTITY1,
	ALIVE_OK_LACKOF_TWO_ALIVE_SUPERVISION_ENTITY1,
	ALIVE_NOTOK_LACKOF_THREE_ALIVE_SUPERVISION_ENTITY1,
	ALIVE_NOTOK_ADDMORE_ALIVE_SUPERVISION_ENTITY1,
	CHANGE_MODE
}Wdg_Test_t;



#endif /* APPLICATIONSOFTWARE_WDG_SWC_API_WDG_SWC_H */

/*
 **********************************************************************************************************************
 * End of the file
 **********************************************************************************************************************
 */
