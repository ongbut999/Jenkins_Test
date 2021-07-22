
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"
#include "NvM_Cfg_SchM.h"
#include "Rte_NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_Queue.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"
#include "NvM_Prv_ProcessMultiBlock.h"

/*
 **********************************************************************************************************************
 * Type definitions
 **********************************************************************************************************************
 */
typedef NvM_RequestResultType (*NvM_Prv_JobEvalReqResult_tpfct)(NvM_Prv_JobData_tst const* JobData_pcst);
typedef uint8 (*NvM_Prv_JobEvalProductionErrors_tpfct)(NvM_Prv_JobData_tst const* JobData_pcst);
typedef void (*NvM_Prv_JobUpdateBlockStatus_tpfct)(NvM_Prv_JobData_tst const* JobData_pcst);

/*
 **********************************************************************************************************************
 * Local declarations
 **********************************************************************************************************************
 */
static NvM_RequestResultType NvM_Prv_EvalReqResult(NvM_Prv_JobData_tst const* JobData_pcst);
static NvM_RequestResultType NvM_Prv_EvalReqResult_Read(NvM_Prv_JobData_tst const* JobData_pcst);
static NvM_RequestResultType NvM_Prv_EvalReqResult_InvalidateForRemoveNonResistant(NvM_Prv_JobData_tst const* JobData_pcst);
static NvM_RequestResultType NvM_Prv_EvalReqResult_RestoreForImplicitRecovery(NvM_Prv_JobData_tst const* JobData_pcst);
static NvM_RequestResultType NvM_Prv_EvalReqResult_ReadIdConfigForReadAll(NvM_Prv_JobData_tst const* JobData_pcst);

static uint8 NvM_Prv_EvalProductionErrors(NvM_Prv_JobData_tst const* JobData_pcst);
static uint8 NvM_Prv_EvalProductionErrors_Read(NvM_Prv_JobData_tst const* JobData_pcst);
static uint8 NvM_Prv_EvalProductionErrors_ReadIdConfigForReadAll(NvM_Prv_JobData_tst const* JobData_pcst);

static void NvM_Prv_UpdateBlockStatus_Restore(NvM_Prv_JobData_tst const* JobData_pcst);
static void NvM_Prv_UpdateBlockStatus_ReadWrite(NvM_Prv_JobData_tst const* JobData_pcst);
static void NvM_Prv_UpdateBlockStatusJobValidate(NvM_Prv_JobData_tst const* JobData_pcst);
static void NvM_Prv_UpdateBlockStatusIdConfigForReadAll(NvM_Prv_JobData_tst const* JobData_pcst);

static NvM_Prv_JobEvalReqResult_tpfct NvM_Prv_GetFctJobEvalReqResult(NvM_Prv_idJob_ten idJob_en);
static NvM_Prv_JobEvalProductionErrors_tpfct NvM_Prv_GetFctJobEvalProductionErrors(NvM_Prv_idJob_ten idJob_en);
static NvM_Prv_JobUpdateBlockStatus_tpfct NvM_Prv_GetFctJobUpdateBlockStatus(NvM_Prv_idJob_ten idJob_en);

/*
 **********************************************************************************************************************
 * Inline declarations
 **********************************************************************************************************************
 */
LOCAL_INLINE boolean NvM_Prv_EvalCommonResults(NvM_Prv_JobData_tst const* JobData_pcst,
                                               NvM_RequestResultType* stReqResult_puo,
                                               uint8* stProductionErrors_pu8);
LOCAL_INLINE void NvM_Prv_MainFunctionResultEval_FinalBlockCallbacks(NvM_RequestResultType stRequestResult_uo,
                                                                     NvM_BlockIdType idActiveBlock_uo,
                                                                     NvM_Prv_idService_tuo idActiveService_uo);
LOCAL_INLINE void NvM_Prv_MainFunctionResultEval_ResetMainStates(NvM_BlockIdType idBlock_uo,
                                                                 NvM_Prv_idQueue_tuo idQueue_uo,
                                                                 NvM_Prv_idService_tuo idService_uo,
                                                                 NvM_Prv_ServiceBit_tuo ServiceBit_uo,
                                                                 NvM_RequestResultType stRequestResult_uo);

