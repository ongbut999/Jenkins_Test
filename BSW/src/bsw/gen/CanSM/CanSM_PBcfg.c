
   

     

/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: CanSM / AR42.6.0.0           Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1             Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *

 </VersionHead>*/



  /*********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
 #include "CanSM_PBcfg.h"




#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"

/*LUT for network index*/
CONST(uint8, CANSM_CONST) CanSM_NetworkId_LUT[1][CANSM_NUM_CAN_NETWORKS]=
{
    {0,1}
};

#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"


/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"
/* CanSM Network Index for corresponding CAN Controller ID */
CONST(uint8, CANSM_CONST) CanSM_NetworktoCtrl_Config_acu8[] = 
{
    0,
    1
};


/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"

/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_8
#include "CanSM_MemMap.h"

/* CAN Contollerid for each network */
static CONST(uint8, CANSM_VAR) CanSM_Ctrl_CanSMManagerNetwork_Can_Network_Config_au8[] = 
{  
   CanIfConf_CanIfCtrlCfg_Can_Network_CANNODE_0

};

static CONST(uint8, CANSM_VAR) CanSM_Ctrl_CanSMManagerNetwork_Can_Network_XCP_Config_au8[] = 
{  
   CanIfConf_CanIfCtrlCfg_Can_Network_CANNODE_1

};




/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_8
#include "CanSM_MemMap.h"

 

/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_START_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"



CONST(CanSM_NetworkConf_tst, CANSM_CONST) CanSM_Network_Config_acst[] = 
{
/* ControllerStartIndx      BorTimeL1    BorTimeL2       BorTimeTxEnsured   BusOffErrID    Trcv_Handle   SizeOfController   BorCounter_L1_L2            ComMChannelId                   canSMEnableBusOffDelay    PN enabled/disabled for Transceiver*/
{
CanSM_Ctrl_CanSMManagerNetwork_Can_Network_Config_au8,100u,         1000u, 5000u, DemConf_DemEventParameter_DemEventParameter_CanBusoff,255, 
1, 5,                       0,           FALSE,    FALSE },
{
CanSM_Ctrl_CanSMManagerNetwork_Can_Network_XCP_Config_au8,100u,         1000u, 5000u, DemConf_DemEventParameter_DemEventParameter_CanController1_Busoff,255, 
1, 5,                       1,           FALSE,    FALSE }

};


/* CanSM Configuration */
CONST(CanSM_ConfigType, CANSM_CONST) CanSM_ConfigSet[] = 
{

    {
        CanSM_Network_Config_acst,   /* Network Configuration array */
        CanSM_NetworktoCtrl_Config_acu8, /* CanSm Network Index mapped to corresponding CAN controller */
        
        70, /*CanSMModeRequestRepetitionTime*/
        5, /*CanSMModeRequestRepetitionMax*/
        CANSM_NUM_CAN_NETWORKS,      /*Number of CANSM Networks configured*/
        0 /*Active configSet index*/

    }
};
/* PRECOMPILE defines for placing the PB variables to the default data section*/
#define CANSM_STOP_SEC_CONST_UNSPECIFIED
#include "CanSM_MemMap.h"
