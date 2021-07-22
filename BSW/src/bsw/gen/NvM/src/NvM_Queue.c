

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "Rte_NvM.h"

#include "NvM_Prv_Queue.h"
#include "NvM_Prv_ErrorDetection.h"
#include "NvM_Prv_ProcessMultiBlock.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
/**
 * \brief
 * Definition of the structure which defines a queue as circular buffer.
 */
typedef struct
{
    /// Index of the first element (head) in the queue.
    /// The head of the queue is the oldest element so it will be dequeued as first.
    uint16                              idxHead_u16;
    /// Counter of free entries currently available.
    uint16                              cntrFreeEntries_u16;
    /// Maximum number of entries the queue can maintain.
    uint16 const                        size_cu16;
    /// Constant pointer to the component global variable which holds the minimum number of free entries in the queue.
    uint8* const                        minNrFreeEntries_cpu8;
    /// Pointer to the array to store the entries.
    NvM_Prv_QueueEntry_tst* const  data_cpo;

} NvM_Prv_Queue_tst;

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
*/
/**
 * \brief
 * Size definition of the queue for multi-block requests.
 * \details
 * Queue for multi-block requests has always only one entry.
 */
#define NVM_PRV_SIZE_MULTI_QUEUE    (1u)

/**
 * \brief
 * Size definition of the queue for auxiliary requests.
 * \details
 * If enabled by the parameter NvMRbAuxInterface the queue for auxiliary requests has only one entry,
 * otherwise the queue for auxiliary requests is not available -> size = 0.
 */
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2933] Queue for auxiliary requests has only one single entry
#if (NVM_RB_AUX_INTERFACE == STD_ON)
# define NVM_PRV_SIZE_AUX_QUEUE     (1u)
#else
# define NVM_PRV_SIZE_AUX_QUEUE     (0u)
#endif

/**
 * \brief
 * Size definition of the queue for single-block requests with immediate priority.
 * \details
 * If enabled by the parameter NvMJobPrioritization the queue size is defined by the parameter NvMSizeImmediateJobQueue,
 * otherwise the queue is not available -> size = 0.
 * \note
 * If the immediate queue is disabled then NVM_SIZE_IMMEDIATE_JOB_QUEUE = 1 due to the implementation
 * in corrresponding BCT-action. For this reason queue management is using own constant to get queue size 0.
 */
#if (NVM_JOB_PRIORITIZATION == STD_ON)
# define NVM_PRV_SIZE_IMMEDIATE_QUEUE   (NVM_SIZE_IMMEDIATE_JOB_QUEUE)
#else
# define NVM_PRV_SIZE_IMMEDIATE_QUEUE   (0u)
#endif

/**
 * \brief
 * Size definition of the queue for all requests provided by the NvM.
 */
#define NVM_PRV_SIZE_OVERALL_QUEUE (NVM_PRV_SIZE_MULTI_QUEUE    +   \
                                    NVM_PRV_SIZE_AUX_QUEUE      +   \
                                    NVM_SIZE_STANDARD_JOB_QUEUE +   \
                                    NVM_PRV_SIZE_IMMEDIATE_QUEUE)

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
*/
// Queue monitoring
#define NVM_START_SEC_VAR_SAVED_ZONE_8
#include "NvM_MemMap.h"
/// Minimum number of free entries in the standard queue reached so far during the runtime of the ECU.
uint8 NvM_Rb_minNrFreeStdQueueEntries_u8;

#if (NVM_JOB_PRIORITIZATION == STD_ON)
/// Minimum number of free entries in the immediate queue reached so far during the runtime of the ECU.
uint8 NvM_Rb_minNrFreeImmQueueEntries_u8;
#endif

#define NVM_STOP_SEC_VAR_SAVED_ZONE_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

/// Definition of the array for all requests provided by the NvM.
static NvM_Prv_QueueEntry_tst NvM_Prv_Queue_ast[NVM_PRV_SIZE_OVERALL_QUEUE];

