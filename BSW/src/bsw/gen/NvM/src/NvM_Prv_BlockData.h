
#ifndef NVM_PRV_BLOCKDATA_H
#define NVM_PRV_BLOCKDATA_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM_Prv_BlockDescriptor.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
 */
// Definitions for giving special block IDs some semantics
// ------------------------------------------------------------------------------------------------
/**
 * Definition of the reserved block ID used for multi block operations.
 * TRACE[NVM471]
 */
#define NVM_PRV_MULTI_BLOCK         (0u)

#if (NVM_RB_AUX_INTERFACE == STD_ON)
/**
 * Definition of the block ID used for administrative information related to operations triggered by auxiliary users
 * (for this use case, an additional admin block has been reserved behind all "regular" admin blocks)
 */
# define NVM_PRV_AUX_ADMIN_BLOCK    NVM_CFG_NR_BLOCKS
#endif

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef boolean (*NvM_Prv_Block_IsNvmEnqueuingForMulti_tpfct)(NvM_BlockIdType idBlock_uo);

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
// Declaration of variables containing administrative data for all NVRAM blocks.
// ------------------------------------------------------------------------------------------------
// TRACE[NVM135] Administrative block is private
#define NVM_START_SEC_VAR_SAVED_ZONE_8
#include "NvM_MemMap.h"
/**
 * Declaration of the array containing attribute/status information of all NVRAM blocks.
 */
extern uint8 NvM_Prv_stBlock_rAwAM_au8[NVM_CFG_NR_BLOCKS];
#define NVM_STOP_SEC_VAR_SAVED_ZONE_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_16
#include "NvM_MemMap.h"
/**
 * Declaration of the array containing all requests pending on each NVRAM block.
 */
extern uint16 NvM_Prv_stRequests_rAMwAM_au16[NVM_PRV_NR_BLOCKS_ADMIN];
#define NVM_STOP_SEC_VAR_CLEARED_16
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"
/**
 * Declaration of the array containing results of the last asynchronous request for all NVRAM blocks.
 */
extern NvM_RequestResultType NvM_Prv_stRequestResult_rAwAM_au8[NVM_PRV_NR_BLOCKS_ADMIN];
/**
 * Declaration of the array containing indexes for all NVRAM block.
 */
extern uint8 NvM_Prv_idxDataSet_rAMwA_au8[NVM_PRV_NR_BLOCKS_ADMIN];
#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

# define NVM_START_SEC_VAR_SAVED_ZONE_16
# include "NvM_MemMap.h"
extern uint16 NvM_Prv_idConfigStored_rMwM_u16;   // RAM block of the config ID block
# define NVM_STOP_SEC_VAR_SAVED_ZONE_16
# include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_Block_InitializeData(boolean isSavedZoneDataLost_b);
#if (NVM_RB_AUX_INTERFACE == STD_ON)
extern void NvM_Prv_Block_InitializeDataAux(void);
#endif

extern void NvM_Prv_Block_SetIsNvmEnqueuingForMulti(NvM_Prv_Block_IsNvmEnqueuingForMulti_tpfct IsNvmEnqueuingForMulti_pfct);
extern boolean NvM_Prv_Block_IsNvmEnqueuingForMulti(NvM_BlockIdType idBlock_uo);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
**********************************************************************************************************************
* Inline functions
**********************************************************************************************************************
*/
LOCAL_INLINE boolean NvM_Prv_Block_IsPRamBlockValid(NvM_BlockIdType idBlock_uo)
{
    return ((NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] & NVM_BLOCK_STATE_RAM_VALID) != 0u);
}

LOCAL_INLINE boolean NvM_Prv_Block_IsChanged(NvM_BlockIdType idBlock_uo)
{
    return ((NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] & NVM_BLOCK_STATE_RAM_CHANGED) != 0u);
}

LOCAL_INLINE boolean NvM_Prv_Block_IsTrgWriteAllActive(NvM_BlockIdType idBlock_uo)
{
    boolean isTrgWriteAllActive_b = FALSE;
#if (NVM_RB_SET_WRITEALL_TRIGGER_API == STD_ON)
    isTrgWriteAllActive_b = (NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] & NVM_RB_BLOCK_STATE_MASK_TRG_WRITEALL) != 0u;
#endif
    return isTrgWriteAllActive_b;
}

LOCAL_INLINE boolean NvM_Prv_Block_IsRomDataAmbiguous(NvM_BlockIdType idBlock_uo)
{
    return ((NULL_PTR != NvM_Prv_GetRomBlockAddress(idBlock_uo)) &&
            (NVM_BLOCK_DATASET == NvM_Prv_GetBlockType(idBlock_uo)) &&
            (NvM_Prv_idxDataSet_rAMwA_au8[idBlock_uo] < NvM_Prv_GetNrNonVolatileBlocks(idBlock_uo))
           );
}

