
#ifndef NVM_PRV_BLOCKDESCRIPTOR_H
#define NVM_PRV_BLOCKDESCRIPTOR_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "Rte_NvM_Type.h"
#include "NvM_Types.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
/**
 * Definition of the immediate job priority for a NVRAM block.
 */
// TRACE[ECUC_NvM_00477]
#define NVM_PRV_JOB_PRIORITY_IMMEDIATE      (0u)

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef Std_ReturnType (*NvM_Prv_ExplicitSync_Copy_tpfct)(void* NvMBuffer_pv);

/**
 * Definition of different bit masks to access different configuration flags withis block descriptors
 */
typedef enum
{
    /// Bit mask definition to get information whether a block shall be processed during NvM_ReadAll.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM117_Conf] Parameter NvMBlockDescriptor:NvMSelectBlockForReadAll
    NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL              = 0x0001,
    /// Bit mask definition to get information whether the block shall be processed during NvM_WriteAll.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM549_Conf] Parameter NvMBlockDescriptor:NvMSelectBlockForWriteAll
    NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL             = 0x0002,
    /// Bit mask definition to get information whether the block shall be processed during NvM_Rb_FirstInitAll.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2828] Parameter NvMBlockDescriptor:NvMRbSelectBlockForFirstInitAll
    NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL        = 0x0004,
    /// Bit mask definition to get information whether the block shall be initialized when a layout change is detected.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2881] Parameter NvMBlockDescriptor:NvMRbInitBlockAtLayoutChange
    NVM_PRV_BLOCK_FLAG_SELECT_FOR_INIT_AT_LAYOUT_CHANGE = 0x0008,
    /// Bit mask definition to get information whether the block is initially write protected.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM033_Conf] Parameter NvMBlockDescriptor:NvMBlockWriteProt
    NVM_PRV_BLOCK_FLAG_WRITE_PROTECTED                  = 0x0010,
    /// Bit mask definition to get information whether the block shall be written only once.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM072_Conf] Parameter NvMBlockDescriptor:NvMWriteBlockOnce
    NVM_PRV_BLOCK_FLAG_WRITE_ONCE                       = 0x0020,
    /// Bit mask definition to get information whether the block shall be resistant to block layout changes.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM483_Conf] ParameterNvMBlockDescriptor:NvMResistantToChangedSw
    NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW          = 0x0040,
    /// Bit mask definition to get information whether the block shall use explicit synchronization mechanism.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM519_Conf] Parameter NvMBlockDescriptor:NvMBlockUseSyncMechanism
    NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM               = 0x0080,
    /// Bit mask definition to get information whether the block shall be processed during NvM_ValidateAll.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[NVM557_Conf] Parameter NvMBlockDescriptor:NvMBlockUseAutoValidation
    NVM_PRV_BLOCK_FLAG_USE_AUTO_VALIDATION              = 0x0100,
    /// Bit mask definition to get information whether the block is using a variable block length.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2996] Parameter NvMBlockDescriptor:NvMRbNvBlockLengthString
    NVM_PRV_BLOCK_FLAG_USE_VARIABLE_BLOCK_LENGTH        = 0x0200,
    /// Bit mask definition to get information whether the block is configured for migration.
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3027] Parameter NvMBlockDescriptor:NvMRbFirstReadDataMigration
    NVM_PRV_BLOCK_FLAG_SELECT_FOR_MIGRATION             = 0x0400,
    /// Bit mask definition to get information whether the block shall be initialized unconditionally
    /// This information is stored in the NVRAM block descriptor, see NvM_Prv_BlockDescriptor_tst.stFlags_u16
    /// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3175] Parameter NvMBlockDescriptor:NvMRbRamInitUnconditional
    NVM_PRV_BLOCK_FLAG_RAM_INIT_UNCONDITIONAL           = 0x0800

} NvM_Prv_BlockConfiguration_ten;

