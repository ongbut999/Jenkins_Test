

#ifndef DCMCORE_DSLDSD_INL_H
#define DCMCORE_DSLDSD_INL_H

/**************************************************************************************************/
/* Included  header files                                                                         */
/**************************************************************************************************/


/**
 **************************************************************************************************
 * Dcm_Prv_ReloadS3Timer :  Inline function to start P3 timer monitoring
 *
 * \param           None
 *
 *
 * \retval          None
 * \seealso
 * \usedresources
 **************************************************************************************************
 */


LOCAL_INLINE FUNC(void, DCM_CODE) Dcm_Prv_ReloadS3Timer (void);
LOCAL_INLINE FUNC(void, DCM_CODE) Dcm_Prv_ReloadS3Timer (void)
{

#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)

    if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
    {
        /* if KWP is running protocol start P3 timer */

        DCM_TimerStart(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32, Dcm_DsldTimer_st.dataTimeoutP3max_u32,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
    }
    else
    {
        /* if UDS is running protocol start S3 timer */

        DCM_TimerStart(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32, DCM_CFG_S3MAX_TIME,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
    }
#else
    /* if UDS is running protocol start S3 timer */

    DCM_TimerStart(Dcm_DsldGlobal_st.dataTimeoutMonitor_u32, DCM_CFG_S3MAX_TIME,Dcm_P2OrS3StartTick_u32,Dcm_P2OrS3TimerStatus_uchr)
#endif
}

/**
 **************************************************************************************************
 * Dcm_StartProtocol : Function to call all RTE configured functions.
 *
 * \param           ProtocolID: protocol id
 *
 *
 * \retval          Std_ReturnType (E_OK,E_NOT_OK,DCM_E_PROTOCOL_NOT_ALLOWED)
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

LOCAL_INLINE FUNC(Std_ReturnType,DCM_CODE) Dcm_StartProtocol(VAR(Dcm_ProtocolType,AUTOMATIC) ProtocolID);
LOCAL_INLINE FUNC(void,DCM_CODE) Dcm_StopProtocol(VAR(Dcm_ProtocolType,AUTOMATIC) ProtocolID);

LOCAL_INLINE  FUNC(Std_ReturnType,DCM_CODE) Dcm_StartProtocol(VAR(Dcm_ProtocolType,AUTOMATIC) ProtocolID)
{
#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS !=0))
    VAR(uint32_least,AUTOMATIC) idxIndex_qu32;
#endif
    VAR(Std_ReturnType,AUTOMATIC) dataReturnType_u8;

    /* Call DcmAppl function to start the protocol */
    dataReturnType_u8 = DcmAppl_DcmStartProtocol(ProtocolID);

#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS !=0))
    if(dataReturnType_u8 == E_OK)
    {
        /* Call all configured functions in RTE */
        for(idxIndex_qu32 = 0x00 ; idxIndex_qu32<Rte_NPorts_CallbackDCMRequestServices_R() ; idxIndex_qu32++)
        {
            dataReturnType_u8 =((Rte_Ports_CallbackDCMRequestServices_R())[idxIndex_qu32].Call_StartProtocol)(ProtocolID);

            if(Dcm_IsInfrastructureErrorPresent_b(dataReturnType_u8) != FALSE )
            {
                dataReturnType_u8 = DCM_INFRASTRUCTURE_ERROR;

            }
            else if((dataReturnType_u8 == DCM_E_PROTOCOL_NOT_ALLOWED) || (dataReturnType_u8 == E_NOT_OK))
            {
                /* Do nothing */
            }
            else
            {
                dataReturnType_u8 = E_OK;
            }
            if(dataReturnType_u8 != E_OK)
            {
                break;
            }
        }
    }
#endif
    return(dataReturnType_u8);
}

/**
 **************************************************************************************************
 * Dcm_StopProtocol : Function to call all RTE configured functions.
 *
 * \param           ProtocolID: protocol id
 *
 *
 * \retval          void
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

LOCAL_INLINE  FUNC(void,DCM_CODE) Dcm_StopProtocol(VAR(Dcm_ProtocolType,AUTOMATIC) ProtocolID)
{
#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS !=0))
    VAR(uint32_least,AUTOMATIC) idxIndex_qu32;
#endif

    /* Call DcmAppl function to stop the protocol */
    (void)DcmAppl_DcmStopProtocol(ProtocolID);

#if((DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_CALL_BACK_NUM_PORTS!=0))
    /* Call all configured functions in RTE */
    for(idxIndex_qu32 =0x00 ; idxIndex_qu32<Rte_NPorts_CallbackDCMRequestServices_R() ; idxIndex_qu32++)
    {
        (void)((Rte_Ports_CallbackDCMRequestServices_R())[idxIndex_qu32].Call_StopProtocol)(ProtocolID);
    }
#endif
}

/**
 **************************************************************************************************
 * Dcm_SesCtrlChangeIndication : Function to call all RTE configured functions.
 *
 * \param           dataSesCtrlTypeOld_u8: Old  session
 *                  dataSesCtrlTypeNew_u8: Changed session
 *
 * \retval          Std_ReturnType (but ignored)
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

LOCAL_INLINE FUNC(Std_ReturnType,DCM_CODE) Dcm_SesCtrlChangeIndication(
        VAR(Dcm_SesCtrlType,AUTOMATIC) dataSesCtrlTypeOld_u8,
        VAR(Dcm_SesCtrlType,AUTOMATIC) dataSesCtrlTypeNew_u8
);

LOCAL_INLINE FUNC(Std_ReturnType,DCM_CODE) Dcm_SesCtrlChangeIndication(
        VAR(Dcm_SesCtrlType,AUTOMATIC) dataSesCtrlTypeOld_u8,
        VAR(Dcm_SesCtrlType,AUTOMATIC) dataSesCtrlTypeNew_u8
)
{

    /* Call DcmAppl function to indicate the session change */
    DcmAppl_DcmSesCtrlChangeIndication(dataSesCtrlTypeOld_u8,dataSesCtrlTypeNew_u8);
    return(E_OK);
}


/**
 **************************************************************************************************
 * Dcm_ConfirmationRespPend: Function to call all RTE configured functions on reception of a forced response pend.
 *
 * \param           status: ConfirmationStatus of the forced resp pend
 *
 * \retval          Std_ReturnType
 * \seealso
 * \usedresources
 **************************************************************************************************
 */

LOCAL_INLINE FUNC(Std_ReturnType,DCM_CODE) Dcm_ConfirmationRespPend(
        VAR(Dcm_ConfirmationStatusType,AUTOMATIC) status
);
LOCAL_INLINE FUNC(Std_ReturnType,DCM_CODE) Dcm_ConfirmationRespPend(
        VAR(Dcm_ConfirmationStatusType,AUTOMATIC) status
)
{

    /* Call DcmAppl function for response pend */
    DcmAppl_ConfirmationRespPend(status);
    return(E_OK);
}

#endif   /* for _DCMCORE_DSLDSD_INL_H */

