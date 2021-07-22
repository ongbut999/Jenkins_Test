

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "rba_BswSrv.h"
#include "DcmCore_DslDsd_Inf.h"



/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.h"
static VAR(boolean, AUTOMATIC) Dcm_isNrc21responseSet_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_Cfg_MemMap.h"
static P2VAR(PduInfoType, AUTOMATIC, DCM_APPL_DATA) Dcm_PduInfo_pst;
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Dcm_Cfg_MemMap.h"





/***********************************************************************************************************************
 *    Inline Function Definitions
 **********************************************************************************************************************/


/***********************************************************************************************************************
 Function name    : Dcm_Prv_isRetryRequested
 Syntax           : Dcm_Prv_isRetryRequested(&RetryInfoPtr,&PduInfoPtr,&RetValPtr)
 Description      : This Inline function is used to check if retry is requested from lower layer
 Parameter        : const RetryInfoType*,const PduInfoType*,BufReq_ReturnType*
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isRetryRequested(P2CONST(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) RetryInfoPtr,
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,P2VAR(BufReq_ReturnType,AUTOMATIC,DCM_APPL_DATA) RetValPtr)
{
    VAR(boolean,AUTOMATIC) isRetryRequested_b = FALSE;

    if(RetryInfoPtr != NULL_PTR)
    {
        if(RetryInfoPtr->TpDataState == TP_DATARETRY)
        {
            if((PduInfoPtr->SduDataPtr != NULL_PTR) && (RetryInfoPtr->TxTpDataCnt > 0u ))
            {
                isRetryRequested_b   = TRUE;
            }
            else
            {
                *RetValPtr = BUFREQ_E_NOT_OK;
            }
        }
    }

    return isRetryRequested_b;
}





/***********************************************************************************************************************
 Function name    : Dcm_Prv_isNormalResponseAvailable
 Syntax           : Dcm_Prv_isNormalResponseAvailable(DcmTxPduId)
 Description      : This Inline function is used to check whether Normal response is available.
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isNormalResponseAvailable(VAR(PduIdType,AUTOMATIC) DcmTxPduId)
{
   return((Dcm_Dsld_Conf_cs.ptr_txtable_pca[DcmTxPduId] == Dcm_DsldGlobal_st.dataActiveTxPduId_u8) && \
           ((Dcm_Prv_GetDslState() == DSL_STATE_WAITING_FOR_TXCONFIRMATION)  || \
            (Dcm_Prv_GetDslState() == DSL_STATE_ROETYPE1_RECEIVED))

         );
}




#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isPagedBufferResponseAvailable
 Syntax           : Dcm_Prv_isPagedBufferResponseAvailable(DcmTxPduId)
 Description      : This Inline function is used to check whether Paged buffer response is available
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isPagedBufferResponseAvailable(VAR(PduIdType,AUTOMATIC) DcmTxPduId)
{
   return((Dcm_Dsld_Conf_cs.ptr_txtable_pca[DcmTxPduId] == Dcm_DsldGlobal_st.dataActiveTxPduId_u8) && \
        (Dcm_Prv_GetDslState() == DSL_STATE_PAGEDBUFFER_TRANSMISSION));
}
#endif





#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isRoeType2ResponseAvailable
 Syntax           : Dcm_Prv_isRoeType2ResponseAvailable(DcmTxPduId)
 Description      : This funcion is used to
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isRoeType2ResponseAvailable(VAR(PduIdType,AUTOMATIC) DcmTxPduId)
{
    return (Dcm_DsldConnTable_pcst[Dcm_DsldRxTable_pcu8[Dcm_Roe2MesContext_st.dcmRxPduId]].roetype2_txpdu_u8 == \
            Dcm_Dsld_Conf_cs.ptr_txtable_pca[DcmTxPduId]);
}
#endif






#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_isCurrentPageTransmitted
 Syntax           : Dcm_Prv_isCurrentPageTransmitted(SduLength,&RetryInfoPtr)
 Description      : This Inline Function is used to check if Current page is Transmitted in case of paged buffer Tx
 Parameter        : PduLengthType,const RetryInfoType*
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isCurrentPageTransmitted(VAR(PduLengthType, AUTOMATIC) SduLength,
        P2CONST(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) RetryInfoPtr)
{
    VAR(boolean,AUTOMATIC) pageStatus_b = FALSE;

    if(SduLength == 0u)
    {
        if(RetryInfoPtr != NULL_PTR)
        {
            if(RetryInfoPtr->TpDataState == TP_DATACONF)
            {
                pageStatus_b = TRUE;
            }
        }
        else
        {
            pageStatus_b = TRUE;
        }
    }

    return pageStatus_b;
}
#endif



/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessPagedBufferResponse
 Syntax           : Dcm_Prv_ProcessPagedBufferResponse(&PduInfoPtr,&RetryInfoPtr)
 Description      : This Function is used to handle Panged buffer states and process the response.
 Parameter        : const PduInfoType*,const RetryInfoType*
 Return value     : BufReq_ReturnType
***********************************************************************************************************************/
/*TRACE[SWS_Dcm_00028]*/
static FUNC(BufReq_ReturnType,DCM_CODE) Dcm_Prv_ProcessPagedBufferResponse(
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
        P2CONST(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) RetryInfoPtr)
{
    VAR(BufReq_ReturnType,AUTOMATIC) bufRequestStatus_en = BUFREQ_E_NOT_OK;
    VAR(uint8,AUTOMATIC)subStateTemp_u8 = Dcm_Prv_GetDslSubState();

    switch(subStateTemp_u8)
    {
        case DSL_SUBSTATE_DATA_READY :

            /* When the TP requests Dcm to copy payload, check if length indicated to copy is greater than the available
               Dcm response length.
               If yes then send DET error when first Dcm_TpCopyTxData fails for the paged buffer in the first page  */

            if(PduInfoPtr->SduLength <= (PduLengthType)Dcm_DsldGlobal_st.dataCurrentPageRespLength_u32)
            {
                Dcm_DsldPduInfo_st.SduDataPtr = &Dcm_DsldGlobal_st.adrActiveTxBuffer_tpu8[0];
                Dcm_DsldPduInfo_st.SduLength  = (PduLengthType)Dcm_DsldGlobal_st.dataCurrentPageRespLength_u32;

                Dcm_PduInfo_pst = &Dcm_DsldPduInfo_st;

                Dcm_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION);
                Dcm_Prv_SetDslSubState(DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM);
                bufRequestStatus_en = BUFREQ_OK;
            }
            else
            {
                bufRequestStatus_en = BUFREQ_E_NOT_OK;
                DCM_DET_ERROR(DCM_COPYTXDATA_ID , DCM_E_INVALID_LENGTH )
            }
            break;


        /*TRACE[SWS_Dcm_01186]*/
        case DSL_SUBSTATE_WAIT_FOR_DATA :

            bufRequestStatus_en = BUFREQ_E_BUSY;
            break;



        case DSL_SUBSTATE_WAIT_PAGE_TXCONFIRM :

            /* Current page transmission is over. Give the page back to service to fill next page */
            if(FALSE != Dcm_Prv_isCurrentPageTransmitted(Dcm_DsldPduInfo_st.SduLength,RetryInfoPtr))
            {
                Dcm_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION);
                Dcm_Prv_SetDslSubState(DSL_SUBSTATE_WAIT_FOR_DATA);
                bufRequestStatus_en = BUFREQ_E_BUSY;
            }
            else
            {
                if((Dcm_DsldPduInfo_st.SduLength < PduInfoPtr->SduLength ) && (Dcm_DsldGlobal_st.flgPagedBufferTxOn_b))
                {
                    /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMSET takes void pointer
                      as input and object type pointer is converted to void pointer*/
                    DCM_MEMSET(& Dcm_DsldGlobal_st.adrActiveTxBuffer_tpu8[0], (sint32)DCM_CFG_SIGNAL_DEFAULT_VALUE,
                                    Dcm_DsldPduInfo_st.SduLength);

                    /* copy the reaming bytes to Start page address */
                    /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object type
                    pointer is converted to void pointer*/
                    DCM_MEMCOPY(& Dcm_DsldGlobal_st.adrActiveTxBuffer_tpu8[0], Dcm_DsldPduInfo_st.SduDataPtr,
                                    Dcm_DsldPduInfo_st.SduLength);

                    Dcm_Prv_SetDslState(DSL_STATE_PAGEDBUFFER_TRANSMISSION);
                    Dcm_Prv_SetDslSubState(DSL_SUBSTATE_WAIT_FOR_DATA);
                    bufRequestStatus_en = BUFREQ_E_BUSY;
                }
                else
                {
                    /* Current page transmission is not yet over. To copy the requested data */
                    Dcm_PduInfo_pst = &Dcm_DsldPduInfo_st;
                    bufRequestStatus_en = BUFREQ_OK;
                }
            }
            break;

        default :
            /*nothing to do*/
            break;

    }
    return bufRequestStatus_en;
}

