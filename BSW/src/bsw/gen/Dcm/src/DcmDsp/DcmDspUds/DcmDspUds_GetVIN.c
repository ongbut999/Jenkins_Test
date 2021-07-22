

#include "DcmDspUds_Uds_Inf.h"

#if((DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF) && (DCM_CFG_DIDSUPPORT != DCM_CFG_OFF))

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint8,DCM_VAR) Dcm_VInData_au8[DCM_VIN_DATALEN] = {0};  /*Buffer to store VIN data*/
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
boolean Dcm_VinReceived_b = FALSE; /*Flag to indicate VIN data is received successfully or not */
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static Dcm_DIDIndexType_tst s_Dcm_idxRdbiDidIndexType_st; /*Store the index of DID of either Dcm_DidConfig or Dcm_DIDRangeCOnfig structure*/
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
#define DCM_START_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static boolean s_VIN_DcmReadDataConditionsRteCallPlaced_b;
#define DCM_STOP_SEC_VAR_CLEARED_BOOLEAN /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 **********************************************************************************************************************
 * Dcm_GetVin :
 *  This function is called by DOIP for reading the VIN DID.
 *
 * \param           : *Data - pointer to the target buffer(17 bytes) provided by DOIP
 * \return          : Std_ReturnType
 * \retval          : E_OK - if the VIN DID is read successfully
 * 					  E_NOT_OK - if the VIN DID is not read successfully
 * \seealso
 * \usedresources
 **********************************************************************************************************************
 */

FUNC (Std_ReturnType,DCM_CODE) Dcm_GetVin (P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data)
{
    Std_ReturnType dataStatusReturn_u8 = E_NOT_OK;
    uint8 indexVinBuff = 0;
    /* Check if VIN data is available or Application buffer is available */
    if((Dcm_VinReceived_b != FALSE) && (Data != NULL_PTR))
    {

        /* Store VIN DID in application Buffer  */
       for(indexVinBuff = 0;indexVinBuff < DCM_VIN_DATALEN ;indexVinBuff++)
       {
          *(Data) = Dcm_VInData_au8[indexVinBuff];
		  Data++;
       }

       if(indexVinBuff == DCM_VIN_DATALEN)
       {
         /*17 bytes data is copied into Application buffer*/
           dataStatusReturn_u8 = E_OK;
       }
    }
    return dataStatusReturn_u8;
}

/**
 **********************************************************************************************************************
 * Dcm_VinBuffer_Init :
 *  This function is called by Dcm_MainFunction for reading the VIN DID data during start up .
 *  if VIN DID data is read successfully , it is stored in Dcm_VInData_au8[]
 *

 * \return          : Std_ReturnType
 * \retval          : E_OK - if the VIN DID is read successfully
 *                    E_NOT_OK - if the VIN DID is not read successfully
 *                    DCM_E_PENDING - More time is required to read the data\n
 * \seealso
 * \usedresources
 **********************************************************************************************************************
 */
