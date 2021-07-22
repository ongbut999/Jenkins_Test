
/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
 */
#include "NvM.h"

#include "NvM_Prv.h"
#include "NvM_Prv_BlockData.h"
#include "NvM_Prv_ErrorDetection.h"

#if (NVM_DEV_ERROR_DETECT == STD_ON)
// TRACE[NVM556] NvM module shall include Det.h
# include "Det.h"
// TRACE[NVM089] Check version compatibility of included header files
# if (!defined(DET_AR_RELEASE_MAJOR_VERSION) || (DET_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION))
#  error "AUTOSAR major version undefined or mismatched"
# endif
#if (!defined(DET_AR_RELEASE_MINOR_VERSION) || ((DET_AR_RELEASE_MINOR_VERSION != 0) && (DET_AR_RELEASE_MINOR_VERSION != 2)))
#error "AUTOSAR minor version undefined or mismatched"
#endif
#endif

/*
 **********************************************************************************************************************
 * Variables
 **********************************************************************************************************************
 */
#define NVM_START_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

// Variable saving blocks' errors (useful for debugging)
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2811] public block specific production error array
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2812] public summary variable of all occured production errors (index #0)
uint8 NvM_Rb_stBlockErrors_au8[NVM_CFG_NR_BLOCKS];

#define NVM_STOP_SEC_VAR_CLEARED_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "NvM_MemMap.h"

// ID of the most previous error reported via Det_ReportError within NvM (initialized to NVM_PRV_NO_DET_ERROR)
NvM_Prv_idDetError_tuo NvM_Prv_idLastDetError_uo;
// ID of the service which triggered the last DET error (initialized to NVM_SERVICE_ID_INIT)
NvM_Prv_idService_tuo NvM_Prv_idServiceLastDetError_uo;
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3113] Private variable to store block ID used in NvM service
//                                               which has caused the last DET error
NvM_BlockIdType NvM_Prv_idBlockLastDetError_uo;

#define NVM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
#include "NvM_MemMap.h"

/*
 **********************************************************************************************************************
 * NvM-private code
 **********************************************************************************************************************
 */
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/**
 * This function returns the block ID used in NvM service which has caused the last DET error.
 *
 * Typical use case for this function is to be used as callback within the DET.
 * If NvM service which has caused the last DET error does not use any block or no DET error has occured yet,
 * then this function returns 0.
 *
 * \param[global in] NvM_Prv_idBlockCausingLastDetError_uo
 * Global variable to store block ID used in NvM service which has caused the last DET error
 *
 * \return
 * Block identifier used in NvM service which has caused the last DET error.
 */
NvM_BlockIdType NvM_Rb_GetBlockIdCausingLastDetError(void)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3113] Service to get the block ID used in NvM service
    //                                               which has caused the last DET error
    return (NvM_Prv_idBlockLastDetError_uo);
}

/**
 * \brief
 * This private function reports the passed error to the DET together with the NvM service which has detected
 * this error.
 * \details
 * Additionally this function stores the reported error and the NvM service to the NvM private variables.
 *
 * \param[in] idService_uo
 * Id of the service which reports an error to the DET.
 * \param[in] idError_uo
 * Id of the error which shall be reported to the DET.
 */
// TRACE[NVM191]
// Development errors shall be reported to the Det_ReportError service
// TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3113]
// NvM private function to set block ID used in NvM service which has caused the last DET error
static void NvM_Prv_ReportDetError(NvM_Prv_idService_tuo idService_uo,
                                   NvM_Prv_idDetError_tuo idError_uo,
                                   NvM_BlockIdType idBlock_uo)
{
    // TRACE[NVM188] If the NvMDevErrorDetect switch is enabled API parameter checking is enabled
#if (NVM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID, idService_uo, idError_uo);
#endif

    NvM_Prv_idServiceLastDetError_uo = idService_uo;
    NvM_Prv_idLastDetError_uo = idError_uo;
    NvM_Prv_idBlockLastDetError_uo = idBlock_uo;
}

/**
 * \brief
 * This NvM private function initializes all data which will be reported to the DET.
 * \details
 * The reported data will be initialized only if data in the saved zone is lost.
 *
 * \param[in] isSavedZoneDataLost_b
 * Status information of the data in the saved zone RAM:
 * - true = data in the saved zone RAM is lost after the reset
 * - false = data in the saved zone RAM is unchanged after the reset
 */