#endif




/***********************************************************************************************************************
 Function name    : Dcm_Prv_isNrc21ResponseAvailable
 Syntax           : Dcm_Prv_isNrc21ResponseAvailable(&ServiceIdPtr,DcmTxPduId)
 Description      : This Function is used to check whether NRC21 response is available
 Parameter        : uint16*, PduIdType
 Return value     : boolean
***********************************************************************************************************************/
static FUNC(boolean,DCM_CODE)Dcm_Prv_isNrc21ResponseAvailable(P2VAR(uint16,AUTOMATIC,DCM_APPL_DATA) ServiceIdPtr,
        VAR(PduIdType, AUTOMATIC) DcmTxPduId)
{
    VAR(boolean, AUTOMATIC) isNrc21Available_b  = FALSE;
    VAR(uint8,AUTOMATIC) connectionId_u8     = 0u;
    VAR(uint8,AUTOMATIC) idxProtocol_u8      = 0u;
    VAR(PduIdType,AUTOMATIC) idxTxpduid_u8   = 0u;
    VAR(PduIdType, AUTOMATIC) idxPduId_u16   = 0u;

    for ( idxPduId_u16 = 0; idxPduId_u16 < DCM_CFG_NUM_RX_PDUID ; idxPduId_u16++ )
    {
        if(DCM_SERVICEID_DEFAULT_VALUE != Dcm_DslRxPduArray_ast[idxPduId_u16].Dcm_DslServiceId_u8)
        {
            *ServiceIdPtr         = Dcm_DslRxPduArray_ast[idxPduId_u16].Dcm_DslServiceId_u8;
            connectionId_u8       = Dcm_DsldRxTable_pcu8[idxPduId_u16];
            idxProtocol_u8        = Dcm_DsldConnTable_pcst[connectionId_u8].protocol_num_u8;
            idxTxpduid_u8         = Dcm_DsldConnTable_pcst[connectionId_u8].txpduid_num_u8;

            /*nrc21 flag for the transmission is set to True*/
            if (( idxTxpduid_u8 == Dcm_Dsld_Conf_cs.ptr_txtable_pca[DcmTxPduId]) &&
                    (FALSE != Dcm_DsldProtocol_pcst[idxProtocol_u8].nrc21_b))
            {
                isNrc21Available_b = TRUE;
                break;
            }
        }
    }
    return isNrc21Available_b;
}





