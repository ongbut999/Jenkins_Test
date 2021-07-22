



 
/*<VersionHead>
 * This Configuration File is generated using versions (automatically filled in) as listed below.
 *
 * $Generator__: Com / AR42.6.0.0                Module Package Version
 * $Editor_____: ISOLAR-A/B 6.0.1_6.0.1                Tool Version
 * $Model______: 2.3.0.4                ECU Parameter Definition Version
 *
 
 </VersionHead>*/



/*
 * If COM_DontUseExternalSymbolicNames is defined before including Com_Cfg.h file, then external symbolic names will
 * not be visible.
 * Com_PBcfg.c file should not use external symbolic names.
 * This mechanism is used to prevent the accidental usage of external symbolic names in this file
 * This file should use only internal symbolic name defined in  Com_PBcfg_InternalId.h
 */
#define COM_DontUseExternalSymbolicNames
#include "Com_Prv.h"
#include "Com_Cbk.h"
#include "PduR_Com.h"
#include "Com_PBcfg.h"

/*
 * The file Com_PBcfg_InternalId.h defines internal symbolic names
 * These names should be used in the tables generated in this file
 * Regular symbolic names should not be used here
 */
#include "Com_PBcfg_InternalId.h"


/* START: Tx Signal Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xTxSigCfg_tst ,COM_CONST) Com_Prv_xTxSigCfg_acst[COM_NUM_TX_SIGNALS] =
{
        
    {  /* MCU01_ShutDownAllowed */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        24,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU01_Ready */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU01_HighVolAllowed */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        41,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU01_Status */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        42,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU01_ActDischStatus */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        44,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU01_SelfCheck */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        46,                                                /*BitPosition*/

        2,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU01_CheckSum */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        56,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU01_Counter */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        4,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU01_CurCntTor */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(4094uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        27,                                                /*BitPosition*/

        13,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x22                                               /*General*/

    },
        
    {  /* MCU01_Motorspd */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(32767uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        16,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x22                                               /*General*/

    },
        
    {  /* MCU01_EmergShutDown */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        55,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU02_IGBTTmp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(40uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU02_MotorTmp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(40uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        8,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT8
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x20                                               /*General*/

    },
        
    {  /* MCU02_Vdc */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        26,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x22                                               /*General*/

    },
        
    {  /* MCU02_Idc */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(511uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        10,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x22                                               /*General*/

    },
        
    {  /* MCU02_MinTor */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        20,                                                /*BitPosition*/

        9,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x22                                               /*General*/

    },
        
    {  /* MCU02_MaxTor */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        13,                                                /*BitPosition*/

        11,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = UINT16
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x22                                               /*General*/

    },
        
    {  /* MCU03_LI_OverSpeed */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        51,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_LI_OverTempEM */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        50,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_LI_OverTempINV */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        49,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_LI_UdcUnder */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        48,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_LI_UdcOver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        52,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_PhaseImp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        39,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_12VSupply */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        32,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_PhCOver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        47,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_PhBOver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        46,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_PhAOver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        45,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_OverSpeed */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        41,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_MsgTO */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        43,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_OverTempEM */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        40,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_OverTempINV */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        36,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_IntError */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        38,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_HWOverCur */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        44,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_UDCUnder */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        37,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_UdcOver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        34,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_IdcOver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        33,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_ToqError */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        35,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_RF_BusOff */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        42,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_SysFailure */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        11,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_Resolver */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        2,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_PhCSamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        5,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_PhBSamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        4,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_InvTempSamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        9,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_PhASamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        3,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_DESAT */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        0,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_UdcSamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        8,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_COMError */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        10,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_5VSupply */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        1,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_EMTempSamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        6,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU03_NRF_IdcSamp */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        15,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    },
        
    {  /* MCU04_Test */
#ifdef COM_TxInvalid
        (uint32)(0uL),                                                /*DataInvalid_Val*/
#endif
        (uint32)(0uL),                                                /* Init_Val*/
        
        /*
        {
            TransProp       : 3;    = TRIGGERED
            FilterAlgorithm : 4;    = COM_NOTCONFIGURED
            DataInvalidType : 1;    = COM_FALSE
            TimeOutEnabled  : 1;    = COM_FALSE
        }Com_TxSigPropType;    */
        0x54,                                               /* Transmission Fields */

#ifdef COM_TxSigUpdateBit
        COM_UPDATE_MAX,                                    /*Update bit Position*/
#endif /* #ifdef COM_TxSigUpdateBit */

        15,                                                /*BitPosition*/

        1,/*BitSize*/

#ifdef COM_TxFilters
        0xff,                                              /*Filter_Index*/
#endif

#ifdef COM_EffectiveSigTOC
        0xff,                                              /*OldVal_Index*/
#endif

        (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_04_Can_Network_CANNODE_0,             /*Ipdu Reference*/
        /*
        {
            Type:5;       = BOOLEAN
            Endianess:1;  = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType;*/
        0x26                                               /*General*/

    }

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Tx Signal Details  */

/* START: Rx Signal Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xRxSigCfg_tst ,COM_CONST) Com_Prv_xRxSigCfg_acst[COM_NUM_RX_SIGNALS] =
{    
        
    {  /* HCU01_EmergShutDown */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       36,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_CheckSum */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       56,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      8, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_Counter */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       48,                         /*BitPosition*/
       2,                /* Signal Buffer Index */
       
      4, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_ActiveDischarge */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       37,                         /*BitPosition*/
       3,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_McuModeCmd */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       38,                         /*BitPosition*/
       4,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_EnaMCU */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       24,                         /*BitPosition*/
       5,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_SpeedCmd */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(255uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       25,                         /*BitPosition*/
       0,                /* Signal Buffer Index */
       
      15, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = NONE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x28         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_Shift */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_HCU01_Shift,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(3uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       32,                         /*BitPosition*/
       6,                /* Signal Buffer Index */
       
      2, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT8
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x20,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = REPLACE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x68         /* Reception Fields */
    }
    ,
        
    {  /* HCU01_TqCmd */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_HCU01_TqCmd,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(255uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       10,                         /*BitPosition*/
       1,                /* Signal Buffer Index */
       
      14, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = UINT16
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x22,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = REPLACE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x68         /* Reception Fields */
    }
    ,
        
    {  /* HCU02_Poweroff */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_HCU02_Poweroff,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(1uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       6,                         /*BitPosition*/
       7,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_02_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = REPLACE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x68         /* Reception Fields */
    }
    ,
        
    {  /* HCU03_Poweroff */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_HCU03_Poweroff,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(1uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       8,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_03_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = REPLACE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x68         /* Reception Fields */
    }
    ,
        
    {  /* HCU04_Poweroff */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_HCU04_Poweroff,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       9,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_04_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = REPLACE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x68         /* Reception Fields */
    }
    ,
        
    {  /* HCU05_Poweroff */
#ifdef COM_RxSignalNotify
        /* Notification Signal part */
        
        &Rte_COMCbk_HCU05_Poweroff,
        
#endif
#ifdef COM_RxSigInvalidNotify
        /* Com Invalid Notification */
        
        NULL_PTR,
#endif
#ifdef COM_RxSigInvalid
       (uint32)(0uL),    /* DataInvalid_Val */
#endif
           (uint32)(0uL),        /*Init_Val */
#ifdef COM_RxSigUpdateBit
       COM_UPDATE_MAX,                    /*Update bit Position*/
#endif /* #ifdef COM_RxSigUpdateBit */
       0,                         /*BitPosition*/
       10,                /* Signal Buffer Index */
       
      1, /*BitSize*/

#ifdef COM_RxFilters
        0xff,                           /*Filter_Index*/
#endif

       (Com_IpduIdType)ComConf_ComIPdu_Internal_HCU_05_Can_Network_CANNODE_0,                       /*Ipdu Reference*/
        /*
        {
            Type:5;        = BOOLEAN
            Endianess:1;   = BIG_ENDIAN
            UpdBitConf:1;  = COM_FALSE
            Not_Used:1;
        }Com_GeneralType; */
        0x26,       /*General*/

        /*
        {
            DataInvalidType:2;   =  NONE
            FilterAlgorithm:4;   = COM_NOTCONFIGURED
            DataTimeoutType:1;   = REPLACE
            IsGwSignal:1         = COM_FALSE
        } Com_RxSigPropType; */
        0x68         /* Reception Fields */
    }
    

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Rx Signal Details  */











/* START: TMS Details  */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

static CONST(Com_TransModeInfo ,COM_CONST) Com_MCU_01_Can_Network_CANNODE_0_TransModeInfo =
/* MCU_01_Can_Network_CANNODE_0 has only True mode configured */
    {
        1, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
;

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"




/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

static CONST(Com_TransModeInfo ,COM_CONST) Com_MCU_02_Can_Network_CANNODE_0_TransModeInfo =
/* MCU_02_Can_Network_CANNODE_0 has only True mode configured */
    {
        5, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
;

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"




/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

static CONST(Com_TransModeInfo ,COM_CONST) Com_MCU_03_Can_Network_CANNODE_0_TransModeInfo =
/* MCU_03_Can_Network_CANNODE_0 has only True mode configured */
    {
        5, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
;

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"




/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* MCU_04_Can_Network_CANNODE_0 has a TMS switch */
static CONST(Com_TransModeInfo ,COM_CONST) Com_MCU_04_Can_Network_CANNODE_0_TransModeInfo[] =
{
    /* True Mode configuration */
    {
        5, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
,
    /* False Mode configuration */
    {
        5, /* TimePeriod */
        
        1, /* TimeOffset */
        
        0, /* RepetitionPeriod */
        
        0,  /* NumRepetitions */

#ifdef COM_MIXEDPHASESHIFT
        COM_TXMODE_PERIODIC, /* Mode */
        COM_FALSE    /* MixedPhaseShift status */
#else
        COM_TXMODE_PERIODIC /* Mode */
#endif /* #ifdef COM_MIXEDPHASESHIFT */

    }
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: TMS Details  */



/* START: Tx IPDU Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xTxIpduInfoCfg_tst ,COM_CONST) Com_Prv_xTxIpduCfg_acst[COM_NUM_TX_IPDU] =
{
    {   /*Ipdu: MCU_01_Can_Network_CANNODE_0*/

        Com_IpduBuf_MCU_01_Can_Network_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        &Com_MCU_01_Can_Network_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        1,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        11,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_MCU_01_Can_Network_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_MCU01_ShutDownAllowed,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif






/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = TRUEMODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    defaultTMSStatus:1;           = COM_FALSE
    ipduPartOfIpduGrp:1;          = COM_TRUE
    Not_Used:1;
}Com_TxIpduFlagType;
*/
        0x4002,  /*Transmission Type*/

        /* Com_MainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: MCU_02_Can_Network_CANNODE_0*/

        Com_IpduBuf_MCU_02_Can_Network_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        &Com_MCU_02_Can_Network_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        5,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        6,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_MCU_02_Can_Network_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_MCU02_IGBTTmp,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif






/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = TRUEMODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    defaultTMSStatus:1;           = COM_FALSE
    ipduPartOfIpduGrp:1;          = COM_TRUE
    Not_Used:1;
}Com_TxIpduFlagType;
*/
        0x4002,  /*Transmission Type*/

        /* Com_MainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: MCU_03_Can_Network_CANNODE_0*/

        Com_IpduBuf_MCU_03_Can_Network_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        &Com_MCU_03_Can_Network_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        7,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        5,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        33,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_MCU_03_Can_Network_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_MCU03_LI_OverSpeed,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif






/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = TRUEMODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    defaultTMSStatus:1;           = COM_FALSE
    ipduPartOfIpduGrp:1;          = COM_TRUE
    Not_Used:1;
}Com_TxIpduFlagType;
*/
        0x4002,  /*Transmission Type*/

        /* Com_MainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTx,

        0xFF               /*Padding Byte*/

    },
    {   /*Ipdu: MCU_04_Can_Network_CANNODE_0*/

        Com_IpduBuf_MCU_04_Can_Network_CANNODE_0,              /*Pointer to the Ipdu Buffer*/

        
        Com_MCU_04_Can_Network_CANNODE_0_TransModeInfo,
        
        #ifdef COM_TxIPduCallOuts
        /* Ipdu Callout Function*/
        NULL_PTR,
        
        #endif
        #ifdef COM_TxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,
        #endif

        #ifdef COM_ERRORNOTIFICATION
        /* Error Notification part */

        NULL_PTR,
        #endif

        #ifdef COM_TxIPduTimeOutNotify
        /* Timeout Notification part*/

        NULL_PTR,
        #endif


        #ifdef COM_METADATA_SUPPORT
        NULL_PTR,               /* Pointer to the MetaData Ipdu Buffer */
        #endif


        8,/*Size in Bytes*/
        #ifdef COM_TxIPduTimeOut
        5,               /*Timeout Fact*/
        #endif /* #ifdef COM_TxIPduTimeOut */
        0, /*MinDelay Time factor*/

        1,                    /*No Of Signals present in the IPDU*/
        #ifdef COM_TX_SIGNALGROUP

        0,               /*No of Signal Groups present in the IPDU*/
        #endif

        (PduIdType)PduRConf_PduRSrcPdu_MCU_04_Can_Network_CANNODE_0_Com2PduR,              /* PduR Id */

        (Com_TxIntSignalIdType)ComSignal_Internal_MCU04_Test,     /*Index to First Signal within this Ipdu*/
        #ifdef COM_TX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif






/*
{
    Signal_Processing:1;          = IMMEDIATE
    TMSCalclation:2;              = MODE_VALID
    NoneModeTimeOut:1;            = COM_FALSE
    ClearUpdBit:2                 = CLEAR_UPDATEBIT_NOT_APPLICABLE
    FilterEvalReq:1               = COM_FALSE
    IsDynPdu:1;                   = COM_FALSE
    IsGwDestPdu:1;                = COM_FALSE
    IsCalloutFrmTrigTrans:1;      = COM_FALSE
    isLargeDataPdu:1;             = COM_FALSE
    isCancelTransmitSupported:1;  = COM_FALSE
    IsMetaDataSupported:1;        = COM_FALSE
    defaultTMSStatus:1;           = COM_FALSE
    ipduPartOfIpduGrp:1;          = COM_TRUE
    Not_Used:1;
}Com_TxIpduFlagType;
*/
        0x4000,  /*Transmission Type*/

        /* Com_MainFunctionTx() */
        ComMainFunction_Internal_MainFunctionTx,

        0xFF               /*Padding Byte*/

    }
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Tx IPDU Details  */

/* START : Time out information structure for signals with update-bits */
#ifdef COM_RxSigUpdateTimeout
#endif /* #ifdef COM_RxSigUpdateTimeout */
/* END : Time out information structure for signals with update-bits */

/* START : Time out information structure for signal groups with update-bits */
#ifdef COM_RxSigGrpUpdateTimeout
#endif /* #ifdef COM_RxSigGrpUpdateTimeout */

#ifdef COM_RxSigUpdateTimeout
#endif /* #ifdef COM_RxSigUpdateTimeout */
/* END : Time out information structure for signals with update-bits */

/* START : Time out information structure for signal groups with update-bits */
#ifdef COM_RxSigGrpUpdateTimeout
#endif /* #ifdef COM_RxSigGrpUpdateTimeout */
/* END : Time out information structure for signal groups with update-bits */



/* START: Rx IPDU Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


CONST(Com_Prv_xRxIpduInfoCfg_tst ,COM_CONST) Com_Prv_xRxIpduCfg_acst[COM_NUM_RX_IPDU] =
{
    {   /*Ipdu: HCU_01_Can_Network_CANNODE_0*/
        

        Com_LocalBuf_HCU_01_Can_Network_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_HCU_01_Can_Network_CANNODE_0,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        8, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        30,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        9,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_HCU01_EmergShutDown,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /* Com_MainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                 /* Reception Type */


    },
    {   /*Ipdu: HCU_02_Can_Network_CANNODE_0*/
        

        Com_LocalBuf_HCU_02_Can_Network_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_HCU_02_Can_Network_CANNODE_0,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        1, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        30,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_HCU02_Poweroff,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /* Com_MainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                 /* Reception Type */


    },
    {   /*Ipdu: HCU_03_Can_Network_CANNODE_0*/
        

        Com_LocalBuf_HCU_03_Can_Network_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_HCU_03_Can_Network_CANNODE_0,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        1, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        30,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_HCU03_Poweroff,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /* Com_MainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                 /* Reception Type */


    },
    {   /*Ipdu: HCU_04_Can_Network_CANNODE_0*/
        

        Com_LocalBuf_HCU_04_Can_Network_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_HCU_04_Can_Network_CANNODE_0,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        1, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        30,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_HCU04_Poweroff,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /* Com_MainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                 /* Reception Type */


    },
    {   /*Ipdu: HCU_05_Can_Network_CANNODE_0*/
        

        Com_LocalBuf_HCU_05_Can_Network_CANNODE_0,              /*Pointer to the Local Ipdu Buffer*/
        
        #ifdef COM_RxSigUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signals with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigUpdateTimeout */
        #ifdef COM_RxSigGrpUpdateTimeout

        NULL_PTR,                       /* Pointer to timeout information structure for signal groups with update-bits, within the IPdu */
        #endif /* #ifdef COM_RxSigGrpUpdateTimeout */

        #ifdef COM_RxIPduCallOuts
        /* Ipdu Callout */

        NULL_PTR,
        
        #endif

        #ifdef COM_RxIPduTimeoutNotify
        /* Timeout Notification part*/

        &Com_RxTONotify_HCU_05_Can_Network_CANNODE_0,
        #endif /* COM_RxIPduTimeoutNotify */

        #ifdef COM_RxIPduNotification
        /* Ipdu Notification Function*/

        NULL_PTR,              /* Rx IPdu notification callback */
        #endif

        1, /*Size in Bytes*/

        #ifdef COM_RxIPduTimeout

        0,        /* First time out value after IPDU group start */

        30,              /*CC requriment: Support Rx IPDU Timeout*/
        #endif /* #ifdef COM_RxIPduTimeout */

        1,                /*No Of Signals present in the IPDU*/
        #ifdef COM_RX_SIGNALGROUP

        0,           /*No of Signal Groups present in the IPDU*/
        #endif

        (Com_RxIntSignalIdType)ComSignal_Internal_HCU05_Poweroff,   /*Index to First Signal within this Ipdu*/
         #ifdef COM_RX_SIGNALGROUP

        0,                            /*This IPDU does not contain any Signal Groups*/
        #endif
#ifdef COM_SIGNALGATEWAY
        0,       /* Number of signals with gateway */
#endif /* #ifdef COM_SIGNALGATEWAY */
#ifdef COM_SIGNALGROUPGATEWAY
        0,   /* Number of signal groups with gateway */
#endif /* #ifdef COM_SIGNALGROUPGATEWAY */

        /* Com_MainFunctionRx() */
        ComMainFunction_Internal_MainFunctionRx,

        /*
        {
            Signal_Processing:1;  = IMMEDIATE
            Notify_Cbk:1;         = true
            IsGwIPdu:1;           = false
            Not_Used:5;
        } Com_RxIpduFlagType;
        */
        0x2                 /* Reception Type */


    }
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: Rx IPDU Details  */



/* START: IPDU Group Details  */

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xIpduGrpInfoCfg_tst ,COM_CONST) Com_Prv_xIpduGrpCfg_acst[2] =
{           /* "Index of First IPdu"               "No of Rx-Ipdus" */
{
    /* ComIPduGroup_Rx */
    
    0,
    
    5
}
,{
    /* ComIPduGroup_Tx */
    
    5,
    
    0
}

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

/* END: IPDU Group Details  */

   





/* Reference to Ipdus belonging to the Ipdu Groups */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_IpduIdType ,COM_CONST) Com_Prv_xIPduGrp_IpduRefCfg_au8[9] =
{

    /* ComIPduGroup_Rx */

    ComConf_ComIPdu_Internal_HCU_01_Can_Network_CANNODE_0,
    ComConf_ComIPdu_Internal_HCU_02_Can_Network_CANNODE_0,
    ComConf_ComIPdu_Internal_HCU_03_Can_Network_CANNODE_0,
    ComConf_ComIPdu_Internal_HCU_04_Can_Network_CANNODE_0,
    ComConf_ComIPdu_Internal_HCU_05_Can_Network_CANNODE_0,
    /* ComIPduGroup_Tx */

    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_02_Can_Network_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_01_Can_Network_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_03_Can_Network_CANNODE_0),
    (COM_NUM_RX_IPDU + (Com_IpduIdType)ComConf_ComIPdu_Internal_MCU_04_Can_Network_CANNODE_0)
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


#if defined ( COM_TX_SIGNALGROUP_ARRAY )

/* Tx-SignalGroup Array are not configured */
# define Com_Prv_xTxSigGrpArrayCfg_acst      ( NULL_PTR )
#endif /* #if defined ( COM_TX_SIGNALGROUP_ARRAY ) */

#if defined ( COM_RX_SIGNALGROUP_ARRAY )
/* Rx-SignalGroup Array are not configured */
# define Com_Prv_xRxSigGrpArrayCfg_acst      ( NULL_PTR )
#endif /* #if defined ( COM_RX_SIGNALGROUP_ARRAY ) */

/* Start section for RAM variables */

/* START: I-PDU Buffers */

   /* Tx Ipdu buffers */


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


    VAR(uint8,COM_VAR) Com_IpduBuf_MCU_01_Can_Network_CANNODE_0[8];

    VAR(uint8,COM_VAR) Com_IpduBuf_MCU_02_Can_Network_CANNODE_0[8];

    VAR(uint8,COM_VAR) Com_IpduBuf_MCU_03_Can_Network_CANNODE_0[7];

    VAR(uint8,COM_VAR) Com_IpduBuf_MCU_04_Can_Network_CANNODE_0[8];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"



    /* Rx-Ipdu Local Buffers */


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


    VAR(uint8,COM_VAR) Com_LocalBuf_HCU_01_Can_Network_CANNODE_0[8];

    VAR(uint8,COM_VAR) Com_LocalBuf_HCU_02_Can_Network_CANNODE_0[1];

    VAR(uint8,COM_VAR) Com_LocalBuf_HCU_03_Can_Network_CANNODE_0[1];

    VAR(uint8,COM_VAR) Com_LocalBuf_HCU_04_Can_Network_CANNODE_0[1];

    VAR(uint8,COM_VAR) Com_LocalBuf_HCU_05_Can_Network_CANNODE_0[1];


/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"



/* END: I-PDU Buffers */

#ifdef COM_F_MASKEDNEWDIFFERSOLD

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint32 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
VAR(uint32,COM_VAR) Com_F_OldVal[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint32 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_32
#include "Com_MemMap.h"
#endif /* #ifdef COM_F_MASKEDNEWDIFFERSOLD */

#if defined(COM_EffectiveSigTOC) || defined(COM_EffectiveSigGrpTOC)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_OldValTrigOnChngType,COM_VAR) Com_OldValTrigOnChng[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #if defined(COM_EffectiveSigTOC) || defined(COM_EffectiveSigGrpTOC) */

#ifdef COM_F_ONEEVERYN

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
CONST(Com_OneEveryNType,COM_CONST) Com_OneEveryN_Const[1] =
{
    /* Period   Offset  Occurence*/


{    1,    5, 1    }    /*  DummyForMisra    */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_OneEveryNType,COM_VAR) Com_OneEveryN[1];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #ifdef COM_F_ONEEVERYN */


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

#ifdef COM_TP_IPDUTYPE
VAR(PduLengthType,COM_VAR)          Com_TpTxIpduLength_auo[COM_NUM_TX_IPDU];
#endif

VAR(Com_TxIpduRamData,COM_VAR)      Com_TxIpduRam_s[COM_NUM_TX_IPDU];

VAR(Com_RxIpduRamData,COM_VAR)      Com_RxIpduRam_s[COM_NUM_RX_IPDU];

VAR(Com_TxSignalFlagType,COM_VAR)   Com_TxSignalFlag[COM_NUM_TX_SIGNALS];

VAR(Com_RxSignalFlagType,COM_VAR)   Com_RxSignalFlag[COM_NUM_RX_SIGNALS];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

VAR(uint8,COM_VAR)    Com_IpduCounter_s[COM_NUM_TX_IPDU + COM_NUM_RX_IPDU];

VAR(uint8,COM_VAR)    Com_IpduCounter_DM[COM_NUM_RX_IPDU];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


#if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(PduIdType,COM_VAR)    Com_RxGwQueue_aux[COM_NUM_GWSRC_IPDUS+1u];

VAR(Com_RxGwQueueRAMType,COM_VAR)   Com_RxGwQueue_S;

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY) */


#ifdef COM_RX_SIGNALGROUP

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxSignalGrpFlagType,COM_VAR) Com_RxSignalGrpFlag[1u];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#ifdef COM_TX_SIGNALGROUP
#if defined(COM_EffectiveSigGrpTOC) || defined(COM_SIGNALGROUPGATEWAY)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxSignalGrpFlagType,COM_VAR) Com_TxSignalGrpFlag[1u];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif /* #if defined(COM_EffectiveSigGrpTOC) || defined(COM_SIGNALGROUPGATEWAY) */


/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of struct/enum/pointer type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_TxGrpSignalFlagType,COM_VAR) Com_TxGrpSignalFlag[1u];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of struct/enum/pointer type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"
#endif

#ifdef COM_RxIPduDeferredProcessing

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

    /* Buffer to hold data for deferred signal processing */
    VAR(uint8,COM_VAR) Com_DeferredBuffer[ 8 ];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

#endif /* #ifdef COM_RxIPduDeferredProcessing */

#if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY)

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of boolean type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_BOOLEAN
#include "Com_MemMap.h"

    VAR(boolean, AUTOMATIC) Com_IsGwSignalsUpdated_ab[ COM_NUM_GWSRC_IPDUS ];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of boolean type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_BOOLEAN
#include "Com_MemMap.h"

#endif /* #if defined (COM_SIGNALGATEWAY) || defined (COM_SIGNALGROUPGATEWAY) */

/* End section for RAM variables */


#if defined (COM_F_MASKEDNEWEQUALSX ) || defined(COM_F_MASKEDNEWDIFFERSX)

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_MaskXType ,COM_CONST) Com_MaskX[1] =
{
    /*Mask       X*/



{    1,    5    }    /*  DummyForMisra    */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


#endif /* #if defined (COM_F_MASKEDNEWEQUALSX ) || defined(COM_F_MASKEDNEWDIFFERSX) */


#ifdef COM_F_MASKEDNEWDIFFERSOLD

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_32
#include "Com_MemMap.h"

CONST(uint32 ,COM_CONST) Com_Mask[1] =
{
    /*Mask*/
    1    /* DummyForMisra */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_32
#include "Com_MemMap.h"

#endif /* #ifdef COM_F_MASKEDNEWDIFFERSOLD */


#if defined (COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS)

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_POSMinMaxType ,COM_CONST) Com_POSMinMax[1]=
{
    /*  Min      Max */





{    1,    5    }    /*  DummyForMisra    */


};


/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #if defined (COM_F_NEWISWITHIN_POS) || defined(COM_F_NEWISOUTSIDE_POS) */


#if defined (COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG)

/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_NEGMinMaxType ,COM_CONST) Com_NEGMinMax[1] =
{
    /*  Min      Max */


{    1,    5    }    /*  DummyForMisra    */
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

#endif /* #if defined (COM_F_NEWISWITHIN_NEG) || defined(COM_F_NEWISOUTSIDE_NEG) */


/* Signal Buffers */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint8 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"

VAR(uint8,COM_VAR) Com_SigType_u8[11];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint8 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_8
#include "Com_MemMap.h"


/* Type: UINT16, SINT16 */

/* ------------------------------------------------------------------------ */
/* Begin section for RAM variables of uint16 type */
#define COM_START_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"

VAR(uint16,COM_VAR) Com_SigType_u16[2];

/* ------------------------------------------------------------------------ */
/* End section for RAM variables of uint16 type */
#define COM_STOP_SEC_VAR_CLEARED_POSTBUILD_16
#include "Com_MemMap.h"


/* Type: UINT32, SINT32 */
#define Com_SigType_u32          ( NULL_PTR )

/* Type: UINT64, SINT64 */
#ifdef COM_RXSIG_INT64
#define Com_SigType_u64          ( NULL_PTR )
#endif /* #ifdef COM_RXSIG_INT64 */


#ifdef COM_RXSIG_FLOAT64SUPP
#define Com_SigType_f64          ( NULL_PTR )
#endif /* #ifdef COM_RXSIG_FLOAT64SUPP */

#ifdef COM_RX_DYNAMIC_SIGNAL_SUPPORT
#define Com_SigType_dyn          ( NULL_PTR )
#endif

#ifdef COM_RX_SIGNALGROUP_ARRAY
#define Com_RxSigGrpArrayBuf_u8  ( NULL_PTR )
#endif /* #ifdef COM_RX_SIGNALGROUP_ARRAY */

#ifdef COM_RX_SIGNALGROUP
/* Rx Group Signal Buffers */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */
#define Com_RxGrpSigType_u8      ( NULL_PTR )

/* Type: UINT16, SINT16 */
#define Com_RxGrpSigType_u16     ( NULL_PTR )

/* Type: UINT32, SINT32 */
#define Com_RxGrpSigType_u32     ( NULL_PTR )

/* Type: UINT64, SINT64 */
#ifdef COM_RXGRPSIG_INT64
#define Com_RxGrpSigType_u64     ( NULL_PTR )
#endif /* #ifdef COM_RXGRPSIG_INT64 */

#ifdef COM_RXGRPSIG_FLOAT64SUPP
#define Com_RxGrpSigType_f64     ( NULL_PTR )
#endif

/* The function Com_ReceiveSignalGroup() is not interrupt safe, hence there is need to
 * to generate second buffer for all the group signals
 */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */
#define Com_SecondRxGrpSigType_u8        ( NULL_PTR )

/* Type: UINT16, SINT16 */
#define Com_SecondRxGrpSigType_u16       ( NULL_PTR )

/* Type: UINT32, SINT32 */
#define Com_SecondRxGrpSigType_u32       ( NULL_PTR )

/* Type: UINT64, SINT64 */
#ifdef COM_RXGRPSIG_INT64
#define Com_SecondRxGrpSigType_u64       ( NULL_PTR )
#endif /* #ifdef COM_RXGRPSIG_INT64 */

#ifdef COM_RXGRPSIG_FLOAT64SUPP
#define Com_SecondRxGrpSigType_f64       ( NULL_PTR )
#endif /* #ifdef COM_RXGRPSIG_FLOAT64SUPP */

#endif /* #ifdef COM_RX_SIGNALGROUP */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xRxRamBuf_tst, COM_CONST) Com_Prv_xRxRamBuf_acst[ 1u ] =
{
    {
        (P2VAR(uint8, TYPEDEF, COM_APPL_DATA))              Com_SigType_u8

#ifdef COM_RX_DYNAMIC_SIGNAL_SUPPORT
        ,(P2VAR(uint8, TYPEDEF, COM_APPL_DATA))             Com_SigType_dyn
#endif

        ,(P2VAR(uint16, TYPEDEF, COM_APPL_DATA))            Com_SigType_u16

        ,(P2VAR(uint32, TYPEDEF, COM_APPL_DATA))            Com_SigType_u32

#ifdef COM_RXSIG_INT64
        ,(P2VAR(uint64, TYPEDEF, COM_APPL_DATA))            Com_SigType_u64
#endif

#ifdef COM_RXSIG_FLOAT64SUPP
        ,(P2VAR(float64, TYPEDEF, COM_APPL_DATA))           Com_SigType_f64
#endif

#ifdef COM_RX_SIGNALGROUP
        ,(P2VAR(uint8, TYPEDEF, COM_APPL_DATA))             Com_RxGrpSigType_u8

        ,(P2VAR(uint16, TYPEDEF, COM_APPL_DATA))            Com_RxGrpSigType_u16

        ,(P2VAR(uint32, TYPEDEF, COM_APPL_DATA))            Com_RxGrpSigType_u32

#ifdef COM_RXGRPSIG_INT64
        ,(P2VAR(uint64, TYPEDEF, COM_APPL_DATA))            Com_RxGrpSigType_u64
#endif

#ifdef COM_RXGRPSIG_FLOAT64SUPP
        ,(P2VAR(float64, TYPEDEF, COM_APPL_DATA))           Com_RxGrpSigType_f64
#endif

        ,(P2VAR(uint8, TYPEDEF, COM_APPL_DATA))             Com_SecondRxGrpSigType_u8

        ,(P2VAR(uint16, TYPEDEF, COM_APPL_DATA))            Com_SecondRxGrpSigType_u16

        ,(P2VAR(uint32, TYPEDEF, COM_APPL_DATA))            Com_SecondRxGrpSigType_u32

#ifdef COM_RXGRPSIG_INT64
        ,(P2VAR(uint64, TYPEDEF, COM_APPL_DATA))            Com_SecondRxGrpSigType_u64
#endif

#ifdef COM_RXGRPSIG_FLOAT64SUPP
        ,(P2VAR(float64, TYPEDEF, COM_APPL_DATA))           Com_SecondRxGrpSigType_f64
#endif

#ifdef COM_RX_SIGNALGROUP_ARRAY
        ,(P2VAR(uint8, TYPEDEF, COM_APPL_DATA))             Com_RxSigGrpArrayBuf_u8
#endif

#endif /* #ifdef COM_RX_SIGNALGROUP */

#ifdef COM_RxIPduDeferredProcessing
        ,(P2VAR(uint8, TYPEDEF, COM_APPL_DATA))             Com_DeferredBuffer
#endif
    }

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



#ifdef COM_TX_SIGNALGROUP



/* Tx Group Signal Buffers  */
/* Type: UINT8, SINT8, UINT8_N, BOOLEAN */
#define Com_TxGrpSigType_u8          ( NULL_PTR )

/* Type: UINT16, SINT16 */
#define Com_TxGrpSigType_u16         ( NULL_PTR )

/* Type: UINT32, SINT32 */
#define Com_TxGrpSigType_u32         ( NULL_PTR )

/* Type: UINT64, SINT64 */
#ifdef COM_TXGRPSIG_INT64
#define Com_TxGrpSigType_u64         ( NULL_PTR )
#endif /* #ifdef COM_TXGRPSIG_INT64 */


#ifdef COM_TXGRPSIG_FLOAT64SUPP
/* Type: FLOAT64 */
#define Com_TxGrpSigType_f64         ( NULL_PTR )
#endif /* #ifdef COM_TXGRPSIG_FLOAT64SUPP */




/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_Prv_xTxSigGrpRamBuf_tst, COM_CONST) Com_Prv_xTxSigGrpRamBuf_acst[ 1u ] =
{
    {
        (P2VAR(uint8, TYPEDEF, COM_APPL_DATA))              Com_TxGrpSigType_u8,

        (P2VAR(uint16, TYPEDEF, COM_APPL_DATA))             Com_TxGrpSigType_u16,

        (P2VAR(uint32, TYPEDEF, COM_APPL_DATA))             Com_TxGrpSigType_u32

#ifdef COM_TXGRPSIG_INT64
        ,(P2VAR(uint64, TYPEDEF, COM_APPL_DATA))            Com_TxGrpSigType_u64
#endif

#ifdef COM_TXGRPSIG_FLOAT64SUPP
        ,(P2VAR(float64, TYPEDEF, COM_APPL_DATA))           Com_TxGrpSigType_f64
#endif

    }

};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"


#endif/* #ifdef COM_TX_SIGNALGROUP */


/* ------------------------------------------------------------------------ */
/* Begin section for constants */
#define COM_START_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"

CONST(Com_MainFunctionCfgType, COM_CONST) Com_MainFunctionCfg[ COM_NUM_OF_MAINFUNCTION ] =
{
    {
        /* Com_MainFunctionRx() - cylce time Rx: 0.01 s */
        0u,  /* Start RxIPdu-Id */
        5u,  /* Num of RxIpdus */
        10u /* TimeBase in ms */
    }
    ,{
        /* Com_MainFunctionTx() - cylce time Tx: 0.01 s */
        0u,  /* Start TxIPdu-Id */
        4u,  /* Num of TxIpdus */
        10u /* TimeBase in ms */
    }
};

/* ------------------------------------------------------------------------ */
/* End section for constants */
#define COM_STOP_SEC_CONFIG_DATA_POSTBUILD_UNSPECIFIED
#include "Com_MemMap.h"