void NvM_Prv_ErrorDetection_InitializeDetError(boolean isSavedZoneDataLost_b)
{
    if (isSavedZoneDataLost_b)
    {
        NvM_Prv_idServiceLastDetError_uo = NVM_SERVICE_ID_INIT;
        NvM_Prv_idLastDetError_uo = NVM_PRV_NO_DET_ERROR;
        NvM_Prv_idBlockLastDetError_uo = 0u;
    }
}

/**
 * \brief
 * This NvM private function initializes all block specific production errors.
 */
void NvM_Prv_ErrorDetection_InitializeProductionErrors(void)
{
    NvM_BlockIdType idBlock_uo;
    // Variable saving blocks' errors (useful for debugging)
    for (idBlock_uo = 0u; idBlock_uo < NVM_CFG_NR_BLOCKS; ++idBlock_uo)
    {
        NvM_Rb_stBlockErrors_au8[idBlock_uo] = 0u; // No errors
    }
}

/**
 * \brief
 * This NVM private function sets a production error.
 *
 * \param[in] idBlock_uo
 * ID of the block for which production error is reported.
 * \param[in] MaskErrorBit_u8
 * Bit mask of the production error to be set.
 * \param[out] NvM_Rb_stBlockErrors_au8
 * Global array with all block specific production error.
 */
void NvM_Prv_ErrorDetection_SetProductionError(NvM_BlockIdType idBlock_uo, uint8 MaskErrorBit_u8)
{
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2811] Report block specific production error
    NvM_Rb_stBlockErrors_au8[idBlock_uo] |= MaskErrorBit_u8;
    // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-2812] Set reported production error in the overall summary
    NvM_Rb_stBlockErrors_au8[0] |= MaskErrorBit_u8;
}

/**
 * \brief
 * This NvM private function reports the DET error NVM_E_BLOCK_PENDING if the passed block is already queued or
 * currently in progress.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the block is pending. This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * Block ID used in NvM service causing last DET error.
 * \param[in] isBlockPending_b
 * Information whether the passed block is pending.
 */
void NvM_Prv_ErrorDetection_IsBlockPending(NvM_Prv_idService_tuo idService_uo,
                                           NvM_BlockIdType idBlock_uo,
                                           boolean isBlockPending_b)
{
    if (isBlockPending_b)
    {
        // TRACE[NVM632] Report the DET error NVM_E_BLOCK_PENDING when the NVRAM block identifier is already queued or
        //               currently in progress
        NvM_Prv_ReportDetError(idService_uo, NVM_E_BLOCK_PENDING, idBlock_uo);
    }
}

/**
 * \brief
 * This NvM private function checks the passed service bit and reports the DET error NVM_E_SINGLE_BLOCK_SERVICE_ID
 * if this bit is invalid.
 *
 * \param[in] idService_uo
 * ID of the service which checks the service bit. This service ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * Block ID used in NvM service causing last DET error.
 * \param[in] ServiceBit_uo
 * Service bit to be checked for validness.
 *
 * \return
 * Validness of the passed block ID:
 * - TRUE = service bit is valid
 * - FALSE = service bit is invalid
 */
boolean NvM_Prv_ErrorDetection_IsServiceBitValid(NvM_Prv_idService_tuo idService_uo,
                                                 NvM_BlockIdType idBlock_uo,
                                                 NvM_Prv_ServiceBit_tuo ServiceBit_uo)
{
    boolean isServiceBitValid_b = (ServiceBit_uo < NvM_Prv_ServiceBit_Unspecified_e);

    if (!isServiceBitValid_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_SINGLE_BLOCK_SERVICE_ID, idBlock_uo);
    }
    return isServiceBitValid_b;
}

boolean NvM_Prv_ErrorDetection_IsJobIdValid(NvM_Prv_idService_tuo idService_uo,
                                            NvM_BlockIdType idBlock_uo,
                                            NvM_Prv_idJob_ten idJob_en)
{
    boolean isJobIdValid_b = (idJob_en < NvM_Prv_idJob_Invalid_e);

    if (!isJobIdValid_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PRV_JOB_ID, idBlock_uo);
    }
    return isJobIdValid_b;
}

