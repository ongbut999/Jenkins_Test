

#include "Dcm.h"
#include "Rte_Dcm.h"

#include "DcmDspUds_Uds_Prot.h"

#include "SchM_Dcm.h"


#include "ComM_Dcm.h"

#include "DcmDspUds_Rc_Prot.h"


#include "DcmDspUds_Rdtc_Priv.h"

#include "DcmDspUds_Er_Prot.h"



#include "DcmDspUds_Cdtcs_Prot.h"



#include "DcmAppl.h"

#include "DcmCore_DslDsd_Prot.h"




/**
 ***************************************************************************************************
            Session Control (DSC) Service
 ***************************************************************************************************
*/
/* Initialization of the parameters for the supported sessions */
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_Dsp_Session_t, DCM_CONST) Dcm_Dsp_Session[DCM_CFG_DSP_NUMSESSIONS] =
{

   /* session configuration for DEFAULT_SESSION*/
   {
		50000,				/* P2 Max time in us */
		5000000,				/* P2* Max time in us */
		0x1,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_NO_BOOT			/* Diagnostic session used for jump to Bootloader */
	},

   /* session configuration for PROGRAMMING_SESSION*/
   {
		50000,				/* P2 Max time in us */
		5000000,				/* P2* Max time in us */
		0x2,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_OEM_BOOT			/* Diagnostic session used for jump to Bootloader */
	},

   /* session configuration for EXTENDED_DIAGNOSTIC_SESSION*/
   {
		50000,				/* P2 Max time in us */
		5000000,				/* P2* Max time in us */
		0x3,				/* Session ID */
		RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION, /* DcmDiagnosticSessionControl Mode  for the Session Level */
		DCM_NO_BOOT			/* Diagnostic session used for jump to Bootloader */
	}
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



/**
 ***************************************************************************************************
            Security Access (SECA) Service
 ***************************************************************************************************
*/
/* Initialization of the parameters for the supported security */
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_Dsp_Security_t, DCM_CONST) Dcm_Dsp_Security[DCM_CFG_DSP_NUMSECURITY] =
{
   /* security configuration for DSP_SEC_LEV_L1*/
   {
   
		10000,			/* Delay timer on Power On in DcmTaskTime Counts*/

		10000,			/* Delay time after failed security access in DcmTaskTime Counts */

		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*)	&GetSeed, /* Function for the GetSeed Function */
		/* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
		(void*)	&CompareKey, /* Function for the Compare Key Function */
		0x1, 		/* Security Level */
		4,			/* Security Seed size */
		4,			/* Security Key size */
		2,			/* Number of failed security access after which delay time is active */
		0,			/* Number of failed security access after which security is locked */
		0,			/* Size of the Access Data Record in Seed Request */
		USE_ASYNCH_FNC			}

};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"















#if (DCM_CFG_DSP_ROUTINECONTROL_ENABLED != DCM_CFG_OFF)
/**
 ***************************************************************************************************
            Routine control (RC) service - start
 ***************************************************************************************************
 */




#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint16,DCM_VAR)              Dcm_RCSigOutN_as16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint32,DCM_VAR)              Dcm_RCSigOutN_as32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint8,DCM_VAR)               Dcm_RCSigOutN_as8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint32,DCM_VAR)              Dcm_RCSigOutN_au32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint16,DCM_VAR)              Dcm_RCSigOutN_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


typedef enum
{
    DcmDspRoutine_DriveVacuumPump_DcmDspStopRoutineOutSignal_StpOut,
    DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineOutSignal_StrtOut,
    DcmDspRoutine_DriveVacuumPump_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut,
    DCM_RC_SIGOUTUINT8MAX
} Dcm_DspRoutineSigOutUInt8Idx_ten;

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static VAR(uint8,DCM_VAR)               Dcm_RCSigOut_au8[3];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint8,DCM_VAR)               Dcm_RCSigOutN_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"






