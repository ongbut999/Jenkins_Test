
#ifndef NVM_PRV_QUEUE_H
#define NVM_PRV_QUEUE_H

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

/*
 **********************************************************************************************************************
 * Extern declarations
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern void NvM_Prv_Queue_Initialize(boolean isSavedZoneDataLost_b);
extern boolean NvM_Prv_Queue_IsEmpty(NvM_Prv_idQueue_tuo idQueue_uo);
extern uint16 NvM_Prv_Queue_GetFreeEntries(NvM_Prv_idQueue_tuo idQueue_uo);
extern boolean NvM_Prv_Queue_EnqueueRequest(NvM_Prv_idQueue_tuo idQueue_uo,
                                            NvM_Prv_QueueEntry_tst const* QueueEntry_pcst);
extern void NvM_Prv_Queue_DequeueRequest(NvM_Prv_idQueue_tuo idQueue_uo);
extern NvM_Prv_idQueue_tuo NvM_Prv_Queue_GetEntryToProcess(NvM_Prv_QueueEntry_tst** QueueEntry_ppst);
extern boolean NvM_Prv_Queue_IsMultiEnqueued(NvM_Prv_idService_tuo idService_uo);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/* NVM_PRV_QUEUE_H */
#endif