boolean NvM_Prv_ErrorDetection_IsJobResultMemIfPlausible(NvM_Prv_idService_tuo idService_uo,
                                                         NvM_BlockIdType idBlock_uo,
                                                         MemIf_JobResultType JobResult_en)
{
    boolean isJobResultMemIfPlausible_b = ((JobResult_en == MEMIF_JOB_OK) ||
                                           (JobResult_en == MEMIF_JOB_FAILED) ||
                                           (JobResult_en == MEMIF_JOB_CANCELED) ||
                                           (JobResult_en == MEMIF_BLOCK_INVALID) ||
                                           (JobResult_en == MEMIF_BLOCK_INCONSISTENT));
    if (!isJobResultMemIfPlausible_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_MEMIF_JOB_RESULT, idBlock_uo);
    }
    return isJobResultMemIfPlausible_b;
}

/**
 * \brief
 * This NvM private function checks whether the RAM mirror used for explicit synchronization is big enough
 * for the passed block and reports the DET error NVM_E_RAM_MIRROR_SIZE if RAM mirror is too small.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the block size is valid. This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * ID of the block for which the size will be validated.
 * \param[in] SizeRamMirror_u32
 * Size of the RAM mirror used for explicit synchronization
 *
 * \return
 * - TRUE = RAM mirror is big enough
 * - FALSE = RAM mirror is too small
 */
