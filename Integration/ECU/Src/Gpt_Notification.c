/*----------------------------------------------------------------------------------------------------------------------------------------
 * @file       		Gpt_Notification.c  
 *
 * @author      	fu jianjun
 *
 * @date_created:   2018-10-9
 *
 * @version    		  V1.0     
 *
 * @description:    This file is a template for implementing functionality to the IoHwAb.
 *
 * @Modification:     
 *    					Date		  Author		Description
 *                         		- --           -----         -----
 *----------------------------------------------------------------------------------------------------------------------------------------*/

/****************************************************************************
* 	Include Files
****************************************************************************/
#include "Gpt_Notification.h"
/****************************************************************************
* 	Local Macro Definitions
****************************************************************************/
volatile uint8  Gpt_1ms_cnt=0u;
volatile uint8  Task10ms_flag=0u;
volatile uint8  Task100ms_flag=0u;
volatile uint8  Task1000ms_flag=0u;

volatile uint8 Task_10ms_cnt=0u;
volatile uint8 Task_100ms_cnt=0u;
volatile uint16 Task_1000ms_cnt=0u;

/****************************************************************************
 *  LOCAL FUNCTIONS
****************************************************************************/





/****************************************************************************
 *  GLOBAL FUNCTIONS
****************************************************************************/




/****************************************************************************
 * @Function:        Gpt_Notification_Channel0_1ms()
 *
 * @description:    
 *              	              	 
 * @param 		    
 * 
 * @author     		fujianjun
 * 
 * @date       		2018-10-9
 *
 * @return    			
 *
 * @Modification:     
 *    					Date		  Author		Description
 *                         		- --           -----         -----            
****************************************************************************/
void Gpt_Notification_Channel0_1ms(void)
{
	Gpt_1ms_cnt++;

	Task_10ms_cnt++;
	Task_100ms_cnt++;
	Task_1000ms_cnt++;
	
	if(10 == Task_10ms_cnt)
	{
		Task10ms_flag=1u;
		Task_10ms_cnt=0u;
	}
	if(100 == Task_100ms_cnt)
	{
		Task100ms_flag=1u;
		Task_100ms_cnt=0u;
	}
	if(1000 == Task_1000ms_cnt)
	{
		Task1000ms_flag=1u;
		Task_1000ms_cnt=0u;
	}

}