/*
 **********************************************************************************************************************
 * Constants
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

#define NvM_Prv_EvalResult_Idle_pfct                            NULL_PTR
#define NvM_Prv_EvalResult_Read_pfct                            NvM_Prv_EvalReqResult_Read
#define NvM_Prv_EvalResult_Write_pfct                           NvM_Prv_EvalReqResult
#define NvM_Prv_EvalResult_Erase_pfct                           NvM_Prv_EvalReqResult
#define NvM_Prv_EvalResult_Restore_pfct                         NvM_Prv_EvalReqResult
#define NvM_Prv_EvalResult_Maintain_pfct                        NULL_PTR
#define NvM_Prv_EvalResult_Validate_pfct                        NvM_Prv_EvalReqResult
#define NvM_Prv_EvalResult_Invalidate_pfct                      NvM_Prv_EvalReqResult
#define NvM_Prv_EvalResult_ReadIdConfigForReadAll_pfct          NvM_Prv_EvalReqResult_ReadIdConfigForReadAll
#define NvM_Prv_EvalResult_InvalidateForFirstInitAll_pfct       NvM_Prv_EvalReqResult
#define NvM_Prv_EvalResult_RestoreForImplicitRecovery_pfct      NvM_Prv_EvalReqResult_RestoreForImplicitRecovery
#define NvM_Prv_EvalResult_InvalidateForRemoveNonResistant_pfct NvM_Prv_EvalReqResult_InvalidateForRemoveNonResistant
#define NvM_Prv_EvalResult_Invalid_pfct                         NULL_PTR

/**
 * Function-like macro: LIST_ENTRY_JOB_EVAL_REQ_RESULT_FCT
 *
 * This macro generates an entry for a function to evaluate request result in a list of all jobs provided by NvM.
 * s.a. macro LIST_ID_JOB to generate a list for all jobs provided by NvM
 *
 * Paramater:
 * Name: name of the job for which a function will be generated.
 */
#define LIST_ENTRY_JOB_EVAL_REQ_RESULT_FCT(Name)        NvM_Prv_EvalResult_##Name##_pfct,

static NvM_Prv_JobEvalReqResult_tpfct const NvM_Prv_JobEvalReqResultFcts_capfct[NvM_Prv_idJob_Count_e] =
{
    LIST_ID_JOB(LIST_ENTRY_JOB_EVAL_REQ_RESULT_FCT)
};


#define NvM_Prv_EvalProdErrors_Idle_pfct                            NULL_PTR
#define NvM_Prv_EvalProdErrors_Read_pfct                            NvM_Prv_EvalProductionErrors_Read
#define NvM_Prv_EvalProdErrors_Write_pfct                           NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_Erase_pfct                           NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_Restore_pfct                         NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_Maintain_pfct                        NULL_PTR
#define NvM_Prv_EvalProdErrors_Validate_pfct                        NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_Invalidate_pfct                      NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_ReadIdConfigForReadAll_pfct          NvM_Prv_EvalProductionErrors_ReadIdConfigForReadAll
#define NvM_Prv_EvalProdErrors_InvalidateForFirstInitAll_pfct       NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_RestoreForImplicitRecovery_pfct      NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_InvalidateForRemoveNonResistant_pfct NvM_Prv_EvalProductionErrors
#define NvM_Prv_EvalProdErrors_Invalid_pfct                         NULL_PTR

/**
 * Function-like macro: LIST_ENTRY_JOB_EVAL_PROD_ERRORS_FCT
 *
 * This macro generates an entry for a function to evaluate production errors in a list of all jobs provided by NvM.
 * s.a. macro LIST_ID_JOB to generate a list for all jobs provided by NvM
 *
 * Paramater:
 * Name: name of the job for which a function will be generated.
 */
#define LIST_ENTRY_JOB_EVAL_PROD_ERRORS_FCT(Name)       NvM_Prv_EvalProdErrors_##Name##_pfct,

static NvM_Prv_JobEvalProductionErrors_tpfct const NvM_Prv_JobEvalProductionErrorsFcts_capfct[NvM_Prv_idJob_Count_e] =
{
    LIST_ID_JOB(LIST_ENTRY_JOB_EVAL_PROD_ERRORS_FCT)
};


