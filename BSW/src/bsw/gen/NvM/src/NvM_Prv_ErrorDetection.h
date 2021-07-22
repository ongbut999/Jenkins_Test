
#ifndef NVM_PRV_ERRORDETECTION_H
#define NVM_PRV_ERRORDETECTION_H
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
// Macro used to initialize the local DET error ID variable used in APIs
#define NVM_PRV_NO_DET_ERROR (0u)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define NVM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "NvM_MemMap.h"

// ID of the most previous error reported via Det_ReportError within NvM (initialized to NVM_PRV_NO_DET_ERROR)
extern NvM_Prv_idDetError_tuo NvM_Prv_idLastDetError_uo;
// ID of the service which triggered the last DET error (initialized to NVM_SERVICE_ID_INIT)
extern NvM_Prv_idService_tuo NvM_Prv_idServiceLastDetError_uo;
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3113] Private variable to store block ID used in NvM service
//                                               which has caused the last DET error
extern NvM_BlockIdType NvM_Prv_idBlockLastDetError_uo;

#define NVM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_ErrorDetection_InitializeDetError(boolean isSavedZoneDataLost_b);
extern void NvM_Prv_ErrorDetection_InitializeProductionErrors(void);
extern void NvM_Prv_ErrorDetection_SetProductionError(NvM_BlockIdType idBlock_uo, uint8 MaskErrorBit_u8);
extern void NvM_Prv_ErrorDetection_IsBlockPending(NvM_Prv_idService_tuo idService_uo,
                                                  NvM_BlockIdType idBlock_uo,
                                                  boolean isBlockPending_b);
extern boolean NvM_Prv_ErrorDetection_IsServiceBitValid(NvM_Prv_idService_tuo idService_uo,
                                                        NvM_BlockIdType idBlock_uo,
                                                        NvM_Prv_ServiceBit_tuo ServiceBit_uo);
extern boolean NvM_Prv_ErrorDetection_IsJobIdValid(NvM_Prv_idService_tuo idService_uo,
                                                   NvM_BlockIdType idBlock_uo,
                                                   NvM_Prv_idJob_ten idJob_en);
extern boolean NvM_Prv_ErrorDetection_IsJobResultMemIfPlausible(NvM_Prv_idService_tuo idService_uo,
                                                                NvM_BlockIdType idBlock_uo,
                                                                MemIf_JobResultType JobResult_en);
extern boolean NvM_Prv_ErrorDetection_IsBlockSizeValidForExplicitSync(NvM_Prv_idService_tuo idService_uo,
                                                                      NvM_BlockIdType idBlock_uo,
                                                                      uint32 SizeRamMirror_u32);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForDataIdx(NvM_Prv_idService_tuo idService_uo,
                                                           NvM_BlockIdType idBlock_uo,
                                                           uint8 const* ptrDataIdx_pcu8);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForRequestResult(NvM_Prv_idService_tuo idService_uo,
                                                                 NvM_BlockIdType idBlock_uo,
                                                                 NvM_RequestResultType const* ptrReqResult_pcuo);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForMigrationResult(NvM_Prv_idService_tuo idService_uo,
                                                                   NvM_BlockIdType idBlock_uo,
                                                                   NvM_Rb_MigrationResult_ten const* ptrMigrationResult_pcen);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForNvmStatus(NvM_Prv_idService_tuo idService_uo,
                                                             NvM_Rb_StatusType const* ptrNvmStatus_pcen);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForBlockLength(NvM_Prv_idService_tuo idService_uo,
                                                               NvM_BlockIdType idBlock_uo,
                                                               uint16 const* ptrBlockLength_pcu16);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForServiceId(NvM_Prv_idService_tuo idService_uo,
                                                             NvM_Prv_idService_tuo const* ptrIdService_pcuo);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForBlockId(NvM_Prv_idService_tuo idService_uo,
                                                           NvM_BlockIdType const* ptrIdBlock_pcuo);
extern boolean NvM_Prv_ErrorDetection_IsPtrValidForVersionInfo(NvM_Prv_idService_tuo idService_uo,
                                                               Std_VersionInfoType const* ptrVersionInfo_pcst);
extern boolean NvM_Prv_ErrorDetection_IsNvmInitialized(NvM_Prv_idService_tuo idService_uo,
                                                       NvM_BlockIdType idBlock_uo);
extern boolean NvM_Prv_ErrorDetection_IsBlockIdValid(NvM_Prv_idService_tuo idService_uo,
                                                     NvM_BlockIdType idBlock_uo,
                                                     boolean isMultiBlockAllowed_b);
extern boolean NvM_Prv_ErrorDetection_IsDefaultDataAvailable(NvM_Prv_idService_tuo idService_uo,
                                                             NvM_BlockIdType idBlock_uo);
extern boolean NvM_Prv_ErrorDetection_IsRamBlockAddressValid(NvM_Prv_idService_tuo idService_uo,
                                                             NvM_BlockIdType idBlock_uo,
                                                             void const* RamBlockAddress_pv);
extern boolean NvM_Prv_ErrorDetection_IsBlockTypeDataset(NvM_Prv_idService_tuo idService_uo,
                                                         NvM_BlockIdType idBlock_uo);
extern boolean NvM_Prv_ErrorDetection_IsBlockIdxValid(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_BlockIdType idBlock_uo,
                                                      uint8 idxData_u8);
extern boolean NvM_Prv_ErrorDetection_IsBlockPriorityImmediate(NvM_Prv_idService_tuo idService_uo,
                                                               NvM_BlockIdType idBlock_uo);
extern boolean NvM_Prv_ErrorDetection_IsBlockWriteProtectionChangeable(NvM_Prv_idService_tuo idService_uo,
                                                                       NvM_BlockIdType idBlock_uo);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_ERRORDETECTION_H */
#endif