/***********************************************************************************************************************
 Function name    : Dcm_Prv_ValidateCopyTxDataType
 Syntax           : Dcm_Prv_ValidateCopyTxDataType(DcmTxPduId,&PduInfoPtr,&RetryInfoPtr)
 Description      : This Function is used to update the Dcm_PduInfo_pst Structure based on following type of Responses
                    1)Normal Response
                    2)Paged Buffer Response
                    3)RoE Type 2 Response
                    4)NRC21 response
 Parameter        : PduIdType,const PduInfoType*,const RetryInfoType*
 Return value     : BufReq_ReturnType
***********************************************************************************************************************/
static FUNC(BufReq_ReturnType,DCM_CODE) Dcm_Prv_ValidateCopyTxDataType (VAR(PduIdType, AUTOMATIC) DcmTxPduId,
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
        P2CONST(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) RetryInfoPtr)
{
    VAR(BufReq_ReturnType,AUTOMATIC) bufRequestStatus_en = BUFREQ_E_NOT_OK;
    VAR(uint16,AUTOMATIC) serviceId_u16 = 0u;

    if(FALSE != Dcm_Prv_isNormalResponseAvailable(DcmTxPduId))
    {
        Dcm_PduInfo_pst = &Dcm_DsldPduInfo_st;
        bufRequestStatus_en = BUFREQ_OK;
    }
#if(DCM_PAGEDBUFFER_ENABLED != DCM_CFG_OFF)
    else if(FALSE != Dcm_Prv_isPagedBufferResponseAvailable(DcmTxPduId))
    {
        bufRequestStatus_en = Dcm_Prv_ProcessPagedBufferResponse(PduInfoPtr,RetryInfoPtr);
    }
#endif
#if(DCM_CFG_ROETYPE2_ENABLED != DCM_CFG_OFF)
    else if(FALSE != Dcm_Prv_isRoeType2ResponseAvailable(DcmTxPduId))
    {
        Dcm_PduInfo_pst = &Dcm_DsldRoe2PduInfo_st;
        bufRequestStatus_en = BUFREQ_OK;
    }
#endif
    else
    {
        if(FALSE !=  Dcm_Prv_isNrc21ResponseAvailable(&serviceId_u16,DcmTxPduId))
        {
            Dcm_isNrc21responseSet_b = TRUE;
            bufRequestStatus_en = BUFREQ_OK;

            Dcm_PduInfo_pst->SduLength = DCM_NEGATIVE_RESPONSE_LENGTH;

            *(Dcm_PduInfo_pst->SduDataPtr) = DCM_NEGRESPONSE_INDICATOR;

            *(Dcm_PduInfo_pst->SduDataPtr + 1u) = (uint8)serviceId_u16;

            *(Dcm_PduInfo_pst->SduDataPtr + 2u) = DCM_E_BUSYREPEATREQUEST;
        }
    }

#if(DCM_PAGEDBUFFER_ENABLED == DCM_CFG_OFF)
    (void)PduInfoPtr;
    (void)RetryInfoPtr;
#endif

    return bufRequestStatus_en;
}




