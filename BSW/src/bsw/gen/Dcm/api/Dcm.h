

#ifndef DCM_H
#define DCM_H


/**************************************************************************************************/
/* Included header files                                                                          */
/**************************************************************************************************/

#include "ComStack_Types.h"



/* These defines which are defined below are to be available from Std_Types.h which is included via ComStack_Types.h
   but in case the projects have legacy Std_Types.h, it would possible that these defines probably aren't existing.
   In those cases, where these defines aren't already available, Dcm redefines the same for its usage */


#include "Dcm_Cfg_DslDsd.h"
#include "Dcm_Types.h"
#include "DcmCore_DslDsd_Pub.h"


#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
#include "Dcm_Cfg_DspUds.h"
#include "Dcm_Lcfg_DspUds.h"
#include "DcmDspUds_Uds_Pub.h"
#endif


/* FC_VariationPoint_START */
#if(DCM_CFG_DSPOBDSUPPORT_ENABLED != DCM_CFG_OFF)
#include "Dcm_Lcfg_DspObd.h"
#include "DcmDspObd_Obd_Pub.h"
#endif
/* FC_VariationPoint_END */
#include "Dcm_Lcfg_DslDsd.h"

#if(DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED==DCM_CFG_OFF)
#ifndef DCM_PRV_EXPORTAPI2LEGACY
#define DCM_PRV_EXPORTAPI2LEGACY
#endif
#endif
#ifndef DCM_PRV_EXPORTAPI2LEGACY
#include "Dcm_Export.h"
#endif


/**
* @ingroup DCM_H
*  Dcm_GetVin: This function is called by DOIP for reading the VIN DID.
*
*  @param[out]:    *Data  pointer to the target buffer(17 bytes) provided by DOIP
*  @retval:         Std_ReturnType      E_OK - if the VIN DID is read successfully
*                                       E_NOT_OK - if the VIN DID is not read successfully
*/

#if(DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF)
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_GetVin (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif

#if(DCM_CFG_RTESUPPORT_ENABLED == DCM_CFG_OFF)
/**
 * @ingroup DCM_H
 * Dcm_SetActiveDiagnostic - The call of this function allows to activate and deactivate the call of ComM_DCM_ActiveDiagnostic() function
 *  @param[in]    active:  True Dcm will call ComM_DCM_ActiveDiagnostic() \n
 *                           False Dcm shall not call ComM_DCM_ActiveDiagnostic()
 *  @retval    E_OK : this value is always returned.
 */
extern FUNC(Std_ReturnType,DCM_CODE) Dcm_SetActiveDiagnostic(VAR(boolean, AUTOMATIC) active);
#endif

#define DCM_START_SEC_VAR_CLEARED_8
#include "Dcm_Cfg_MemMap.h"
extern Dcm_SrvOpStatusType Dcm_SrvOpstatus_u8;
#define DCM_STOP_SEC_VAR_CLEARED_8
#include "Dcm_Cfg_MemMap.h"

#endif/* DCM_H_ */

/**
 * \defgroup DCM_H    DCM - AUTOSAR interface
 * This interface provides functionality to report errors
 * as specified by AUTOSAR.\n
 * To use this interface include the header <b>dcm.h</b>
 */

/**
 * \defgroup DCMCORE_DSLDSD_AUTOSAR     DCMCORE_DSLDSD - AUTOSAR interface
 *
 */
/**
 * \defgroup DCMCORE_DSLDSD_EXTENDED     DCMCORE_DSLDSD - EXTENDED interface
 *
 */
/* FC_VariationPoint_START */
/**
 * \defgroup DCMDSP_OBD_AUTOSAR   DCMDSP_OBD - AUTOSAR interface
 *
 */
/**
 * \defgroup DCMDSP_OBD_EXTENDED   DCMDSP_OBD - EXTENDED interface
 *
 */
/* FC_VariationPoint_END */
/**
 * \defgroup DCMDSP_UDS_EXTENDED   DCMDSP_UDS - EXTENDED interface
 *
 */
/**
 * \defgroup DCM_TPL    DCM-APPL Functions
 *
 */



/* DCM_H_ */
