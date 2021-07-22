

#include "DcmCore_DslDsd_Inf.h"
#include "DcmCore_DslDsd_Prot.h"

/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_Cfg_MemMap.h"



/***********************************************************************************************************************
 Function name    : Dcm_Prv_isFunctionalTesterPresentReceived
 Syntax           : Dcm_Prv_isFunctionalTesterPresentReceived(DcmRxPduId)
 Description      : This Inline funtion is used to check whether Functional Tester present request has arrived
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
/*TRACE[SWS_Dcm_01168]*/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isFunctionalTesterPresentReceived(VAR(PduIdType, AUTOMATIC) DcmRxPduId)
{
    return ((Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslFuncTesterPresent_b) && \
            !(Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b));
}




/***********************************************************************************************************************
 Function name    : Dcm_Prv_isValidRequestReceived
 Syntax           : Dcm_Prv_isValidRequestReceived(DcmRxPduId)
 Description      : This Inline funtion is used to check whether a valid request is received and to be processed by DSP
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isValidRequestReceived(VAR(PduIdType, AUTOMATIC) DcmRxPduId)
{
    return(Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b);
}





/***********************************************************************************************************************
 Function name    : Dcm_Prv_isLowPriorityRequestReceived
 Syntax           : Dcm_Prv_isLowPriorityRequestReceived(DcmRxPduId)
 Description      : This Inline Function is used to check whether Low priority request has arrived
 Parameter        : PduIdType
 Return value     : boolean
***********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean,DCM_CODE) Dcm_Prv_isLowPriorityRequestReceived(VAR(PduIdType, AUTOMATIC) DcmRxPduId)
{
  return((Dcm_DsldProtocol_pcst[(Dcm_DsldConnTable_pcst[Dcm_DsldRxTable_pcu8[DcmRxPduId]].protocol_num_u8)].nrc21_b)&& \
            (DCM_CHKFULLCOMM_MODE(Dcm_DsldConnTable_pcst[Dcm_DsldRxTable_pcu8[DcmRxPduId]].channel_idx_u8)));
}





/***********************************************************************************************************************
 Function name    : Dcm_Prv_CopyDataToRxBuffer
 Syntax           : Dcm_Prv_CopyDataToRxBuffer(DcmRxPduId,&PduInfoPtr,&RxBufferSizePtr)
 Description      : This function is used to perform actual copy operation.
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : None
***********************************************************************************************************************/
/*TRACE[SWS_Dcm_00443]*/
static FUNC(void,DCM_CODE)Dcm_Prv_CopyDataToRxBuffer(VAR(PduIdType, AUTOMATIC) DcmRxPduId,
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
        P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr)
{
    /*MR12 DIR 1.1 VIOLATION:This is required for implememtaion as DCM_MEMCOPY takes void pointer as input and object
     * type pointer is converted to void pointer*/
    DCM_MEMCOPY(Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr,PduInfoPtr->SduDataPtr,
            PduInfoPtr->SduLength);

    Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduDataPtr += PduInfoPtr->SduLength;
    Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength  -= PduInfoPtr->SduLength;

#if(DCM_CALLAPPLICATIONONREQRX_ENABLED!=DCM_CFG_OFF)
    #if(DCM_BUFQUEUE_ENABLED !=DCM_CFG_OFF)
        if(Dcm_QueueStructure_st.Dcm_QueHandling_en == DCM_QUEUE_IDLE)
    #endif
        {
            (void)DcmAppl_CopyRxData(DcmRxPduId,PduInfoPtr->SduLength);
        }
#endif

   *(RxBufferSizePtr) = Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength;
}






/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProvideRxBufferSize
 Syntax           : Dcm_Prv_ProvideRxBufferSize(DcmRxPduId,&RxBufferSizePtr)
 Description      : This function is used to Provide available Rx buffer size
 Parameter        : PduIdType, PduLengthType*
 Return value     : none
***********************************************************************************************************************/
static FUNC(void,DCM_CODE)Dcm_Prv_ProvideRxBufferSize(VAR(PduIdType, AUTOMATIC) DcmRxPduId,
        P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr)
{
    VAR(uint8,AUTOMATIC) idxProtocol_u8  = Dcm_DsldConnTable_pcst[Dcm_DsldRxTable_pcu8[DcmRxPduId]].protocol_num_u8;

    if (FALSE !=  Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslCopyRxData_b)
    {
       /*Dcm needs to update to the underlying TP on the no. of remaining bytes left */
       *(RxBufferSizePtr) = Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslRxPduBuffer_st.SduLength;
    }
    else
    {
       /* Simulating reception without copying, thus update to TP that Buffer is available for any length.
          The available Rx buffer is updated in this case. */
       *(RxBufferSizePtr) = (PduLengthType)(Dcm_DsldProtocol_pcst[idxProtocol_u8].rx_buffer_size_u32);
    }
}






