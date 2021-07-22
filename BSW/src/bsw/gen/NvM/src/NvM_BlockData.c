
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
// Administrative block (as separate arrays for memory mapping, debugging, and struct packing reasons)
// TRACE[NVM134]

#define NVM_START_SEC_VAR_SAVED_ZONE_8
#include "NvM_MemMap.h"
/**
 * Global private array of bit-fields which represents the current attribute/status informations of each NVRAM-block.
 * TRACE[NVM134]
 * TRACE[NVM135]
 * This part of administrative data is located in saved zone RAM due to requirements for quick RAM initialization.
 * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2786]
 *
 * The current state is part of administrative-block as it is required by AUTOSAR.
 * Following states are combined here as a bit-field:
 * - bit 0 = state of the block validness (access mask = NVM_BLOCK_STATE_RAM_VALID)
 *   TRACE[NVM128]
 *   TRACE[NVM132]
 *   TRACE[NVM133]
 * - bit 1 = state of the block change (access mask = NVM_BLOCK_STATE_RAM_CHANGED)
 *   TRACE[NVM344]
 *   TRACE[NVM345]
 *   TRACE[NVM696]
 *   TRACE[NVM472]
 * - bit 2 = state of the WriteAll trigger (access mask = NVM_RB_BLOCK_STATE_MASK_TRG_WRITEALL)
 *   TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2978]
 * - bit 3 = state of the block write protection (access mask = NVM_BLOCK_STATE_WRITE_PROT)
 *   TRACE[NVM054]
 * - bits 4-7 not used
 */
uint8 NvM_Prv_stBlock_rAwAM_au8[NVM_CFG_NR_BLOCKS];

#define NVM_STOP_SEC_VAR_SAVED_ZONE_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_16
#include "NvM_MemMap.h"
/**
 * Global private array of bit-fields which represents all requests pending on each NVRAM-block.
 *
 * Pending requests are part of administrative-block as it is required by AUTOSAR.
 * There are user initiated requests and internally initiated requests.
 * Mapping of pending requests to single bits is defined as follows:
 * - bit  0 = user request ReadAll
 *            (access mask = (1u << NvM_Prv_ServiceBit_ReadAll_e))
 * - bit  1 = internal request to remove non-resistant blocks after ReadAll
 *            (access mask = (1u << NvM_Prv_ServiceBit_RemoveNonResistant_e))
 * - bit  2 = user request WriteAll
 *            (access mask = (1u << NvM_Prv_ServiceBit_WriteAll_e))
 * - bit  3 = user request FirstInitAll
 *            (access mask = (1u << NvM_Prv_ServiceBit_FirstInitAll_e))
 * - bit  4 = internal request to maintain redundant blocks
 *            (access mask = (1u << NvM_Prv_ServiceBit_Maintain_e))
 * - bit  5 = internal request to initialize blocks upon layout change
 *            (access mask = (1u << NvM_Prv_ServiceBit_InitAtLayoutChange_e))
 * - bit  6 = user request ValidateAll
 *            (access mask = (1u << NvM_Prv_ServiceBit_ValidateAll_e))
 * - bit  7 = not used
 * - bit  8 = user request ReadBlock
 *            (access mask = (1u << NvM_Prv_ServiceBit_Read_e))
 * - bit  9 = user request WriteBlock
 *            (access mask = (1u << NvM_Prv_ServiceBit_Write_e))
 * - bit 10 = user request InvalidateBlock
 *            (access mask = (1u << NvM_Prv_ServiceBit_Invalidate_e))
 * - bit 11 = user request EraseBlock
 *            (access mask = (1u << NvM_Prv_ServiceBit_Erase_e))
 * - bit 12 = user request RestoreBlock
 *            (access mask = (1u << NvM_Prv_ServiceBit_Restore_e))
 *
 * TRACE[NVM134]
 */
uint16 NvM_Prv_stRequests_rAMwAM_au16[NVM_PRV_NR_BLOCKS_ADMIN];
#define NVM_STOP_SEC_VAR_CLEARED_16
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"
/**
 * Global private array with results of last request for each NVRAM-block.
 *
 * Request results are part of administrative-block as it is required by AUTOSAR.
 * Following request results are defined:
 * - NVM_REQ_OK                (0) = Last asynchronous request finished successfully
 * - NVM_REQ_NOT_OK            (1) = Last asynchronous request finished unsuccessfully
 * - NVM_REQ_PENDING           (2) = An asynchronous request is currently pending
 * - NVM_REQ_INTEGRITY_FAILED  (3) = Data integrity failure for last read operation
 * - NVM_REQ_BLOCK_SKIPPED     (4) = Referenced block skipped in NvM_ReadAll or NvM_WriteAll
 * - NVM_REQ_NV_INVALIDATED    (5) = Referenced block invalidated
 * - NVM_REQ_CANCELED          (6) = Multiblock write request canceled
 * - NVM_REQ_REDUNDANCY_FAILED (7) = Required redundancy of the referenced block lost
 * - NVM_REQ_RESTORED_FROM_ROM (8) = Referenced block restored from ROM
 *
 * TRACE[NVM134]
 * TRACE[NVM136]
 */
