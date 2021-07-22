


 
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
#include "PduR_LoIf.h"


/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_CanIfTxConfirmation - PDU Router CanIfTxConfirmation
 *      This function is called by the CanIf after the PDU has been transmitted on the network.
 *
 * \param           PduIdType Id: ID of  L-PDU that has been transmitted.
 *
 *
 * \retval          None
 * \seealso         PDUR194
 * \usedresources
 **************************************************************************************************
 */

FUNC( void, PDUR_CODE ) PduR_CanIfTxConfirmation( VAR(PduIdType, AUTOMATIC) id )
{
    PduR_rCanIfTxConfirmation( id );
}

/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_CanIfRxIndication - PDU Router CanIfRxIndication
 *      This function is called by the CanIf after a L-PDU has been received.
 *
 * \param           PduIdType id
 *                  const uint8 *ptr
 *
 * \retval          None
 * \seealso         PDUR193 and PDUR258
 * \usedresources
 **************************************************************************************************
 */

FUNC( void, PDUR_CODE ) PduR_CanIfRxIndication( VAR(PduIdType, AUTOMATIC) id,
                                                P2CONST( PduInfoType, TYPEDEF, PDUR_APPL_DATA ) ptr)
{
    PduR_rCanIfRxIndication((id), (ptr));
}

/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_dCanIfRxIndication - PDU Router CanIfRxIndication
        Function to be invoked DET enable for PduR_CanIfRxIndication
 *      This function is called by the CanIf after a L-PDU has been received.
 *
 * \param           PduIdType CanIf_RxPduId
 *                  const uint8 *ptr
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC( void, PDUR_CODE ) PduR_dCanIfRxIndication( VAR(PduIdType, AUTOMATIC) id, P2CONST( PduInfoType, TYPEDEF, PDUR_APPL_DATA ) ptr )
{

    PDUR_CHECK_STATE_VOID(PDUR_SID_CANIFRXIND)



    PDUR_CHECK_PTR_VOID(PDUR_SID_CANIFRXIND, ptr)

    /*Check for Invalid Id and null pointer */
    if ( ( id >= PDUR_NR_VALID_CANIFIFRXTOUP_IDS ) || ( PduR_iCanIfRxIndicationFunc(id) == NULL_PTR ) )
    {
        PDUR_REPORT_ERROR(PDUR_SID_CANIFRXIND, PDUR_E_PDU_ID_INVALID);
        return;
    }
   /*Call the upper layer RxIndication function */
    PduR_iCanIfRxIndicationFunc(id)( PduR_iCanIfRxIndicationID(id), ptr );
}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"


/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

/**
 **************************************************************************************************
 * PduR_dCanIfTxConfirmation - PDU Router CanIfTxConfirmation
 *      Function to be invoked DET enable for PduR_CanIfTxConfirmation
 *      This function is called by the CanIf after the PDU has been transmitted on the network.
 *
 * \param           PduIdType CanTxPduId: ID of CAN L-PDU that has been transmitted.
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC( void, PDUR_CODE ) PduR_dCanIfTxConfirmation( VAR(PduIdType, AUTOMATIC) id)
{

    PDUR_CHECK_STATE_VOID(PDUR_SID_CANIFTXCONF)

    /*Check for Invalid Id and null pointer */
    if ( ( id >= PDUR_NR_VALID_CANIFIFTXTOUP_IDS ) || ( PduR_iCanIfTxConfirmationFunc(id) == NULL_PTR ) )
    {
        PDUR_REPORT_ERROR(PDUR_SID_CANIFTXCONF, PDUR_E_PDU_ID_INVALID);
        return;
    }

    /*Call the upper layer TxConfirmation function */
    PduR_iCanIfTxConfirmationFunc(id)( PduR_iCanIfTxConfirmationID(id) );
}
/* ------------------------------------------------------------------------ */
/* End section for code */

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"


