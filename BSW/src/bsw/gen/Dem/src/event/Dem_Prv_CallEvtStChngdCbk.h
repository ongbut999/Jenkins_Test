

#ifndef DEM_PRV_CALLEVTSTCHNGDCBK_H
#define DEM_PRV_CALLEVTSTCHNGDCBK_H

#if(DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
#include "FiM.h"
#endif
#if (DEM_CFG_TRIGGERDLTREPORTS == DEM_CFG_TRIGGERDLTREPORTS_ON)
#include "Dlt.h"
#endif
#include "Dem_DTCs.h"
#include "Dem_Cfg_EventsCallback.h"
#include "Dem_EventStatus.h"


DEM_INLINE void Dem_CallBackTriggerOnEventStatus (
		Dem_EventIdType EventId,
		Dem_UdsStatusByteType EventStatusOld,
		Dem_UdsStatusByteType EventStatusNew,
		Dem_UdsStatusByteType dtcStByteOld
)
{
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
    Dem_DtcIdType dtcId;
    Dem_UdsStatusByteType dtcStByteNew;
    Dem_DtcCodeType dtcCode;
#endif

    DEM_ASSERT_ISNOTLOCKED();
    DEM_UNUSED_PARAM(dtcStByteOld);
    DEM_UNUSED_PARAM(EventId);
    DEM_UNUSED_PARAM(EventStatusOld);
    DEM_UNUSED_PARAM(EventStatusNew);

#if (DEM_CFG_EVT_STATUS_CHANGE_NUM_CALLBACKS > 0)
    Dem_CallEventStatusChangedCallBack(EventId, EventStatusOld, EventStatusNew);
#endif
#if ( DEM_CFG_TRIGGERDLTREPORTS == DEM_CFG_TRIGGERDLTREPORTS_ON )
    Dlt_DemTriggerOnEventStatus(EventId, EventStatusOld, EventStatusNew);
#endif
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
    if ( Dem_EventIdIsDtcAssigned(EventId) )
    {
        dtcId = Dem_DtcIdFromEventId(EventId);
        if ( Dem_DtcIsSupported(dtcId) )
        {
            dtcStByteNew = (uint8)(Dem_DtcStatusByteRetrieve (dtcId) & DEM_CFG_DTCSTATUS_AVAILABILITYMASK);
            if (dtcStByteNew != dtcStByteOld)
            {
                dtcCode = Dem_GetDtcCode(dtcId);
                Dem_CallbackDTCStatusChangedIndication( dtcCode, dtcStByteOld, dtcStByteNew);
            }
        }
    }
#endif
}

DEM_INLINE void Dem_StatusChange_GetOldStatus (
		Dem_EventIdType EventId,
		Dem_UdsStatusByteType *isoByteOld,
		Dem_UdsStatusByteType *dtcStByteOld
)
{
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
	Dem_DtcIdType dtcId;
#endif
	*(isoByteOld) = Dem_EvtGetIsoByte(EventId);
    *dtcStByteOld = 0;
#if ( DEM_CFG_DTC_STATUSCHANGEDCALLBACK == DEM_CFG_DTC_STATUSCHANGEDCALLBACK_ON )
	if ( Dem_EventIdIsDtcAssigned(EventId) )
	{
		dtcId = Dem_DtcIdFromEventId(EventId);
		if ( Dem_DtcIsSupported(dtcId) )
		{
			*(dtcStByteOld) = (uint8)(Dem_DtcStatusByteRetrieve (dtcId) & DEM_CFG_DTCSTATUS_AVAILABILITYMASK);
		}
	}
#else
	(void) dtcStByteOld;
#endif
}

DEM_INLINE void Dem_TriggerOn_EventStatusChange (
        Dem_EventIdType EventId,
        Dem_UdsStatusByteType isoByteOld,
        Dem_UdsStatusByteType isoByteNew,
        Dem_UdsStatusByteType dtcStByteOld
)
{
    if ( isoByteNew != isoByteOld )
    {
#if (DEM_CFG_TRIGGERFIMREPORTS == DEM_CFG_TRIGGERFIMREPORTS_ON)
        /* DET will be reported if FiM_DemTriggerOnEventStatus function is called before Fim_Init() and FiM_DemInit() */
        if(Dem_Is_Fim_Initialized())
        {
            DEM_ENTERLOCK_MON();
            FiM_DemTriggerOnEventStatus (EventId, isoByteOld, isoByteNew);
            DEM_EXITLOCK_MON();
        }
#endif
        Dem_CallBackTriggerOnEventStatus(EventId,isoByteOld,isoByteNew,dtcStByteOld);
    }

}
#endif

