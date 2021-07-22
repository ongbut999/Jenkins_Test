
#ifndef DEM_CFG_EVENTS_DATASTRUCTURES_H
#define DEM_CFG_EVENTS_DATASTRUCTURES_H

#include "Dem.h"
#include "Dem_Lib.h"
#include "rba_DiagLib.h"
#include "Dem_Lock.h"
#include "Dem_Cfg_StorageCondition.h"
#include "Dem_Cfg_EnableCondition.h"

typedef Std_ReturnType (*Dem_EvtClearAllowedFncType) ( boolean* Allowed );

#define DEM_RECOV    (1u)
#define DEM_NOTREC   (0u)

#define DEM_DEBOUNCE_RESET    (1u)
#define DEM_DEBOUNCE_FREEZE   (0u)

#define DEM_NO_TF_RESET   (1u)
#define DEM_TF_RESET      (0u)

#define DEM_ONLY_THIS_CYCLE_AND_READINESS   (1u)
#define DEM_NO_STATUS_BYTE_CHANGE           (0u)

typedef struct
{
	uint8 dataDataContainer_1;  // AgingThreshold
} Dem_EvtParam_8Type;

typedef struct
{
	uint16 dataDataContainer_2;  // EventIsStoredInPrimary, AgingAllowed, Significance, InitialSuppressionStatus, DebounceParamSettingIndex, EventPriority, MaxNumberFreezeFrameRecords
} Dem_EvtParam_16Type;


extern const Dem_EvtParam_8Type Dem_EvtParam_8[6];
extern const Dem_EvtParam_16Type Dem_EvtParam_16[6];

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetDebounceBehavior(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DEM_DEBOUNCE_FREEZE;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetIsRecoverable(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DEM_RECOV;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetStoreTestFailedToNextOC(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return TRUE;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetRequestsWarningIndicator(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return FALSE; /* feature deactivated */
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE Dem_EventCategoryType Dem_EvtParam_GetCategory(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return 0; /* feature deactivated */
}

LOCAL_INLINE boolean Dem_EvtParam_GetEventIsStoredInPrimary(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return RBA_DIAGLIB_ISBITSET16(Dem_EvtParam_16[indx].dataDataContainer_2, 0);
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetEventIsStoredInSecondary(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return FALSE;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetEventIsStoredInMirror(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return FALSE;
}

LOCAL_INLINE boolean Dem_EvtParam_GetAgingAllowed(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return RBA_DIAGLIB_ISBITSET16(Dem_EvtParam_16[indx].dataDataContainer_2, 1);
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetIsGlobalFDCCallbackConfigured(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return FALSE; /* feature deactivated */
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE boolean Dem_EvtParam_GetTriggersDataChangedCallback(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return FALSE; /* feature deactivated */
}

LOCAL_INLINE uint8 Dem_EvtParam_GetSignificance(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return (uint8)(RBA_DIAGLIB_GETSINGLEBIT16(Dem_EvtParam_16[indx].dataDataContainer_2, 2));
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetOperationCycleID(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DemConf_DemOperationCycle_DemOperationCycle_0;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetAgingCycleID(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DemConf_DemOperationCycle_DemOperationCycle_0;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetFailureCycleID(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DemConf_DemOperationCycle_DemOperationCycle_0;
}

LOCAL_INLINE boolean Dem_EvtParam_GetInitialSuppressionStatus(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return RBA_DIAGLIB_ISBITSET16(Dem_EvtParam_16[indx].dataDataContainer_2, 3);
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetDebounceMethodIndex(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DEM_DEBMETH_IDX_ARCTRBASECLASS;
}

LOCAL_INLINE uint16 Dem_EvtParam_GetDebounceParamSettingIndex(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return (uint16)(RBA_DIAGLIB_GETBITS16(Dem_EvtParam_16[indx].dataDataContainer_2, 4, 3));
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetBufferTimeSFB(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return 0; /* feature deactivated */
}

LOCAL_INLINE uint8 Dem_EvtParam_GetAgingThreshold(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return Dem_EvtParam_8[indx].dataDataContainer_1;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetAgingThresholdForTFSLC(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return 0u;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetFailureConfirmationThreshold(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return 1u;
}

LOCAL_INLINE uint8 Dem_EvtParam_GetEventPriority(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return (uint8)(RBA_DIAGLIB_GETBITS16(Dem_EvtParam_16[indx].dataDataContainer_2, 7, 3));
}

LOCAL_INLINE uint8 Dem_EvtParam_GetMaxNumberFreezeFrameRecords(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return (uint8)(RBA_DIAGLIB_GETBITS16(Dem_EvtParam_16[indx].dataDataContainer_2, 10, 2));
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE Dem_StoCoList Dem_EvtParam_GetStorageConditions(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return 0; /* feature deactivated */
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE Dem_EnCoList Dem_EvtParam_GetEnableConditions(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return 0; /* feature deactivated */
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetCallbackEventStatusChangedIndex(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return FALSE; /* feature deactivated */
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE Dem_EvtClearAllowedFncType Dem_EvtParam_GetCallbackClearAllowed(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return NULL_PTR; /* feature deactivated */
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE uint8 Dem_EvtParam_GetClearAllowedBehavior(Dem_EventIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 6));
	return DEM_NO_STATUS_BYTE_CHANGE; /* feature deactivated */
}



#endif