LOCAL_INLINE boolean NvM_Prv_Block_IsInRom(NvM_BlockIdType idBlock_uo, uint8 idxDataset_u8)
{
    return ((NVM_BLOCK_DATASET == NvM_Prv_GetBlockType(idBlock_uo)) &&
            (idxDataset_u8 >= NvM_Prv_GetNrNonVolatileBlocks(idBlock_uo)));
}

LOCAL_INLINE boolean NvM_Prv_Block_IsWriteProtected(NvM_BlockIdType idBlock_uo)
{
    return ((NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] & NVM_BLOCK_STATE_WRITE_PROT) != 0u);
}

LOCAL_INLINE boolean NvM_Prv_Block_IsWriteable(NvM_BlockIdType idBlock_uo, uint8 idxDataset_u8)
{
    boolean IsBlockInRom_b = NvM_Prv_Block_IsInRom(idBlock_uo, idxDataset_u8);
    return (!NvM_Prv_Block_IsWriteProtected(idBlock_uo) && !IsBlockInRom_b);
}

LOCAL_INLINE uint8 NvM_Prv_Block_GetIdxDataset(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_idxDataSet_rAMwA_au8[idBlock_uo];
}

LOCAL_INLINE NvM_RequestResultType NvM_Prv_Block_GetRequestResult(NvM_BlockIdType idBlock_uo)
{
    return NvM_Prv_stRequestResult_rAwAM_au8[idBlock_uo];
}

LOCAL_INLINE boolean NvM_Prv_Block_IsRequestPending(NvM_BlockIdType idBlock_uo, uint16 maskService_u16)
{
    return ((NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] & maskService_u16) != 0u);
}

LOCAL_INLINE boolean NvM_Prv_Block_IsPending(NvM_BlockIdType idBlock_uo)
{
    return (NvM_Prv_Block_IsNvmEnqueuingForMulti(idBlock_uo) ||
            ((NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] != 0)
#if (NVM_PRV_MAINTAIN_REDUNDANT_BLOCKS)
              && (NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] != (1u << NvM_Prv_ServiceBit_Maintain_e))
#endif
            )
           );
}

LOCAL_INLINE void NvM_Prv_Block_SetIdxData(NvM_BlockIdType idBlock_uo, uint8 idxData_u8)
{
    NvM_Prv_idxDataSet_rAMwA_au8[idBlock_uo] = idxData_u8;
}

LOCAL_INLINE void NvM_Prv_Block_SetRequestResult(NvM_BlockIdType idBlock_uo, NvM_RequestResultType Result_uo)
{
    NvM_Prv_stRequestResult_rAwAM_au8[idBlock_uo] = Result_uo;
}

LOCAL_INLINE void NvM_Prv_Block_SetRequest(NvM_BlockIdType idBlock_uo, NvM_Prv_ServiceBit_tuo ServiceBit_uo)
{
    NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] |= (1u << ServiceBit_uo);
}

LOCAL_INLINE void NvM_Prv_Block_SetRequests(NvM_BlockIdType idBlock_uo, uint16 maskRequests_u16)
{
    NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] |= maskRequests_u16;
}

LOCAL_INLINE void NvM_Prv_Block_ClearRequests(NvM_BlockIdType idBlock_uo, uint16 maskRequests_u16)
{
    NvM_Prv_stRequests_rAMwAM_au16[idBlock_uo] &= (~maskRequests_u16);
}

LOCAL_INLINE void NvM_Prv_Block_SetState(NvM_BlockIdType idBlock_uo,
                                         uint8 maskBitsToChange_u8,
                                         uint8 maskBitsNewValue_u8)
{
    NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] = ((NvM_Prv_stBlock_rAwAM_au8[idBlock_uo] & (~maskBitsToChange_u8)) |
                                             (maskBitsNewValue_u8 & maskBitsToChange_u8));
}

LOCAL_INLINE boolean NvM_Prv_Block_HasIdConfigChanged(void)
{
    return (NVM_COMPILED_CONFIG_ID != NvM_Prv_idConfigStored_rMwM_u16);
}

LOCAL_INLINE void NvM_Prv_Block_SetIdConfig(uint16 idConfigNew_u16)
{
    NvM_Prv_idConfigStored_rMwM_u16 = idConfigNew_u16;
}

LOCAL_INLINE boolean NvM_Prv_Block_InitIdConfigDuringWriteAll(void)
{
    boolean InitIdConfigDuringWriteAll_b = FALSE;

#if ((NVM_DYNAMIC_CONFIGURATION == STD_ON) && (NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_OFF))
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2901] Signal the writing of the Config ID block
    //                                               in WriteAll when dynamic conf is active and
    //                                               extended dynamic conf is inactive
    InitIdConfigDuringWriteAll_b = NvM_Prv_Block_HasIdConfigChanged();
#endif
    return InitIdConfigDuringWriteAll_b;
}

/* NVM_PRV_BLOCKDATA_H */
#endif
