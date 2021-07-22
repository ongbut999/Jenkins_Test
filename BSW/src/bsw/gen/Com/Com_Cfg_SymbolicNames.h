


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/

#ifndef COM_CFG_SYMBOLICNAMES_H
#define COM_CFG_SYMBOLICNAMES_H

/* Note: Module variant generation is done here, specifically to make below macros available on the inclusion of 
 * Com_MemMap.h by other modules without Com.h inclusion */

/* definition of supported module variant  */

#define COM_VARIANT_PRE_COMPILE                   0

#define COM_VARIANT_LINK_TIME                     1

#define COM_VARIANT_POSTBUILD_LOADABLE            2

#define COM_VARIANT_POSTBUILD_SELECTABLE          3

/* Macro to hold configured module variant */
#define COM_CONFIGURATION_VARIANT                 COM_VARIANT_PRE_COMPILE


/* if COM_DontUseExternalSymbolicNames is defined while including this file, then the below symbolic names will not
   be visible in the including file */
#ifndef     COM_DontUseExternalSymbolicNames

/* ------------------------------------------------------------------------ */
/* Begin section for IPdu symbolic names */

/* Tx IPdus */
        #define ComConf_ComIPdu_MCU_01_Can_Network_CANNODE_0 0
        #define ComConf_ComIPdu_MCU_02_Can_Network_CANNODE_0 1
        #define ComConf_ComIPdu_MCU_03_Can_Network_CANNODE_0 2
        #define ComConf_ComIPdu_MCU_04_Can_Network_CANNODE_0 3
    /* Rx IPdus */
        #define ComConf_ComIPdu_HCU_01_Can_Network_CANNODE_0 0
        #define ComConf_ComIPdu_HCU_02_Can_Network_CANNODE_0 1
        #define ComConf_ComIPdu_HCU_03_Can_Network_CANNODE_0 2
        #define ComConf_ComIPdu_HCU_04_Can_Network_CANNODE_0 3
        #define ComConf_ComIPdu_HCU_05_Can_Network_CANNODE_0 4

/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Signal symbolic names */