#define NvM_Prv_UpdateStatus_Idle_pfct                              NULL_PTR
#define NvM_Prv_UpdateStatus_Read_pfct                              NvM_Prv_UpdateBlockStatus_ReadWrite
#define NvM_Prv_UpdateStatus_Write_pfct                             NvM_Prv_UpdateBlockStatus_ReadWrite
#define NvM_Prv_UpdateStatus_Erase_pfct                             NULL_PTR
#define NvM_Prv_UpdateStatus_Restore_pfct                           NvM_Prv_UpdateBlockStatus_Restore
#define NvM_Prv_UpdateStatus_Maintain_pfct                          NULL_PTR
#define NvM_Prv_UpdateStatus_Validate_pfct                          NvM_Prv_UpdateBlockStatusJobValidate
#define NvM_Prv_UpdateStatus_Invalidate_pfct                        NULL_PTR
#define NvM_Prv_UpdateStatus_ReadIdConfigForReadAll_pfct            NvM_Prv_UpdateBlockStatusIdConfigForReadAll
#define NvM_Prv_UpdateStatus_InvalidateForFirstInitAll_pfct         NULL_PTR
#define NvM_Prv_UpdateStatus_RestoreForImplicitRecovery_pfct        NvM_Prv_UpdateBlockStatus_Restore
#define NvM_Prv_UpdateStatus_InvalidateForRemoveNonResistant_pfct   NULL_PTR
#define NvM_Prv_UpdateStatus_Invalid_pfct                           NULL_PTR

/**
 * Function-like macro: LIST_ENTRY_JOB_UPDATE_BLOCK_STATUS_FCT
 *
 * This macro generates an entry for a function to update block status in a list of all jobs provided by NvM.
 * s.a. macro LIST_ID_JOB to generate a list for all jobs provided by NvM
 *
 * Paramater:
 * Name: name of the job for which a function will be generated.
 */
#define LIST_ENTRY_JOB_UPDATE_BLOCK_STATUS_FCT(Name)    NvM_Prv_UpdateStatus_##Name##_pfct,

static NvM_Prv_JobUpdateBlockStatus_tpfct const NvM_Prv_JobUpdateBlockStatusFcts_capfct[NvM_Prv_idJob_Count_e] =
{
    LIST_ID_JOB(LIST_ENTRY_JOB_UPDATE_BLOCK_STATUS_FCT)
};

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * NvM-private code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

static NvM_RequestResultType NvM_Prv_EvalReqResult(NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_RequestResultType stRequestResult_uo;

    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_OK;
    }
    else
    {
        stRequestResult_uo = NVM_REQ_NOT_OK;
    }
    return stRequestResult_uo;
}

static NvM_RequestResultType NvM_Prv_EvalReqResult_Read(NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_RequestResultType stRequestResult_uo;
    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_OK;
    }
    else if (MEMIF_BLOCK_INVALID == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_NV_INVALIDATED;
    }
    else if (MEMIF_BLOCK_INCONSISTENT == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_INTEGRITY_FAILED;
    }
    else if (MEMIF_JOB_FAILED == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_NOT_OK;
    }
    else // (MEMIF_JOB_CANCELED == JobData_pst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_NOT_OK;
    }
    return stRequestResult_uo;
}

static NvM_RequestResultType NvM_Prv_EvalReqResult_InvalidateForRemoveNonResistant(NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_RequestResultType stRequestResult_uo;
    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_NV_INVALIDATED;
    }
    else
    {
        stRequestResult_uo = NVM_REQ_NOT_OK;
    }
    return stRequestResult_uo;
}

static NvM_RequestResultType NvM_Prv_EvalReqResult_RestoreForImplicitRecovery(NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_RequestResultType stRequestResult_uo;
    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_RESTORED_FROM_ROM;
    }
    else
    {
        stRequestResult_uo = NVM_REQ_NOT_OK;
    }
    return stRequestResult_uo;
}