#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_INIT_UNSPECIFIED
#include "NvM_MemMap.h"

/// Definition of the array for all queues provided by the NvM.
static NvM_Prv_Queue_tst NvM_Prv_Queues_ast[NvM_Prv_idQueue_nrQueues_e] =
{
    // queue for multi-block requests
    {
        0,                                              // idxHead_u16
        NVM_PRV_SIZE_MULTI_QUEUE,                       // cntrFreeEntries_u16
        NVM_PRV_SIZE_MULTI_QUEUE,                       // size_cu16
        NULL_PTR,                                       // minNrFreeEntries_cpu8
        &NvM_Prv_Queue_ast[0]                           // data_cpo
    },

#if (NVM_RB_AUX_INTERFACE == STD_ON)
    // queue for auxiliary requests
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2932] Own queue for auxiliary jobs
    {
        0,                                              // idxHead_u16
        NVM_PRV_SIZE_AUX_QUEUE,                         // cntrFreeEntries_u16
        NVM_PRV_SIZE_AUX_QUEUE,                         // size_cu16
        NULL_PTR,                                       // minNrFreeEntries_cpu8
        &NvM_Prv_Queue_ast[NVM_PRV_SIZE_MULTI_QUEUE]    // data_cpo
    },
#endif

    // queue for single-block requests with standard priority
    {
        0,                                              // idxHead_u16
        NVM_SIZE_STANDARD_JOB_QUEUE,                    // cntrFreeEntries_u16
        NVM_SIZE_STANDARD_JOB_QUEUE,                    // size_cu16
        &NvM_Rb_minNrFreeStdQueueEntries_u8,            // minNrFreeEntries_cpu8
        &NvM_Prv_Queue_ast[NVM_PRV_SIZE_MULTI_QUEUE +
                           NVM_PRV_SIZE_AUX_QUEUE]      // data_cpo
    }

// TRACE[NVM564] NvMJobPrioritization enables/disables immediate job processing
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    ,
    // queue for single-block requests with immediate priority
    {
        0,                                              // idxHead_u16
        NVM_PRV_SIZE_IMMEDIATE_QUEUE,                   // cntrFreeEntries_u16
        NVM_PRV_SIZE_IMMEDIATE_QUEUE,                   // size_cu16
        &NvM_Rb_minNrFreeImmQueueEntries_u8,            // minNrFreeEntries_cpu8
        &NvM_Prv_Queue_ast[NVM_PRV_SIZE_MULTI_QUEUE +
                           NVM_PRV_SIZE_AUX_QUEUE   +
                           NVM_SIZE_STANDARD_JOB_QUEUE] // data_cpo
    }
#endif
};

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
 * This function initializes all queues used by the NvM.
 * \details
 * Queue data stored in the saved zone will be initialized only if is lost.
 *
 * \param[in] isSavedZoneDataLost_b
 * Status information of the data in the saved zone RAM:
 * - true = data in the saved zone RAM is lost after the reset
 * - false = data in the saved zone RAM is unchanged after the reset
 */
void NvM_Prv_Queue_Initialize(boolean isSavedZoneDataLost_b)
{
    NvM_Prv_idQueue_tuo idQueue_uo;

    for (idQueue_uo = 0; idQueue_uo < NvM_Prv_idQueue_nrQueues_e; ++idQueue_uo)
    {
        NvM_Prv_Queues_ast[idQueue_uo].idxHead_u16 = 0;
        NvM_Prv_Queues_ast[idQueue_uo].cntrFreeEntries_u16 = NvM_Prv_Queues_ast[idQueue_uo].size_cu16;

        if (isSavedZoneDataLost_b && (NvM_Prv_Queues_ast[idQueue_uo].minNrFreeEntries_cpu8 != NULL_PTR))
        {
            *(NvM_Prv_Queues_ast[idQueue_uo].minNrFreeEntries_cpu8) = (uint8)NvM_Prv_Queues_ast[idQueue_uo].size_cu16;
        }
    }
}

