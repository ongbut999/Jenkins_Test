

// TRACE[NVM321]
// NvM file containing all configuration parameters which are to be implemented as constants

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/

#include "NvM.h"
#include "Rte_NvM.h"
#include "MemIf.h"
// TRACE[NVM089]
// Check version compatibility of included header files
#if (!defined(MEMIF_AR_RELEASE_MAJOR_VERSION) || (MEMIF_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
    #error "AUTOSAR major version undefined or mismatched"
#endif

#if (!defined(MEMIF_AR_RELEASE_MINOR_VERSION) || ((MEMIF_AR_RELEASE_MINOR_VERSION != 0) && \
                                                  (MEMIF_AR_RELEASE_MINOR_VERSION != 2)))
# error "AUTOSAR minor version undefined or mismatched"
#endif

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ExplicitSynchronization.h"

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2997]
// Include custumer/user specific declarations

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
*/

// Single block callback of NVRAM block ECUM_CFG_NVM_BLOCK
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType EcuM_Rb_NvMSingleBlockCallbackFunction(uint8 ServiceId, NvM_RequestResultType JobResult);

// RAM block of NVRAM block ECUM_CFG_NVM_BLOCK
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 EcuM_Rb_dataShutdownInfo_st[];

// RAM block of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 RamBlock_DID_F199[];