#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint16,DCM_VAR)              Dcm_RCSigInN_as16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#define DCM_START_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint32,DCM_VAR)              Dcm_RCSigInN_as32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(sint8,DCM_VAR)               Dcm_RCSigInN_as8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_32/*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint32,DCM_VAR)              Dcm_RCSigInN_au32[1];
#define DCM_STOP_SEC_VAR_CLEARED_32 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint16,DCM_VAR)              Dcm_RCSigInN_au16[1];
#define DCM_STOP_SEC_VAR_CLEARED_16 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


typedef enum
{
    DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineInSignal_StrtIn,
    DCM_RC_SIGINUINT8MAX
} Dcm_DspRoutineSigInUInt8Idx_ten;

#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static VAR(uint8,DCM_VAR)               Dcm_RCSigIn_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8/*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_8 /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
VAR(uint8,DCM_VAR)               Dcm_RCSigInN_au8[1];
#define DCM_STOP_SEC_VAR_CLEARED_8/*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

FUNC(uint32,DCM_CODE) Dcm_RCGetSigVal_u32 ( VAR(uint8,AUTOMATIC) dataSigType_en, VAR(uint16,AUTOMATIC) idxSignalIndex_u16 )
{
    VAR(uint32,AUTOMATIC)       dataSigVal_u32;

    dataSigVal_u32 = 0;
   
    switch (dataSigType_en)
    {
    case DCM_UINT8:
        dataSigVal_u32 = (uint32)Dcm_RCSigOut_au8[idxSignalIndex_u16];
        break;
/*MR12 RULE 16.6 VIOLATION: This 'switch' statement contains only a single path - it is redundant. MISRA C:2012 Rule-16.6*/
    default:
        (void)idxSignalIndex_u16;
        break;
    }
    return (dataSigVal_u32);
}