static NvM_RequestResultType NvM_Prv_EvalReqResult_ReadIdConfigForReadAll(NvM_Prv_JobData_tst const* JobData_pcst)
{
    NvM_RequestResultType stRequestResult_uo;

#if ((NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON) || (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON))
    boolean isInitAtLayoutChangeRequired_b = FALSE;
    boolean isRemoveNonResistantRequired_b = FALSE;
#endif

    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        if (NvM_Prv_Block_HasIdConfigChanged())
        {
            stRequestResult_uo = NVM_REQ_NOT_OK;
#if (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON)
            isInitAtLayoutChangeRequired_b = TRUE;
#endif
#if (NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON)
            isRemoveNonResistantRequired_b = TRUE;
#endif
        }
        else
        {
            stRequestResult_uo = NVM_REQ_OK;
        }
    }
    else if (MEMIF_BLOCK_INVALID == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_NV_INVALIDATED;
        // set ConfigID to compiled value to signal that ConfigId has not changed and to avoid writing it
        NvM_Prv_Block_SetIdConfig(NVM_COMPILED_CONFIG_ID);

#if (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON)
        isInitAtLayoutChangeRequired_b = TRUE;
#endif
#if (NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON)
        isRemoveNonResistantRequired_b = FALSE;
#endif
    }
    else if (MEMIF_BLOCK_INCONSISTENT == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_NV_INVALIDATED;
        // set ConfigID to signal that ConfigId has changed and to trigger writing it
        NvM_Prv_Block_SetIdConfig(~((uint16)NVM_COMPILED_CONFIG_ID));

#if (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON)
        isInitAtLayoutChangeRequired_b = TRUE;
#endif
#if (NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON)
        isRemoveNonResistantRequired_b = FALSE;
#endif
    }
    else if (MEMIF_JOB_FAILED == JobData_pcst->Result_en)
    {
        stRequestResult_uo = NVM_REQ_INTEGRITY_FAILED;
        // set ConfigID to signal that ConfigId has changed and to trigger writing it
        NvM_Prv_Block_SetIdConfig(~((uint16)NVM_COMPILED_CONFIG_ID));

#if (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON)
        isInitAtLayoutChangeRequired_b = TRUE;
#endif
#if (NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON)
        isRemoveNonResistantRequired_b = TRUE;
#endif
    }
    else // MEMIF_JOB_CANCELED
    {
        stRequestResult_uo = NVM_REQ_NOT_OK;
        // set ConfigID to compiled value to signal that ConfigId has not changed and to avoid writing it
        NvM_Prv_Block_SetIdConfig(NVM_COMPILED_CONFIG_ID);
    }

#if ((NVM_RB_REMOVE_NON_RESISTANT_BLOCKS == STD_ON) || (NVM_RB_INIT_AT_LAYOUT_CHANGE == STD_ON))
    NvM_Prv_InitAfterReadAll(isInitAtLayoutChangeRequired_b,
                             isRemoveNonResistantRequired_b);
#endif

    return stRequestResult_uo;
}

static uint8 NvM_Prv_EvalProductionErrors(NvM_Prv_JobData_tst const* JobData_pcst)
{
    uint8 stProductionErrors_u8 = 0;
    if (MEMIF_JOB_OK != JobData_pcst->Result_en)
    {
        stProductionErrors_u8 |= NVM_E_REQ_FAILED;
    }
    return stProductionErrors_u8;
}

static uint8 NvM_Prv_EvalProductionErrors_Read(NvM_Prv_JobData_tst const* JobData_pcst)
{
    uint8 stProductionErrors_u8 = 0;
    if (MEMIF_BLOCK_INCONSISTENT == JobData_pcst->Result_en)
    {
        stProductionErrors_u8 |= NVM_E_INTEGRITY_FAILED;
    }
    else if (MEMIF_JOB_FAILED == JobData_pcst->Result_en)
    {
        stProductionErrors_u8 |= NVM_E_REQ_FAILED;
    }
    else
    {
        // no production errors shall be reported
        stProductionErrors_u8 = 0;
    }
    return stProductionErrors_u8;
}

static uint8 NvM_Prv_EvalProductionErrors_ReadIdConfigForReadAll(NvM_Prv_JobData_tst const* JobData_pcst)
{
    uint8 stProductionErrors_u8 = 0;
    if (MEMIF_JOB_FAILED == JobData_pcst->Result_en)
    {
        stProductionErrors_u8 |= NVM_E_REQ_FAILED;
    }
    return stProductionErrors_u8;
}

static void NvM_Prv_UpdateBlockStatus_Restore(NvM_Prv_JobData_tst const* JobData_pcst)
{
    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        if (JobData_pcst->RamBlock_pu8 == NvM_Prv_GetPRamBlockAddress(JobData_pcst->idBlock_uo))
        {
            NvM_Prv_Block_SetState(JobData_pcst->idBlock_uo, NVM_BLOCK_STATE_RAM_MASK, NVM_BLOCK_STATE_RAM_VALID_CHANGED);
        }
    }
}

