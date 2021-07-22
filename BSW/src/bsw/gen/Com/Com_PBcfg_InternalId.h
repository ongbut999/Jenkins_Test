


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/
#ifndef COM_PBCFG_INTERNALID_H
#define COM_PBCFG_INTERNALID_H

/*
 * VERY IMP : This file contains internal symbolic names , which are defined as Internal IDs
 *            This file should be generated from Com_Generate_PB action.
 *            This file is generated for both pre-compile & post-build variant.
 *            For pre-compile , Internal ID and External ID would be the same.
 *            No other code should be generated in this file
 *            This file should be only included in COM_PBcfg.c file.
 * COM internal structures and tables (defined in COM_PBcfg.c file) must use internal symolic names, defined in this file
 *
 */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx IPdu internal symbolic names */

#define     ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0               0
#define     ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0               1
#define     ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0               2
#define     ComConf_ComIPdu_Internal_MCU_04_Can_Network_CANNODE_0               3


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx IPdu internal symbolic names */

#define     ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0               0
#define     ComConf_ComIPdu_Internal_HCU_02_Can_Network_CANNODE_0               1
#define     ComConf_ComIPdu_Internal_HCU_03_Can_Network_CANNODE_0               2
#define     ComConf_ComIPdu_Internal_HCU_04_Can_Network_CANNODE_0               3
#define     ComConf_ComIPdu_Internal_HCU_05_Can_Network_CANNODE_0               4


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx signal internal symbolic names */

#define     ComSignal_Internal_MCU01_ShutDownAllowed               0
#define     ComSignal_Internal_MCU01_Ready               1
#define     ComSignal_Internal_MCU01_HighVolAllowed               2
#define     ComSignal_Internal_MCU01_Status               3
#define     ComSignal_Internal_MCU01_ActDischStatus               4
#define     ComSignal_Internal_MCU01_SelfCheck               5
#define     ComSignal_Internal_MCU01_CheckSum               6
#define     ComSignal_Internal_MCU01_Counter               7
#define     ComSignal_Internal_MCU01_CurCntTor               8
#define     ComSignal_Internal_MCU01_Motorspd               9
#define     ComSignal_Internal_MCU01_EmergShutDown               10
#define     ComSignal_Internal_MCU02_IGBTTmp               11
#define     ComSignal_Internal_MCU02_MotorTmp               12
#define     ComSignal_Internal_MCU02_Vdc               13
#define     ComSignal_Internal_MCU02_Idc               14
#define     ComSignal_Internal_MCU02_MinTor               15
#define     ComSignal_Internal_MCU02_MaxTor               16
#define     ComSignal_Internal_MCU03_LI_OverSpeed               17
#define     ComSignal_Internal_MCU03_LI_OverTempEM               18
#define     ComSignal_Internal_MCU03_LI_OverTempINV               19
#define     ComSignal_Internal_MCU03_LI_UdcUnder               20
#define     ComSignal_Internal_MCU03_LI_UdcOver               21
#define     ComSignal_Internal_MCU03_RF_PhaseImp               22
#define     ComSignal_Internal_MCU03_12VSupply               23
#define     ComSignal_Internal_MCU03_RF_PhCOver               24
#define     ComSignal_Internal_MCU03_RF_PhBOver               25
#define     ComSignal_Internal_MCU03_RF_PhAOver               26
#define     ComSignal_Internal_MCU03_RF_OverSpeed               27
#define     ComSignal_Internal_MCU03_RF_MsgTO               28
#define     ComSignal_Internal_MCU03_RF_OverTempEM               29
#define     ComSignal_Internal_MCU03_RF_OverTempINV               30
#define     ComSignal_Internal_MCU03_RF_IntError               31
#define     ComSignal_Internal_MCU03_RF_HWOverCur               32
#define     ComSignal_Internal_MCU03_RF_UDCUnder               33
#define     ComSignal_Internal_MCU03_RF_UdcOver               34
#define     ComSignal_Internal_MCU03_RF_IdcOver               35
#define     ComSignal_Internal_MCU03_RF_ToqError               36
#define     ComSignal_Internal_MCU03_RF_BusOff               37
#define     ComSignal_Internal_MCU03_NRF_SysFailure               38
#define     ComSignal_Internal_MCU03_NRF_Resolver               39
#define     ComSignal_Internal_MCU03_NRF_PhCSamp               40
#define     ComSignal_Internal_MCU03_NRF_PhBSamp               41
#define     ComSignal_Internal_MCU03_NRF_InvTempSamp               42
#define     ComSignal_Internal_MCU03_NRF_PhASamp               43
#define     ComSignal_Internal_MCU03_NRF_DESAT               44
#define     ComSignal_Internal_MCU03_NRF_UdcSamp               45
#define     ComSignal_Internal_MCU03_NRF_COMError               46
#define     ComSignal_Internal_MCU03_NRF_5VSupply               47
#define     ComSignal_Internal_MCU03_NRF_EMTempSamp               48
#define     ComSignal_Internal_MCU03_NRF_IdcSamp               49
#define     ComSignal_Internal_MCU04_Test               50


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx signal internal symbolic names */

#define     ComSignal_Internal_HCU01_EmergShutDown               0
#define     ComSignal_Internal_HCU01_CheckSum               1
#define     ComSignal_Internal_HCU01_Counter               2
#define     ComSignal_Internal_HCU01_ActiveDischarge               3
#define     ComSignal_Internal_HCU01_McuModeCmd               4
#define     ComSignal_Internal_HCU01_EnaMCU               5
#define     ComSignal_Internal_HCU01_SpeedCmd               6
#define     ComSignal_Internal_HCU01_Shift               7
#define     ComSignal_Internal_HCU01_TqCmd               8
#define     ComSignal_Internal_HCU02_Poweroff               9
#define     ComSignal_Internal_HCU03_Poweroff               10
#define     ComSignal_Internal_HCU04_Poweroff               11
#define     ComSignal_Internal_HCU05_Poweroff               12


/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx signal group internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx signal group internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Tx group signal internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Rx group signal internal symbolic names */



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for mapping IPdu group symbolic names to internal IDs */

/* Currently IPdu group symbolic names are not used in any COM tables.
  Hence it is currently not required to generate Ipdu group internal symbolic names */

/* ------------------------------------------------------------------------ */
/* End section */


#endif /* #ifndef COM_PBCFG_INTERNALID_H */
