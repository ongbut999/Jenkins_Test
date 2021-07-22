
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "DcmCore_DslDsd_Inf.h"


/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 **************************************************************************************************
 * Dcm_GetActiveProtocol : API to get the active protocol id
 *
 * \param           ActiveProtocol: Address of global variable Passed by the application.
 *
 *
 * \retval          Std_ReturnType E_OK always
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC(Std_ReturnType,DCM_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, DCM_APPL_DATA) ActiveProtocol)
{
    if(ActiveProtocol != NULL_PTR)
    {
        if(FALSE != Dcm_Prv_isProtocolStarted())
        {
            *(ActiveProtocol) = Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].protocolid_u8;
        }
        else
        {
            *(ActiveProtocol) = DCM_NO_ACTIVE_PROTOCOL;
        }
    }
    return(E_OK);
}



/**
 **************************************************************************************************
 * Dcm_GetActiveProtocolRxBufferSize : API to get the Active protocol RX buffer size
 *
 * \param           rxBufferLength: Address of global variable in which the buffer size should be written.
 *
 *
 * \retval          E_OK: RX buffer size read successfully
 *                  E_NOT_OK: RX Buffer size not read, possibly because of no active protocol
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC(Std_ReturnType,DCM_CODE) Dcm_GetActiveProtocolRxBufferSize(CONSTP2VAR(Dcm_MsgLenType, AUTOMATIC, DCM_APPL_DATA) rxBufferLength)
{
    VAR(Std_ReturnType,AUTOMATIC) bufferSizeStatus = E_NOT_OK;

    if(NULL_PTR != rxBufferLength)
    {
        if(FALSE != Dcm_Prv_isProtocolStarted())
        {
            *(rxBufferLength) = Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].rx_buffer_size_u32;
            bufferSizeStatus = E_OK;
        }
    }

    return (bufferSizeStatus);
}


/**
 **************************************************************************************************
 * Dcm_GetActiveServiceTable : API to get the service table id
 *
 * \param           ActiveServiceTable: Address of global variable Passed by the application.
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC(void,DCM_CODE) Dcm_GetActiveServiceTable (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ActiveServiceTable)
{
    if(NULL_PTR != ActiveServiceTable)
    {
        *(ActiveServiceTable) = Dcm_DsldGlobal_st.datActiveSrvtable_u8;
    }
}



#if (DCM_CFG_RBA_DIAGADAPT_SUPPORT_ENABLED != DCM_CFG_OFF)

/**
 **************************************************************************************************
 * Dcm_GetMediumOfActiveConnection: API to get Medium information(ie.Can,Flexray..etc) available in the ComMChannel the active connection.
 *                                  This is explicitly provided only for rba_DiagAdapt.This should be invoked only by rba_DiagAdapt only when new protocol request is received from Tester.
 *
 * \param[out]          ActiveMediumId  : Variable Passed by the rba_DiagAdapt to get active Medium information of ComMChannel for the active connection.
 *
 *
 * \retval              E_OK.
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC(Std_ReturnType,DCM_CODE) Dcm_GetMediumOfActiveConnection(\
        CONSTP2VAR(Dcm_DslDsd_MediumType_ten, AUTOMATIC, DCM_APPL_DATA) ActiveMediumId)
{
    if(ActiveMediumId != NULL_PTR)
    {
        /*Get the MediumId of the active connection*/
        *ActiveMediumId = Dcm_active_commode_e[Dcm_DsldConnTable_pcst[Dcm_DsldGlobal_st.nrActiveConn_u8].channel_idx_u8].MediumId;
    }
    return(E_OK);
}

#endif

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