static void NvM_Prv_UpdateBlockStatus_ReadWrite(NvM_Prv_JobData_tst const* JobData_pcst)
{
    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        if (JobData_pcst->RamBlock_pu8 == NvM_Prv_GetPRamBlockAddress(JobData_pcst->idBlock_uo))
        {
            NvM_Prv_Block_SetState(JobData_pcst->idBlock_uo, NVM_BLOCK_STATE_RAM_MASK, NVM_BLOCK_STATE_RAM_VALID);
        }
        if (NvM_Prv_IsBlockSelected(JobData_pcst->idBlock_uo, NVM_PRV_BLOCK_FLAG_WRITE_ONCE))
        {
            NvM_Prv_Block_SetState(JobData_pcst->idBlock_uo, NVM_BLOCK_STATE_WRITE_PROT, NVM_BLOCK_STATE_WRITE_PROT);
        }
    }
}

static void NvM_Prv_UpdateBlockStatusJobValidate(NvM_Prv_JobData_tst const* JobData_pcst)
{
    if (MEMIF_JOB_OK == JobData_pcst->Result_en)
    {
        NvM_Prv_Block_SetState(JobData_pcst->idBlock_uo, NVM_BLOCK_STATE_RAM_CHANGED, NVM_BLOCK_STATE_RAM_CHANGED);
    }
}

static void NvM_Prv_UpdateBlockStatusIdConfigForReadAll(NvM_Prv_JobData_tst const* JobData_pcst)
{
    if (NvM_Prv_Block_InitIdConfigDuringWriteAll())
    {
        // TRACE[NVM310] Mark the config ID block as VALID/CHANGED to enable its writing during WriteAll
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2901] Signal the writing of the config ID block in WriteAll
        //                                               when dynamic conf is active and extended dynamic conf is inactive
        NvM_Prv_Block_SetState(JobData_pcst->idBlock_uo, NVM_BLOCK_STATE_RAM_MASK, NVM_BLOCK_STATE_RAM_VALID_CHANGED);
    }
}

static NvM_Prv_JobEvalReqResult_tpfct NvM_Prv_GetFctJobEvalReqResult(NvM_Prv_idJob_ten idJob_en)
{
    if (idJob_en >= NvM_Prv_idJob_Count_e)
    {
        idJob_en = NvM_Prv_idJob_Invalid_e;
    }
    return NvM_Prv_JobEvalReqResultFcts_capfct[idJob_en];
}

static NvM_Prv_JobEvalProductionErrors_tpfct NvM_Prv_GetFctJobEvalProductionErrors(NvM_Prv_idJob_ten idJob_en)
{
    if (idJob_en >= NvM_Prv_idJob_Count_e)
    {
        idJob_en = NvM_Prv_idJob_Invalid_e;
    }
    return NvM_Prv_JobEvalProductionErrorsFcts_capfct[idJob_en];
}

static NvM_Prv_JobUpdateBlockStatus_tpfct NvM_Prv_GetFctJobUpdateBlockStatus(NvM_Prv_idJob_ten idJob_en)
{
    if (idJob_en >= NvM_Prv_idJob_Count_e)
    {
        idJob_en = NvM_Prv_idJob_Invalid_e;
    }
    return NvM_Prv_JobUpdateBlockStatusFcts_capfct[idJob_en];
}

void NvM_Prv_MainFunctionResultEval(void)
{
    // Evaluate the result of the job identified by idActiveJob_rMwM_en

    boolean isRequestResultEvaluated_b = FALSE;
    NvM_RequestResultType stRequestResult_uo = NVM_REQ_NOT_OK;
    uint8 stProductionErrors_u8 = 0;

    NvM_Prv_idService_tuo idActiveService_uo = NvM_Prv_GetActiveService();
    NvM_Prv_idQueue_tuo idActiveQueue_en = NvM_Prv_Main_st.idQueueActive_uo;
    NvM_BlockIdType idBlock_uo = NvM_Prv_Main_st.QueueEntry_pst->idBlock_uo;
#if (NVM_RB_AUX_INTERFACE == STD_ON)
    if (NvM_Prv_IsAuxServiceActive())
    {
        idBlock_uo = NVM_PRV_AUX_ADMIN_BLOCK;
    }

    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3027] Set migration result for auxiliary read
    NvM_Prv_SetAuxMigrationResult(idActiveService_uo, NvM_Prv_Main_st.QueueEntry_pst->idBlock_uo);
