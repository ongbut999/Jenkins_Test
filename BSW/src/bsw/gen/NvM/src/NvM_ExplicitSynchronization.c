
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"
#include "NvM_Prv_ExplicitSynchronization.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

// counter for explicit sync operations
uint8 NvM_Prv_cntrMirrorOperations_u8;

#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

// RAM mirror definition used in explicit synchronization
// TRACE[NVM512] No NvM mirror is allocated if no block uses explicit synchronization
// TRACE[NVM513] Only one mirror is allocated
#if ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_OFF))

# define NVM_START_SEC_VAR_CLEARED_8
# include "NvM_MemMap.h"

uint8 NvM_Prv_RamMirror_au8[NVM_PRV_SIZE_RAM_MIRROR];

# define NVM_STOP_SEC_VAR_CLEARED_8
# include "NvM_MemMap.h"

#elif ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON))

#define BSW_START_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"

// Runtime RAM Block Configuration feature in combination with explicit synchronization needs definition of
// NvM mirror at runtime
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3028]
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3029]
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3030]
uint8 *NvM_Prv_RamMirror_au8;
uint32 NvM_Prv_RntRamMirrorSize_u32;

#define BSW_STOP_SEC_VAR_CLEARED_32
#include "Bsw_MemMap.h"

#endif

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean NvM_Prv_ExplicitSync_IsBlockSizeValid(NvM_BlockIdType idBlock_uo);
LOCAL_INLINE MemIf_JobResultType NvM_Prv_ExplicitSync_CallCopyFct(NvM_Prv_ExplicitSync_Copy_tpfct CopyFunction_pfct,
                                                                  void* RamBlock_pv);

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

void NvM_Prv_ExplicitSync_Initialize(void)
{
    NvM_Prv_cntrMirrorOperations_u8 = 0;
}

boolean NvM_Prv_ExplicitSync_CheckBlockSizes(void)
{
    boolean areBlockSizesValid_b = TRUE;

#if ((NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON) && (NVM_PRV_HAS_RAM_MIRROR == STD_ON))
    NvM_BlockIdType idBlock_uo;

    for (idBlock_uo = NVM_CFG_FIRST_USED_BLOCK; idBlock_uo < NVM_CFG_NR_BLOCKS; ++idBlock_uo)
    {
        if (NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM))
        {
            if (NvM_Prv_GetBlockSize(idBlock_uo) > NvM_Prv_RntRamMirrorSize_u32)
            {
                // BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3100 Indicate bad initialization
                areBlockSizesValid_b = FALSE;
            }
        }
    }
#endif

    return areBlockSizesValid_b;
}

boolean NvM_Prv_ExplicitSync_IsOngoing(void)
{
    return (NvM_Prv_cntrMirrorOperations_u8 > 0u);
}

MemIf_JobResultType NvM_Prv_ExplicitSync_CopyData(NvM_Prv_ExplicitSync_Copy_tpfct CopyFunction_pfct,
                                                  NvM_BlockIdType idBlock_uo)
{
    MemIf_JobResultType stExplicitSync_en = MEMIF_JOB_OK;

#if (NVM_PRV_HAS_RAM_MIRROR == STD_ON)
    void* RamBlock_pv = NvM_Prv_GetActiveRamBlock();

    // Check whether block size is valid and explicit synchronization is enabled and
    if (NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_USE_SYNC_MECHANISM) &&
        (RamBlock_pv == NvM_Prv_RamMirror_au8))
    {
        // Check whether block size is valid
        if (NvM_Prv_ExplicitSync_IsBlockSizeValid(idBlock_uo))
        {
            stExplicitSync_en = NvM_Prv_ExplicitSync_CallCopyFct(CopyFunction_pfct, RamBlock_pv);
        }
        else
        {
            // Explicit synchronization failed
            stExplicitSync_en = MEMIF_JOB_FAILED;
        }
    }
#endif
    return stExplicitSync_en;
}

#if ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON))
void NvM_Prv_InitRuntimeRamMirror(uint8* RamMirror_pu8, uint32 RuntimeRamMirrorSize_u32)
{
    // Set explicit synchronization RAM buffer start address and its size
    NvM_Prv_RamMirror_au8 = RamMirror_pu8;
    NvM_Prv_RntRamMirrorSize_u32 = RuntimeRamMirrorSize_u32;
}
#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline code
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean NvM_Prv_ExplicitSync_IsBlockSizeValid(NvM_BlockIdType idBlock_uo)
{
    boolean isBlockSizeValid_b = TRUE;

#if ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON))
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3049]
    // Only needed if Runtime Block Configuration feature is active
    // In this case RAM mirror length is configured by user and not automatically by BCT
    // => a length missmatch could occurs
    // Check whether the currently NV block length does not exceeds the RAM mirror length
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3049] block size greater than size of the RAM mirror
    //                                               used for explicit synchronization
    isBlockSizeValid_b = NvM_Prv_ErrorDetection_IsBlockSizeValidForExplicitSync(NvM_Prv_GetActiveService(),
                                                                                idBlock_uo,
                                                                                NvM_Prv_RntRamMirrorSize_u32);
#else
    (void)idBlock_uo;
#endif
    return isBlockSizeValid_b;
}

LOCAL_INLINE MemIf_JobResultType NvM_Prv_ExplicitSync_CallCopyFct(NvM_Prv_ExplicitSync_Copy_tpfct CopyFunction_pfct,
                                                                  void* RamBlock_pv)
{
    MemIf_JobResultType stCopyFct_en;

    // Check whether valid copy function is available
    if ((NULL_PTR != CopyFunction_pfct))
    {
        if (E_OK == CopyFunction_pfct(RamBlock_pv))
        {
            // Copy function for explicit synchronization succeeded
            stCopyFct_en = MEMIF_JOB_OK;
            // Reset counter for the next explicit sync operation
            NvM_Prv_cntrMirrorOperations_u8 = 0;
        }
        else
        {
            // Copy function for explicit synchronization failed
            ++NvM_Prv_cntrMirrorOperations_u8;
            // TRACE[NVM579] The maximal number of mirror operation retries is NVM_REPEAT_MIRROR_OPERATIONS
            if (NvM_Prv_cntrMirrorOperations_u8 > NVM_REPEAT_MIRROR_OPERATIONS)
            {
                // Explicit synchronization failed finally
                stCopyFct_en = MEMIF_JOB_FAILED;
                // Reset counter for the next explicit sync operation
                NvM_Prv_cntrMirrorOperations_u8 = 0;
            }
            else
            {
                // -> Retry mirror operation in next cycle
                stCopyFct_en = MEMIF_JOB_PENDING;
            }
        }
    }
    else
    {
        // Explicit synchronization failed
        stCopyFct_en = MEMIF_JOB_FAILED;
        // Reset counter for the next explicit sync operation
        NvM_Prv_cntrMirrorOperations_u8 = 0;
    }
    return stCopyFct_en;
}
