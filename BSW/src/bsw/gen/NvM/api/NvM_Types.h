
// TRACE[NVM550] Header file specifying all public NvM types
#ifndef NVM_TYPES_H
#define NVM_TYPES_H

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "MemIf_Types.h"
// TRACE[NVM553] Make pre-compile time configuration accessible via public header
#include "NvM_Cfg.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3050] Enumeration for NvM migration status information
typedef enum
{
    NVM_RB_MIGRATION_RESULT_INIT_E              = 0,    // Initialization value, result not yet available
    NVM_RB_MIGRATION_RESULT_NOT_NECESSARY_E     = 1,    // RAM size == size on medium (migration not necessary)
    NVM_RB_MIGRATION_RESULT_TO_SMALLER_SIZE_E   = 2,    // RAM size < size on medium (remaining data discarded)
    NVM_RB_MIGRATION_RESULT_TO_BIGGER_SIZE_E    = 3,    // RAM size > size on medium (remaining data filled with zero)
    NVM_RB_MIGRATION_RESULT_NOT_DONE_E          = 4,    // Migration not done, because data were not read
    NVM_RB_MIGRATION_RESULT_DEACTIVATED_E       = 5     // Migrations is deactivated by configuration
}NvM_Rb_MigrationResult_ten;

// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2751] Enumeration for general NvM status information
typedef enum
{
    NVM_RB_STATUS_UNINIT = 0,   // NvM is not initialized yet
    NVM_RB_STATUS_IDLE = 1,     // NvM is currently idle
    NVM_RB_STATUS_BUSY = 2      // NvM is currently busy
} NvM_Rb_StatusType;

// TRACE[NVM137] Enumeration of block management types (public because the enum literal names are defined by AUTOSAR)
typedef enum
{
    NVM_BLOCK_NATIVE,     // TRACE[NVM557] Block is a standard block (no redundant storage, no dataset features)
    NVM_BLOCK_REDUNDANT,  // TRACE[NVM558] Like a native block, but with redundant storage on the memory media
    NVM_BLOCK_DATASET     // TRACE[NVM559] Allows several NV blocks and ROM blocks for one RAM block
} NvM_BlockManagementType;

// Enumeration of NvM activities
// TRACE[NVM507] Private type added to public NvM_Types.h to allow AUTOSAR debugging
typedef enum
{
    NVM_PRV_ACTIVITY_NOT_INIT = 0,  // NvM not initialized, job processing prohibited
    NVM_PRV_ACTIVITY_IDLE,          // Arbitrate incoming requests (last arbitration did not find any request)
    NVM_PRV_ACTIVITY_ARBITRATE,     // Arbitrate incoming requests (coming from a busy state)
    NVM_PRV_ACTIVITY_JOB_START,     // Start job
    NVM_PRV_ACTIVITY_POLL_RESULT,   // Wait for the termination of a MemIf job
    NVM_PRV_ACTIVITY_JOB_COMPLETE,  // Complete job after MemIf has finished or if MemIf is not required
    NVM_PRV_ACTIVITY_RESULT_EVAL    // Evaluate the result of the request
} NvM_Prv_Activities_ten;

/**
 * Definition of enumeration for the block request type.
 */
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3061] Enumeration for the block request type
typedef enum
{
    /// Block request type is not available, e.g. NvM not yet initialized.
    NvM_Rb_RequestType_NA_e     = 0,
    /// Multi block request is active.
    NvM_Rb_RequestType_Multi_e,
    /// Single block request is active.
    NvM_Rb_RequestType_Single_e

} NvM_Rb_RequestType_ten;

/**
 * This macro generates lists where each entry corresponds to a job provided by NvM.
 *
 * Each entry of the macro shall look like follows:
 *
 * ENTRY(Name)
 *
 * with:
 * Name          Name of the job for which the entry is generated
 */
#define LIST_ID_JOB(ENTRY)                      \
        ENTRY(Idle)                             \
        ENTRY(Read)                             \
        ENTRY(Write)                            \
        ENTRY(Erase)                            \
        ENTRY(Restore)                          \
        ENTRY(Maintain)                         \
        ENTRY(Validate)                         \
        ENTRY(Invalidate)                       \
        ENTRY(ReadIdConfigForReadAll)           \
        ENTRY(InvalidateForFirstInitAll)        \
        ENTRY(RestoreForImplicitRecovery)       \
        ENTRY(InvalidateForRemoveNonResistant)  \
        ENTRY(Invalid)

#define LIST_ENTRY_ID_JOB(Name)             NvM_Prv_idJob_##Name##_e,

// Enumeration of NvM-internal job IDs
// TRACE[NVM507] Private type added to public NvM_Types.h to allow AUTOSAR debugging
typedef enum
{
    LIST_ID_JOB(LIST_ENTRY_ID_JOB)

    //-------------------------------------------------------------------------
    // This is actually no job ID,
    // in fact this enum value defines count of jobs available in NvM and
    // can be used for array definition
    //-------------------------------------------------------------------------
    NvM_Prv_idJob_Count_e

} NvM_Prv_idJob_ten;

/**
 * This macro generates lists where each entry corresponds to a service bit provided by NvM.
 *
 * Each entry of the macro shall look like follows:
 *
 * ENTRY(ServiceBit, JobName)
 *
 * with:
 * ServiceBit   Service bit for which the entry is generated
 * JobName      Name of the job for which the entry is generated
 */
