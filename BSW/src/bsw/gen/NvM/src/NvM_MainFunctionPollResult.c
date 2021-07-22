
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

/*
 **********************************************************************************************************************
 * Code
 **********************************************************************************************************************
*/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

void NvM_Prv_MainFunctionPollResult(void)
{
    // Get the result of the current job
    // TRACE[NVM346] Check the status of the currently active MemIf job
    NvM_Prv_Main_st.JobData_st.Result_en =
            MemIf_GetJobResult(NvM_Prv_GetIdxDevice(NvM_Prv_Main_st.QueueEntry_pst->idBlock_uo));

    if (MEMIF_JOB_PENDING != NvM_Prv_Main_st.JobData_st.Result_en)
    {
        // MemIf job has ended -> switch to result evaluation
        NvM_Prv_Main_st.Activity_rAMwM_en = NVM_PRV_ACTIVITY_JOB_COMPLETE;
    }
}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