boolean NvM_Prv_ErrorDetection_IsBlockSizeValidForExplicitSync(NvM_Prv_idService_tuo idService_uo,
                                                               NvM_BlockIdType idBlock_uo,
                                                               uint32 SizeRamMirror_u32)
{
    boolean isBlockSizeValid_b = (NvM_Prv_GetBlockSize(idBlock_uo) <= SizeRamMirror_u32);

    if (!isBlockSizeValid_b)
    {
        // block size greater than size of the RAM mirror used for explicit synchronization
        NvM_Prv_ReportDetError(idService_uo, NVM_E_RAM_MIRROR_SIZE, idBlock_uo);
    }

    return isBlockSizeValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed data index pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the data index pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * ID of the block for which the data index pointer will be validated.
 * \param[in] ptrDataIdx_pcu8
 * Data index pointer to be validated.
 *
 * \return
 * - TRUE = data index pointer is valid
 * - FALSE = data index pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForDataIdx(NvM_Prv_idService_tuo idService_uo,
                                                    NvM_BlockIdType idBlock_uo,
                                                    uint8 const* ptrDataIdx_pcu8)
{
    boolean isPtrValid_b = (NULL_PTR != ptrDataIdx_pcu8);

    if (!isPtrValid_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, idBlock_uo);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed request result pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the request result pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * ID of the block for which the request result pointer will be validated.
 * \param[in] ptrReqResult_pcuo
 * Request result pointer to be validated.
 *
 * \return
 * - TRUE = request result pointer is valid
 * - FALSE = request result pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForRequestResult(NvM_Prv_idService_tuo idService_uo,
                                                          NvM_BlockIdType idBlock_uo,
                                                          NvM_RequestResultType const* ptrReqResult_pcuo)
{
    boolean isPtrValid_b = (NULL_PTR != ptrReqResult_pcuo);

    if (!isPtrValid_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, idBlock_uo);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed migration result pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the migration result pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * ID of the block for which the migration result pointer will be validated.
 * \param[in] ptrReqResult_pcuo
 * Migration result pointer to be validated.
 *
 * \return
 * - TRUE = migration result pointer is valid
 * - FALSE = migration result pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForMigrationResult(NvM_Prv_idService_tuo idService_uo,
                                                            NvM_BlockIdType idBlock_uo,
                                                            NvM_Rb_MigrationResult_ten const* ptrMigrationResult_pcen)
{
    boolean isPtrValid_b = (NULL_PTR != ptrMigrationResult_pcen);

    if (!isPtrValid_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, idBlock_uo);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed NvM status pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the NvM status pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] ptrReqResult_pcuo
 * NvM status pointer to be validated.
 *
 * \return
 * - TRUE = NvM status pointer is valid
 * - FALSE = NvM status pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForNvmStatus(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_Rb_StatusType const* ptrNvmStatus_pcen)
{
    boolean isPtrValid_b = (NULL_PTR != ptrNvmStatus_pcen);

    if (!isPtrValid_b)
    {
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3114] Set block ID to 0 if NvM service does not use any block ID
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, 0);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed block length pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the block length pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * ID of the block for which the block length pointer will be validated.
 * \param[in] ptrReqResult_pcuo
 * Block length pointer to be validated.
 *
 * \return
 * - TRUE = block length pointer is valid
 * - FALSE = block length pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForBlockLength(NvM_Prv_idService_tuo idService_uo,
                                                        NvM_BlockIdType idBlock_uo,
                                                        uint16 const* ptrBlockLength_pcu16)
{
    boolean isPtrValid_b = (NULL_PTR != ptrBlockLength_pcu16);

    if (!isPtrValid_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, idBlock_uo);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed service ID pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the service ID pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] ptrReqResult_pcuo
 * Service ID pointer to be validated.
 *
 * \return
 * - TRUE = service ID pointer is valid
 * - FALSE = service ID pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForServiceId(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_Prv_idService_tuo const* ptrIdService_pcuo)
{
    boolean isPtrValid_b = (NULL_PTR != ptrIdService_pcuo);

    if (!isPtrValid_b)
    {
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3114] Set block ID to 0 if NvM service does not use any block ID
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, 0);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed block ID pointer is valid and reports the DET error
 * NVM_E_PARAM_DATA if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the block ID pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] ptrIdBlock_pcuo
 * Block ID pointer to be validated.
 *
 * \return
 * - TRUE = block ID pointer is valid
 * - FALSE = block ID pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForBlockId(NvM_Prv_idService_tuo idService_uo,
                                                    NvM_BlockIdType const* ptrIdBlock_pcuo)
{
    boolean isPtrValid_b = (NULL_PTR != ptrIdBlock_pcuo);

    if (!isPtrValid_b)
    {
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3114] Set block ID to 0 if NvM service does not use any block ID
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_DATA, 0);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This NvM private function checks whether the passed version info pointer is valid and reports the DET error
 * NVM_E_PARAM_POINTER if NULL pointer is passed.
 *
 * \param[in] idService_uo
 * ID of the service which checks whether the version info pointer is valid.
 * This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * ID of the block for which the version info pointer will be validated.
 * \param[in] ptrVersionInfo_pcst
 * Version info pointer to be validated.
 *
 * \return
 * - TRUE = version info pointer is valid
 * - FALSE = version info pointer is invalid
 */
boolean NvM_Prv_ErrorDetection_IsPtrValidForVersionInfo(NvM_Prv_idService_tuo idService_uo,
                                                        Std_VersionInfoType const* ptrVersionInfo_pcst)
{
    boolean isPtrValid_b = (NULL_PTR != ptrVersionInfo_pcst);

    if (!isPtrValid_b)
    {
        // TRACE[BSW_SWS_AR4_0_R2_NVRAMManager_Ext-3114] Set block ID to 0 if NvM service does not use any block ID
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_POINTER, 0);
    }

    return isPtrValid_b;
}

/**
 * \brief
 * This private function checks the initialization of the NvM and reports the DET error NVM_E_NOT_INITIALIZED
 * when the NvM is not yet initialized.
 *
 * \param[in] idService_uo
 * ID of the service which checks the NvM initialization. This ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * Block ID used in NvM service causing last DET error.
 *
 * \return
 * Initialization status of the NvM:
 * - TRUE = NvM initialized
 * - FALSE = NvM not initialized
 */
boolean NvM_Prv_ErrorDetection_IsNvmInitialized(NvM_Prv_idService_tuo idService_uo,
                                                NvM_BlockIdType idBlock_uo)
{
    boolean isNvmInitialized_b = NvM_Prv_IsNvmInitialized();

    if (!isNvmInitialized_b)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_NOT_INITIALIZED, idBlock_uo);
    }

    return (isNvmInitialized_b);
}

/**
 * \brief
 * This NvM private function checks the passed block ID and reports the DET error NVM_E_PARAM_BLOCK_ID
 * if this ID is invalid.
 *
 * \param[in] idService_uo
 * ID of the service which checks the block ID. This service ID will be reported together with DET error.
 * \param[in] idBlock_uo
 * Block ID to be checked for validness.
 * \param[in] isMultiBlockAllowed_b
 * Flag to define whether the multi-block ID is valid ID or not
 *
 * \return
 * Validness of the passed block ID:
 * - TRUE = block ID is valid
 * - FALSE = block ID is invalid
 */
