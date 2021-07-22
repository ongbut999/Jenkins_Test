

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "DcmCore_DslDsd_Inf.h"



/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.h"
static VAR(boolean,DCM_VAR) Dcm_isResetToDefaultRequested_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Dcm_Cfg_MemMap.h"





/***********************************************************************************************************************
 *    Inline Function Definitions
 **********************************************************************************************************************/


#if(DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF)
/***********************************************************************************************************************
 Function name    : Dcm_Prv_ResetRoeEvents
 Syntax           : Dcm_Prv_ResetRoeEvents(void)
 Description      : This Inline function is used to reset Roe Events
 Parameter        : None
 Return value     : None
***********************************************************************************************************************/
LOCAL_INLINE FUNC(void,DCM_CODE) Dcm_Prv_ResetRoeEvents(void)
{
#if(DCM_CFG_DSP_ROEDID_ENABLED != DCM_CFG_OFF)
    Dcm_ResetRoeDidevents();
#endif

#if(DCM_CFG_DSP_ROEONDTCSTATUSCHANGE_ENABLED != DCM_CFG_OFF)
    Dcm_ResetRoeOnDtcevents();
#endif
}
#endif




/***********************************************************************************************************************
 *    Function Definitions
 **********************************************************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_Cfg_MemMap.h"

/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetNonDefaultSesCtrlType
 Syntax           : Dcm_Prv_SetNonDefaultSesCtrlType(CurrentSession_u8,SesCtrlType_u8)
 Description      : This function is used to Set default session control type
 Parameter        : Dcm_SesCtrlType, Dcm_SesCtrlType
 Return value     : None
***********************************************************************************************************************/
static FUNC(boolean,DCM_CODE) Dcm_Prv_SetNonDefaultSesCtrlType (VAR(Dcm_SesCtrlType,AUTOMATIC) CurrentSession_u8,
        VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_u8)
{
    VAR(boolean,AUTOMATIC) isSessionAvailable = FALSE;

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))
    VAR(uint32,AUTOMATIC) sessionMask_u32 = 0u;
#endif

    VAR(uint8,AUTOMATIC) nrSessions_u8 = 0u;
    VAR(uint8,AUTOMATIC) idxIndex_u8   = 0u;

    /* Calculate the number  of sessions configured in ECU for particular protocol*/
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    if(DCM_IS_KWPPROT_ACTIVE() != FALSE)
    {
        nrSessions_u8 = DCM_CFG_NUM_KWP_SESSIONS;
    }
    else
    {
        nrSessions_u8 = DCM_CFG_NUM_UDS_SESSIONS;
    }
#else
    nrSessions_u8 = DCM_CFG_NUM_UDS_SESSIONS;
#endif

    /* get the index of requested session id in session look up table */
    for(idxIndex_u8 = 0x1; idxIndex_u8 < nrSessions_u8 ; idxIndex_u8++)
    {
        if(Dcm_DsldSessionTable_pcu8[idxIndex_u8]== SesCtrlType_u8)
        {
            /* session found */
            break;
        }
    }

    if(idxIndex_u8 != nrSessions_u8)
    {
        isSessionAvailable = TRUE;
        /* set the session index */
        Dcm_DsldGlobal_st.idxActiveSession_u8 = idxIndex_u8;

        if(DCM_IS_KWPPROT_ACTIVE() == FALSE)
        {
            /* lock the ECU in any UDS session transition*/
            Dcm_DsldGlobal_st.idxActiveSecurity_u8 = 0x00u;
        }

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF))
        Dcm_RoutineSetSesCtrlType(SesCtrlType_u8);
#endif


#if(DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_ResetRoeEvents();
#endif

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))
        sessionMask_u32 = Dcm_DsldGetActiveSessionMask_u32();

        /*The below function code will loop through all the IOCBI DIDs and call all the returncontrol to ECU functions
         *  to reset all the  active IOctrls supported in the current session level*/
        Dcm_ResetActiveIoCtrl(sessionMask_u32,0x1u,TRUE);
#endif
    }
    else
    {
        DCM_DET_ERROR(DCM_SETSESSIONLEVEL , DCM_E_SESSION_NOT_CONFIGURED)
    }

    return isSessionAvailable;
}