NvM_RequestResultType NvM_Prv_stRequestResult_rAwAM_au8[NVM_PRV_NR_BLOCKS_ADMIN];
/**
 * Global private array with indexes of the dataset blocks to get data from the corresponding data array.
 *
 * Request results are part of administrative-block as it is required by AUTOSAR.
 * TRACE[NVM134]
 * TRACE[NVM144]
 * TRACE[NVM160]
 */
uint8 NvM_Prv_idxDataSet_rAMwA_au8[NVM_PRV_NR_BLOCKS_ADMIN];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"


# define NVM_START_SEC_VAR_SAVED_ZONE_16
# include "NvM_MemMap.h"
uint16 NvM_Prv_idConfigStored_rMwM_u16;            // RAM block of the config ID block
# define NVM_STOP_SEC_VAR_SAVED_ZONE_16
# include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

static NvM_Prv_Block_IsNvmEnqueuingForMulti_tpfct NvM_Prv_Block_IsNvmEnqueuingForMulti_pfct = NULL_PTR;

#define NVM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "NvM_MemMap.h"


/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/**
 * \brief
 * This function initializes the data for all NVRAM-blocks.
 * \details
 * Block status informations will be initialized only if data in the saved zone is lost and
 * unconditional initialization of this block is not configured.
 *
 * \param isSavedZoneDataLost_b
 * Status information of the data in the saved zone RAM:
 * - true = data in the saved zone RAM is lost after the reset
 * - false = data in the saved zone RAM is unchanged after the reset
 */
void NvM_Prv_Block_InitializeData(boolean isSavedZoneDataLost_b)
{
    NvM_BlockIdType idBlock_uo;
    // Initialize all administrative blocks
    for (idBlock_uo = NVM_PRV_MULTI_BLOCK; idBlock_uo < NVM_CFG_NR_BLOCKS; ++idBlock_uo)
    {
        // No request pending
        NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] = 0;
        // TRACE[NVM470] The default value after reset is NVM_REQ_OK
        NvM_Prv_stRequestResult_rAwAM_au8[idBlock_uo] = NVM_REQ_OK;
        // TRACE[NVM192] The dataset index is initialized to zero during init
        NvM_Prv_idxDataSet_rAMwA_au8[idBlock_uo] = 0;

        if (NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_RAM_INIT_UNCONDITIONAL) || isSavedZoneDataLost_b)
        {
            // Current attribute/status informations shall be initialized only if data in the saved zone is lost
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2980] Also reset WriteAllTrigger flag
            // OR
            // Data in saved zone RAM is remained unchanged but RAM block shall be initialized unconditionally
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3174]
            // Reset status informations to initialize permanent RAM block unconditionally by ReadAll

            // Standard RAM state: INVALID/UNCHANGED, no WriteAllTrigger, not write protected
            //                     -> permanent RAM block will be initialized by ReadAll
            NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] = 0;
            // TRACE[NVM326] Enable write protection flag if configured accordingly
            if (NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_WRITE_PROTECTED))
            {
                NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] |= NVM_BLOCK_STATE_WRITE_PROT;
            }
        }
    }
}

#if (NVM_RB_AUX_INTERFACE == STD_ON)
void NvM_Prv_Block_InitializeDataAux(void)
{
    // No request pending
    NvM_Prv_stRequests_rAMwAM_au16[NVM_PRV_AUX_ADMIN_BLOCK] = 0;
    // TRACE[NVM470] The default value after reset is NVM_REQ_OK
    NvM_Prv_stRequestResult_rAwAM_au8[NVM_PRV_AUX_ADMIN_BLOCK] = NVM_REQ_OK;
    // TRACE[NVM192] The dataset index is initialized to zero during init
    NvM_Prv_idxDataSet_rAMwA_au8[NVM_PRV_AUX_ADMIN_BLOCK] = 0;
}
#endif

void NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NvM_Prv_Block_IsNvmEnqueuingForMulti_tpfct IsNvmEnqueuingForMulti_pfct)
{
    NvM_Prv_Block_IsNvmEnqueuingForMulti_pfct = IsNvmEnqueuingForMulti_pfct;
}