FUNC(void,DCM_CODE) Dcm_RCSetSigVal ( VAR(uint8,AUTOMATIC) dataSigType_en, VAR(uint16,AUTOMATIC) idxSignalIndex_u16, VAR(uint32,AUTOMATIC) dataSigVal_u32)
{

    switch (dataSigType_en)
    {
    case DCM_UINT8:
        Dcm_RCSigIn_au8[idxSignalIndex_u16]=(uint8)dataSigVal_u32;
        break;
/*MR12 RULE 16.6 VIOLATION: This 'switch' statement contains only a single path - it is redundant. MISRA C:2012 Rule-16.6*/
    default:
        (void)dataSigVal_u32;
        (void)idxSignalIndex_u16;
        break;
    }
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_DriveVacuumPump_StrtInSig[]=
{
     {
        0,            /* Start bit position of the signal */
        8,               /* length of the signal */
        DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineInSignal_StrtIn,            /* Index of the signal */
        DCM_LITTLE_ENDIAN,       /* Signal Endianness is LITTLE_ENDIAN*/
        DCM_UINT8  /* Data Type is UINT8 */             
    }
};



static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_DriveVacuumPump_StrtOutSig[]=
{
   {
        0,             /* Start bit position of the signal */
        8,               /* length of the signal */
	    DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineOutSignal_StrtOut,           /* Index of the signal */
	    DCM_LITTLE_ENDIAN,       /* Signal Endianness is LITTLE_ENDIAN*/
	   DCM_UINT8  /* Data Type is UINT8 */      
    }
};


static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_DriveVacuumPump_StopOutSig[]=
{
   {
        0,             /* Start bit position of the signal */
        8,               /* length of the signal */
        DcmDspRoutine_DriveVacuumPump_DcmDspStopRoutineOutSignal_StpOut,            /* Index of the signal */
        DCM_LITTLE_ENDIAN,       /* Signal Endianness is LITTLE_ENDIAN*/
        DCM_UINT8  /* Data Type is UINT8 */   
    }
};

static CONST(Dcm_DspRoutineSignalInfo_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_DriveVacuumPump_ReqRsltOutSig[]=
{
    {
        0,             /* Start bit position of the signal */
        8,               /* length of the signal */
        DcmDspRoutine_DriveVacuumPump_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut,            /* Index of the signal */
        DCM_LITTLE_ENDIAN,       /* Signal Endianness is LITTLE_ENDIAN*/
        DCM_UINT8  /* Data Type is UINT8 */    
    }
};





static CONST(Dcm_DspRoutineInfoType_tst, DCM_CONST) DcmDspRc_DcmDspRoutine_DriveVacuumPump=
{
    /* Allowed Security Row Bit Mask for Routine*/
   0x2uL,

    /* Allowed Session Row Bit Mask for Routine */
     0x4uL,
     NULL_PTR,       /*  No User defined Mode rule Function configured  */
    /* Reference to In Signal from StartRoutine */
    DcmDspRc_DcmDspRoutine_DriveVacuumPump_StrtInSig,
    /* Reference to In Signal from StopRoutine */
    NULL_PTR,
/* Reference to In Signal from RequestResultRoutine */
    NULL_PTR,
    /* Reference to Out Signal from StartRoutine */
    DcmDspRc_DcmDspRoutine_DriveVacuumPump_StrtOutSig,
    /* Reference to Out Signal from StopRoutine */
    DcmDspRc_DcmDspRoutine_DriveVacuumPump_StopOutSig,
    /* Reference to Out Signal from RequestResultsRoutine */
    DcmDspRc_DcmDspRoutine_DriveVacuumPump_ReqRsltOutSig,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for Start Routine */
    1,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for Stop Routine */
    0,
    /* (Maximum) Size of Control Option Record i.e. Optional Bytes in Request for RequestResults Routine */
    0,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for Request Start Routine */
    1,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for Request Stop Routine */
    1,
    /* (Maximum) Size of Status Option Record i.e. Optional Bytes in Response for RequestResults Routine */
    1,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for Start Routine */
    1,

    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for Stop Routine */
    0,
    /* Minimum Size of Control Option Record i.e. Optional Bytes in Request for RequestResult Routine */
    0,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request Start Routine */
    1,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request Stop Routine */
    1,
    /* Minimum Size of Status Option Record i.e. Optional Bytes in Response for Request RequestResults Routine */
    1,
    /* Number of In Signals configured for StartRoutine */
    1,
    /* Number of In Signals configured for StopRoutine */
    0,
/* Number of In Signals configured for ReqResultsRoutine */
    0,
    /* Number of Out Signals configured for StartRoutine */
    1,
    /* Number of Out Signals configured for StopRoutine */
    1,
    /* Number of Out Signals configured for RequestResultsRoutine */
    1
};






#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

static FUNC(Std_ReturnType,DCM_CODE) Dcm_Dsp_RC_DcmDspRoutine_DriveVacuumPump_Func ( VAR(uint8, AUTOMATIC) dataSubFunc_u8 )
{
    VAR(Std_ReturnType,AUTOMATIC) dataRetVal_u8;
    dataRetVal_u8 = E_NOT_OK;

    switch (dataSubFunc_u8)
    {
    case 1u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_DriveVacuumPump_Start
                (
Dcm_RCSigIn_au8[DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineInSignal_StrtIn],
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_DriveVacuumPump_DcmDspStartRoutineOutSignal_StrtOut]),
                    &(Dcm_RCNegResCode_u8)
                  );

        break;

    case 2u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_DriveVacuumPump_Stop
                (
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_DriveVacuumPump_DcmDspStopRoutineOutSignal_StpOut]),
                    &(Dcm_RCNegResCode_u8)
                );

        break;

    case 3u:
        dataRetVal_u8 = Rte_Call_RoutineServices_DcmDspRoutine_DriveVacuumPump_RequestResults
                (
                    Dcm_RCOpStatus_u8,
                    &(Dcm_RCSigOut_au8[DcmDspRoutine_DriveVacuumPump_DcmDspRequestRoutineResultsOutSignal_0_ReqRsltOut]),
                    &(Dcm_RCNegResCode_u8)
                );
        break;

    default:
        Dcm_RCNegResCode_u8 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }

    return (dataRetVal_u8);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/* Array with function pointers configured for RIDs to check if they are supported in the current variant */