/**
 * \brief
 * This function returns the status of the given queue.
 *
 * \param[in] idQueue_uo
 * Id of the queue for which the status is requested.
 *
 * \return
 * - true = given queue is empty
 * - false = given queue has at least one entry
 */
boolean NvM_Prv_Queue_IsEmpty(NvM_Prv_idQueue_tuo idQueue_uo)
{
    return (NvM_Prv_Queues_ast[idQueue_uo].size_cu16 == NvM_Prv_Queues_ast[idQueue_uo].cntrFreeEntries_u16);
}

/**
 * \brief
 * This function returns number of free entries in the given queue.
 *
 * \param[in] idQueue_uo
 * Id of the queue for which the number of free entries is requested.
 *
 * \return
 * Number of free entries
 */
uint16 NvM_Prv_Queue_GetFreeEntries(NvM_Prv_idQueue_tuo idQueue_uo)
{
    uint16 cntrFreeEntries_u16 = 0u;
    if (idQueue_uo < NvM_Prv_idQueue_nrQueues_e)
    {
        cntrFreeEntries_u16 = NvM_Prv_Queues_ast[idQueue_uo].cntrFreeEntries_u16;
    }
    return cntrFreeEntries_u16;
}

/**
 * \brief
 * This function enqueues a block request into the given queue.
 *
 * \param[in] idQueue_uo
 * Id of the queue to enqueue the passed block request.
 * \param[in] QueueEntry_pcst
 * Pointer to the constant block request to be enqueued into the passed queue.
 *
 * \return
 * - true = passed block request enqueued successfully
 * - false = enqueuing of the passed block request has failed
 */
boolean NvM_Prv_Queue_EnqueueRequest(NvM_Prv_idQueue_tuo idQueue_uo,
                                     NvM_Prv_QueueEntry_tst const* QueueEntry_pcst)
{
    boolean isRequestEnqueued_b = FALSE;

    if ((idQueue_uo < NvM_Prv_idQueue_nrQueues_e) && (QueueEntry_pcst != NULL_PTR))
    {
        if (0 == NvM_Prv_Queues_ast[idQueue_uo].cntrFreeEntries_u16)
        {
            // Queue is full -> enqueueing another entry is not possible
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2815] Report a production error in case of queue overflow
            NvM_Prv_ErrorDetection_SetProductionError(QueueEntry_pcst->idBlock_uo, NVM_E_QUEUE_OVERFLOW);
        }
        else
        {
            NvM_Prv_Queue_tst *const Queue_cpst = &(NvM_Prv_Queues_ast[idQueue_uo]);
            uint16 idxEnd_u16;
            uint16 cntrEntries = Queue_cpst->size_cu16 - Queue_cpst->cntrFreeEntries_u16;
            idxEnd_u16 = (Queue_cpst->idxHead_u16 + cntrEntries) % Queue_cpst->size_cu16;

            Queue_cpst->data_cpo[idxEnd_u16].idService_uo = QueueEntry_pcst->idService_uo;
            Queue_cpst->data_cpo[idxEnd_u16].idBlock_uo = QueueEntry_pcst->idBlock_uo;
            Queue_cpst->data_cpo[idxEnd_u16].ServiceBit_uo = QueueEntry_pcst->ServiceBit_uo;
            Queue_cpst->data_cpo[idxEnd_u16].BlockData_pv = QueueEntry_pcst->BlockData_pv;

            --Queue_cpst->cntrFreeEntries_u16;

            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2808]
            // Update the minimum number of standard queue free entries
            // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2809]
            // Update the minimum number of immediate queue free entries
            if ((Queue_cpst->minNrFreeEntries_cpu8 != NULL_PTR) &&
                (Queue_cpst->cntrFreeEntries_u16 < *Queue_cpst->minNrFreeEntries_cpu8))
            {
                *(Queue_cpst->minNrFreeEntries_cpu8) = (uint8)Queue_cpst->cntrFreeEntries_u16;
            }

            isRequestEnqueued_b = TRUE;
        }
    }
    return isRequestEnqueued_b;
}