/**
 * Definition of the structure for common configuration options of the NvM used during the runtime.
 * TRACE[NVM028_Conf]
 */
typedef struct
{
    /**
     * Pointer to a callback function which shall be invoked on termination of each asynchronous multi-block request.
     * TRACE[NVM468]
     * TRACE[NVM331]
     * TRACE[NVM500_Conf] Parameter NvMCommon:NvMMultiBlockCallback
     */
    void (*MultiBlockCallback_pfct)(uint8 ServiceId, NvM_RequestResultType JobResult);
    /**
     * Pointer to a callback function which shall be invoked on start of each asynchronous multi-block request.
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2762] Parameter NvMCommon:NvMRbMultiBlockStartCallback
     */
    void (*RbMultiBlockStartCallback_pfct)(uint8 ServiceId);
    /**
     * Pointer to a callback function which shall be invoked on termination of each asynchronous single-block request.
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2842]
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2843] Parameter NvMCommon:NvMRbObserverCallback
     */
    Std_ReturnType (*ObserverCallback_pfct)(NvM_BlockIdType BlockId,
                                            uint8 ServiceId,
                                            NvM_RequestResultType JobResult);
} NvM_Prv_Common_tst;

/**
 * Definition of the structure for a NVRAM block descriptor.
 * A NVRAM block descriptor contains all information about a single NVRAM block needed during the runtime.
 * The NVRAM block descriptors are condensed in the NVRAM block descriptor table.
 * TRACE[NVM061_Conf]
 */