CONST(Dcm_DspRoutineType_tst, DCM_CONST) Dcm_DspRoutine_cast[DCM_CFG_RC_NUMRIDS]=
{

    /* DcmDspRoutine_DriveVacuumPump */
    {
        0x601,        /* Routine Identifier */
        TRUE,      /* Fixed length */
        TRUE,       /* UsePort is set to TRUE, call will be to RTE ports */
        &DcmDspRc_DcmDspRoutine_DriveVacuumPump,      /* Reference to Routine Info */
        &Dcm_Dsp_RC_DcmDspRoutine_DriveVacuumPump_Func,        /* Reference to Call-out function */

        TRUE,       /* Is Start Routine supported ? */

        TRUE,       /* Is Stop Routine supported ? */
        TRUE,       /* Stop this routine if active on Session change */
        TRUE,       /* Is RequestSequnceError supported for RequestResults subfunction for Routine which is not started ? */
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),      /*Configuration mask indicating the availability of routine in different DCMConfigsets*/
#endif
        TRUE,       /* Is Request Results Routine supported ? */
    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/* Array for storing current status of each RID*/
VAR(Dcm_DspRoutineStatusType_ten, DCM_VAR) Dcm_RoutineStatus_aen[DCM_CFG_RC_NUMRIDS];
#define DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




/**
 ***************************************************************************************************
            Routine control (RC) service - end
 ***************************************************************************************************
 */
 
#endif












 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
 #include "Dcm_Cfg_MemMap.h"
              
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ReadDidSignal_DcmDspData_VehicleSpeed(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
    /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
     return(Rte_Read_R_DataServices_DcmDspData_VehicleSpeed_Data(Data));
}
                
              
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ReadDidSignal_DcmDspData_SystemFaultRank(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Data)
{
    /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
     return(Rte_Read_R_DataServices_DcmDspData_SystemFaultRank_Data(Data));
}
                
 
  
 
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


 #define DCM_START_SEC_CODE /*Adding this for memory mapping*/
 #include "Dcm_Cfg_MemMap.h"
static FUNC(Std_ReturnType,DCM_CODE) Dcm_WriteDidSignal_DcmDspData_VehicleSpeed(VAR(uint8,AUTOMATIC) Data)
{
   /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
    return(Rte_Write_P_DataServices_DcmDspData_VehicleSpeed_Data(Data));
}
static FUNC(Std_ReturnType,DCM_CODE) Dcm_WriteDidSignal_DcmDspData_SystemFaultRank(VAR(uint8,AUTOMATIC) Data)
{
   /*MR12 RULE 13.4 VIOLATION: The result of an assignment is being used in an arithmetic operation or another assigning operation. MISRA C:2012 Rule-13.4 */
    return(Rte_Write_P_DataServices_DcmDspData_SystemFaultRank_Data(Data));
}
 
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


/*Handling of  Sender receiver supported IOCBI DIDs*/
 








/**
 **********************************************************************************************************************
           DID Signal Substructure Configuration for IOCBI
 **********************************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_SignalDIDIocbiConfig_tst, DCM_CONST) Dcm_DspIOControlInfo[2]=
{
    {
            NULL_PTR,
            NULL_PTR,
            NULL_PTR,
            NULL_PTR    
    },
    {
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&Rte_Call_DataServices_DcmDspData_VacuumPumpPressure_1100_ReturnControlToECU,            /* Return Control To Ecu Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&Rte_Call_DataServices_DcmDspData_VacuumPumpPressure_1100_ResetToDefault,         /* Reset To Default Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
            (void*)&Rte_Call_DataServices_DcmDspData_VacuumPumpPressure_1100_FreezeCurrentState,            /* Freeze Current State Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&Rte_Call_DataServices_DcmDspData_VacuumPumpPressure_1100_ShortTermAdjustment            /* Short Term Adjustment Function */
                
    }
};
  
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/**
 **********************************************************************************************************************
           DID Signal Substructure Configuration for condition check for read and write and read datalength function
 **********************************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_SignalDIDSubStructConfig_tst, DCM_CONST) Dcm_DspDid_ControlInfo_st[4]=
{
    {
        NULL_PTR,
        NULL_PTR
,
        NULL_PTR
          
,
        0
    },



    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            NULL_PTR,           /* Write Data Function */
                1    /*Index to DcmDspControlInfoStructure*/   /*IOCBI Sub structure address*/
    }