/**
 * \brief
 * This function dequeues a block request from the given queue.
 *
 * \param[in] idQueue_uo
 * Id of the queue to dequeue the passed block request.
 */
void NvM_Prv_Queue_DequeueRequest(NvM_Prv_idQueue_tuo idQueue_uo)
{
    // check whether the queue has entries
    if ((idQueue_uo < (NvM_Prv_idQueue_tuo)NvM_Prv_idQueue_nrQueues_e) &&
        (NvM_Prv_Queues_ast[idQueue_uo].cntrFreeEntries_u16 < NvM_Prv_Queues_ast[idQueue_uo].size_cu16))
    {
        NvM_Prv_Queue_tst *const Queue_cpst = &(NvM_Prv_Queues_ast[idQueue_uo]);
        Queue_cpst->idxHead_u16 = (Queue_cpst->idxHead_u16 + 1) % Queue_cpst->size_cu16;
        ++Queue_cpst->cntrFreeEntries_u16;
    }
}

/**
 * \brief
 * This function determines which request will be executed as next by the NvM.
 * \details
 * Normally this function goes through all available queues due to the their priority in descending order.
 * And if one queue has an entry to be executed then the pointer to this entry will be returned.
 *
 * If multi-block request is active then this function checks only if immediate queue has an entry.
 * And if immediate queue has no entries or is not available then this function returns the pointer
 * to the multi-block queue.
 *
 * \param[out] QueueEntry_ppst
 * Pointer to the pointer to the queue entry to return the parameter of the next executed request.
 *
 * \return
 * ID of the queue from which the next request to be processed has been taken.
 */
NvM_Prv_idQueue_tuo NvM_Prv_Queue_GetEntryToProcess(NvM_Prv_QueueEntry_tst** QueueEntry_ppst)
{
    NvM_Prv_idQueue_tuo idQueue_uo = NvM_Prv_idQueue_nrQueues_e;

    if (NULL_PTR != QueueEntry_ppst)
    {
        *QueueEntry_ppst = NULL_PTR;
        while ((NULL_PTR == *QueueEntry_ppst) && (idQueue_uo > 0u))
        {
            --idQueue_uo;

            if (NvM_Prv_Multi_IsInProgress() && (NvM_Prv_idQueue_Standard_e == idQueue_uo))
            {
                idQueue_uo = NvM_Prv_idQueue_Multi_e;
            }

            if (!NvM_Prv_Queue_IsEmpty(idQueue_uo))
            {
                *QueueEntry_ppst = &NvM_Prv_Queues_ast[idQueue_uo].data_cpo[NvM_Prv_Queues_ast[idQueue_uo].idxHead_u16];
            }
        }
        if (NULL_PTR == *QueueEntry_ppst)
        {
            idQueue_uo = NvM_Prv_idQueue_nrQueues_e;
        }
    }

    return idQueue_uo;
}

boolean NvM_Prv_Queue_IsMultiEnqueued(NvM_Prv_idService_tuo idService_uo)
{
    boolean IsEnqueuedMulti_b = FALSE;
    if (!NvM_Prv_Queue_IsEmpty(NvM_Prv_idQueue_Multi_e))
    {
        uint16 idxHead_u16 = NvM_Prv_Queues_ast[NvM_Prv_idQueue_Multi_e].idxHead_u16;
        NvM_Prv_idService_tuo idServiceEnqueued_uo =
                NvM_Prv_Queues_ast[NvM_Prv_idQueue_Multi_e].data_cpo[idxHead_u16].idService_uo;
        if (idService_uo == idServiceEnqueued_uo)
        {
            IsEnqueuedMulti_b = TRUE;
        }
    }
    return IsEnqueuedMulti_b;
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