typedef struct
{
    /**
     * Block ID to be passed to the MemIf.
     * Do not confuse this ID with NVRAM block ID used within NvM.
     */
    uint16 idBlockMemIf_u16;
    /**
     * Pointer to the block legth in bytes.
     * If runtime calculation of block lengths is enabled by the NvM configuration then block lengths will be located
     * in RAM so pointer points to a variable with block length calculated during runtime.
     * Otherwise if runtime calculation is disabled by the NvM configuration then block legths will be located
     * in ROM so pointer points to a constant with block length configured during compile time.
     * TRACE[NVM479_Conf] Parameter NvMBlockDescriptor:NvMNvBlockLength
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028] Parameter NvMCommon:NvMRbRuntimeRamBlockConfiguration
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2996] Parameter NvMBlockDescriptor:NvMRbNvBlockLengthString
     */
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
    uint16* nrBlockBytes_pu16;
#else
    uint16 const* nrBlockBytes_pu16;
#endif
    /**
     * Device index where the block is located (Fee / Ea).
     * TRACE[NVM035_Conf] Parameter NvMBlockDescriptor:NvMNvramDeviceId
     */
    uint8 idxDevice_u8;
    /**
     * Number of non-volatile blocks in a contiguous area according to the given block management type.
     * TRACE[NVM480_Conf] Parameter NvMBlockDescriptor:NvMNvBlockNum
     */
    uint8 nrNvBlocks_u8;
    /**
     * Number of multiple ROM blocks in a contiguous area according to the given block management type.
     * TRACE[NVM485_Conf] Parameter NvMBlockDescriptor:NvMRomBlockNum
     */
    uint8 nrRomBlocks_u8;
    /**
     * Pointer to the permanent RAM block data.
     * If this pointer is NULL_PTR then no permanent RAM block data has been configured by the user.
     * If runtime calculation of RAM block data addresses is enabled by the NvM configuration
     * then RAM block data addresses will be located in RAM and pointer points to a void pointer
     * calculated during runtime.
     * Otherwise if runtime calculation is disabled by the NvM configuration then RAM block data addresses
     * will be located in ROM and pointer points to a constant void pointer configured during compile time.
     * TRACE[NVM126]
     * TRACE[NVM482_Conf] Parameter NvMBlockDescriptor:NvMRamBlockDataAddress
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028] Parameter NvMCommon:NvMRbRuntimeRamBlockConfiguration
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3086] Parameter NvMBlockDescriptor:NvMRbRamBlockDataAddressString
     */
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
    void** adrRamBlock_ppv;
#else
    void* const* adrRamBlock_ppv;
#endif
    /**
     * Pointer to the ROM block data.
     * If this pointer is NULL_PTR then no ROM block data has been configured by the user.
     * TRACE[NVM020]
     * TRACE[NVM484_Conf] Parameter NvMBlockDescriptor:NvMRomBlockDataAddress
     */
    void const* adrRomBlock_pcv;
    /**
     * Pointer to the block specific callback function which shall be invoked on termination
     * of each asynchronous single-block request.
     * If this pointer is NULL_PTR then no callback has been configured by the user.
     * TRACE[NVM113]
     * TRACE[NVM467]
     * TRACE[NVM330]
     * TRACE[NVM506_Conf] Parameter NvMBlockDescriptor:NvMSingleBlockCallback
     */
    Std_ReturnType (*SingleBlockCallback_pfct)(uint8 ServiceId, NvM_RequestResultType JobResult);
    /**
     * Pointer to the block specific callback function which shall be invoked on start
     * of each asynchronous single-block request.
     * If this pointer is NULL_PTR then no callback has been configured by the user.
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3056]
     * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3062] Parameter NvMBlockDescriptor:NvMRbSingleBlockStartCallback
     */
    Std_ReturnType (*SingleBlockStartCallback_pfct)(uint8 ServiceId);
    /**
     * Pointer to the block specific callback function which shall be invoked if no ROM block data is available
     * for initialization of the block.
     * If this pointer is NULL_PTR then no callback has been configured by the user.
     * TRACE[NVM469]
     * TRACE[NVM352]
     * TRACE[NVM116_Conf] Parameter NvMBlockDescriptor:NvMInitBlockCallback
     */
    Std_ReturnType (*InitBlockCallback_pfct)(void);
    /**
     * Pointer to the block specific callback function to let the application copy data from the NvM mirror
     * to application's RAM block.
     * If this pointer is NULL_PTR then no callback has been configured by the user.
     * TRACE[NVM540]
     * TRACE[NVM542]
     * TRACE[NVM521_Conf] Parameter NvMBlockDescriptor:NvMReadRamBlockFromNvCallback
     */
    Std_ReturnType (*ReadRamBlockFromNvm_pfct)(void* NvMBuffer);
    /**
     * Pointer the block specific callback function to let the application copy data from the application's RAM block
     * to the NvM mirror.
     * If this pointer is NULL_PTR then no callback has been configured by the user.
     * TRACE[NVM539]
     * TRACE[NVM541]
     * TRACE[NVM520_Conf] Parameter NvMBlockDescriptor:NvMWriteRamBlockToNvCallback
     */
    Std_ReturnType (*WriteRamBlockToNvm_pfct)(void* NvMBuffer);
    /**
     * Block management type.
     * TRACE[NVM062_Conf] Parameter NvMBlockDescriptor:NvMBlockManagementType
     */
    NvM_BlockManagementType BlockManagementType_en;
    /**
     * Block job priority.
     * TRACE[NVM477_Conf] Parameter NvMBlockDescriptor:NvMBlockJobPriority
     */
    uint8 JobPriority_u8;
    /**
     * Bit-field containing several configuration parameter which can be represented by a bit.
     * NvM provides special bit mask to access individual bits from this bit-field:
     * - NVM_PRV_BLOCK_FLAG_SELECT_FOR_READ_ALL
     *   TRACE[NVM117_Conf] Parameter NvMBlockDescriptor:NvMSelectBlockForReadAll
     * - NVM_PRV_BLOCK_FLAG_SELECT_FOR_WRITE_ALL
     *   TRACE[NVM549_Conf] Parameter NvMBlockDescriptor:NvMSelectBlockForWriteAll
     * - NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL
     *   TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2828] Parameter NvMBlockDescriptor:NvMRbSelectBlockForFirstInitAll
     * - NVM_PRV_BLOCK_FLAG_SELECT_FOR_INIT_AT_LAYOUT_CHANGE
     *   TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2881] Parameter NvMBlockDescriptor:NvMRbInitBlockAtLayoutChange
     * - NVM_PRV_BLOCK_FLAG_WRITE_PROTECTED
     *   TRACE[NVM033_Conf] Parameter NvMBlockDescriptor:NvMBlockWriteProt
     * - NVM_PRV_BLOCK_FLAG_WRITE_ONCE
     *   TRACE[NVM072_Conf] Parameter NvMBlockDescriptor:NvMWriteBlockOnce
     * - NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW
     *   TRACE[NVM483_Conf] Parameter NvMBlockDescriptor:NvMResistantToChangedSw
     * - NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM
     *   TRACE[NVM519_Conf] Parameter NvMBlockDescriptor:NvMBlockUseSyncMechanism
     * - NVM_PRV_BLOCK_FLAG_USE_AUTO_VALIDATION
     *   TRACE[NVM557_Conf] Parameter NvMBlockDescriptor:NvMBlockUseAutoValidation
     * - NVM_PRV_BLOCK_FLAG_USE_VARIABLE_BLOCK_LENGTH
     *   TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2996] Parameter NvMBlockDescriptor:NvMRbNvBlockLengthString
     * - NVM_PRV_BLOCK_FLAG_SELECT_FOR_MIGRATION
     *   TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3027] Parameter NvMBlockDescriptor:NvMRbFirstReadDataMigration
     */
    uint16 stFlags_u16;

} NvM_Prv_BlockDescriptor_tst;

