/*AGT1HC: This file is created to map the data configuration between BSW and MCAL*/
/*
 * EcuM_PBDefine.h
 *
 *  Created on: Mar - 15 -2018
 *      Author: AGT1HC
 */

#ifndef BASICSOFTWARE_SRC_BSW_GEN_ECUM_INTEGRATION_ECUM_PBDEFINE_H_
#define BASICSOFTWARE_SRC_BSW_GEN_ECUM_INTEGRATION_ECUM_PBDEFINE_H_


#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Can.h"

#include "Gpt.h"
#include "Gpt_Cfg.h"




#define Mcu_Config                  Mcu_ConfigRoot
#define Port_Config                 Port_ConfigRoot
#define Can_ConfigPtr         Can_17_MCanP_ConfigRoot
#define Dio_Config                  Dio_ConfigRoot
#define Fls_Config                  Fls_17_Pmu_ConfigRoot
//#define Pwm_17_Gtm_Config           Pwm_ConfigRoot
//#define Icu_17_GtmCcu6_Config       Icu_ConfigRoot
//#define IoHwAb_Adc_Config           Adc_ConfigRoot
//#define Spi_Config                  Spi_ConfigRoot
#define Gpt_Config                  Gpt_ConfigRoot

extern void McuFunc_InitializeClock(void);

#endif /* BASICSOFTWARE_SRC_BSW_GEN_ECUM_INTEGRATION_ECUM_PBDEFINE_H_ */
