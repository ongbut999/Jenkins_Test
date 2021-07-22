

 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: PduR  / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/

#ifndef PDUR_CFG_SYMBOLICNAMES_H
#define PDUR_CFG_SYMBOLICNAMES_H

/* Note: Module variant generation is done here, specifically to make below macros available on the inclusion of 
 * PduR_memmap.h header file by other modules without PduR_Cfg.h inclusion */


#define PDUR_VARIANT_PRE_COMPILE    (0)

#define PDUR_VARIANT_POSTBUILD_LOADABLE    (1)

#if !defined(PDUR_CONFIGURATION_VARIANT)
#define PDUR_CONFIGURATION_VARIANT    PDUR_VARIANT_PRE_COMPILE
#endif /* PDUR_CONFIGURATION_VARIANT */




/* For PduRRoutingTable: Symbolic Name reference are generated for Tx Paths and Rx paths
For TxPaths:
PduRConf_PduRSrcPdu_<shortname of PduRSrcPdu> will be used by module which gives PduR_<UpperLayer>Transmit request e.g Com,Dcm,Up-Cdd
PduRConf_PduRDestPdu_<shortname of PduRDestPdu> will be used by module which gives PduR_<LowerLayer>TxConfirmation callback e.g CanIf,CanTp,Low-Cdd

For RxPaths:
PduRConf_PduRSrcPdu_<shortname of PduRSrcPdu> will be used by module which gives PduR_<LowerLayer>RxIndication callback e.g CanIf,CanTp,Low-Cdd */

#define PduRConf_PduRSrcPdu_Diag_Functional_request_Can_Network_CANNODE_0_CanTp2PduR    0
#define PduRConf_PduRDestPdu_Diag_Functional_request_Can_Network_CANNODE_0_PduR2Dcm  0

#define PduRConf_PduRSrcPdu_Diag_Physical_request_Can_Network_CANNODE_0_CanTp2PduR    1
#define PduRConf_PduRDestPdu_Diag_Physical_request_Can_Network_CANNODE_0_PduR2Dcm  1

#define PduRConf_PduRSrcPdu_Diag_Physical_response_Can_Network_CANNODE_0_Phys_Dcm2PduR    0
#define PduRConf_PduRDestPdu_Diag_Physical_response_Can_Network_CANNODE_0_Phys_PduR2CanTp  0

#define PduRConf_PduRSrcPdu_HCU_01_Can_Network_CANNODE_0_CanIf2PduR    0

#define PduRConf_PduRSrcPdu_HCU_02_Can_Network_CANNODE_0_CanIf2PduR    1

#define PduRConf_PduRSrcPdu_HCU_03_Can_Network_CANNODE_0_CanIf2PduR    2

#define PduRConf_PduRSrcPdu_HCU_04_Can_Network_CANNODE_0_CanIf2PduR    3

#define PduRConf_PduRSrcPdu_HCU_05_Can_Network_CANNODE_0_CanIf2PduR    4

#define PduRConf_PduRSrcPdu_MCU_01_Can_Network_CANNODE_0_Com2PduR    0
#define PduRConf_PduRDestPdu_MCU_01_Can_Network_CANNODE_0_PduR2CanIf  0

#define PduRConf_PduRSrcPdu_MCU_02_Can_Network_CANNODE_0_Com2PduR    1
#define PduRConf_PduRDestPdu_MCU_02_Can_Network_CANNODE_0_PduR2CanIf  1

#define PduRConf_PduRSrcPdu_MCU_03_Can_Network_CANNODE_0_Com2PduR    2
#define PduRConf_PduRDestPdu_MCU_03_Can_Network_CANNODE_0_PduR2CanIf  2

#define PduRConf_PduRSrcPdu_MCU_04_Can_Network_CANNODE_0_Com2PduR    3
#define PduRConf_PduRDestPdu_MCU_04_Can_Network_CANNODE_0_PduR2CanIf  3




#endif /* PDUR_CFG_SYMBOLICNAMES_H */