boolean NvM_Prv_Block_IsNvmEnqueuingForMulti(NvM_BlockIdType idBlock_uo)
{
    boolean IsBlockPartOfMulti_b = FALSE;

    // if aux service is active then idBlock_uo = NVM_PRV_AUX_ADMIN_BLOCK = NVM_CFG_NR_BLOCKS
    if ((idBlock_uo < NVM_CFG_NR_BLOCKS) && (NULL_PTR != NvM_Prv_Block_IsNvmEnqueuingForMulti_pfct))
    {
        IsBlockPartOfMulti_b = NvM_Prv_Block_IsNvmEnqueuingForMulti_pfct(idBlock_uo);
    }

    return IsBlockPartOfMulti_b;
}

/**
 * \brief
 * This function returns the type of NVRAM storage for given block.
 * \details
 * If passed block ID is invalid then this function returns NVM_BLOCK_NATIVE.
 *
 * \param BlockId
 * Block ID for which the type of NVRAM storage shall be returned.
 *
 * \return
 * NVRAM storage type for given block.
 *
 * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3169]
 */
NvM_BlockManagementType NvM_Rb_GetBlockType(NvM_BlockIdType BlockId)
{
    NvM_BlockManagementType BlockType_uo = NVM_BLOCK_NATIVE;

    if ((BlockId >= NVM_CFG_FIRST_USED_BLOCK) && (BlockId < NVM_CFG_NR_BLOCKS))
    {
        BlockType_uo = NvM_Prv_GetBlockType(BlockId);
    }

    return BlockType_uo;
}
/**
 * \brief
 * This function returns whether the initialization at layout change is enqueued into the queue
 * for multi block requests but is not yet in progress.
 *
 * \param[global in] NvM_Prv_stRequests_rAMwAM_au16[NVM_PRV_MULTI_BLOCK]
 * Element of the global array which contains all pending multi block requests.
 *
 * \return
 * Information whether the initialization at layout change is enqueued:
 * - TRUE = initialization at layout change is enqueued and NOT in progress
 * - FALSE = initialization at layout change is NOT enqueued or is already in progress
 *
 * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3167]
 */
boolean NvM_Rb_IsInitAtLayoutChangeEnqueued(void)
{
    NvM_Prv_idService_tuo idServiceActive_uo = NvM_Prv_GetActiveService();

    return (NvM_Prv_Block_IsRequestPending(NVM_PRV_MULTI_BLOCK, (1u << NvM_Prv_ServiceBit_InitAtLayoutChange_e)) &&
            (NVM_SERVICE_ID_RB_INIT_AFTER_READ_ALL != idServiceActive_uo));
}
/**
 * \brief
 * This function returns whether a block is selected for initialization at layout change.
 * \details
 * If passed block ID is invalid then this function returns FALSE, i.e. a block with invalid ID is never selected
 * for initialization at layout change.
 *
 * \param BlockId
 * Block ID for which the selection status for initialization at layout change shall be returned.
 *
 * \return
 * Selection status for initialization at layout:
 * - TRUE = given block is selected for initialization at layout change
 * - FALSE = given block is NOT selected for initialization at layout change
 *
 * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3164]
 */
boolean NvM_Rb_IsBlockSelectedForInitAtLayoutChange(NvM_BlockIdType BlockId)
{
    boolean isBlockSelected_b = FALSE;

    if ((BlockId >= NVM_CFG_FIRST_USED_BLOCK) && (BlockId < NVM_CFG_NR_BLOCKS))
    {
        isBlockSelected_b = NvM_Prv_IsBlockSelected(BlockId, NVM_PRV_BLOCK_FLAG_SELECT_FOR_INIT_AT_LAYOUT_CHANGE);
    }
    return isBlockSelected_b;
}
/**
 * \brief
 * This function returns whether a block is selected for first initialization.
 * \details
 * If passed block ID is invalid then this function returns FALSE, i.e. a block with invalid ID is never selected
 * for first initialization.
 *
 * \param BlockId
 * Block ID for which the selection status for first initialization shall be returned.
 *
 * \return
 * Selection status for first initialization:
 * - TRUE = given block is selected for first initialization
 * - FALSE = given block is NOT selected for first initialization
 *
 * TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3162]
 */
boolean NvM_Rb_IsBlockSelectedForFirstInitAll(NvM_BlockIdType BlockId)
{
    boolean isBlockSelected_b = FALSE;

    if ((BlockId >= NVM_CFG_FIRST_USED_BLOCK) && (BlockId < NVM_CFG_NR_BLOCKS))
    {
        isBlockSelected_b = NvM_Prv_IsBlockSelected(BlockId, NVM_PRV_BLOCK_FLAG_SELECT_FOR_FIRST_INIT_ALL);
    }
    return isBlockSelected_b;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