/**
 * Definition of the structure to assign the persistent ID to the block ID for a NVRAM block.
 */
typedef struct
{
    uint16          PersistentId_u16;   // Persistent Id
    NvM_BlockIdType BlockId_u16;        // Block Id
} NvM_Prv_PersId_BlockId_tst;

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */
// Declaration of different configuration-dependent data.
// Definition of all this data is done in NvM_Cfg.c.
// ------------------------------------------------------------------------------------------------
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/**
 * Declaration of the container with all common configuration data.
 * TRACE[NVM028_Conf]
 */
extern const NvM_Prv_Common_tst             NvM_Prv_Common_cst;
/**
 * Declaration of the NVRAM block descriptor table.
 * TRACE[NVM061_Conf]
 */
extern const NvM_Prv_BlockDescriptor_tst    NvM_Prv_BlockDescriptors_acst[NVM_CFG_NR_BLOCKS];
/**
 * Declaratiion of the table to get the NvM block ID using the persistent ID.
 */
extern const NvM_Prv_PersId_BlockId_tst     NvM_Prv_PersId_BlockId_acst[NVM_PRV_NR_PERSISTENT_IDS];
/**
 * Declaration of the table with all persistant IDs.
 */
extern const uint16                         NvM_Prv_PersIds_acu16[NVM_CFG_NR_BLOCKS];

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#if (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON)
# define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"

extern uint16 NvM_Prv_BlockLengths_au16[NVM_CFG_NR_BLOCKS];
extern void *NvM_Prv_RamBlockAdr_apv[NVM_CFG_NR_BLOCKS];

# define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# include "NvM_MemMap.h"
#else
# define NVM_START_SEC_CONST_UNSPECIFIED
# include "NvM_MemMap.h"

extern uint16 const NvM_Prv_BlockLengths_acu16[NVM_CFG_NR_BLOCKS];
extern void * const NvM_Prv_RamBlockAdr_acpv[NVM_CFG_NR_BLOCKS];

# define NVM_STOP_SEC_CONST_UNSPECIFIED
# include "NvM_MemMap.h"
#endif

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

