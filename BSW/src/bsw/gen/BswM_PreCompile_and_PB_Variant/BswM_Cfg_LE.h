#ifndef BSWM_CFG_LE_H
#define BSWM_CFG_LE_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Std_Types.h"

#include "Mcu.h"

#include "Stubs.h"

#include "Rte_Main.h"

#include "CanSM_ComM.h"

#include "CanIf.h"

#include "Can.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */

/******************************     BswM Logical Expression    *****************************************/

#define BSWMLOGEXP_BSWM_LE_APPRUN  \
                     ( ( CANIF_CS_STARTED  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEALREADYSTARTED].dataMode_en )  \
                     && ( CANIF_CS_STARTED  ==  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEALREADYSTARTED_XCP].dataMode_en )  \
                     && ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_APP_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_NM  \
                    ( DCM_DISABLE_RX_TX_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM  \
                    ( DCM_DISABLE_RX_ENABLE_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_DISABLE_RX_TX_NORM  \
                    ( DCM_DISABLE_RX_TX_NORMAL  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_NM  \
                    ( DCM_ENABLE_RX_TX_NM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM  \
                    ( DCM_ENABLE_RX_DISABLE_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ENABLE_RX_TX_NORM  \
                    ( DCM_ENABLE_RX_TX_NORM  ==  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].dataMode_u8 )

#define BSWMLOGEXP_BSWM_LE_DCM_ECURESET_HARD  \
                     ( ( RTE_MODE_DcmEcuReset_EXECUTE  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_MODENOTIFICATION_ECURESET].dataMode_u16 )  \
                     || ( RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_DIAGNOSTICSESSIONCONTROL].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_DCM_ECURESET_SOFT  \
                    ( RTE_MODE_DcmEcuReset_SOFT  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_MODENOTIFICATION_ECURESET].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_NETWORKRELEASE  \
                    ( RTE_MODE_ComMMode_COMM_NO_COMMUNICATION  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_NETWORKREQUEST  \
                    ( RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_POSTRUN  \
                     ( ( RTE_MODE_MDG_App_Mode_SwcRequest_ECUM_STATE_APP_POST_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].dataMode_u16 )  \
                     || ( RTE_MODE_MDG_App_Mode_ECUM_NOWAKEUP  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_PREPSHUTDOWN  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_PREP_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_RUN  \
                     ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_RUN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                     && ( RTE_MODE_MDG_App_Mode_ECUM_WAKEUP  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].dataMode_u16 ) )

#define BSWMLOGEXP_BSWM_LE_SHUTDOWN  \
                     ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_SHUTDOWN  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                     && ( NVM_REQ_PENDING  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMWRITEALLCOMPLETE].dataMode_en ) )

#define BSWMLOGEXP_BSWM_LE_STARTUPONE  \
                    ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_ONE  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )

#define BSWMLOGEXP_BSWM_LE_STARTUPTWO  \
                     ( ( RTE_MODE_MDG_ECUM_STATE_ECUM_STATE_STARTUP_TWO  ==  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].dataMode_u16 )  \
                     && ( NVM_REQ_PENDING  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMREADALLCOMPLETE].dataMode_en ) )

/******************   Macros for checking whether the ModeValues are defined   ******************************/

#define BSWMMODEVALUE_BSWM_LE_APPRUN  \
        ( ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEALREADYSTARTED].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_CanSMIndicationModeInfo_ast[BSWM_IDX_BSWM_MRP_CONTROLLERSTATEALREADYSTARTED_XCP].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_NM  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_DISABLE_RX_TX_NORM  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_NM  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ENABLE_RX_TX_NORM  \
        ( FALSE  !=  BswM_Cfg_DcmComModeRequestModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_COMMODEREQUEST_ECAN].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_DCM_ECURESET_HARD  \
        ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_MODENOTIFICATION_ECURESET].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_DIAGNOSTICSESSIONCONTROL].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_DCM_ECURESET_SOFT  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_DCM_MODENOTIFICATION_ECURESET].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_NETWORKRELEASE  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_NETWORKREQUEST  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_SWC_NETWORK].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_POSTRUN  \
        ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_PREPSHUTDOWN  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_RUN  \
        ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWMSWCMODEREQUEST].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_SHUTDOWN  \
        ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMWRITEALLCOMPLETE].isValidModePresent_b ) )

#define BSWMMODEVALUE_BSWM_LE_STARTUPONE  \
        ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )

#define BSWMMODEVALUE_BSWM_LE_STARTUPTWO  \
        ( ( FALSE  !=  BswM_Cfg_GenericReqModeInfo_ast[BSWM_IDX_BSWM_MRP_BSWM_MDG].isValidModePresent_b )  \
         && ( FALSE  !=  BswM_Cfg_NvMJobModeInfo_ast[BSWM_IDX_BSWM_MRP_NVMREADALLCOMPLETE].isValidModePresent_b ) )

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */

/********************************  LogicalExpressionEvaluateFunctions  ***************************************/
#define BSWM_START_SEC_CODE
#include "BswM_Cfg_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_AppRun (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_DISABLE_NM (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_ENABLE_TX_NORM (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_DISABLE_RX_TX_NORM (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_ENABLE_NM (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_DISABLE_TX_NORM (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_ENABLE_RX_TX_NORM (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_EcuReset_HARD (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_DCM_EcuReset_SOFT (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_NetworkRelease (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_NetworkRequest (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_PostRun (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_PrepShutdown (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_Run (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_Shutdown (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartupOne (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);
extern FUNC(void, BSWM_CODE) BswM_Cfg_LE_BswM_LE_StartupTwo (P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) isValidMode_pb, P2VAR(boolean, AUTOMATIC, BSWM_APPL_DATA) hasLogExpRes_pb);

#define BSWM_STOP_SEC_CODE
#include "BswM_Cfg_MemMap.h"

#endif  /* BSWM_CFG_LE_H */
/**********************************************************************************************************************
 * End of header file
 **********************************************************************************************************************/
