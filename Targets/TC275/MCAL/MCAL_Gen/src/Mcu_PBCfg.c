/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Mcu_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\90 $                                                 **
**                                                                            **
**  DATE, TIME: 2021-06-23, 14:06:04                                          **
**                                                                            **
**  GENERATOR : Build b141014-0350                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : MCU configuration generated out of ECU configuration       **
**                 file  (Mcu.bmd)                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/

/* Include module header file */
#include "Mcu.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*
   Configuration Options:
   For the clock setting configuration
   PLL status
*/

/* Normal Mode */
#define MCU_NORMAL_MODE        (0x01U)

/******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Memory Mapping the configuration constant */
#define MCU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*
   Configuration : Mcu_ConfigType
   For Mcu_ConfigType: MCU specific configuration ID
   This id corresponds to the container name of the McuConfiguration.
   Use this as the parameter for API: Mcu_Init
    - MCU035 : Configuration of MCU
*/
/*
                     Container: McuClockSettingConfig
                     Multilplicity : 1 - *
*/

static const Mcu_ClockCfgType Mcu_kClockConfiguration0[] =
{
    /*McuClockSettingConfig_0*/
  {
    {
      /*K2 divider steps*/
      5U, /* 100.0 MHz */ 
      4U, /* 120.0 MHz  */
      3U, /* 150.0 MHz  */
      2U, /* 200.0 MHz  */
      2U, /* 200.0 MHz  */
      2U,  /* 200.0 MHz */ 
      0U,
      0U,
    },
    {
      500U,  /* ramp up delay for K2 div step 1*/
      600U, /* ramp up delay for K2 div step 2*/
      750U, /* ramp up delay for K2 div step 3*/
      1000U, /* ramp up delay for K2 div step 4*/
      1000U, /* ramp up delay for K2 div step 5*/
      1000U, /* ramp up delay for K2 div step 6*/
      0U, /* ramp up delay for K2 div step 7*/
      0U, /* ramp up delay for K2 div step 8*/
    },

    {
      1U,                              /* K1DIV */
      5U,                              /* K3DIV */
      29U,                             /* NDIV */
      0U,                              /* PDIV */
      4U,                              /* K2DivSteps */
      MCU_NORMAL_MODE,                 /* NORMAL/PRESCALER MODE */
      0U                               /* reserved */
    },

    {
      19U,                             /* PLL ERAY N divider */
      4U,                              /* PLL ERAY K2 divider */
      4U,                              /* PLL ERAY K3 divider */
      0U,                              /* PLL ERAY P Divider */
      0U                               /* reserved */
    },

    /*
      SRI Clock     = 200.0MHz
      SPB Clock     = 100.0MHz
    */
    (uint32)0x02120122U, /* CCUCON0 Register Configuration*/
    (uint32)0x02212212U, /* CCUCON1 Register Configuration*/
    (uint32)0x00000002U, /* CCUCON2 Register Configuration*/
    (uint32)0x00000041U,/* CCUCON5 Register Configuration*/
    (uint32)0x00000000U, /* CCUCON6 Register Configuration*/
    (uint32)0x00000000U, /* CCUCON7 Register Configuration*/
    (uint32)0x00000000U,  /* CCUCON8 Register Configuration*/
    10U, /* Ramp to PLL delay configured in us */

  }/*McuClockSettingConfig_0*/

};

/* Ptr to RAM Section in config structure */
/*
    Container: McuRamSectorSettingConf
    Multiplicity: 1 - *

*/
/*
    Configuration: RAM Section Id
    This id corresponds to the container name of the McuRAMSettingConfiguration.
    Use this as the parameter for API: Mcu_InitRamSection
    MCU030 : Definition of RAM section
*/

static const Mcu_RamCfgType Mcu_kRamConfiguration0[] =
{
  {
    /* RAM Section Configuration: McuRamSectorSettingConf_0 */
    /* IFX_MISRA_RULE_11_01_STATUS=Cast from unsigned int to pointer, this is
       required to assign the ram base address to local variable to access
       ram memory.*/    
    (Mcu_RamBaseAdrType)0x70000000U, /* RAM section base address */

    (Mcu_RamSizeType)0x2000,        /* RAM section size */
    
    (Mcu_RamPrstDatType)0x0        /* Default Value */
    
  }
};

/* Standby Mode config structure for Mode Configuration:
 * McuModuleConfiguration_0/McuModeSettingConf/McuModeSettingConf_2 
 */
static const Mcu_StandbyModeType Mcu_kStandbyModeConf0 = 
{
  /* PMSWCR0 Register value */
  0x220000U,
  /* RAR Crc Check */
  (uint8)FALSE
};

/* Main MCU Configuration Structure */
const Mcu_ConfigType Mcu_ConfigRoot[1] =
{
  {
    /*McuModuleConfiguration_0*/
    
    /*Mcu Clock Configuration*/
    Mcu_kClockConfiguration0,
    /*Mcu Ram Configuration*/
    Mcu_kRamConfiguration0,
    /*Ptr to Gtm_ConfigRoot*/
    &Gtm_ConfigRoot[0],
    /* Reset request configuration  */
    /* 
     * Upper 16-bits contain ARSTDIS register configuration value, 
     * lower 16-bits contain RSTCON register configuration value
     */
    0x200U,
    /* Total number of Clock settings */
    ((Mcu_ClockType)1U),
    /* Total number of RAM Sectors */
    ((Mcu_RamSectionType)1U),
    /* The maximum mode that is supported by this module instance */
    (MCU_MODE_MAX0),
    /* Ptr to Standby Mode in config structure */
    &Mcu_kStandbyModeConf0,
  }
};

#define MCU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