, 
    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	    (void*)&Dcm_WriteDidSignal_DcmDspData_VehicleSpeed,         /* Write Data Function */
            0                                                /*IOCBI Sub structure address*/
    }
, 
    {

            NULL_PTR,          /* Condition Check Read Function */
            NULL_PTR,          /* Read Data Length Function */
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	    (void*)&Dcm_WriteDidSignal_DcmDspData_SystemFaultRank,         /* Write Data Function */
            0                                                /*IOCBI Sub structure address*/
    }

};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/**
 ***************************************************************************************************
           DID Signal Configuration
 ***************************************************************************************************
**/

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST(Dcm_DataInfoConfig_tst, DCM_CONST) Dcm_DspDataInfo_st [3]=
{
    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&Dcm_ReadDidSignal_DcmDspData_SystemFaultRank,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           3,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                    /* Data Type is UINT8*/
	       USE_DATA_SENDER_RECEIVER,      /*DataUsePort is USE_DATA_SENDER_RECEIVER*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
	        (void*)&Rte_Call_DataServices_DcmDspData_VacuumPumpPressure_1100_ReadData,            /* Read Data Function */
    
    
           16,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           1,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                                          /* Data Type is UINT8 */
	       USE_DATA_SYNCH_CLIENT_SERVER,      /*DataUsePort is USE_DATA_SYNCH_CLIENT_SERVER*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
,    
     {   
            /* MR12 RULE 11.1 VIOLATION: Typecast to function pointer required for implementation - Required for efficient RAM usage by using single void function pointer */
             (void*)&Dcm_ReadDidSignal_DcmDspData_VehicleSpeed,            /* Read Data Function */
    
    
           8,                                                 /*Signal Data Size */
           DCM_INVALID_NVDBLOCK,                               /*NVM block id for USE_BLOCK_ID*/
           2,    /*Index to DcmDspControlInfoStructure*/
           DCM_UINT8,                    /* Data Type is UINT8*/
	       USE_DATA_SENDER_RECEIVER,      /*DataUsePort is USE_DATA_SENDER_RECEIVER*/
           DCM_BIG_ENDIAN,                 /*Signal endianness is BIG_ENDIAN*/
     
           TRUE,       /*Signal's fixedLength type**/
     
     
    }
    
    
};



#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



/**
 ***************************************************************************************************
           DID Signal Configuration
 ***************************************************************************************************
**/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


/* DID DcmDspDid_VacuumPumpPressure_1100 signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_1100_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        1
    }
};

/* DID DcmDspDid_VehicleSpeed signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_2310_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        2
    }
};

/* DID DcmDspDid_SystemFaultRank signal configuration */
static CONST(Dcm_SignalDIDConfig_tst, DCM_CONST) DcmDspDid_2311_SigConf[1]=
{
 /* Signal DcmDspDidSignal */
    {
        0,    /* Signal Bit Position */
        0
    }
};


#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



/**
 ***************************************************************************************************
           DID Extended Configuration
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DcmDspDidInfo_VacuumPumpPressure_1100=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed Write Session levels */
        0x0uL,           /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
    0x4uL, /* Allowed IO control Session levels */
    0x2uL, /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_NO,                                         /*Control mask is not relvant*/
        0x0,                                         /*Control mask size in bytes*/
        TRUE,            /* If Enabled allows the IOcontrol(IOCBI DIDS) to be reset on session/security change */
    
        0xF
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DcmDspDidInfo_VehicleSpeed=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
    0x5uL, /* Allowed Write Session levels */
    0x2uL, /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};