// Init-related functions (defined in NvM_Cfg.c)
extern void NvM_Prv_InitRamBlockProperties(void);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
**********************************************************************************************************************
* Inline functions
**********************************************************************************************************************
*/
/**
 * \brief
 * This NvM private function provides information whether a block is configured for the given feature.
 *
 * \param idBlock_uo
 * ID of the block for which the configuration information will be provided.
 * \param SelectionMask_en
 * Bit mask for the configuration information to be provide.
 *
 * \return
 * - TRUE = block is configured for the given feature
 * - FALSE = block is not configured for the given feature
 */
LOCAL_INLINE boolean NvM_Prv_IsBlockSelected(NvM_BlockIdType idBlock_uo,
                                             NvM_Prv_BlockConfiguration_ten SelectionMask_en)
{
    return ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
            ((NvM_Prv_BlockDescriptors_acst[idBlock_uo].stFlags_u16 & ((uint16)SelectionMask_en)) != 0u));
}

/**
 * \brief
 * This NvM private function provides the information whether default data is available for the given block.
 *
 * \param idBlock_uo
 * ID of the block to provide the availability of the default data.
 *
 * \return
 * - TRUE = default data is available
 * - FALSE = default data is not available
 */
LOCAL_INLINE boolean NvM_Prv_IsDefaultDataAvailable(NvM_BlockIdType idBlock_uo)
{
    return ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
            ((NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRomBlock_pcv) ||
             (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].InitBlockCallback_pfct)));
}

/**
 * \brief
 * This NvM private function checks for the given block whether the configured block length is valid.
 *
 * \param idBlock
 * ID of the block for which the block length will be checked.
 *
 * \return
 * - TRUE = block length is valid
 * - FALSE = block length is invalid
 */
LOCAL_INLINE boolean NvM_Prv_IsBlockLengthValid(NvM_BlockIdType idBlock_uo)
{
    return ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
            (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16) &&
            (0u != *NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16));
}

/**
 * \brief
 * This NvM private function checks whether the given block is configured with immediate priority.
 *
 * \param idBlock_uo
 * ID of the block for which the priority will be checked.
 *
 * \return
 * - TRUE = block is configured with immediate priority
 * - FALSE = block is configured with standard priority
 */
LOCAL_INLINE boolean NvM_Prv_HasBlockImmediateJobPriority(NvM_BlockIdType idBlock_uo)
{
    boolean HasBlockImmediateJobPriority_b = FALSE;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
        (NVM_PRV_JOB_PRIORITY_IMMEDIATE == NvM_Prv_BlockDescriptors_acst[idBlock_uo].JobPriority_u8))
    {
        HasBlockImmediateJobPriority_b = TRUE;
    }
#endif
    return HasBlockImmediateJobPriority_b;
}

/**
 * \brief
 * This NvM private function returns the configured block size for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured block size will be returned.
 *
 * \return
 * Configured block size
 */
LOCAL_INLINE uint16 NvM_Prv_GetBlockSize(NvM_BlockIdType idBlock_uo)
{
    uint16 BlockSize_u16 = 0;

    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
        (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16))
    {
        BlockSize_u16 = *NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrBlockBytes_pu16;
    }

    return BlockSize_u16;
}

/**
 * \brief
 * This NvM private function returns the configured block management type for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured block management type will be returned.
 *
 * \return
 * Configured block management type
 */
LOCAL_INLINE NvM_BlockManagementType NvM_Prv_GetBlockType(NvM_BlockIdType idBlock_uo)
{
    NvM_BlockManagementType BlockType = NVM_BLOCK_NATIVE;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        BlockType = NvM_Prv_BlockDescriptors_acst[idBlock_uo].BlockManagementType_en;
    }
    return BlockType;
}

/**
 * \brief
 * This NvM private function returns the configured number of non-volatile data sets for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured number of non-volatile data sets will be returned.
 *
 * \return
 * Configured number of non-volatile data sets
 */