/***********************************************************************************************************************
 Function name    : Dcm_Prv_ProcessCopyRxData
 Syntax           : Dcm_Prv_ProcessCopyRxData(DcmRxPduId,&PduInfoPtr,&RxBufferSizePtr)
 Description      : This API is used to process request copy operation
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : BufReq_ReturnType
***********************************************************************************************************************/
static FUNC(BufReq_ReturnType,DCM_CODE)Dcm_Prv_ProcessCopyRxData(VAR(PduIdType, AUTOMATIC) DcmRxPduId,
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
        P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr)
{
    VAR(BufReq_ReturnType,AUTOMATIC) bufRequestStatus_en = BUFREQ_E_NOT_OK;

    if (FALSE != Dcm_Prv_isValidRequestReceived(DcmRxPduId))
    {
        Dcm_Prv_CopyDataToRxBuffer(DcmRxPduId,PduInfoPtr,RxBufferSizePtr);
        bufRequestStatus_en = BUFREQ_OK;
    }
    else
    {
        if(FALSE != Dcm_Prv_isLowPriorityRequestReceived(DcmRxPduId))
        {
            /*Save ServiceId For NRC21 Handling In TxTpConfirmation*/
            SchM_Enter_Dcm_Global_NoNest();
            if (Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8 == DCM_SERVICEID_DEFAULT_VALUE)
            {
                Dcm_DslRxPduArray_ast[DcmRxPduId].Dcm_DslServiceId_u8 = (uint8)PduInfoPtr->SduDataPtr[0];
            }
            SchM_Exit_Dcm_Global_NoNest();

            bufRequestStatus_en = BUFREQ_OK;
        }
    }

    return bufRequestStatus_en;
}





/***********************************************************************************************************************
 Function name    : Dcm_Prv_CopyRxData_CheckEnvironment
 Syntax           : Dcm_Prv_CopyRxData_CheckEnvironment(DcmRxPduId,&PduInfoPtr,&RxBufferSizePtr)
 Description      : This API is used to validate all parameters passed to Dcm_CopyRxData
 Parameter        : PduIdType,const PduInfoType*, const PduLengthType*
 Return value     : boolean
***********************************************************************************************************************/
static FUNC(boolean,DCM_CODE) Dcm_Prv_CopyRxData_CheckEnvironment(VAR(PduIdType, AUTOMATIC) DcmRxPduId,
        P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
        P2CONST(PduLengthType, AUTOMATIC, DCM_APPL_DATA) RxBufferSizePtr)
{
    VAR(boolean,AUTOMATIC) environmentStatus_b = FALSE;

    if (DcmRxPduId >= DCM_CFG_NUM_RX_PDUID)
    {
        DCM_DET_ERROR(DCM_COPYRXDATA_ID , DCM_E_DCMRXPDUID_RANGE_EXCEED)
    }
    else if ((PduInfoPtr == NULL_PTR) || (RxBufferSizePtr == NULL_PTR))
    {
        DCM_DET_ERROR(DCM_COPYRXDATA_ID , DCM_E_PARAM_POINTER)
    }
    else if( (PduInfoPtr->SduLength != 0u) && (PduInfoPtr->SduDataPtr == NULL_PTR))
    {
        DCM_DET_ERROR(DCM_COPYRXDATA_ID , DCM_E_PARAM_POINTER)
    }
    else
    {
        environmentStatus_b = TRUE;
    }

    return environmentStatus_b;
}





/***********************************************************************************************************************
 Function name    : Dcm_CopyRxData
 Syntax           : Dcm_CopyRxData(id,&PduInfoPtr,&bufferSizePtr)
 Description      : This Call back API is invoked by the lower layer to copy the request in DCM
 Parameter        : PduIdType,const PduInfoType*, PduLengthType*
 Return value     : BufReq_ReturnType
***********************************************************************************************************************/
/*TRACE[SWS_Dcm_00556][SWS_Dcm_00831]*/
FUNC(BufReq_ReturnType,DCM_CODE) Dcm_CopyRxData( VAR(PduIdType, AUTOMATIC) id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr)
{
    VAR(BufReq_ReturnType,AUTOMATIC) bufRequestStatus_en = BUFREQ_E_NOT_OK;

    if(FALSE != Dcm_Prv_CopyRxData_CheckEnvironment(id,PduInfoPtr,bufferSizePtr))
    {
/*TRACE[BSW_SWS_AR4_2_R2_DiagnosticCommunicationManager_Ext-2858]*/
#if(DCM_CFG_RXPDU_SHARING_ENABLED != DCM_CFG_OFF)
        if ((NULL_PTR != PduInfoPtr->SduDataPtr) && (FALSE != Dcm_isObdRequestReceived_b))
        {
            if(FALSE != Dcm_Prv_isRxPduShared(id,PduInfoPtr->SduDataPtr[0]))
            {
                id = (DCM_CFG_NUM_RX_PDUID-1u);
            }
        }
#endif

        /*TRACE[SWS_Dcm_00996]*/
        if(PduInfoPtr->SduLength == 0u)
        {
            Dcm_Prv_ProvideRxBufferSize(id,bufferSizePtr);
            bufRequestStatus_en = BUFREQ_OK;
        }
        else if(FALSE != Dcm_Prv_isFunctionalTesterPresentReceived(id))
        {
            bufRequestStatus_en = BUFREQ_OK;
        }
        else
        {
            /*Accept the request if Data to be copied is less than the buffer size available OR Low priority
              Request has arrived*/
            if((PduInfoPtr->SduLength <= Dcm_DslRxPduArray_ast[id].Dcm_DslRxPduBuffer_st.SduLength) || \
                    (FALSE != Dcm_Prv_isLowPriorityRequestReceived(id)))
            {
                bufRequestStatus_en = Dcm_Prv_ProcessCopyRxData(id,PduInfoPtr,bufferSizePtr);
            }
            else
            {
                DCM_DET_ERROR(DCM_COPYRXDATA_ID , DCM_E_INTERFACE_BUFFER_OVERFLOW )
            }
        }
    }
    return (bufRequestStatus_en);
}

#define DCM_STOP_SEC_CODE
#include "Dcm_Cfg_MemMap.h"
