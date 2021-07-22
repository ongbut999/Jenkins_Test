
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "NvM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_Queue.h"
#include "NvM_Prv_ErrorDetection.h"

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */
/**
 * Function-like macro: LIST_ENTRY_ID_JOB_FOR_SERVICE_BIT
 *
 * This macro generates an entry for a job ID in a list of all service bits provided by NvM.
 * s.a. macro LIST_SERVICE_BIT to generate a list for all service bits provided by NvM
 *
 * Paramater:
 * Unused: unused
 * JobName: name of the job for which a job ID will be generated.
 */
#define LIST_ENTRY_ID_JOB_FOR_SERVICE_BIT(Unused, JobName)     NvM_Prv_idJob_##JobName##_e,

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

static NvM_Prv_idJob_ten const NvM_Prv_MapServiceBitToIdJob_caen[NvM_Prv_ServiceBit_nr_e] =
{
    LIST_SERVICE_BIT(LIST_ENTRY_ID_JOB_FOR_SERVICE_BIT)
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

/**
 * Global NvM state information which is not block-specific.
 */
NvM_Prv_MainStates_tst NvM_Prv_Main_st;

#define NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

void NvM_Prv_InitializeMainStates(void)
{
    // Set NvM state to Arbitrate and not to Idle because NvM could get requests before first MainFunction call
    NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_ARBITRATE;

    NvM_Prv_Main_st.idQueueActive_uo = NvM_Prv_idQueue_nrQueues_e;
    NvM_Prv_Main_st.QueueEntry_pst = NULL_PTR;

    NvM_Prv_Main_st.JobData_st.idJob_en = NvM_Prv_idJob_Idle_e;
    NvM_Prv_Main_st.JobData_st.idBlock_uo = 0;
    NvM_Prv_Main_st.JobData_st.RamBlock_pu8 = NULL_PTR;
    NvM_Prv_Main_st.JobData_st.idxDataset_u8 = 0;
    NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_OK;
}

void NvM_Prv_UninitializeMainStates(void)
{
    // Set NvM state to NotInit to make sure that NvM will not accept any requests
    NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_NOT_INIT;

    NvM_Prv_Main_st.idQueueActive_uo = NvM_Prv_idQueue_nrQueues_e;
    NvM_Prv_Main_st.QueueEntry_pst = NULL_PTR;

    NvM_Prv_Main_st.JobData_st.idJob_en = NvM_Prv_idJob_Idle_e;
    NvM_Prv_Main_st.JobData_st.idBlock_uo = 0;
    NvM_Prv_Main_st.JobData_st.RamBlock_pu8 = NULL_PTR;
    NvM_Prv_Main_st.JobData_st.idxDataset_u8 = 0;
    NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_OK;
}

boolean NvM_Prv_IsNvmInitialized(void)
{
    return (NVM_PRV_ACTIVITY_NOT_INIT != NvM_Prv_Main_st.Activity_rAMwM_en);
}

boolean NvM_Prv_IsNvmIdle(void)
{
    return (NVM_PRV_ACTIVITY_IDLE == NvM_Prv_Main_st.Activity_rAMwM_en);
}

NvM_Prv_idService_tuo NvM_Prv_GetActiveService(void)
{
    NvM_Prv_idService_tuo idServiceActive_uo = NVM_SERVICE_ID_INIT;
    if (NULL_PTR != NvM_Prv_Main_st.QueueEntry_pst)
    {
        idServiceActive_uo = NvM_Prv_Main_st.QueueEntry_pst->idService_uo;
    }
    return idServiceActive_uo;
}

void* NvM_Prv_GetActiveRamBlock(void)
{
    void* RamBlock_pv = NULL_PTR;
    if (NULL_PTR != NvM_Prv_Main_st.QueueEntry_pst)
    {
        RamBlock_pv = NvM_Prv_Main_st.QueueEntry_pst->BlockData_pv;
    }
    return RamBlock_pv;
}

boolean NvM_Prv_IsMultiActive(void)
{
    return (NvM_Prv_idQueue_Multi_e == NvM_Prv_Main_st.idQueueActive_uo);
}

boolean NvM_Prv_IsAuxServiceActive(void)
{
    boolean isAuxServiceActive_b = FALSE;

#if (NVM_RB_AUX_INTERFACE == STD_ON)
    isAuxServiceActive_b = (NvM_Prv_idQueue_Aux_e == NvM_Prv_Main_st.idQueueActive_uo);
#endif

    return isAuxServiceActive_b;
}

NvM_Prv_idJob_ten NvM_Prv_GetJobId(NvM_Prv_ServiceBit_tuo ServiceBit_uo)
{
    if (ServiceBit_uo >= NvM_Prv_ServiceBit_nr_e)
    {
        ServiceBit_uo = NvM_Prv_ServiceBit_Unspecified_e;
    }

    return NvM_Prv_MapServiceBitToIdJob_caen[ServiceBit_uo];
}

void NvM_MainFunction(void)
{
    // TRACE[NVM464] Service for performing the processing of the NvM jobs
    // TRACE[NVM256] Same as NVM464
    // TRACE[NVM324] No assumption is made about the invocation timing relative to other BSW main processing functions

    // TRACE[NVM257] Check for proper initialization before doing any real job processing
    // Note: This is done in a strict way here, thereby trying to catch general RAM corruption e.g. by wild pointers
    if ((NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_NOT_INIT) &&
        (NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_IDLE) &&
        (NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_ARBITRATE) &&
        (NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_JOB_START) &&
        (NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_POLL_RESULT) &&
        (NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_JOB_COMPLETE) &&
        (NvM_Prv_Main_st.Activity_rAMwM_en != NVM_PRV_ACTIVITY_RESULT_EVAL))
    {
        // Disallow any further job processing
        NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_NOT_INIT;
    }

    // If NvM is not initialized
    // -> refuse to do anything, report error to Det if this functionality is enabled
    if (NvM_Prv_ErrorDetection_IsNvmInitialized(NVM_SERVICE_ID_MAIN_FUNCTION, 0u))
    {
        // Check whether we shall do request arbitration
        if ((NvM_Prv_Main_st.Activity_rAMwM_en == NVM_PRV_ACTIVITY_IDLE) ||
            (NvM_Prv_Main_st.Activity_rAMwM_en == NVM_PRV_ACTIVITY_ARBITRATE))
        {
            // Perform request arbitration (this may change NvM_Prv_Main_st.Activity_rAMwM_en)
            NvM_Prv_MainFunctionArbitrate();
        }

        // Check whether we shall start a job
        if (NvM_Prv_Main_st.Activity_rAMwM_en == NVM_PRV_ACTIVITY_JOB_START)
        {
            // Start the job identified by NvM_Prv_Main_st.idActiveJob_rMwM_en
            // (this may change NvM_Prv_Main_st.Activity_rAMwM_en)
            NvM_Prv_MainFunctionJobStart();
        }

        // Check whether we shall poll for MemIf jobs
        if (NvM_Prv_Main_st.Activity_rAMwM_en == NVM_PRV_ACTIVITY_POLL_RESULT)
        {
            // Wait for the termination of a MemIf job
            // (this may change NvM_Prv_Main_st.Activity_rAMwM_en)
            NvM_Prv_MainFunctionPollResult();
        }

        // Check whether we shall complete a job
        if (NvM_Prv_Main_st.Activity_rAMwM_en == NVM_PRV_ACTIVITY_JOB_COMPLETE)
        {
            // Complete the job identified by NvM_Prv_Main_st.idActiveJob_rMwM_en
            // (this may change NvM_Prv_Main_st.Activity_rAMwM_en)
            NvM_Prv_MainFunctionJobComplete();
        }

        // Check whether we shall evaluate the result of an asynchronous operation
        if (NvM_Prv_Main_st.Activity_rAMwM_en == NVM_PRV_ACTIVITY_RESULT_EVAL)
        {
            // Evaluate the result of an asynchronous operation (this may change NvM_Prv_Main_st.Activity_rAMwM_en;
            // might also turn a read job into a restore job which is then to be started)
            NvM_Prv_MainFunctionResultEval();
        }

        // TRACE[NVM349] If no further job processing is possible, immediately return
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
