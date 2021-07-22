
#ifndef NVM_PRV_H
#define NVM_PRV_H

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
// Service IDs
// -----------
// Redundant block maintenance service ID
#define NVM_PRV_SERVICE_ID_MAINTAIN_BLOCK (249u)

// Miscellaneous
// -------------
// Magic value used with NvM_Prv_SavedZoneMarker_u32 to detect saved zone resets if NvMRbRamInitCheck is set to quick mode
#define NVM_PRV_SAVED_ZONE_MAGIC_VALUE      (0xABCDEFABuL)

/**
 * Maximum value for the number of written bytes, i.e. number of written bytes cannot exceed this value.
 */
#define NVM_PRV_NR_BYTES_WRITTEN_MAX_VALUE  (0xFFFFFFFFu)
/**
 * Maximum value for the accumulated number of all write requests,
 * i.e. number of written bytes cannot exceed this value.
 */
#define NVM_PRV_CNTR_WRITES_ABS_MAX_VALUE   (0xFFFFFFFFu)
/**
 * Maximum value for the number write requests since last power-on,
 * i.e. number of write requests cannot exceed this value.
 */
#define NVM_PRV_CNTR_WRITES_MAX_VALUE       (0xFFFFu)

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

#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

// Common (i.e. not block-specific) states
// TRACE[NVM506] Hint: All of the following variables are global and hence accessible via debugger
// TRACE[NVM508] The size of all the following variables can be determined via the standard C sizeof operator
extern NvM_Prv_MainStates_tst NvM_Prv_Main_st;

#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
// Private code (defined in various NvM_*.c files)
// -----------------------------------------------
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

#if (NVM_RB_RAM_INIT_CHECK == NVM_RB_RAM_INIT_CHECK_QUICK)
extern void NvM_Prv_SetMarkerSavedZone(uint32 MarkerSavedZone_u32);
extern uint32 NvM_Prv_GetMarkerSavedZone(void);
#endif

#if (NVM_RB_AUX_INTERFACE == STD_ON)
extern void NvM_Prv_InitializeAuxMigrationResult(void);
extern void NvM_Prv_SetAuxMigrationResult(NvM_Prv_idService_tuo idService_uo, NvM_BlockIdType idBlock_uo);
#endif

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2999] the potentially incompatible blocks after layout changes should be
//                                               sanitized by ReadAll at first
extern boolean NvM_Prv_IsSanitizedByReadAll(NvM_BlockIdType idBlock_uo);
#if ((NVM_DYNAMIC_CONFIGURATION == STD_ON) && (NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON))
extern void NvM_Prv_InitializeStateReadAll(void);
#endif

#if ((NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON) || (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON))
extern void NvM_Prv_InitAfterReadAll(boolean isInitAtLayoutChangeRequired_b,
                                     boolean isRemoveNonResistantRequired_b);
#endif

// Main function sub-tasks (defined in NvM_MainFunction+.c)
extern void NvM_Prv_InitializeMainStates(void);
extern void NvM_Prv_UninitializeMainStates(void);
extern boolean NvM_Prv_IsNvmInitialized(void);
extern boolean NvM_Prv_IsNvmIdle(void);
extern NvM_Prv_idService_tuo NvM_Prv_GetActiveService(void);
extern void* NvM_Prv_GetActiveRamBlock(void);
extern boolean NvM_Prv_IsMultiActive(void);
extern boolean NvM_Prv_IsAuxServiceActive(void);
extern NvM_Prv_idJob_ten NvM_Prv_GetJobId(NvM_Prv_ServiceBit_tuo ServiceBit_uo);
extern void NvM_Prv_StartJob(NvM_Prv_idJob_ten idJob_en,
                             NvM_BlockIdType idBlock_uo,
                             uint8* RamBlock_pu8,
                             uint8 idxDataset_u8);

extern void NvM_Prv_MainFunctionArbitrate(void);
extern void NvM_Prv_MainFunctionJobStart(void);
extern void NvM_Prv_MainFunctionPollResult(void);
extern void NvM_Prv_MainFunctionJobComplete(void);
extern void NvM_Prv_MainFunctionResultEval(void);

#if (NVM_RB_REQ_MONITOR == NVM_RB_REQ_MON_WRITE)
extern void NvM_Prv_InitializeWriteMonCntrs(boolean isSavedZoneDataLost_b);
extern void NvM_Prv_IncreaseWriteCounters(NvM_BlockIdType idBlock_uo,
                                          uint16 BlockLength_u16);
#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_H */
#endif
