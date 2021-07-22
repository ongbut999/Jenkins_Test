
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "Rte_NvM.h"

#include "MemIf.h"
// TRACE[NVM089] Check version compatibility of included header files
#if (!defined(MEMIF_AR_RELEASE_MAJOR_VERSION) || (MEMIF_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
# error "AUTOSAR major version undefined or mismatched"
#endif

#if (!defined(MEMIF_AR_RELEASE_MINOR_VERSION) || ((MEMIF_AR_RELEASE_MINOR_VERSION != 0) && \
                                                  (MEMIF_AR_RELEASE_MINOR_VERSION != 2)))
# error "AUTOSAR minor version undefined or mismatched"
#endif

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"
#include "NvM_Prv_ExplicitSynchronization.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef void (*NvM_Prv_JobStart_tpfct)(NvM_Prv_JobData_tst* JobData_pst);

/*
 **********************************************************************************************************************
 * Local declarations
 **********************************************************************************************************************
 */
static void NvM_Prv_JobStart_Read(NvM_Prv_JobData_tst* JobData_pst);
static void NvM_Prv_JobStart_Write(NvM_Prv_JobData_tst* JobData_pst);
static void NvM_Prv_JobStart_Invalidate(NvM_Prv_JobData_tst* JobData_pst);
static void NvM_Prv_JobStart_Maintain(NvM_Prv_JobData_tst* JobData_pst);
static NvM_Prv_JobStart_tpfct NvM_Prv_GetFctJobStart(NvM_Prv_idJob_ten idJob_en);

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */
#define NvM_Prv_JobStart_Idle_pfct                              NULL_PTR
#define NvM_Prv_JobStart_Read_pfct                              NvM_Prv_JobStart_Read
#define NvM_Prv_JobStart_Write_pfct                             NvM_Prv_JobStart_Write
#define NvM_Prv_JobStart_Erase_pfct                             NvM_Prv_JobStart_Invalidate
#define NvM_Prv_JobStart_Restore_pfct                           NULL_PTR
#define NvM_Prv_JobStart_Maintain_pfct                          NvM_Prv_JobStart_Maintain
#define NvM_Prv_JobStart_Validate_pfct                          NULL_PTR
#define NvM_Prv_JobStart_Invalidate_pfct                        NvM_Prv_JobStart_Invalidate
#define NvM_Prv_JobStart_ReadIdConfigForReadAll_pfct            NvM_Prv_JobStart_Read
#define NvM_Prv_JobStart_InvalidateForFirstInitAll_pfct         NvM_Prv_JobStart_Invalidate
#define NvM_Prv_JobStart_RestoreForImplicitRecovery_pfct        NULL_PTR
#define NvM_Prv_JobStart_InvalidateForRemoveNonResistant_pfct   NvM_Prv_JobStart_Invalidate
#define NvM_Prv_JobStart_Invalid_pfct                           NULL_PTR

/**
 * Function-like macro: LIST_ENTRY_JOB_START_FCT
 *
 * This macro generates an entry for a start job function in a list of all jobs provided by NvM.
 * s.a. macro LIST_ID_JOB to generate a list for all jobs provided by NvM
 *
 * Paramater:
 * Name: name of the job for which a start job function will be generated.
 */
#define LIST_ENTRY_JOB_START_FCT(Name)      NvM_Prv_JobStart_##Name##_pfct,

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