#endif

    isRequestResultEvaluated_b = NvM_Prv_EvalCommonResults(&NvM_Prv_Main_st.JobData_st,
                                                           &stRequestResult_uo,
                                                           &stProductionErrors_u8);

    // Set scheduling lock
    SchM_Enter_NvM_Main();

    // Part to be done after result evaluation WITHIN scheduling lock
    if (isRequestResultEvaluated_b)
    {
        // Set global variables from local copies to update results/states for the user
        // TRACE[NVM175] Indicate the request result to the user
        NvM_Prv_Block_SetRequestResult(idBlock_uo, stRequestResult_uo);
        NvM_Prv_ErrorDetection_SetProductionError(NvM_Prv_Main_st.QueueEntry_pst->idBlock_uo, stProductionErrors_u8);
    }

    // Reset the states of NvM's main state machine because the current job is now completely finished
    NvM_Prv_MainFunctionResultEval_ResetMainStates(idBlock_uo,
                                                   idActiveQueue_en,
                                                   idActiveService_uo,
                                                   NvM_Prv_Main_st.QueueEntry_pst->ServiceBit_uo,
                                                   stRequestResult_uo);

    // Reset scheduling lock
    SchM_Exit_NvM_Main();

    // Part to be done after result evaluation WITHOUT scheduling lock
    if (isRequestResultEvaluated_b)
    {
        // Invoke observer and singleblock callbacks if applicable
        NvM_Prv_MainFunctionResultEval_FinalBlockCallbacks(stRequestResult_uo,
                                                           idBlock_uo,
                                                           idActiveService_uo);
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * Inline code
 **********************************************************************************************************************
 */
// ====================================================================================================================
LOCAL_INLINE boolean NvM_Prv_EvalCommonResults(NvM_Prv_JobData_tst const* JobData_pcst,
                                               NvM_RequestResultType* stReqResult_puo,
                                               uint8* stProductionErrors_pu8)
{
    boolean isReqResultEvaluated_b = FALSE;


    // We rely heavily on the fact that we know really all possible job results
    // -> check this assumption and report DET error if development error detection is enabled
    if (NvM_Prv_ErrorDetection_IsJobResultMemIfPlausible(NVM_SERVICE_ID_MAIN_FUNCTION,
                                                         JobData_pcst->idBlock_uo,
                                                         JobData_pcst->Result_en))
    {
        // Pointer to the function to evaluate request results of the currently active job
        NvM_Prv_JobEvalReqResult_tpfct JobEvalReqResult_pfct = NvM_Prv_GetFctJobEvalReqResult(JobData_pcst->idJob_en);
        // Pointer to the function to evaluate production errors occured during the currently active job
        NvM_Prv_JobEvalProductionErrors_tpfct JobEvalProductionErrors_pfct =
                NvM_Prv_GetFctJobEvalProductionErrors(JobData_pcst->idJob_en);
        // Pointer to the function to update the status of the block handled during the currently active job
        NvM_Prv_JobUpdateBlockStatus_tpfct JobUpdateBlockStatus_pfct =
                NvM_Prv_GetFctJobUpdateBlockStatus(JobData_pcst->idJob_en);

        if (NULL_PTR != JobEvalReqResult_pfct)
        {
            *stReqResult_puo = JobEvalReqResult_pfct(JobData_pcst);
            isReqResultEvaluated_b = TRUE;

            // TRACE[NVM395] Maintain overall result of the multiblock operation
            if (NvM_Prv_IsMultiActive() &&
                ((MEMIF_BLOCK_INCONSISTENT == JobData_pcst->Result_en) || (MEMIF_JOB_FAILED == JobData_pcst->Result_en)))
            {
                // TRACE[NVM301] Set final multiblock result to NVM_REQ_NOT_OK (applies to NvM_ReadAll)
                // TRACE[NVM318] Same as NVM301, applied to NvM_WriteAll
                // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2836] NVM_REQ_NOT_OK is one
                //                                               of the two possible request results of first init
                NvM_Prv_Multi_SetResult(NVM_REQ_NOT_OK);
            }
        }
        if (NULL_PTR != JobEvalProductionErrors_pfct)
        {
            *stProductionErrors_pu8 = JobEvalProductionErrors_pfct(JobData_pcst);
        }
        if (NULL_PTR != JobUpdateBlockStatus_pfct)
        {
            JobUpdateBlockStatus_pfct(JobData_pcst);
        }
    }
    return isReqResultEvaluated_b;
}

// ====================================================================================================================

LOCAL_INLINE void NvM_Prv_MainFunctionResultEval_FinalBlockCallbacks(NvM_RequestResultType stRequestResult_uo,
                                                                     NvM_BlockIdType idActiveBlock_uo,
                                                                     NvM_Prv_idService_tuo idActiveService_uo)
{
    // Invoke observer and singleblock callbacks if applicable
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2842] Invoke the observer callback if this callback routine is configured
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2844] Invoke the observer callback before the singleblock callback
    NvM_Prv_InvokeObserverCallback(idActiveBlock_uo, idActiveService_uo, stRequestResult_uo);

    // TRACE[NVM347] Invoke singleblock callback if callback routine is configured
    // TRACE[NVM281] Processing of this block finished -> invoke callback function (applies to NvM_ReadAll)
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2839] Same as NVM281, but applied to first init
    // TRACE[NVM740] The callback is invoked upon termination of the block operation
    // TRACE[NVM742] The caller is only actively notified if a callback has been configured
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2930]
    // Don't invoke the singleblock callback if the current service is triggered by an auxiliary user
    if (!NvM_Prv_IsAuxServiceActive())
    {
        // TRACE[NVM741] Supply the ID of the just finished block operation to the callback owner
        NvM_Prv_InvokeSingleBlockCallback(idActiveBlock_uo, idActiveService_uo, stRequestResult_uo);
    }
}