#define LIST_SERVICE_BIT(ENTRY)                                         \
        ENTRY(ReadAll,              Read                            )   \
        ENTRY(RemoveNonResistant,   InvalidateForRemoveNonResistant )   \
        ENTRY(WriteAll,             Write                           )   \
        ENTRY(FirstInitAll,         Idle                            )   \
        ENTRY(Maintain,             Maintain                        )   \
        ENTRY(InitAtLayoutChange,   Write                           )   \
        ENTRY(ValidateAll,          Validate                        )   \
        ENTRY(NotUsed_0,            Invalid                         )   \
        ENTRY(Read,                 Read                            )   \
        ENTRY(Write,                Write                           )   \
        ENTRY(Invalidate,           Invalidate                      )   \
        ENTRY(Erase,                Erase                           )   \
        ENTRY(Restore,              Restore                         )   \
        ENTRY(NotUsed_1,            Invalid                         )   \
        ENTRY(NotUsed_2,            Invalid                         )   \
        ENTRY(NotUsed_3,            Invalid                         )   \
        ENTRY(Unspecified,          Invalid                         )

#define LIST_ENTRY_SERVICE_BIT(ServiceBit, Unused)      NvM_Prv_ServiceBit_##ServiceBit##_e,

/**
 * \brief
 * Definition of different bits for all asynchronous services provided by NvM.
 * \details
 * These bits are used to define corresponding masks for service flags in the administrative blocks.
 * A set bit in the administrative block signals that the corresponding service has been requested.
 *
 * Definition of bit masks as anonymous enumeration instead of several prepocessor defines is done
 * to get better structuring to show that all these bit masks belongs together.
 */
enum
{
    LIST_SERVICE_BIT(LIST_ENTRY_SERVICE_BIT)

    NvM_Prv_ServiceBit_nr_e
};

/// Type definition of different bits for all services provided by NvM.
// TRACE[NVM507] Private type added to public NvM_Types.h to allow AUTOSAR debugging
typedef uint16 NvM_Prv_ServiceBit_tuo;

/// Type definition for services provided by NvM.
/// NvM defines individual service IDs within NvM.h since these IDs are part of the public interface.
// TRACE[NVM507] Private type added to public NvM_Types.h to allow AUTOSAR debugging
typedef uint8 NvM_Prv_idService_tuo;

/// Type definition for DET errors which can be reported by NvM.
/// NvM defines individual DET error IDs within NvM.h since these IDs are part of the public interface.
typedef uint8 NvM_Prv_idDetError_tuo;

/**
 * \brief
 * Definition of different queue IDs used by NvM.
 * \details
 * The order of IDs defines also the priority of the corresponding queue in ascending order .
 */
enum
{
    NvM_Prv_idQueue_Multi_e,        //> ID of the queue for multi-block requests

#if (NVM_RB_AUX_INTERFACE == STD_ON)
    NvM_Prv_idQueue_Aux_e,          //> ID of the queue for auxiliary single block requests
#endif

    NvM_Prv_idQueue_Standard_e,     //> ID of the queue for single block requests with standard priority

// TRACE[NVM564] NvMJobPrioritization enables/disables immediate job processing
#if (NVM_JOB_PRIORITIZATION == STD_ON)
    NvM_Prv_idQueue_Immediate_e,    //> ID of the queue for single block requests with immediate priority
#endif

    //-------------------------------------------------------------------------
    // Add IDs of new queues before this line
    NvM_Prv_idQueue_nrQueues_e      //> Number of queues available in NvM
};

/// Type definition for queues used by NvM.
typedef uint8 NvM_Prv_idQueue_tuo;

// Structure for holding one single block queue entry
// TRACE[NVM507] Private type added to public NvM_Types.h to allow AUTOSAR debugging
typedef struct
{
    /// ID of the requested block service
    NvM_Prv_idService_tuo idService_uo;

    /// ID of the block for which a service is requested
    NvM_BlockIdType idBlock_uo;

    /// Service bit for the requested block service
    NvM_Prv_ServiceBit_tuo ServiceBit_uo;

    /// Pointer to the buffer holding the block data
    // TRACE[NVM088] No assumptions can be made about alignment, hence a void pointer
    void *BlockData_pv;

} NvM_Prv_QueueEntry_tst;

typedef struct
{
    ///ID of the job to be executed by the NvM (NVM_PRV_JOB_ID_IDLE if no job shall be executed)
    NvM_Prv_idJob_ten idJob_en;
    /// Id of the block used in the NvM job
    NvM_BlockIdType idBlock_uo;
    /// Pointer to the RAM block used in the NvM job
    uint8* RamBlock_pu8;
    /// Index of the dataset used in currently active job
    uint8 idxDataset_u8;
    /// Lower layers result of the currently active job
    MemIf_JobResultType Result_en;

} NvM_Prv_JobData_tst;

// Structure for holding all state information which is not block-specific
// (to have these variables gathered in one struct both optimizes resources and eases debugging)
// TRACE[NVM507] Private type added to public NvM_Types.h to allow AUTOSAR debugging
typedef struct
{
    // General NvM state
    // TRACE[NVM399] Flag indicating whether the NvM already has been initialized
    // TRACE[NVM510] This flag is available for debugging
    NvM_Prv_Activities_ten  Activity_rAMwM_en;

    // ID of the queue with currently ongoing request (NvM_Prv_idQueue_nrQueues_e if no request is currently ongoing)
    NvM_Prv_idQueue_tuo idQueueActive_uo;
    /// Pointer to the data of the currently active request
    NvM_Prv_QueueEntry_tst* QueueEntry_pst;

    // Data of the currently active job
    NvM_Prv_JobData_tst JobData_st;

} NvM_Prv_MainStates_tst;

/* NVM_TYPES_H */
#endif