static NvM_Prv_JobStart_tpfct const NvM_Prv_JobStartFcts_capfct[NvM_Prv_idJob_Count_e] =
{
        LIST_ID_JOB(LIST_ENTRY_JOB_START_FCT)
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
static void NvM_Prv_JobStart_Read(NvM_Prv_JobData_tst* JobData_pst)
{
    JobData_pst->Result_en = MEMIF_JOB_PENDING;

    // Start a MemIf_Read job
    if (NvM_Prv_IsBlockSelected(JobData_pst->idBlock_uo, NVM_PRV_BLOCK_FLAG_SELECT_FOR_MIGRATION))
    {
        // Reads all blocks where Migration or variable block length feature is active
        // Migration feature can be active without variable block length feature
        // Variable block length feature neeads activation of Migration feature
        if (E_OK != MemIf_Rb_VarLenRead(NvM_Prv_GetIdxDevice(JobData_pst->idBlock_uo),
                                        NvM_Prv_GetIdBlockMemIf(JobData_pst->idBlock_uo) + JobData_pst->idxDataset_u8,
                                        0,
                                        JobData_pst->RamBlock_pu8,
                                        NvM_Prv_GetBlockSize(JobData_pst->idBlock_uo)))
        {
            // Starting the read job failed
            JobData_pst->Result_en = MEMIF_JOB_FAILED;
        }
    }
    else
    {
        // Reads a normal block without Migration or variable block length feature active
        if (E_OK != MemIf_Read(NvM_Prv_GetIdxDevice(JobData_pst->idBlock_uo),
                               NvM_Prv_GetIdBlockMemIf(JobData_pst->idBlock_uo) + JobData_pst->idxDataset_u8,
                               0,
                               JobData_pst->RamBlock_pu8,
                               NvM_Prv_GetBlockSize(JobData_pst->idBlock_uo)))
        {
            // Starting the read job failed
            JobData_pst->Result_en = MEMIF_JOB_FAILED;
        }
    }
}

static void NvM_Prv_JobStart_Write(NvM_Prv_JobData_tst* JobData_pst)
{
    JobData_pst->Result_en = MEMIF_JOB_PENDING;

    JobData_pst->Result_en = NvM_Prv_ExplicitSync_CopyData(NvM_Prv_GetCopyFctForWrite(JobData_pst->idBlock_uo),
                                                           JobData_pst->idBlock_uo);

    if (MEMIF_JOB_OK == JobData_pst->Result_en )
    {
        // Start a MemIf_Write job
        if (NvM_Prv_IsBlockSelected(JobData_pst->idBlock_uo, NVM_PRV_BLOCK_FLAG_USE_VARIABLE_BLOCK_LENGTH))
        {
            // Write blocks where the block length is variable (defined in NvMRbNvBlockLengthString)
            // Migration feature must be active here
            if (E_OK != MemIf_Rb_VarLenWrite(NvM_Prv_GetIdxDevice(JobData_pst->idBlock_uo),
                                             NvM_Prv_GetIdBlockMemIf(JobData_pst->idBlock_uo) + JobData_pst->idxDataset_u8,
                                             JobData_pst->RamBlock_pu8,
                                             NvM_Prv_GetBlockSize(JobData_pst->idBlock_uo)))
            {
                // Starting the write job failed
                JobData_pst->Result_en  = MEMIF_JOB_FAILED;
            }
            else
            {
                JobData_pst->Result_en  = MEMIF_JOB_PENDING;
            }
        }
        else
        {
            // Write blocks where the length is defined as numeric literal in NvMNvBlockLength
            // Migration feature could be active here
            if (E_OK != MemIf_Write(NvM_Prv_GetIdxDevice(JobData_pst->idBlock_uo),
                                    NvM_Prv_GetIdBlockMemIf(JobData_pst->idBlock_uo) + JobData_pst->idxDataset_u8,
                                    JobData_pst->RamBlock_pu8))
            {
                // Starting the write job failed
                JobData_pst->Result_en  = MEMIF_JOB_FAILED;
            }
            else
            {
                JobData_pst->Result_en  = MEMIF_JOB_PENDING;
            }
        }

#if (NVM_RB_REQ_MONITOR == NVM_RB_REQ_MON_WRITE)
        NvM_Prv_IncreaseWriteCounters(JobData_pst->idBlock_uo, NvM_Prv_GetBlockSize(JobData_pst->idBlock_uo));
#endif
    }
}

static void NvM_Prv_JobStart_Invalidate(NvM_Prv_JobData_tst* JobData_pst)
{
    JobData_pst->Result_en = MEMIF_JOB_PENDING;

    // Start a MemIf_InvalidateBlock job
    if (E_OK != MemIf_InvalidateBlock(NvM_Prv_GetIdxDevice(JobData_pst->idBlock_uo),
                                      NvM_Prv_GetIdBlockMemIf(JobData_pst->idBlock_uo) + JobData_pst->idxDataset_u8))
    {
        // Starting the invalidate job failed
        JobData_pst->Result_en = MEMIF_JOB_FAILED;
    }
}

static void NvM_Prv_JobStart_Maintain(NvM_Prv_JobData_tst* JobData_pst)
{
    JobData_pst->Result_en = MEMIF_JOB_PENDING;

#if (NVM_PRV_MAINTAIN_REDUNDANT_BLOCKS)
    // Start a MemIf_Rb_BlockMaintenance job
    if (E_OK != MemIf_Rb_BlockMaintenance(NvM_Prv_GetIdxDevice(JobData_pst->idBlock_uo),
                                          NvM_Prv_GetIdBlockMemIf(JobData_pst->idBlock_uo) + JobData_pst->idxDataset_u8))
    {
        // Starting the read job failed
        JobData_pst->Result_en = MEMIF_JOB_FAILED;
    }
#endif
}

static NvM_Prv_JobStart_tpfct NvM_Prv_GetFctJobStart(NvM_Prv_idJob_ten idJob_en)
{
    if (idJob_en >= NvM_Prv_idJob_Count_e)
    {
        idJob_en = NvM_Prv_idJob_Invalid_e;
    }
    return NvM_Prv_JobStartFcts_capfct[idJob_en];
}

void NvM_Prv_MainFunctionJobStart(void)
{
    // Start the job identified by idActiveJob_rMwM_en

    NvM_BlockIdType idBlock_uo = NvM_Prv_Main_st.JobData_st.idBlock_uo;

    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3055] Invoke block-start callback function if configured
    // SingleBlockStartCallback shall be called only if available and only for non-auxiliary services
    if (!NvM_Prv_IsAuxServiceActive())
    {
        NvM_Prv_InvokeSingleBlockStartCallback(idBlock_uo, NvM_Prv_GetActiveService());
    }

    if (NvM_Prv_ErrorDetection_IsJobIdValid(NVM_SERVICE_ID_MAIN_FUNCTION,
                                            idBlock_uo,
                                            NvM_Prv_Main_st.JobData_st.idJob_en))
    {
        NvM_Prv_JobStart_tpfct JobStart_pfct = NvM_Prv_GetFctJobStart(NvM_Prv_Main_st.JobData_st.idJob_en);
        if (NULL_PTR != JobStart_pfct)
        {
            JobStart_pfct(&NvM_Prv_Main_st.JobData_st);
        }
        else
        {
            NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_OK;
        }
    }
    else
    {
        // This function may only be called with a known NvM_Prv_Main_st.idActiveJob_rMwM_en
        // (we should actually never get into this branch; it's just there for robustness)
        NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_FAILED;
    }

    if (!NvM_Prv_ExplicitSync_IsOngoing())
    {
        // Determine the next state depending on the job start result
        if (MEMIF_JOB_PENDING == NvM_Prv_Main_st.JobData_st.Result_en)
        {
            // Polling needed
            NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_POLL_RESULT;
        }
        else
        {
            // Job on lower layers failed of successfully finished -> complete job
            NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_JOB_COMPLETE;
        }
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