boolean NvM_Prv_ErrorDetection_IsBlockIdValid(NvM_Prv_idService_tuo idService_uo,
                                              NvM_BlockIdType idBlock_uo,
                                              boolean isMultiBlockAllowed_b)
{
    boolean isBlockIdValid_b;
    NvM_BlockIdType idBlockLowest_uo;

    if (isMultiBlockAllowed_b)
    {
        idBlockLowest_uo = NVM_PRV_MULTI_BLOCK;
    }
    else
    {
        // TRACE[NVM311] Allow applications to send requests for block ID 1
        idBlockLowest_uo = NVM_CFG_FIRST_USED_BLOCK;
    }

    isBlockIdValid_b = (idBlock_uo >= idBlockLowest_uo) && (idBlock_uo < NVM_CFG_NR_BLOCKS);

    if (!isBlockIdValid_b)
    {
        // TRACE[NVM188] If the NvMDevErrorDetect switch is enabled API parameter checking is enabled
        // TRACE[NVM023] Report DET errors when NvM is called with wrong parameters
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_BLOCK_ID, idBlock_uo);
    }

    return isBlockIdValid_b;
}

boolean NvM_Prv_ErrorDetection_IsDefaultDataAvailable(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_BlockIdType idBlock_uo)
{
    boolean isDefaultDataAvailable_b = FALSE;
    if (NvM_Prv_IsDefaultDataAvailable(idBlock_uo))
    {
        isDefaultDataAvailable_b = TRUE;
    }
    else
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_BLOCK_CONFIG, idBlock_uo);
    }
    return isDefaultDataAvailable_b;
}

boolean NvM_Prv_ErrorDetection_IsRamBlockAddressValid(NvM_Prv_idService_tuo idService_uo,
                                                      NvM_BlockIdType idBlock_uo,
                                                      void const* RamBlockAddress_pv)
{
    boolean isRamBlockAddressValid_b = FALSE;
    // check whether RAM block address is valid
    if (NULL_PTR == RamBlockAddress_pv)
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_ADDRESS, idBlock_uo);
    }
    else
    {
        isRamBlockAddressValid_b = TRUE;
    }
    return isRamBlockAddressValid_b;
}

boolean NvM_Prv_ErrorDetection_IsBlockTypeDataset(NvM_Prv_idService_tuo idService_uo,
                                                  NvM_BlockIdType idBlock_uo)
{
    boolean isBlockTypeDataset_b = FALSE;
    if (NVM_BLOCK_DATASET == NvM_Prv_GetBlockType(idBlock_uo))
    {
        isBlockTypeDataset_b = TRUE;
    }
    else
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_BLOCK_TYPE, idBlock_uo);
    }
    return isBlockTypeDataset_b;
}

boolean NvM_Prv_ErrorDetection_IsBlockIdxValid(NvM_Prv_idService_tuo idService_uo,
                                               NvM_BlockIdType idBlock_uo,
                                               uint8 idxData_u8)
{
    boolean isBlockIdxValid_b = FALSE;
    if (idxData_u8 < NvM_Prv_GetNrDataIndexes(idBlock_uo))
    {
        isBlockIdxValid_b = TRUE;
    }
    else
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_PARAM_BLOCK_DATA_IDX, idBlock_uo);
    }
    return isBlockIdxValid_b;
}

boolean NvM_Prv_ErrorDetection_IsBlockPriorityImmediate(NvM_Prv_idService_tuo idService_uo,
                                                        NvM_BlockIdType idBlock_uo)
{
    boolean isBlockPriorityImmediate_b = FALSE;
    if (NvM_Prv_HasBlockImmediateJobPriority(idBlock_uo))
    {
        isBlockPriorityImmediate_b = TRUE;
    }
    else
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_BLOCK_CONFIG, idBlock_uo);
    }
    return isBlockPriorityImmediate_b;
}

boolean NvM_Prv_ErrorDetection_IsBlockWriteProtectionChangeable(NvM_Prv_idService_tuo idService_uo,
                                                                NvM_BlockIdType idBlock_uo)
{
    boolean isBlockWriteProtectionChangeable_b = FALSE;
    if (!NvM_Prv_IsBlockSelected(idBlock_uo, NVM_PRV_BLOCK_FLAG_WRITE_ONCE))
    {
        isBlockWriteProtectionChangeable_b = TRUE;
    }
    else
    {
        NvM_Prv_ReportDetError(idService_uo, NVM_E_BLOCK_CONFIG, idBlock_uo);
    }
    return isBlockWriteProtectionChangeable_b;
}


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
