/*
 * integration.c
 *
 *  Created on: Jun 7, 2018
 *      Author: CIX2SGH
 */

#include "Os.h"
#include "Mcu.h"
#include "Gpt.h"
#include "Rte_Main.h"
#include "Rte_Const.h"
#include <Os.h>

/**************************************************************/
/* OS Tick timer start 		                                  */
/**************************************************************/
void IC_RteTimerStart ( void )
{

	(void)Rte_Start();
}


/**************************************************************/
/* 				ISR Cat 2 for RTE tick 		  				  */
/**************************************************************/
unsigned long OS_Counter_100ns = 0;
void GptChannelConfiguration_Ntf(void)
{


}


FUNC(void, OS_CODE) Os_Entry_GTMTOM0SR0_ISR(void)
{

}


void Wdg_Cbk_GptNotification0(void)
{
    ;
}