// RAM block of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 RamBlock_DID_F189[];

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_AllEventsStatusByte
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EventStatusByteReadRamBlockFromNvCallback(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_AllEventsStatusByte
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EventStatusByteWriteRamBlockToNvCallback(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory0
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback0(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory0
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback0(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory1
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback1(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory1
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback1(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback2(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback2(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory3
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback3(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory3
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback3(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory4
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvmReadRamBlockFromNvCallback4(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory4
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_EvMemNvMWriteRamBlockToNvCallback4(void* NvMBuffer);

// Explicit sync read callback of NVRAM block NvMBlockDescriptor_Dem_GenericNvData
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_GenericNVDataReadRamBlockFromNvCallback(void* NvMBuffer);

// Explicit sync write callback of NVRAM block NvMBlockDescriptor_Dem_GenericNvData
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern Std_ReturnType Dem_GenericNVDataWriteRamBlockToNvCallback(void* NvMBuffer);

// RAM block of NVRAM block NvM_NativeBlock_1024_1
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_1[];

// ROM block start address of NVRAM block NvM_NativeBlock_1024_1
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_1[];

// RAM block of NVRAM block NvM_NativeBlock_1024_2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern uint8 Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2[];

// ROM block start address of NVRAM block NvM_NativeBlock_1024_2
/* MR12 RULE 8.5 VIOLATION: If we declared this in NvM_Cfg.h,
                            we would effectively re-export this to all NvM users */
extern const uint8 Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2[];

/*
 **********************************************************************************************************************
 * Assertions
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

// Array containing (persistent Id, block Id) couples sorted by ascendant persistent Ids
const NvM_Prv_PersId_BlockId_tst NvM_Prv_PersId_BlockId_acst[NVM_PRV_NR_PERSISTENT_IDS] =
{
    //{PersId, BlockId}
    {16142, 5}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_AllEventsStatusByte
    {16680, 3}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_SystemFaultRank
    {32872, 8}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory2
    {33128, 9}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory3
    {33384, 6}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory0
    {33640, 7}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory1
    {34408, 10}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory4
    {42447, 11}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_GenericNvData
    {45679, 4}, // NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_DID_VehicleSpeed
    {59972, 12}, // NvMConf_NvMBlockDescriptor_NvM_NativeBlock_1024_1
    {62199, 2}, // NvMConf_NvMBlockDescriptor_ECUM_CFG_NVM_BLOCK
    {63695, 13}, // NvMConf_NvMBlockDescriptor_NvM_NativeBlock_1024_2
};

// TRACE[NVM028_Conf]
// Structure containing common configuration options
const NvM_Prv_Common_tst NvM_Prv_Common_cst = {NULL_PTR, NULL_PTR, NULL_PTR};

// TRACE[NVM061_Conf]
// Array containing block descriptors
// TRACE[NVM140]
// The block descriptor contents are completely determined by configuration
const NvM_Prv_BlockDescriptor_tst NvM_Prv_BlockDescriptors_acst[NVM_CFG_NR_BLOCKS] =
{
    {
        // Block descriptor of NVRAM block NvM_MultiBlock (NvM block ID: 0):
        0, // MemIf block ID (this block is not stored on any memory device)
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[0]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[0]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        0
    },
    {
        // Block descriptor of NVRAM block NvM_ConfigId (NvM block ID: 1):
        0, // MemIf block ID (this block is not stored on any memory device)
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[1]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[1]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        0
    },
    {
        // Block descriptor of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 2, persistent ID: 62199):
        FeeConf_FeeBlockConfiguration_ECUM_CFG_NVM_BLOCK, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[2]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[2]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        &EcuM_Rb_NvMSingleBlockCallbackFunction, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank (NvM block ID: 3, persistent ID: 16680):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_SystemFaultRank, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[3]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[3]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed (NvM block ID: 4, persistent ID: 45679):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_DID_VehicleSpeed, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[4]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[4]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_AllEventsStatusByte (NvM block ID: 5, persistent ID: 16142):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_AllEventsStatusByte, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[5]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[5]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EventStatusByteReadRamBlockFromNvCallback, // Explicit sync read callback
        &Dem_EventStatusByteWriteRamBlockToNvCallback, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory0 (NvM block ID: 6, persistent ID: 33384):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_EvMemEventMemory0, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[6]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[6]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback0, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback0, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory1 (NvM block ID: 7, persistent ID: 33640):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_EvMemEventMemory1, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[7]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[7]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback1, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback1, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory2 (NvM block ID: 8, persistent ID: 32872):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_EvMemEventMemory2, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[8]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[8]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback2, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback2, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory3 (NvM block ID: 9, persistent ID: 33128):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_EvMemEventMemory3, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[9]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[9]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback3, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback3, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory4 (NvM block ID: 10, persistent ID: 34408):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_EvMemEventMemory4, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[10]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[10]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_EvMemNvmReadRamBlockFromNvCallback4, // Explicit sync read callback
        &Dem_EvMemNvMWriteRamBlockToNvCallback4, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvMBlockDescriptor_Dem_GenericNvData (NvM block ID: 11, persistent ID: 42447):
        FeeConf_FeeBlockConfiguration_NvMBlockDescriptor_Dem_GenericNvData, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[11]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        0, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[11]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)NULL_PTR, // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        &Dem_GenericNVDataReadRamBlockFromNvCallback, // Explicit sync read callback
        &Dem_GenericNVDataWriteRamBlockToNvCallback, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvM_NativeBlock_1024_1 (NvM block ID: 12, persistent ID: 59972):
        FeeConf_FeeBlockConfiguration_NvM_NativeBlock_1024_1, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[12]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        1, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[12]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_1), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
    {
        // Block descriptor of NVRAM block NvM_NativeBlock_1024_2 (NvM block ID: 13, persistent ID: 63695):
        FeeConf_FeeBlockConfiguration_NvM_NativeBlock_1024_2, // MemIf block ID
        (const uint16 *) &(NvM_Prv_BlockLengths_acu16[13]), // Block length calculated on compile time
        0, // Device index (0: Fee, 1..254: Ea)
        1, // Number of NV blocks
        1, // Number of ROM blocks
        &(NvM_Prv_RamBlockAdr_acpv[13]), // RAM block data address calculated on compile time
        /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
        (const void *)&(Rte_ROM_ASW_NVM_ASW_NVM_BlockNative_1024_2), // ROM block data address
        NULL_PTR, // Single block callback
        NULL_PTR, // Single block start callback
        NULL_PTR, // Initialization callback
        NULL_PTR, // Explicit sync read callback
        NULL_PTR, // Explicit sync write callback
        NVM_BLOCK_NATIVE, // Block management type
        1, // Job priority (0: Immediate, 1: Standard)
        // Block flags
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL |
        (uint16)NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
    },
};

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
// Runtime Calculation feature disabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_OFF)
// Used to calculate the NV block lengths on compile time
// This variable is mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
const uint16 NvM_Prv_BlockLengths_acu16[NVM_CFG_NR_BLOCKS] =
{
    // Block length of NVRAM block NvM_MultiBlock (NvM block ID: 0)
    1,
    // Block length of NVRAM block NvM_ConfigId (NvM block ID: 1)
    1,
    // Block length of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 2)
    4,
    // Block length of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank (NvM block ID: 3)
    4,
    // Block length of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed (NvM block ID: 4)
    17,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_AllEventsStatusByte (NvM block ID: 5)
    6,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory0 (NvM block ID: 6)
    20,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory1 (NvM block ID: 7)
    20,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory2 (NvM block ID: 8)
    20,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory3 (NvM block ID: 9)
    20,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory4 (NvM block ID: 10)
    20,
    // Block length of NVRAM block NvMBlockDescriptor_Dem_GenericNvData (NvM block ID: 11)
    16,
    // Block length of NVRAM block NvM_NativeBlock_1024_1 (NvM block ID: 12)
    1024,
    // Block length of NVRAM block NvM_NativeBlock_1024_2 (NvM block ID: 13)
    1024,
};
// Used to calculate the RAM block data addresses on compile runtime
// This variable is mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
void * const NvM_Prv_RamBlockAdr_acpv[NVM_CFG_NR_BLOCKS] =
{
    // Permanent RAM address of NVRAM block NvM_MultiBlock (NvM block ID: 0)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NULL_PTR,
    // Permanent RAM address of NVRAM block NvM_ConfigId (NvM block ID: 1)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NULL_PTR,
    // Permanent RAM address of NVRAM block ECUM_CFG_NVM_BLOCK (NvM block ID: 2)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(EcuM_Rb_dataShutdownInfo_st),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_DID_SystemFaultRank (NvM block ID: 3)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(RamBlock_DID_F199),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_DID_VehicleSpeed (NvM block ID: 4)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(RamBlock_DID_F189),
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_AllEventsStatusByte (NvM block ID: 5)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory0 (NvM block ID: 6)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory1 (NvM block ID: 7)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory2 (NvM block ID: 8)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory3 (NvM block ID: 9)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_EvMemEventMemory4 (NvM block ID: 10)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvMBlockDescriptor_Dem_GenericNvData (NvM block ID: 11)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)NvM_Prv_RamMirror_au8,
    // Permanent RAM address of NVRAM block NvM_NativeBlock_1024_1 (NvM block ID: 12)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_1),
    // Permanent RAM address of NVRAM block NvM_NativeBlock_1024_2 (NvM block ID: 13)
    /* MR12 DIR 1.1, 11.6 VIOLATION: Casting to void pointer can always be done safely */
    (void *)&(Rte_CPim_ASW_NVM_ASW_NVM_BlockNative_1024_2),
};
#endif

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"
/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
// Runtime Calculation feature enabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
// Used to calculate the NV block lengths and RAM block data addresses on runtime
// These variables are mapped into the block descriptor NvM_Prv_BlockDescriptors_acst
uint16 NvM_Prv_BlockLengths_au16[NVM_CFG_NR_BLOCKS];
void *NvM_Prv_RamBlockAdr_apv[NVM_CFG_NR_BLOCKS];
# define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
#endif

/*
 **********************************************************************************************************************
 * Functions
 **********************************************************************************************************************
*/
# define NvM_START_SEC_CODE
# include "NvM_MemMap.h"
/********************************************************************************************
 * Initialization of NV block length and RAM block data address (permanent RAM address)     *
 *                                                                                          *
 * In this case NvMRbRuntimeRamBlockConfiguration is enabled                                *
 * + NV block length is defined either by NvMRbNvBlockLengthString or NvMNvBlockLength      *
 * + RAM block data address is still defined by NvMRamBlockDataAddress but now              *
 *   NvMRamBlockDataAddress can also contain C expressions                                  *
 *                                                                                          *
 * Furthermore if explicit sync feature is enabled the explicit sync buffer is defined here *
 * by setting the start address and calculating the buffer size                             *
 * Start address and end address is defined by user in common options with the parameters   *
 * + NvMRbRuntimeRamBufferAddressStart                                                      *
 * + NvMRbRuntimeRamBufferAddressEnd                                                        *
 *                                                                                          *
 * ******************************************************************************************
*/
void NvM_Prv_InitRamBlockProperties(void)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
    // Runtime Calculation feature enabled
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# if (NVM_PRV_HAS_RAM_MIRROR == STD_ON)
    // Calculate explicit synchronization RAM buffer size
    /* MR12 RULE 11.4 VIOLATION: Cast to an integral type is necessary to calculate the size of the object*/
    uint32 RuntimeRamMirrorSize_u32 = (uint32)(0) - (uint32)(0);

    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3029] Calculate explicit synchronization RAM buffer
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3030] Calculate explicit synchronization RAM buffer
    // Set explicit synchronization RAM buffer start address and its size
    NvM_Prv_InitRuntimeRamMirror((uint8 *)(0),
                                 RuntimeRamMirrorSize_u32);
# endif



#endif
}
# define NVM_STOP_SEC_CODE
# include "NvM_MemMap.h"