/***********************************************************************************************************************
 Function name    : Dcm_Prv_SetDefaultSesCtrlType
 Syntax           : Dcm_Prv_SetDefaultSesCtrlType(CurrentSession_u8,SesCtrlType_u8)
 Description      : This function is used to Set default session control type
 Parameter        : Dcm_SesCtrlType, Dcm_SesCtrlType
 Return value     : None
***********************************************************************************************************************/
static FUNC(void,DCM_CODE) Dcm_Prv_SetDefaultSesCtrlType (VAR(Dcm_SesCtrlType,AUTOMATIC) CurrentSession_u8,
        VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_u8)
{
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    VAR(uint8,AUTOMATIC) idxKwpTiming_u8 = 0u;
#endif

    SchM_Enter_Dcm_DsldTimer_NoNest();
#if(DCM_CFG_KWP_ENABLED != DCM_CFG_OFF)
    if(DCM_IS_KWPPROT_ACTIVE() == FALSE)
    {
        /* set the default session time for UDS session change */
        Dcm_DsldTimer_st.dataTimeoutP2max_u32    =  DCM_CFG_DEFAULT_P2MAX_TIME;
        Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 =  DCM_CFG_DEFAULT_P2STARMAX_TIME;
    }
    else
    {
        /* Set the default timings after default session transition */
        idxKwpTiming_u8 = Dcm_DsldProtocol_pcst[Dcm_DsldGlobal_st.idxCurrentProtocol_u8].timings_idx_u8;
        Dcm_DsldTimer_st.dataTimeoutP2max_u32 = Dcm_Dsld_default_timings_acs[idxKwpTiming_u8].P2_max_u32;
        Dcm_DsldTimer_st.dataTimeoutP3max_u32 = Dcm_Dsld_default_timings_acs[idxKwpTiming_u8].P3_max_u32;
        Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 = Dcm_DsldTimer_st.dataTimeoutP3max_u32;
    }
#else
    /* set the default session time for UDS session change */
    Dcm_DsldTimer_st.dataTimeoutP2max_u32    =  DCM_CFG_DEFAULT_P2MAX_TIME;
    Dcm_DsldTimer_st.dataTimeoutP2StrMax_u32 =  DCM_CFG_DEFAULT_P2STARMAX_TIME;
#endif
    SchM_Exit_Dcm_DsldTimer_NoNest();

    /* lock the ECU */
    Dcm_DsldGlobal_st.idxActiveSecurity_u8 = 0x00u;
    /* set the session index */
    Dcm_DsldGlobal_st.idxActiveSession_u8 = 0x00u;

#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_IOCBI_ENABLED != DCM_CFG_OFF))
    /**The code which would loop through all the IOCBI DIDs and call all the returncontrol to ECU functions to reset all the  active IOctrls
       supported in the current session level*/
    Dcm_ResetActiveIoCtrl(0x1,0x1,TRUE);
#endif


    /*Stopping of all the started routines on transition to default session*/
#if((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF))
    Dcm_RoutineSetSesCtrlType(SesCtrlType_u8);
#endif

     /*Check if transition is from NON-Default to Default session*/
    if(CurrentSession_u8 != Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX])
    {
#if (DCM_CFG_RDPI_ENABLED != DCM_CFG_OFF)
        Dcm_DsldResetRDPI();
#endif


#if(DCM_CFG_DSP_RESPONSEONEVENT_ENABLED != DCM_CFG_OFF)
        Dcm_Prv_ResetRoeEvents();
#endif
    }
}


/*
 ***********************************************************************************************************
 *  Dcm_Prv_SetSesCtrlType :To set the new session control type value in DCM
 *  \param   dataSesCtrlType_u8  New session control type value, Content is according to diagnosticSessionType
 *                         parameter of DiagnosticSessionControl request
 *  \retval        None
 *  \seealso
 *
 ***********************************************************************************************************/
/*TRACE[SWS_Dcm_00139]*/
FUNC(void,DCM_CODE) Dcm_Prv_SetSesCtrlType (VAR(Dcm_SesCtrlType, AUTOMATIC) SesCtrlType_u8)
{
    VAR(Dcm_SesCtrlType,AUTOMATIC) currentSession_u8 = 0u;

    if(FALSE != Dcm_isSessionStored_b)
    {
        currentSession_u8 = Dcm_DsldSessionTable_pcu8[Dcm_DsldGlobal_st.PreviousSessionIndex];
        Dcm_isSessionStored_b = FALSE;
    }
    else
    {
        currentSession_u8 = Dcm_DsldSessionTable_pcu8[Dcm_DsldGlobal_st.idxActiveSession_u8];
    }

    if(SesCtrlType_u8 == Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX])
    {
        Dcm_Prv_SetDefaultSesCtrlType(currentSession_u8,SesCtrlType_u8);
    }
    else
    {
        if(FALSE == Dcm_Prv_SetNonDefaultSesCtrlType(currentSession_u8,SesCtrlType_u8))
        {
            /* requested session is not configured in DSC service give indication to Application */
            /* without changing the session.                                              */
            SesCtrlType_u8 = currentSession_u8;
        }
    }