static CONST(Dcm_ExtendedDIDConfig_tst, DCM_CONST) Did_extendedConfig_DcmDspDidInfo_SystemFaultRank=
{
    
    0x5uL, /* Allowed Read Session levels */
    0xFFFFFFFFuL, /* Allowed Read Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
    0x5uL, /* Allowed Write Session levels */
    0x2uL, /* Allowed Write Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        0x0uL,          /* Allowed IO control Session levels */
        0x0uL,          /* Allowed IO control Security levels */
        NULL_PTR,       /*  No User defined Mode rule Function configured  */
        DCM_CONTROLMASK_INTERNAL,                                         /*Default value of Control mask*/
        0x0,                                         /*Control mask size in bytes*/
        FALSE,          /* If disabled does not the IOcontrol(IOCBI DIDS) to be reset on session/security change */
        0x00u
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


/**
 ***************************************************************************************************
           DID Configuration Structure
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
CONST (Dcm_DIDConfig_tst, DCM_CONST) Dcm_DIDConfig []=
{

    {
        0x1100,                        /*DID*/
        1,                          /*No of Signals*/
        2,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_1100_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_VacuumPumpPressure_1100   /*ExtendedConfiguration*/
    }


,
    {
        0x2310,                        /*DID*/
        1,                          /*No of Signals*/
        1,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_2310_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_VehicleSpeed   /*ExtendedConfiguration*/
    }


,
    {
        0x2311,                        /*DID*/
        1,                          /*No of Signals*/
        1,                            /*TotalSize*/
        TRUE,                      /*FixedLength*/
        FALSE,                      /*DynamicallyDefined*/
        DcmDspDid_2311_SigConf,        /*DidSignalRef*/
#if (DCM_CFG_POSTBUILD_SUPPORT != DCM_CFG_OFF)
        ((DCM_CFG_CONFIGSET1)|(DCM_CFG_CONFIGSET2)|(DCM_CFG_CONFIGSET3)|(DCM_CFG_CONFIGSET4)|
         (DCM_CFG_CONFIGSET5)|(DCM_CFG_CONFIGSET6)|(DCM_CFG_CONFIGSET7)|(DCM_CFG_CONFIGSET8)),                          /*DidConfigurationMask indicating availability of DID in different configuration sets*/
#endif
        &Did_extendedConfig_DcmDspDidInfo_SystemFaultRank   /*ExtendedConfiguration*/
    }



};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"


#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
FUNC(uint16,DCM_CODE) Dcm_DIDcalculateTableSize_u16(void)
{
  return ((uint16)(sizeof(Dcm_DIDConfig))/(uint16)(sizeof(Dcm_DIDConfig_tst)));
}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"







#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
boolean Dcm_ControlDtcSettingModecheck_b(
/* MR12 RULE 8.13 VIOLATION:The object addressed by the pointer parameter 'NegRespCode_u8' is not modified and so the pointer could be of type 'pointer to const' - Prototype is suggested by Autosar */
P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) NegRespCode_u8)
{
    VAR(Std_ReturnType,AUTOMATIC) retVal_u8;
    VAR(boolean,AUTOMATIC) retVal_b;

    /* Call the DcmAppl API to check if the DTC Setting needs to be re-enabled */
    retVal_u8 =DcmAppl_UserDTCSettingEnableModeRuleService();

    if(retVal_u8!=E_OK)
    {
        (void)NegRespCode_u8;
        retVal_b = FALSE;
    }
    else
    {
        (void)NegRespCode_u8;
        retVal_b = TRUE;
    }
    return (retVal_b);

}
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