FUNC(Std_ReturnType ,DCM_CODE) Dcm_VinBuffer_Init(void)
{

    Std_ReturnType dataStatusReturn_u8;/* variable to hold the return value */
    Dcm_DIDIndexType_tst idxVinDidIndexType_st; /* structure for DID index */
    Std_ReturnType dataCondChkRetVal_u8; /* Return value of Condition check API */
    uint16 idxVinDidSignal_u16; /* Signal index for the VIN DID */
    Dcm_NegativeResponseCodeType dataNegRespCode_u8; /* variable for Negative response value */
    const Dcm_DIDConfig_tst *ptrDidConfig;
    const Dcm_DataInfoConfig_tst *ptrSigConfig;
    const Dcm_SignalDIDSubStructConfig_tst *ptrControlSigConfig;
    idxVinDidSignal_u16=0;
    dataCondChkRetVal_u8 = E_OK; /* Initialize to E_OK */
    /* Call the API to get the index of the requested VIN DID */
    dataStatusReturn_u8 = Dcm_GetIndexOfDID(DCM_CFG_VIN_DID,&idxVinDidIndexType_st);
    ptrDidConfig = &Dcm_DIDConfig[idxVinDidIndexType_st.idxIndex_u16];
    /* Initialization of the variables */
    dataNegRespCode_u8=0;
#if(DCM_CFG_DSP_NUMISDIDAVAIL>0)
    /* Check if the DID is supported in current variant */
    /*If data range of Did is a range did or not and supported in the current variant*/
    if((idxVinDidIndexType_st.dataRange_b ==FALSE) && (*Dcm_DIDIsAvail[ptrDidConfig->idxDIDSupportedFnc_u16] != NULL_PTR))
    {
        if((*(IsDIDAvailFnc_pf)(Dcm_DIDIsAvail[ptrDidConfig->idxDIDSupportedFnc_u16]))(DCM_CFG_VIN_DID)!=E_OK)
        {
            dataStatusReturn_u8 = E_NOT_OK;
        }
    }
#endif
    /* Call the Dcm_GetDIDData() API to read the VIN DID */
    /* If the return value is E_OK */
    if(dataStatusReturn_u8 == E_OK)
    {
        for(idxVinDidSignal_u16=0;((idxVinDidSignal_u16<ptrDidConfig->nrSig_u16)&&(dataNegRespCode_u8==0x0)&&(dataCondChkRetVal_u8==E_OK));idxVinDidSignal_u16++)
        {
            ptrSigConfig = &Dcm_DspDataInfo_st[ptrDidConfig->adrDidSignalConfig_pcst[idxVinDidSignal_u16].idxDcmDspDatainfo_u16];
            ptrControlSigConfig = &Dcm_DspDid_ControlInfo_st[ptrSigConfig->idxDcmDspControlInfo_u16];
            if((ptrSigConfig->adrReadFnc_cpv)!= NULL_PTR)
            {
                if(ptrControlSigConfig->adrCondChkRdFnc_cpv!= NULL_PTR)
                {
                    if((ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_FNC) ||
                            (ptrSigConfig->usePort_u8 == USE_DATA_SYNCH_CLIENT_SERVER))
                    {
                        /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                         * Required for efficient RAM usage by using single void function pointer */

                        dataCondChkRetVal_u8 = (*(CondChkReadFunc1_pfct)(ptrControlSigConfig->adrCondChkRdFnc_cpv))(&dataNegRespCode_u8);
                    }
                    else
                    {
                        if((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_FNC) ||
#if(DCM_CFG_RDBIPAGEDBUFFERSUPPORT != DCM_CFG_OFF)
                                (ptrSigConfig->usePort_u8 == USE_DATA_RDBI_PAGED_FNC) ||
#endif
                                (ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER))
                        {
#if (DCM_CFG_DSP_READ_ASP_ENABLED != DCM_CFG_OFF)
                            if((ptrSigConfig->usePort_u8 == USE_DATA_ASYNCH_CLIENT_SERVER) && (ptrSigConfig->UseAsynchronousServerCallPoint_b))
                            {
                                if(!s_VIN_DcmReadDataConditionsRteCallPlaced_b)
                                {
                                    dataCondChkRetVal_u8 = (*(CondChkReadFunc3_pfct)(ptrControlSigConfig->adrCondChkRdFnc_cpv))(s_Dcm_idxRdbiDidIndexType_st.dataopstatus_b);
                                    if(dataCondChkRetVal_u8 == E_OK)
                                    {
                                        s_VIN_DcmReadDataConditionsRteCallPlaced_b = TRUE;
                                        dataCondChkRetVal_u8 = DCM_E_PENDING;
                                    }
                                }
                                else
                                {
                                    dataCondChkRetVal_u8 = (*(CondChkReadFunc1_pfct)(ptrControlSigConfig->adrCondChkRdFncResults_cpv))(&dataNegRespCode_u8);
                                    if(dataCondChkRetVal_u8 == RTE_E_NO_DATA)
                                    {
                                        dataCondChkRetVal_u8 = DCM_E_PENDING;
                                    }
                                    else
                                    {
                                        s_VIN_DcmReadDataConditionsRteCallPlaced_b = FALSE;
                                    }
                                }
                            }
                            else
#endif
                            {
                                /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation -
                                 * Required for efficient RAM usage by using single void function pointer */
                                dataCondChkRetVal_u8 = (*(CondChkReadFunc2_pfct)(ptrControlSigConfig->adrCondChkRdFnc_cpv))(s_Dcm_idxRdbiDidIndexType_st.dataopstatus_b, &dataNegRespCode_u8);
                            }
                        }
                    }
                }
            }
        }
        if(dataCondChkRetVal_u8==DCM_E_PENDING)
        {
            dataStatusReturn_u8=DCM_E_PENDING;
            s_Dcm_idxRdbiDidIndexType_st.dataopstatus_b=DCM_PENDING;
        }

        else if(dataCondChkRetVal_u8==E_OK)
        {
            s_Dcm_idxRdbiDidIndexType_st.dataopstatus_b=DCM_INITIAL;
            dataStatusReturn_u8=Dcm_GetDIDData(&idxVinDidIndexType_st,&Dcm_VInData_au8[0]);
        }
        else
        {
            dataStatusReturn_u8=E_NOT_OK;
        }
        if(dataStatusReturn_u8 == E_OK)
        {
            /*Set flag is true as VIN data is read successfully*/
            Dcm_VinReceived_b = TRUE;
        }
    }
    return dataStatusReturn_u8;
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#endif  /* ((DCM_CFG_VIN_SUPPORTED != DCM_CFG_OFF) && (DCM_CFG_DIDSUPPORT != DCM_CFG_OFF)) */