/* Signal IDs*/
/* Tx Signal ID*/
    #define ComConf_ComSignal_MCU01_ShutDownAllowed 0
    #define ComConf_ComSignal_MCU01_Ready 1
    #define ComConf_ComSignal_MCU01_HighVolAllowed 2
    #define ComConf_ComSignal_MCU01_Status 3
    #define ComConf_ComSignal_MCU01_ActDischStatus 4
    #define ComConf_ComSignal_MCU01_SelfCheck 5
    #define ComConf_ComSignal_MCU01_CheckSum 6
    #define ComConf_ComSignal_MCU01_Counter 7
    #define ComConf_ComSignal_MCU01_CurCntTor 8
    #define ComConf_ComSignal_MCU01_Motorspd 9
    #define ComConf_ComSignal_MCU01_EmergShutDown 10
    #define ComConf_ComSignal_MCU02_IGBTTmp 11
    #define ComConf_ComSignal_MCU02_MotorTmp 12
    #define ComConf_ComSignal_MCU02_Vdc 13
    #define ComConf_ComSignal_MCU02_Idc 14
    #define ComConf_ComSignal_MCU02_MinTor 15
    #define ComConf_ComSignal_MCU02_MaxTor 16
    #define ComConf_ComSignal_MCU03_LI_OverSpeed 17
    #define ComConf_ComSignal_MCU03_LI_OverTempEM 18
    #define ComConf_ComSignal_MCU03_LI_OverTempINV 19
    #define ComConf_ComSignal_MCU03_LI_UdcUnder 20
    #define ComConf_ComSignal_MCU03_LI_UdcOver 21
    #define ComConf_ComSignal_MCU03_RF_PhaseImp 22
    #define ComConf_ComSignal_MCU03_12VSupply 23
    #define ComConf_ComSignal_MCU03_RF_PhCOver 24
    #define ComConf_ComSignal_MCU03_RF_PhBOver 25
    #define ComConf_ComSignal_MCU03_RF_PhAOver 26
    #define ComConf_ComSignal_MCU03_RF_OverSpeed 27
    #define ComConf_ComSignal_MCU03_RF_MsgTO 28
    #define ComConf_ComSignal_MCU03_RF_OverTempEM 29
    #define ComConf_ComSignal_MCU03_RF_OverTempINV 30
    #define ComConf_ComSignal_MCU03_RF_IntError 31
    #define ComConf_ComSignal_MCU03_RF_HWOverCur 32
    #define ComConf_ComSignal_MCU03_RF_UDCUnder 33
    #define ComConf_ComSignal_MCU03_RF_UdcOver 34
    #define ComConf_ComSignal_MCU03_RF_IdcOver 35
    #define ComConf_ComSignal_MCU03_RF_ToqError 36
    #define ComConf_ComSignal_MCU03_RF_BusOff 37
    #define ComConf_ComSignal_MCU03_NRF_SysFailure 38
    #define ComConf_ComSignal_MCU03_NRF_Resolver 39
    #define ComConf_ComSignal_MCU03_NRF_PhCSamp 40
    #define ComConf_ComSignal_MCU03_NRF_PhBSamp 41
    #define ComConf_ComSignal_MCU03_NRF_InvTempSamp 42
    #define ComConf_ComSignal_MCU03_NRF_PhASamp 43
    #define ComConf_ComSignal_MCU03_NRF_DESAT 44
    #define ComConf_ComSignal_MCU03_NRF_UdcSamp 45
    #define ComConf_ComSignal_MCU03_NRF_COMError 46
    #define ComConf_ComSignal_MCU03_NRF_5VSupply 47
    #define ComConf_ComSignal_MCU03_NRF_EMTempSamp 48
    #define ComConf_ComSignal_MCU03_NRF_IdcSamp 49
    #define ComConf_ComSignal_MCU04_Test 50

/* Rx Signal ID*/
    #define ComConf_ComSignal_HCU01_EmergShutDown 0
    #define ComConf_ComSignal_HCU01_CheckSum 1
    #define ComConf_ComSignal_HCU01_Counter 2
    #define ComConf_ComSignal_HCU01_ActiveDischarge 3
    #define ComConf_ComSignal_HCU01_McuModeCmd 4
    #define ComConf_ComSignal_HCU01_EnaMCU 5
    #define ComConf_ComSignal_HCU01_SpeedCmd 6
    #define ComConf_ComSignal_HCU01_Shift 7
    #define ComConf_ComSignal_HCU01_TqCmd 8
    #define ComConf_ComSignal_HCU02_Poweroff 9
    #define ComConf_ComSignal_HCU03_Poweroff 10
    #define ComConf_ComSignal_HCU04_Poweroff 11
    #define ComConf_ComSignal_HCU05_Poweroff 12





/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Signal group symbolic names */



/* Tx SignalGroup ID*/

/* Rx SignalGroup ID*/







/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for Group signal symbolic names */



/* Tx GroupSignal ID*/
#ifdef COM_TX_SIGNALGROUP

#endif
#ifdef COM_RX_SIGNALGROUP
/* Rx GroupSignal ID*/

#endif



/* ------------------------------------------------------------------------ */
/* End section */

/* ------------------------------------------------------------------------ */
/* Begin section for IPdu group symbolic names */


/* IPduGroup ID*/
    #define ComConf_ComIPduGroup_ComIPduGroup_Rx 0
    #define ComConf_ComIPduGroup_ComIPduGroup_Tx 1
/* ------------------------------------------------------------------------ */
/* End section */

#endif /* #ifndef     COM_DontUseExternalSymbolicNames */


#endif /* COM_CFG_SYMBOLICNAMES_H */