/**
 ***************************************************************************************************
            Ecu Reset (ER) Service
 ***************************************************************************************************
*/
#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/* Initialization of the parameters for the supported Reset Types */
CONST(Dcm_DspEcuReset_tst, DCM_CONST) Dcm_DspEcuResetType_cast[DCM_CFG_DSP_NUMRESETTYPE] =
{

    {
        RTE_MODE_DcmEcuReset_HARD,         /* DcmEcuReset Mode  for the ResetType */
        0x1,                              /* ResetType */
        DCM_RESET_NO_BOOT

    },

    {
        RTE_MODE_DcmEcuReset_SOFT,         /* DcmEcuReset Mode  for the ResetType */
        0x3,                              /* ResetType */
        DCM_RESET_NO_BOOT

    }
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"





/**
 ***************************************************************************************************
        Communication Control Service
 ***************************************************************************************************
*/

#define DCM_START_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
P2FUNC(Std_ReturnType,DCM_APPL_CODE,Dcm_ComMUserReEnableModeRuleRef)(void) = &DcmAppl_UserCommCtrlReEnableModeRuleService;
#define DCM_STOP_SEC_VAR_INIT_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

static FUNC(boolean,DCM_CODE) Dcm_ComMChannel_Can_Network_Channel_IsModeDefault ( void )
{
	VAR(boolean,AUTOMATIC)	dataRetValue_b;

	if ( SchM_Mode_Dcm_R_DcmCommunicationControl_ComMChannel_Can_Network_Channel() != RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM_NM )
	{
		dataRetValue_b = FALSE;
	}
	else
	{
		dataRetValue_b = TRUE;
	}
	return (dataRetValue_b);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/* Function to map Dcm_CommunicationModeType to Rte_Communication Mode type for ComMChannel_Can_Network_Channel */
static FUNC(Std_ReturnType,DCM_CODE) Dcm_ComMChannel_Can_Network_Channel_SwitchIndication ( VAR(Dcm_CommunicationModeType,AUTOMATIC) Mode )
{
	VAR(Std_ReturnType,AUTOMATIC)	dataRetValue_u8;
	switch (Mode)
	{
		case DCM_ENABLE_RX_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel( RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM);
			break;
		case DCM_DISABLE_RX_TX_NORMAL:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM);
			break;
		case DCM_ENABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NM: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel( RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NM);
			break;
		case DCM_DISABLE_RX_TX_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NM);
			break;
		case DCM_ENABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM_NM);
			break;
		case DCM_ENABLE_RX_DISABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_DISABLE_TX_NORM_NM);
			break;
		case DCM_DISABLE_RX_ENABLE_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_ENABLE_TX_NORM_NM);
			break;
		case DCM_DISABLE_RX_TX_NORM_NM:  dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_DISABLE_RX_TX_NORM_NM);
			break;
		default: dataRetValue_u8 = SchM_Switch_Dcm_DcmCommunicationControl_ComMChannel_Can_Network_Channel(RTE_MODE_DcmCommunicationControl_ComMChannel_Can_Network_Channel_DCM_ENABLE_RX_TX_NORM);
			break;
	}
	return (dataRetValue_u8);
}

#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

#define DCM_START_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
/*Array  stores the channelID info which is to be informed about the communication mode change if the subnet ID is 0  */
CONST(Dcm_Dsld_AllChannelsInfoType, DCM_CONST) Dcm_AllChannels_ForModeInfo[DCM_CFG_NUM_ALLCHANNELS_MODE_INFO]=
{
	{
		&Dcm_ComMChannel_Can_Network_Channel_SwitchIndication,  	/* Auto generated Dcm function to be called for invoking SchM Switch Indication */
		&Dcm_ComMChannel_Can_Network_Channel_IsModeDefault,		/* Auto generated Dcm function to be called for checking if Active Mode is Default */
 		ComMConf_ComMChannel_ComMChannel_Can_Network_Channel
	}
};
#define DCM_STOP_SEC_CONST_UNSPECIFIED /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"




/**
 ***************************************************************************************************
        Clear Diagnostic Information Service (0x14)
 ***************************************************************************************************
*/











