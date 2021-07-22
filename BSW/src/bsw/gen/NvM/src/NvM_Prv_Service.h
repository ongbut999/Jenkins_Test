
#ifndef NVM_PRV_SERVICE_H
#define NVM_PRV_SERVICE_H
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

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef struct
{
    NvM_Prv_QueueEntry_tst QueueEntry_st;

    // Result of the requested service
    NvM_RequestResultType Result_uo;
    // Dataset index
    uint8 idxDataset_u8;

    // masks to set new states in stBlock
    uint8 maskBitsToChange_u8;
    uint8 maskBitsNewValue_u8;

} NvM_Prv_BlockData_tst;

typedef boolean (*NvM_Prv_Service_CheckParameter_tpfct)(NvM_Prv_BlockData_tst const* BlockData_pcst);
typedef boolean (*NvM_Prv_Service_CheckBlockData_tpfct)(NvM_Prv_BlockData_tst const* BlockData_pcst);
typedef void (*NvM_Prv_Service_SetBlockData_tpfct)(NvM_Prv_BlockData_tst const* BlockData_pcst);

typedef struct
{
    boolean CheckPendingBlock_b;
    NvM_Prv_Service_CheckParameter_tpfct CheckParameter_pfct;
    NvM_Prv_Service_CheckBlockData_tpfct CheckBlockData_pfct;
    NvM_Prv_Service_SetBlockData_tpfct SetBlockData_pfct;

} NvM_Prv_Service_Configuration_tst;

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

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern Std_ReturnType NvM_Prv_Service_Initiate(NvM_Prv_idQueue_tuo idQueue_uo,
                                               NvM_Prv_BlockData_tst const* BlockData_pcst,
                                               NvM_Prv_Service_Configuration_tst const* ServiceConfiguration_pcst);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
**********************************************************************************************************************
* Inline functions
**********************************************************************************************************************
*/

/* NVM_PRV_SERVICE_H */
#endif
