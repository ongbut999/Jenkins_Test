/** @file     SchM_Dcm_Type.h
  *
  * @brief    Basic Software Scheduler Module Interlink Types header file
  *
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  *
  * @note     Generated by ETAS RTA-RTE
  * @note     Version 6.8.0 
  */

#ifndef SchM_Dcm_Type
#define SchM_Dcm_Type

#include "Rte_Type.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* BEGIN: BSW implementation specific types */
#ifndef RTE_CORE
#ifndef RTE_MODETYPE_DCMCOMMUNICATIONCONTROL_COMMCHANNEL_CAN_NETWORK_CHANNEL
#define RTE_MODETYPE_DCMCOMMUNICATIONCONTROL_COMMCHANNEL_CAN_NETWORK_CHANNEL

typedef uint8 Rte_ModeType_DcmCommunicationControl_ComMChannel_Can_Network_Channel;

#endif /* !RTE_MODETYPE_DCMCOMMUNICATIONCONTROL_COMMCHANNEL_CAN_NETWORK_CHANNEL */
#ifndef RTE_MODETYPE_DCMCONTROLDTCSETTING
#define RTE_MODETYPE_DCMCONTROLDTCSETTING

typedef uint8 Rte_ModeType_DcmControlDTCSetting;

#endif /* !RTE_MODETYPE_DCMCONTROLDTCSETTING */
#ifndef RTE_MODETYPE_DCMDIAGNOSTICSESSIONCONTROL
#define RTE_MODETYPE_DCMDIAGNOSTICSESSIONCONTROL

typedef uint8 Rte_ModeType_DcmDiagnosticSessionControl;

#endif /* !RTE_MODETYPE_DCMDIAGNOSTICSESSIONCONTROL */
#ifndef RTE_MODETYPE_DCMECURESET
#define RTE_MODETYPE_DCMECURESET

typedef uint8 Rte_ModeType_DcmEcuReset;

#endif /* !RTE_MODETYPE_DCMECURESET */
#endif /* RTE_CORE */

/* END: BSW implementation specific types */

/* BEGIN: BSW implementation specific definitions */
#ifndef RTE_CORE
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NM      0U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM    1U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM_NM 2U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NM             3U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM           4U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM_NM        5U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NM      6U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM    7U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM_NM 8U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NM              9U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM            10U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM */
#ifndef RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM_NM         11U
#endif /* !RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM_NM */
#ifndef RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING
#define RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING                                                   0U
#endif /* !RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING */
#ifndef RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING
#define RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING                                                    1U
#endif /* !RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING */
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION                                              0U
#endif /* !RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION */
#ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION                                  1U
#endif /* !RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION */
#ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION                                          2U
#endif /* !RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION */
#ifndef RTE_MODE_DcmEcuReset_EXECUTE
#define RTE_MODE_DcmEcuReset_EXECUTE                                                                      0U
#endif /* !RTE_MODE_DcmEcuReset_EXECUTE */
#ifndef RTE_MODE_DcmEcuReset_HARD
#define RTE_MODE_DcmEcuReset_HARD                                                                         1U
#endif /* !RTE_MODE_DcmEcuReset_HARD */
#ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER                                                             2U
#endif /* !RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER */
#ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER                                                  3U
#endif /* !RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER */
#ifndef RTE_MODE_DcmEcuReset_NONE
#define RTE_MODE_DcmEcuReset_NONE                                                                         4U
#endif /* !RTE_MODE_DcmEcuReset_NONE */
#ifndef RTE_MODE_DcmEcuReset_SOFT
#define RTE_MODE_DcmEcuReset_SOFT                                                                         5U
#endif /* !RTE_MODE_DcmEcuReset_SOFT */
#ifndef RTE_TRANSITION_DcmCommunicationControl_ComMChannel_Can_Network_Channel
#define RTE_TRANSITION_DcmCommunicationControl_ComMChannel_Can_Network_Channel                            12U
#endif /* !RTE_TRANSITION_DcmCommunicationControl_ComMChannel_Can_Network_Channel */
#ifndef RTE_TRANSITION_DcmControlDTCSetting
#define RTE_TRANSITION_DcmControlDTCSetting                                                               2U
#endif /* !RTE_TRANSITION_DcmControlDTCSetting */
#ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#define RTE_TRANSITION_DcmDiagnosticSessionControl                                                        3U
#endif /* !RTE_TRANSITION_DcmDiagnosticSessionControl */
#ifndef RTE_TRANSITION_DcmEcuReset
#define RTE_TRANSITION_DcmEcuReset                                                                        6U
#endif /* !RTE_TRANSITION_DcmEcuReset */
#endif /* RTE_CORE */

/* END: BSW implementation specific definitions */


#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif /* !SchM_Dcm_Type */