/***********************************************************************************************************************
 Function name    : Dcm_CopyTxData_CheckEnvironment
 Syntax           : Dcm_CopyTxData_CheckEnvironment(DcmTxPduId,&PduInfoPtr)
 Description      : This Function is used to validate all parameter passed to API Dcm_CopyTxData from Lower layer
 Parameter        : PduIdType,const PduInfoType*
 Return value     : boolean
***********************************************************************************************************************/
static FUNC(boolean,DCM_CODE) Dcm_CopyTxData_CheckEnvironment (VAR(PduIdType, AUTOMATIC) DcmTxPduId,
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr)
{

    VAR(boolean, AUTOMATIC) environmentStatus_b = FALSE;

    if(PduInfoPtr == NULL_PTR)
    {
        DCM_DET_ERROR(DCM_COPYTXDATA_ID , DCM_E_PARAM_POINTER )
    }
    else if((PduInfoPtr->SduDataPtr == NULL_PTR) && (PduInfoPtr->SduLength != 0u))
    {
        DCM_DET_ERROR(DCM_COPYTXDATA_ID , DCM_E_PARAM_POINTER )
    }
    else if( DcmTxPduId >= DCM_NUM_TX_PDUID )
    {
        DCM_DET_ERROR(DCM_COPYTXDATA_ID ,DCM_E_DCMTXPDUID_RANGE_EXCEED)
    }
    else
    {
        environmentStatus_b = TRUE;
    }
    return environmentStatus_b;
}




/*********************************************************************************************************************
 * Dcm_CopyTxData : This call-back function is invoked by medium specific TP (CanTp/FrTp) via PduR to inform the
 * Dcm once upon reception of each segment. Within this call, the received data is copied from the receive TP buffer
 * to the DCM receive buffer.
 *
 * \param           id   : Address of global variable Passed by the appl
 *                  info :
 *                  retry:
 *                  availableDataPtr :
 *
 * \retval          BufReq_ReturnType:
 *
 *
 *
 * \seealso
 * \usedresources
 *********************************************************************************************************************/
/*TRACE[SWS_Dcm_00092][SWS_Dcm_00832]*/
FUNC(BufReq_ReturnType,DCM_CODE) Dcm_CopyTxData (VAR(PduIdType, AUTOMATIC) id,
   /*MR12 RULE 8.13 VIOLATION:The object addressed by the pointer parameter 'retry' is not made constant since it is mentioned in the SWS*/
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,P2VAR(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) availableDataPtr )
{
    VAR(BufReq_ReturnType,AUTOMATIC) bufRequestStatus_en = BUFREQ_E_NOT_OK;

    if(FALSE != Dcm_CopyTxData_CheckEnvironment(id,info))
    {
        bufRequestStatus_en = Dcm_Prv_ValidateCopyTxDataType(id,info,retry);

        if((BUFREQ_OK == bufRequestStatus_en) && (Dcm_PduInfo_pst != NULL_PTR))
        {
            if (info->SduLength == 0u)
            {
                *(availableDataPtr ) = Dcm_PduInfo_pst->SduLength;
            }
            else
            {
                if(FALSE != Dcm_Prv_isRetryRequested(retry,info,&bufRequestStatus_en))
                {
                    Dcm_PduInfo_pst->SduDataPtr = Dcm_PduInfo_pst->SduDataPtr - retry->TxTpDataCnt;
                    Dcm_PduInfo_pst->SduLength  = Dcm_PduInfo_pst->SduLength  + retry->TxTpDataCnt;
                }

                /* If the requested Tx buffer is less than the available Tx buffer, copy the data */
                if((info->SduLength <= Dcm_PduInfo_pst->SduLength) && (BUFREQ_OK == bufRequestStatus_en))
                {
                    /*TRACE[SWS_Dcm_00346]*/
                    /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as
                      input and object type pointer is converted to void pointer*/
                    DCM_MEMCOPY(info->SduDataPtr, Dcm_PduInfo_pst->SduDataPtr, info->SduLength);

                    Dcm_PduInfo_pst->SduDataPtr = Dcm_PduInfo_pst->SduDataPtr + info->SduLength;

                    Dcm_PduInfo_pst->SduLength = (uint16)((uint16)Dcm_PduInfo_pst->SduLength - \
                            (uint16)((FALSE != Dcm_isNrc21responseSet_b) ? 0u : info->SduLength));

                    /*TRACE[SWS_Dcm_00350]*/
                    *(availableDataPtr ) = Dcm_PduInfo_pst->SduLength;
                }
            }
        }
    }
    return(bufRequestStatus_en);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