LOCAL_INLINE uint8 NvM_Prv_GetNrNonVolatileBlocks(NvM_BlockIdType idBlock_uo)
{
    uint8 nrNvBlocks_u8 = 0;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        nrNvBlocks_u8 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrNvBlocks_u8;
    }
    return nrNvBlocks_u8;
}

/**
 * \brief
 * This NvM private function returns the configured overall number of data sets for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured overall number of data sets will be returned.
 *
 * \return
 * Configured number of data sets
 */
LOCAL_INLINE uint16 NvM_Prv_GetNrDataIndexes(NvM_BlockIdType idBlock_uo)
{
    uint8 nrDataIndexes = 0;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        nrDataIndexes = (NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrNvBlocks_u8 +
                         NvM_Prv_BlockDescriptors_acst[idBlock_uo].nrRomBlocks_u8);
    }
    return nrDataIndexes;
}

/**
 * \brief
 * This NvM private function returns the pointer to the configured permanent RAM block for the given block.
 *
 * \details
 * If no permanent RAM block is configured for a block then this function returns a NULL pointer.
 *
 * \param idBlock_uo
 * ID of the block for which the pointer to the configured permanent RAM block will be returned.
 *
 * \return
 * Pointer to the configured permanent RAM block
 */
LOCAL_INLINE void * NvM_Prv_GetPRamBlockAddress(NvM_BlockIdType idBlock_uo)
{
    void * PRamBlockAddress_pv = NULL_PTR;
    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
        (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRamBlock_ppv))
    {
        PRamBlockAddress_pv = *NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRamBlock_ppv;
    }

    return PRamBlockAddress_pv;
}

/**
 * \brief
 * This NvM private function returns the pointer to the configured ROM block for the given block.
 *
 * \details
 * If no ROM block is configured for a block then this function returns a NULL pointer.
 *
 * \param idBlock_uo
 * ID of the block for which the pointer to the configured ROM block will be returned.
 *
 * \return
 * Pointer to the configured ROM block
 */
LOCAL_INLINE void const* NvM_Prv_GetRomBlockAddress(NvM_BlockIdType idBlock_uo)
{
    void const* adrRomBlock_pcv = NULL_PTR;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        adrRomBlock_pcv = NvM_Prv_BlockDescriptors_acst[idBlock_uo].adrRomBlock_pcv;
    }
    return adrRomBlock_pcv;
}

/**
 * \brief
 * This NvM private function returns the configured block ID used by the mem interface for the given block.
 *
 * \param idBlock_uo
 * ID of the block for which the block ID used by the mem interface will be returned.
 *
 * \return
 * Configured block ID used by the mem interface
 */
LOCAL_INLINE uint16 NvM_Prv_GetIdBlockMemIf(NvM_BlockIdType idBlock_uo)
{
    uint16 idBlockMemIf_u16 = 0;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        idBlockMemIf_u16 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].idBlockMemIf_u16;
    }
    return idBlockMemIf_u16;
}

/**
 * \brief
 * This NvM private function returns the configured device index where the given block is located (Fee / Ea).
 *
 * \param idBlock_uo
 * ID of the block for which the configured device index will be returned.
 *
 * \return
 * Configured device index where the given block is located
 */
LOCAL_INLINE uint8 NvM_Prv_GetIdxDevice(NvM_BlockIdType idBlock_uo)
{
    uint8 idxDevice_u8 = 0;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        idxDevice_u8 = NvM_Prv_BlockDescriptors_acst[idBlock_uo].idxDevice_u8;
    }
    return idxDevice_u8;
}

/**
 * \brief
 * This NvM private function returns the configured persistent ID of a block identified by index for persistent IDs.
 *
 * \param idxPersistentId_u16
 * Index of the required persistent ID.
 *
 * \return
 * Configured persistent ID of a block identified by index for persistent IDs
 */
