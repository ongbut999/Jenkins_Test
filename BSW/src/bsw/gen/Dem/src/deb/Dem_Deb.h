


#ifndef DEM_DEB_H
#define DEM_DEB_H

#include "Dem_Types.h"
#include "Dem_DebBase.h"
#include "Dem_Mapping.h"
#include "Dem_Events.h"
#include "Dem_Dependencies.h"
#include "Dem_DisturbanceMemory.h"
#include "Dem_EvBuff.h"
#include "Dem_EventFHandling.h"
#include "Dem_Main.h"
#include "Dem_Cfg_Events_DataStructures.h"


Std_ReturnType Dem_DebGetDebounceCounter4Calculation (Dem_EventIdType EventId, sint16 *debounceCounter);
sint8 Dem_DebCalculateFaultDetectionCounter(Dem_EventIdType EventId, sint16 debounceCounter);
boolean Dem_DebHandleResetConditions (Dem_EventIdType EventId);

#if (DEM_CFG_CHECKAPICONSISTENCY == TRUE)
/* Duplicate of Dem_GetDebouncingOfEvent to make it also available in the GeneralDiagnosticInfo RTE interface */
Std_ReturnType Dem_GetDebouncingOfEvent_GeneralEvtInfo(Dem_EventIdType EventId, Dem_DebouncingStateType* DebouncingState);
/* Duplicate of Dem_GetFaultDetectionCounter to make it also available in the GeneralDiagnosticInfo RTE interface */
Std_ReturnType Dem_GetFaultDetectionCounter_GeneralEvtInfo(Dem_EventIdType EventId, sint8* FaultDetectionCounter);
#endif /* DEM_CFG_CHECKAPICONSISTENCY */


DEM_INLINE Dem_DebouncedActionType Dem_DebCallFilter (Dem_EventIdType EventId, Dem_EventStatusType* status)
{
	Dem_DebFilter funcPoint;
	const void* paramSet;
    uint8_least debAction;
    debAction = DEM_DEBACTION_NOOP;

#if (DEM_CFG_DEBMONINTERNAL == DEM_CFG_DEBMONINTERNAL_ON)

    if(Dem_EvtParam_GetDebounceMethodIndex(EventId) == DEM_DEBMETH_IDX_MONINTERNAL)
    {
        DEM_ASSERT (*status != DEM_EVENT_STATUS_PREPASSED, DEM_DET_APIID_DEBCALLFILTER, 0);
        DEM_ASSERT (*status != DEM_EVENT_STATUS_PREFAILED, DEM_DET_APIID_DEBCALLFILTER, 1);

#if(DEM_CFG_SUPPORT_EVENT_FDCTHRESHOLDREACHED)
        if((*status == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED) || (*status == DEM_EVENT_STATUS_FAILED))
        {
            debAction |= DEM_DEBACTION_SETFDCTHRESHOLDREACHED;
        }
        else if(*status == DEM_EVENT_STATUS_PASSED)
        {
            debAction |= DEM_DEBACTION_RESETFDCTHRESHOLDREACHED;
        }
        else
        {
            /* do nothing */
        }
#endif
#if(DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD == DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD_ON)
        if(*status == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)
        {
            debAction |= DEM_DEBACTION_ALLOW_BUFFER_INSERT|DEM_DEBACTION_SETFDCTHRESHOLDREACHED;
        }
#endif
        return debAction;
    }
#endif

/* Status Changed to Passed in case - in a system which is working fine(Passed reported earlier), if Pre-passed is reported,
* the status is changed to Passed here to gain run-time Optimization */
#if((DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD != DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD_ON) && \
        (!DEM_CFG_SUSPICIOUS_SUPPORT) && !DEM_CFG_ALTERNATIVEDEBDEFINED)
    if((*status == DEM_EVENT_STATUS_PREPASSED) || (*status == DEM_EVENT_STATUS_PASSED))
    {
		/* Debounce level is compared with zero, as in case of Clear, the debounce level will get reset to zero irrespective of the previous report*/
        if((Dem_EvtGetLastReportedEvent (EventId) == DEM_EVENT_STATUS_PASSED) && \
                (Dem_EvtGetDebounceLevel (EventId) != 0 ))

        {
#if (DEM_CFG_DEBARTIMEBASE != DEM_CFG_DEBARTIMEBASE_OFF)
            if(Dem_EvtParam_GetDebounceMethodIndex(EventId) != DEM_DEBMETH_IDX_ARTIME)
#endif
            {
                *status = DEM_EVENT_STATUS_PASSED;
            }
            return debAction;

        }
    }
#else
    DEM_UNUSED_PARAM(debAction);
#endif

	funcPoint = Dem_Cfg_DebClasses[Dem_EvtParam_GetDebounceMethodIndex(EventId)].funcPointer_Filter;
	paramSet = Dem_Cfg_DebClasses[Dem_EvtParam_GetDebounceMethodIndex(EventId)].paramSet;
	DEM_ASSERT (Dem_EvtParam_GetDebounceParamSettingIndex(EventId) < Dem_Cfg_DebClasses[Dem_EvtParam_GetDebounceMethodIndex(EventId)].paramCount, DEM_DET_APIID_DEBCALLFILTER, 2);
	return (*funcPoint) (EventId, status, paramSet, Dem_EvtParam_GetDebounceParamSettingIndex(EventId));
}

