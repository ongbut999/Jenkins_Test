/*----------------------------------------------------------------------------------------------------------------------------------------
 * @file          Gpt_Notification.c       
 *
 * @author          fu jianjun
 *
 * @date_created:   2018-10-09
 *
 * @version    		V1.0     
 *
 * @description:    
 *
 * @Modification:     
 *    					Date		  Author		Description
 *                         		- --           -----         -----
 *
 *----------------------------------------------------------------------------------------------------------------------------------------*/

#ifndef _GPT_NOTIFICATION_H_
#define _GPT_NOTIFICATION_H_

/****************************************************************************
* 	Include Files
****************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
/***************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
*****************************************************************************/

/*****************************************************************************
 *  GLOBAL CONSTANT MACROS
 ****************************************************************************/


extern volatile uint8  Gpt_1ms_cnt;
extern volatile uint8  Task10ms_flag;
extern volatile uint8  Task100ms_flag;
extern volatile uint8  Task1000ms_flag;

extern volatile uint8 Task_10ms_cnt;
extern volatile uint8 Task_100ms_cnt;
extern volatile uint16 Task_1000ms_cnt;
/***************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
****************************************************************************/
extern void Gpt_Notification_Channel0_1ms(void);

#endif