LOCAL_INLINE uint16 NvM_Prv_GetIdPersistent(uint16 idxPersistentId_u16)
{
    uint16 PersistentId_u16 = 0;
    if (idxPersistentId_u16 < NVM_PRV_NR_PERSISTENT_IDS)
    {
        PersistentId_u16 = NvM_Prv_PersId_BlockId_acst[idxPersistentId_u16].PersistentId_u16;
    }
    return PersistentId_u16;
}

/**
 * \brief
 * This NvM private function returns the configured NvM ID of a block identified by index for persistent IDs.
 *
 * \param idxPersistentId_u16
 * Index of the required persistent ID.
 *
 * \return
 * Configured NvM ID of a block identified by index for persistent IDs
 */
LOCAL_INLINE NvM_BlockIdType NvM_Prv_GetIdBlock(uint16 idxPersistentId_u16)
{
    uint16 BlockId_u16 = 0;
    if (idxPersistentId_u16 < NVM_PRV_NR_PERSISTENT_IDS)
    {
        BlockId_u16 = NvM_Prv_PersId_BlockId_acst[idxPersistentId_u16].BlockId_u16;
    }
    return BlockId_u16;
}

/**
 * \brief
 * This NvM private function returns the configured pointer to the block specific callback function
 * to copy data from the NvM mirror to the application's RAM block.
 *
 * \param idBlock_uo
 * ID of the block for which the configured copy function will be returned.
 *
 * \return
 * Configured pointer to the copy function
 */
LOCAL_INLINE NvM_Prv_ExplicitSync_Copy_tpfct NvM_Prv_GetCopyFctForRead(NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_ExplicitSync_Copy_tpfct ReadRamBlockFromNvm_pfct = NULL_PTR;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        ReadRamBlockFromNvm_pfct = NvM_Prv_BlockDescriptors_acst[idBlock_uo].ReadRamBlockFromNvm_pfct;
    }
    return ReadRamBlockFromNvm_pfct;
}

/**
 * \brief
 * This NvM private function returns the configured pointer to the block specific callback function
 * to copy data from the application's RAM block to the NvM mirror.
 *
 * \param idBlock_uo
 * ID of the block for which the configured copy function will be returned.
 *
 * \return
 * Configured pointer to the copy function
 */
LOCAL_INLINE NvM_Prv_ExplicitSync_Copy_tpfct NvM_Prv_GetCopyFctForWrite(NvM_BlockIdType idBlock_uo)
{
    NvM_Prv_ExplicitSync_Copy_tpfct WriteRamBlockToNvm_pfct = NULL_PTR;
    if (idBlock_uo < NVM_CFG_NR_BLOCKS)
    {
        WriteRamBlockToNvm_pfct = NvM_Prv_BlockDescriptors_acst[idBlock_uo].WriteRamBlockToNvm_pfct;
    }
    return WriteRamBlockToNvm_pfct;
}

/**
 * \brief
 * This NvM private function returns the configured block specific initializaton callback function.
 * \details
 * If no initializaton callback function is configured for the passed block then this function does nothing and
 * returns E_NOT_OK.
 *
 * \param idBlock_uo
 * ID of the block for which the configured initialization callback function will be invoked.
 *
 * \return
 * E_OK = initialization callback function is configured and has returned E_OK
 * E_NOT_OK = no initialization callback function is configured or has returned E_NOT_OK
 */
LOCAL_INLINE Std_ReturnType NvM_Prv_InvokeInitBlockCallback(NvM_BlockIdType idBlock_uo)
{
    Std_ReturnType RetValue = E_NOT_OK;
    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
        (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].InitBlockCallback_pfct))
    {
        RetValue = NvM_Prv_BlockDescriptors_acst[idBlock_uo].InitBlockCallback_pfct();
    }
    return RetValue;
}

