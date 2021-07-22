
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "NvM_Cfg_SchM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"

/*
 **********************************************************************************************************************
 * Declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

#if ((NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON) || (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON))

static boolean NvM_Prv_IsBlockPartOfRemoveNonResistant(NvM_BlockIdType idBlock_uo);
static boolean NvM_Prv_IsBlockPartOfInitAtLayoutChange(NvM_BlockIdType idBlock_uo);
static boolean NvM_Prv_IsBlockPartOfInitAfterReadAll(NvM_BlockIdType idBlock_uo);
static void NvM_Prv_FindBlocksForInitAfterReadAll(boolean isInitAtLayoutChangeRequired_b,
                                                  boolean isRemoveNonResistantRequired_b);

#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

#if ((NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON) || (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON))
/**
 * \brief
 * This function initiates the internal multi-block request for block initialization after a ReadAll request
 * in case of a layout change.
 * \details
 * This function can be called after detection of a layout change.
 *
 * \param isInitAtLayoutChangeRequired_b
 * - TRUE = Block initialization is required after a layout change
 * - FALSE = No block initialization is required after a layout change
 * \param isRemoveNonResistantRequired_b
 * - TRUE = Removing of non-resistant blocks is required after a layout change
 * - FALSE = No removing of non-resistant blocks is required after a layout change
 */
void NvM_Prv_InitAfterReadAll(boolean isInitAtLayoutChangeRequired_b,
                              boolean isRemoveNonResistantRequired_b)
{
    NvM_Prv_Block_IsNvmEnqueuingForMulti_tpfct IsNvmEnqueuingBlockForInitAfterReadAll_pfct = NULL_PTR;

    if (isInitAtLayoutChangeRequired_b)
    {
        if (isRemoveNonResistantRequired_b)
        {
            IsNvmEnqueuingBlockForInitAfterReadAll_pfct = NvM_Prv_IsBlockPartOfInitAfterReadAll;
        }
        else
        {
            IsNvmEnqueuingBlockForInitAfterReadAll_pfct = NvM_Prv_IsBlockPartOfInitAtLayoutChange;
        }
    }
    else
    {
        if (isRemoveNonResistantRequired_b)
        {
            IsNvmEnqueuingBlockForInitAfterReadAll_pfct = NvM_Prv_IsBlockPartOfRemoveNonResistant;
        }
    }

    SchM_Enter_NvM_Main();

    if (isInitAtLayoutChangeRequired_b)
    {
        // Signal the initialization of blocks at layout change
        // Notes:
        // - Signalling to block #0 indicates that an init phase is to be carried out
        // Multiblock initialization after ReadAll
        NvM_Prv_Block_SetRequest(NVM_PRV_MULTI_BLOCK, NvM_Prv_ServiceBit_InitAtLayoutChange_e);

        if (NvM_Prv_Block_HasIdConfigChanged())
        {
            NvM_Prv_Block_SetRequest(NVM_RB_CONFIG_ID_BLOCK, NvM_Prv_ServiceBit_InitAtLayoutChange_e);
            NvM_Prv_Block_SetRequestResult(NVM_RB_CONFIG_ID_BLOCK, NVM_REQ_PENDING);
        }
    }

    if (isRemoveNonResistantRequired_b)
    {
        // No multiblock removal triggered yet -> put a request for multiblock removal to the multiblock queue
        // Concurrency note: Another multi-block request can not be enqueued concurrently
        //                   because ReadAll still enqueued if NvM initiates InitAfterReadAll
        NvM_Prv_Block_SetRequest(NVM_PRV_MULTI_BLOCK, NvM_Prv_ServiceBit_RemoveNonResistant_e);

        if (NvM_Prv_Block_HasIdConfigChanged())
        {
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2787] Trigger the writing of the configuration ID
            // Note: We already passed the handling of the config ID block in ReadAll processing
            //       -> the request for removal of the config ID block is interpreted as a write request for this block
            //          after all ReadAll is through with all its blocks
            NvM_Prv_Block_SetRequest(NVM_RB_CONFIG_ID_BLOCK, NvM_Prv_ServiceBit_RemoveNonResistant_e);
            NvM_Prv_Block_SetRequestResult(NVM_RB_CONFIG_ID_BLOCK, NVM_REQ_PENDING);
        }
    }

    NvM_Prv_Block_SetIsNvmEnqueuingForMulti(IsNvmEnqueuingBlockForInitAfterReadAll_pfct);

    SchM_Exit_NvM_Main();

    NvM_Prv_FindBlocksForInitAfterReadAll(isInitAtLayoutChangeRequired_b,
                                          isRemoveNonResistantRequired_b);
    NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NULL_PTR);
}

static boolean NvM_Prv_IsBlockPartOfRemoveNonResistant(NvM_BlockIdType idBlock_uo)
{
    // The following conditions must be fulfilled to remove a block after ReadAll:
    return !NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_RESISTANT_TO_CHANGED_SW);
}

static boolean NvM_Prv_IsBlockPartOfInitAtLayoutChange(NvM_BlockIdType idBlock_uo)
{
    // The following conditions must be fulfilled to initialize a block after ReadAll:
    return NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_SELECT_FOR_INIT_AT_LAYOUT_CHANGE);
}

static boolean NvM_Prv_IsBlockPartOfInitAfterReadAll(NvM_BlockIdType idBlock_uo)
{
    // The following conditions must be fulfilled to initialize a block after ReadAll:
    return (
            // initialization contains removing of a block after ReadAll
            NvM_Prv_IsBlockPartOfRemoveNonResistant(idBlock_uo) ||
            // initialization contains restoring of default values for a block after ReadAll
            NvM_Prv_IsBlockPartOfInitAtLayoutChange(idBlock_uo)
           );
}

static void NvM_Prv_FindBlocksForInitAfterReadAll(boolean isInitAtLayoutChangeRequired_b,
                                                  boolean isRemoveNonResistantRequired_b)
{
    NvM_BlockIdType idBlock_uo;
    for (idBlock_uo = NVM_RB_FIRST_USER_BLOCK; idBlock_uo < NVM_CFG_NR_BLOCKS; ++idBlock_uo)
    {
        if (isRemoveNonResistantRequired_b)
        {
            if (NvM_Prv_IsBlockPartOfRemoveNonResistant(idBlock_uo))
            {
                NvM_Prv_Block_SetRequestResult(idBlock_uo, NVM_REQ_PENDING);
                NvM_Prv_Block_SetRequest(idBlock_uo, NvM_Prv_ServiceBit_RemoveNonResistant_e);
            }
        }
        if (isInitAtLayoutChangeRequired_b)
        {
            if (NvM_Prv_IsBlockPartOfInitAtLayoutChange(idBlock_uo))
            {
                NvM_Prv_Block_SetRequestResult(idBlock_uo, NVM_REQ_PENDING);
                // Internally signal that this block can be written during initialization at layout change
                NvM_Prv_Block_SetRequest(idBlock_uo, NvM_Prv_ServiceBit_InitAtLayoutChange_e);
            }
        }
    }
}

#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
