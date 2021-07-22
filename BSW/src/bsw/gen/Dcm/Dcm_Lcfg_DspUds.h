
#ifndef DCM_LCFG_DSPUDS_H
#define DCM_LCFG_DSPUDS_H
/*
 ***************************************************************************************************
 *    DCM Appl API Prototyes generated from configuration
 ***************************************************************************************************
*/
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
extern FUNC(Std_ReturnType,DCM_APPL_CODE) Dcm_DidServices_F186_ReadData(P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) adrData_pu8);
#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"
#define DCM_START_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"

/***Extern declarations to obtain NRC value from the application in case of E_NOT_OK return from ReadData API ***/
extern FUNC(Std_ReturnType,DCM_APPL_CODE)  DcmAppl_DcmReadDataNRC(VAR(uint16,AUTOMATIC)Did,VAR(uint32,AUTOMATIC)DidSignalPosn,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);



 












































/***ReturnControlToEcu with Internal or No MASK*****/

/***ReturnControlToEcu EXTERNAL CONTROL MASK with MASK SIZE = 1 ***/

/***ReturnControlToEcu EXTERNAL CONTROL MASK with MASK SIZE = 2 ***/ 


/***ReturnControlToEcu EXTERNAL CONTROL MASK with MASK SIZE greater than 2 ***/ 






















/***Routine control Appl functions***/







/***Routine control Appl functions for Range Routine***/






/***Seca dcmDspSecurityGetSeedFnc functions with Useport  USE_ASYNCH_FNC ***/
extern FUNC(Std_ReturnType, DCM_APPL_CODE) GetSeed(VAR(Dcm_SecLevelType,AUTOMATIC) SecLevel_u8,VAR(uint32,AUTOMATIC) Seedlen_u32,VAR(uint32,AUTOMATIC) AccDataRecsize_u32,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) SecurityAccessDataRecord,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Seed,VAR(Dcm_OpStatusType,AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);

/***Seca dcmDspSecurityCompareKeyFnc functions with Useport  USE_ASYNCH_FNC ***/
extern FUNC(Std_ReturnType, DCM_APPL_CODE) CompareKey(VAR(uint32,AUTOMATIC) KeyLen_32,P2VAR(uint8,AUTOMATIC,DCM_INTERN_CONST) Key,VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode);



#define DCM_STOP_SEC_CODE /*Adding this for memory mapping*/
#include "Dcm_Cfg_MemMap.h"



#endif /* DCM_LCFG_DSPUDS_H */