#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF))
    Dcm_Dsp_SecaSessIni();
#endif

#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && (DCM_CFG_DSP_CONTROLDTCSETTING_ENABLED != DCM_CFG_OFF))
    Dcm_ControlDtcSettingExit();
#endif

#if ((DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF) && \
        ((DCM_CFG_DSP_REQUESTUPLOAD_ENABLED != DCM_CFG_OFF)||(DCM_CFG_DSP_REQUESTDOWNLOAD_ENABLED!=DCM_CFG_OFF)))
    Dcm_DspDeactivateRequestUploadDownloadPermission();
#endif

    (void)Dcm_SesCtrlChangeIndication(currentSession_u8, SesCtrlType_u8);
}


/**
 **************************************************************************************************
 * Dcm_GetSesCtrlType : API to get the active session id
 * \param           SesCtrlType
 *
 *
 * \retval          active session id
 * \seealso
 * \usedresources
 **************************************************************************************************
 */
FUNC( Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA)  SesCtrlType)
{
    if(SesCtrlType != NULL_PTR)
    {
        /*Check if the Dcm session flag is set to get the active session id*/
        if(FALSE != Dcm_isSessionStored_b)
        {
            *SesCtrlType = Dcm_DsldSessionTable_pcu8[Dcm_DsldGlobal_st.PreviousSessionIndex];
        }
        else
        {
            *SesCtrlType = Dcm_DsldSessionTable_pcu8[ Dcm_DsldGlobal_st.idxActiveSession_u8];
        }
    }
    else
    {
        /* DET ERROR REPORT */
        DCM_DET_ERROR(DCM_SETSESSION_ID, DCM_E_PARAM_POINTER);
    }

    return(E_OK);
}



/*
**********************************************************************************************************************************
*  Dcm_ResetToDefaultSession: The call to this function allows the application to request for the reset of the current session to Default Session.
*  \param
*  \retval                  : E_OK - The request for resetting the session to default session is accepted.The session transition will be processed in the next Dcm main function
*                             E_NOT_OK - If Dcm is not free and processing some other request.The application has to call the service again in this case to Reset the session to Default
*  \seealso
**********************************************************************************************************************************/
/*TRACE[SWS_Dcm_01062]*/
FUNC(Std_ReturnType,DCM_CODE) Dcm_ResetToDefaultSession(void)
{
   /* Set the variable to TRUE to process the request in the next Dcm main function
    * to avoid long runtime in an interrupt context */
   Dcm_isResetToDefaultRequested_b = TRUE;
   return (E_OK);
}




/*
***********************************************************************************************************
*  Dcm_Prv_ProcessResetToDefaultSession: The call to this process request to Reset To Default Session (done from
*  Main function context)
*  \param
*  \retval                  : void
*  \seealso
***********************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_Prv_ProcessResetToDefaultSession(void)
{
   if(FALSE != Dcm_isResetToDefaultRequested_b)
   {
       Dcm_Prv_SetSesCtrlType(Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX]);

#if (DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)
       #if(DCM_CFG_DSP_DIAGNOSTICSESSIONCONTROL_ENABLED!=DCM_CFG_OFF)

           #if(DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
               (void)SchM_Switch_Dcm_DcmDiagnosticSessionControl(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION);
           #endif

           (void)DcmAppl_Switch_DcmDiagnosticSessionControl(Dcm_DsldSessionTable_pcu8[DCM_DEFAULT_SESSION_IDX]);
       #endif
#endif
       Dcm_isResetToDefaultRequested_b = FALSE;
   }
}



/*
***********************************************************************************************************
*  Dcm_Prv_ResetDefaultSessionRequestFlag: The API called to reset the flag indicating a RTD request
*  Main function context)
*  \param
*  \retval                  : void
*  \seealso
***********************************************************************************************************/
FUNC(void, DCM_CODE) Dcm_Prv_ResetDefaultSessionRequestFlag(void)
{
   Dcm_isResetToDefaultRequested_b = FALSE;
}



#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