/**
 * \brief
 * This NvM private function invokes the configured block specific single request start callback function.
 * \details
 * If no single request start callback function is configured for the passed block then this function does nothing.
 *
 * \param idBlock_uo
 * ID of the block for which the configured single request start callback function will be invoked.
 * \param idService_uo
 * Id of the request for which the start callback function will be invoked.
 */
LOCAL_INLINE void NvM_Prv_InvokeSingleBlockStartCallback(NvM_BlockIdType idBlock_uo,
                                                         NvM_Prv_idService_tuo idService_uo)
{
    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
        (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockStartCallback_pfct))
    {
        // Start callback function returns allways E_OK so return value can be dropped safely
        (void)(NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockStartCallback_pfct)(idService_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured block specific single request termination callback function.
 * \details
 * If no single request termination callback function is configured for the passed block then this function does nothing.
 *
 * \param idBlock_uo
 * ID of the block for which the configured termination callback function will be invoked.
 * \param idService_uo
 * Id of the request for which the termination callback function will be invoked.
 * \param Result_uo
 * Result of the terminated request.
 */
LOCAL_INLINE void NvM_Prv_InvokeSingleBlockCallback(NvM_BlockIdType idBlock_uo,
                                                    NvM_Prv_idService_tuo idService_uo,
                                                    NvM_RequestResultType Result_uo)
{
    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) &&
        (NULL_PTR != NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockCallback_pfct))
    {
        // Termination callback function returns allways E_OK so return value can be dropped safely
        (void)(NvM_Prv_BlockDescriptors_acst[idBlock_uo].SingleBlockCallback_pfct)(idService_uo, Result_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured observer callback function.
 * \details
 * If no observer callback function is configured for the NvM then this function does nothing.
 *
 * \param idBlock_uo
 * ID of the block to be passed to the configured observer callback function.
 * \param idService_uo
 * Id of the request to be passed to the configured observer callback function.
 * \param Result_uo
 * Result of the request to be passed to the configured observer callback function.
 */
LOCAL_INLINE void NvM_Prv_InvokeObserverCallback(NvM_BlockIdType idBlock_uo,
                                                 NvM_Prv_idService_tuo idService_uo,
                                                 NvM_RequestResultType Result_uo)
{
    if (NULL_PTR != NvM_Prv_Common_cst.ObserverCallback_pfct)
    {
        // Observer callback function returns allways E_OK so return value can be dropped safely
        (void)(NvM_Prv_Common_cst.ObserverCallback_pfct)(idBlock_uo, idService_uo, Result_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured multi-block request start callback function.
 * \details
 * If no multi-block request start callback function is configured then this function does nothing.
 *
 * \param idService_uo
 * Id of the request for which the start callback function will be invoked.
 */
LOCAL_INLINE void NvM_Prv_InvokeMultiStartCallback(NvM_Prv_idService_tuo idService_uo)
{
    if (NULL_PTR != NvM_Prv_Common_cst.RbMultiBlockStartCallback_pfct)
    {
        NvM_Prv_Common_cst.RbMultiBlockStartCallback_pfct(idService_uo);
    }
}

/**
 * \brief
 * This NvM private function invokes the configured multi-block request termination callback function.
 * \details
 * If no multi-block request termination callback function is configured then this function does nothing.
 *
 * \param idService_uo
 * Id of the request to be passed to the configured multi-block request termination callback function.
 * \param Result_uo
 * Result of the request to be passed to the configured multi-block request termination callback function.
 */
LOCAL_INLINE void NvM_Prv_InvokeMultiCallback(NvM_Prv_idService_tuo idService_uo,
                                              NvM_RequestResultType Result_uo)
{
    if (NULL_PTR != NvM_Prv_Common_cst.MultiBlockCallback_pfct)
    {
        NvM_Prv_Common_cst.MultiBlockCallback_pfct(idService_uo, Result_uo);
    }
}

/* NVM_PRV_BLOCKDESCRIPTOR_H */
#endif