/* this split of functionality is supposed as preliminary workaround; a final clean-up (conceptual rework of muticore handling) is planned */
DEM_INLINE Dem_boolean_least Dem_DebHandleDebounceAction__processBits(Dem_EventIdType EventId, Dem_DebouncedActionType debAction)
{
    Dem_boolean_least insertToEvBuffer = FALSE;

    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(debAction);

    DEM_ASSERT_ISLOCKED();

#if((DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD == DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD_ON) ||\
        (DEM_CFG_SUPPORT_EVENT_FDCTHRESHOLDREACHED))

    if( (debAction & DEM_DEBACTION_SETFDCTHRESHOLDREACHED) != 0u )
    {
#if(DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD == DEM_CFG_SUPPORTEVENTMEMORYENTRY_ONFDCTHRESHOLD_ON)
        if((!Dem_EvtGetFDCThresholdReachedTOC(EventId)))
        {
            //Set the FDC threshold reached flag
            Dem_EvtSetFDCThresholdReachedTOC(EventId,TRUE);

            if(Dem_OpMoIsInitialized() && ((debAction & DEM_DEBACTION_ALLOW_BUFFER_INSERT) != 0u))
            {
                /*  Check the Causality of the event*/
                if (Dem_StoCoAreAllFulfilled(Dem_EvtParam_GetStorageConditions(EventId)))
                {
                    insertToEvBuffer = TRUE;
                }
            }

        }
#endif
        Dem_EvtSetFDCThresholdReached(EventId,TRUE);
    }
    else
    {
        if((debAction & DEM_DEBACTION_RESETFDCTHRESHOLDREACHED) != 0u )
        {
            Dem_EvtSetFDCThresholdReached(EventId,FALSE);
        }
    }

#endif

#if(DEM_CFG_SUSPICIOUS_SUPPORT)
   if(((debAction & DEM_DEBACTION_SETSUSPICIOUS) != 0u) && (!Dem_EvtIsSuspicious(EventId)))
   {
       Dem_SetEventSuspicion_Internal(EventId,TRUE);
   }
   else
   {
      if(((debAction & DEM_DEBACTION_RESETSUSPICIOUS) != 0u) && (Dem_EvtIsSuspicious(EventId)))
      {
          Dem_SetEventSuspicion_Internal(EventId,FALSE);
      }
   }
#endif


   return (insertToEvBuffer);
}

DEM_INLINE void Dem_DebHandleDebounceAction(Dem_EventIdType EventId, Dem_DebouncedActionType debAction, Dem_DebugDataType debug0 ,Dem_DebugDataType debug1)
{
    Dem_boolean_least insertUnrobustToEvBuffer;
    DEM_ENTERLOCK_MON();
    insertUnrobustToEvBuffer = Dem_DebHandleDebounceAction__processBits(EventId, debAction);
    DEM_EXITLOCK_MON();

    if (insertUnrobustToEvBuffer)
    {
        (void)Dem_EvBuffInsert(C_EVENTTYPE_UNROBUST, EventId DEM_DEBUGDATA_PARAM(debug0, debug1));
    }
    else
    {
        DEM_UNUSED_PARAM(debug0);
        DEM_UNUSED_PARAM(debug1);
    }
}

DEM_INLINE Dem_boolean_least Dem_DebHandleDebounceAction_4_TimeBasedDeb(Dem_EventIdType EventId, Dem_DebouncedActionType debAction)
{
    return Dem_DebHandleDebounceAction__processBits(EventId, debAction);
}



DEM_INLINE void Dem_TimeBasedDebounceInternMainFunction(void)
{
#if (DEM_CFG_DEBARTIMEBASE == DEM_CFG_DEBARTIMEBASE_ON)

    Dem_EventIdIterator eventIt;
    Dem_DebCyclic funcPoint;
    Dem_EventIdType eventId;
    const void* paramSet;


        for (Dem_EventIdIteratorNew (&eventIt); Dem_EventIdIteratorIsValid (&eventIt); Dem_EventIdIteratorNext (
                &eventIt))
        {
            eventId = Dem_EventIdIteratorCurrent(&eventIt);
            funcPoint = Dem_Cfg_DebClasses[Dem_EvtParam_GetDebounceMethodIndex (eventId)].funcPointer_Cyclic;
            paramSet = Dem_Cfg_DebClasses[Dem_EvtParam_GetDebounceMethodIndex (eventId)].paramSet;

            if (funcPoint != NULL_PTR)
            {
                DEM_ASSERT (Dem_EvtParam_GetDebounceParamSettingIndex (eventId) < Dem_Cfg_DebClasses[Dem_EvtParam_GetDebounceMethodIndex (eventId)].paramCount, DEM_DET_APIID_DEBMAINFUNCTION, 0);
                (*funcPoint) (eventId, paramSet, Dem_EvtParam_GetDebounceParamSettingIndex (eventId));
            }
        }

#endif
}


#define DEM_START_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

void Dem_DebMainFunction(void);

#define DEM_STOP_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

#endif
