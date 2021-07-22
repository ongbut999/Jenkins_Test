


 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: PduR  / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/



#include "PduR_Prv.h"

#include "PduR_Cfg.h"
/* Appropriate header files are included to declare the prototypes
 */
#include "PduR_UpTp.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */


#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"
/**
 **************************************************************************************************
 * PduR_dDcmTransmit - Function to be invoked DET enable for PduR_DcmTransmit
 *      This function is called by the Dcm to request a transmission.
 *
 * \param           PduIdType id: ID of Dcm I-PDU to be transmitted.
 *                  P2CONST( PduInfoType, TYPEDEF, PDUR_APPL_DATA ) ptr: Pointer to a structure with I-PDU related data that shall be transmitted:
 *                                         data length and pointer to I-SDU buffer
 *
 * \retval          E_OK Transmit request has been accepted
 *                  E_NOT_OK Transmit request has not been accepted
 *
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC( Std_ReturnType, PDUR_CODE ) PduR_dDcmTransmit( VAR(PduIdType, AUTOMATIC) id, P2CONST( PduInfoType, TYPEDEF, PDUR_APPL_DATA ) ptr)
{
   VAR( Std_ReturnType, AUTOMATIC) r;

    PDUR_CHECK_STATE_RET(PDUR_SID_DCMTX, E_NOT_OK)



    PDUR_CHECK_PTR_RET(PDUR_SID_DCMTX, ptr, E_NOT_OK)


    if ( ( id >= PDUR_NR_VALID_DCM_IDS ) || ( PduR_iDcmTransmitFunc(id) == NULL_PTR ) )
    {
        PDUR_REPORT_ERROR(PDUR_SID_DCMTX, PDUR_E_PDU_ID_INVALID);
        return  E_NOT_OK;
    }


    r = PduR_iDcmTransmitFunc(id)( PduR_iDcmTransmitID(id), ptr );

    if ( E_OK != r  )
    {
        PDUR_REPORT_ERROR(PDUR_SID_DCMTX, PDUR_E_TP_TX_REQ_REJECTED);
    }

    return r;
}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"