// ====================================================================================================================

LOCAL_INLINE void NvM_Prv_MainFunctionResultEval_ResetMainStates(NvM_BlockIdType idBlock_uo,
                                                                 NvM_Prv_idQueue_tuo idQueue_uo,
                                                                 NvM_Prv_idService_tuo idService_uo,
                                                                 NvM_Prv_ServiceBit_tuo ServiceBit_uo,
                                                                 NvM_RequestResultType stRequestResult_uo)
{
    uint16 ServiceBitMask_uo;

    if (NvM_Prv_idQueue_Multi_e == idQueue_uo)
    {
        if (NVM_SERVICE_ID_RB_INIT_AFTER_READ_ALL == idService_uo)
        {
            ServiceBitMask_uo = (1u << NvM_Prv_ServiceBit_InitAtLayoutChange_e) |
                                (1u << NvM_Prv_ServiceBit_RemoveNonResistant_e);
        }
        else if ((NVM_SERVICE_ID_READ_ALL == idService_uo) &&
                 (NVM_RB_CONFIG_ID_BLOCK != idBlock_uo) &&
                 (NVM_REQ_RESTORED_FROM_ROM != stRequestResult_uo))
        {
            ServiceBitMask_uo = (1u << NvM_Prv_ServiceBit_ReadAll_e) |
                                (1u << NvM_Prv_ServiceBit_InitAtLayoutChange_e);
        }
        else
        {
            ServiceBitMask_uo = (1u << ServiceBit_uo);
        }
    }
    else
    {
        ServiceBitMask_uo = (1u << ServiceBit_uo);

        NvM_Prv_Queue_DequeueRequest(idQueue_uo);
        NvM_Prv_Main_st.QueueEntry_pst = NULL_PTR;
        NvM_Prv_Main_st.idQueueActive_uo = NvM_Prv_idQueue_nrQueues_e;
    }

    NvM_Prv_Block_ClearRequests(idBlock_uo, ServiceBitMask_uo);

    NvM_Prv_Main_st.JobData_st.idJob_en = NvM_Prv_idJob_Idle_e;
    NvM_Prv_Main_st.JobData_st.idBlock_uo = 0;
    NvM_Prv_Main_st.JobData_st.idxDataset_u8 = 0;
    NvM_Prv_Main_st.JobData_st.RamBlock_pu8 = NULL_PTR;
    NvM_Prv_Main_st.JobData_st.Result_en = MEMIF_JOB_OK;

    NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_ARBITRATE;
}
