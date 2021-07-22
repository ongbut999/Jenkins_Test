
#ifndef NVM_PRV_EXPLICITSYNCHRONIZATION_H
#define NVM_PRV_EXPLICITSYNCHRONIZATION_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM_Prv_BlockData.h"

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
#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

// counter for explicit sync operations
extern uint8 NvM_Prv_cntrMirrorOperations_u8;

#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

// RAM mirror definition used in explicit synchronization
#if ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_OFF))
# define NVM_START_SEC_VAR_CLEARED_8
# include "NvM_MemMap.h"
extern uint8 NvM_Prv_RamMirror_au8[NVM_PRV_SIZE_RAM_MIRROR];
# define NVM_STOP_SEC_VAR_CLEARED_8
# include "NvM_MemMap.h"
#elif ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON))
# define BSW_START_SEC_VAR_CLEARED_32
# include "Bsw_MemMap.h"
extern uint8 *NvM_Prv_RamMirror_au8;
extern uint32 NvM_Prv_RntRamMirrorSize_u32;
# define BSW_STOP_SEC_VAR_CLEARED_32
# include "Bsw_MemMap.h"
#endif

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_ExplicitSync_Initialize(void);
extern boolean NvM_Prv_ExplicitSync_CheckBlockSizes(void);
extern boolean NvM_Prv_ExplicitSync_IsOngoing(void);
extern MemIf_JobResultType NvM_Prv_ExplicitSync_CopyData(NvM_Prv_ExplicitSync_Copy_tpfct CopyFunction_pfct,
                                                         NvM_BlockIdType idBlock_uo);

#if ((NVM_PRV_HAS_RAM_MIRROR == STD_ON) && (NVM_PRV_RUNTIME_RAM_BLOCK_CONFIG == STD_ON))
extern void NvM_Prv_InitRuntimeRamMirror(uint8* RamMirror_pu8, uint32 RuntimeRamMirrorSize_u32);

#endif

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_EXPLICITSYNCHRONIZATION_H */
#endif
