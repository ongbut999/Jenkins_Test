
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_DTCID_H
#define DEM_CFG_DTCID_H


#include "Dem_Cfg_EventId.h"


#define DEM_CFG_EVCOMB_DISABLED       1u
#define DEM_CFG_EVCOMB_ONSTORAGE      2u
#define DEM_CFG_EVCOMB_ONRETRIEVAL    3u
#define DEM_CFG_EVCOMB            DEM_CFG_EVCOMB_DISABLED


#define DEM_DTCID_INVALID           0u
#define DEM_DTCID_COUNT             4u
#define DEM_DTCID_ARRAYLENGTH       (DEM_DTCID_COUNT+1u)



#define DemConf_DemDTCClass_DemDTC_C110117                           1u
#define DemConf_DemDTCClass_DemDTC_C110216                           2u
#define DemConf_DemDTCClass_DemDTC_C153364                           3u
#define DemConf_DemDTCClass_DemDTC_CANBusOff                         4u

#define DEM_DTCGROUPID_INVALID           0u
#define DEM_DTCGROUPID_COUNT             1u
#define DEM_DTCGROUPID_ARRAYLENGTH       (DEM_DTCGROUPID_COUNT+1u)



// genInfo: for (EvCombination==OFF) the explicit mapping from dtcid to eventId is necessary, because an event may not be assigned to any DTC
#define  DEM_MAP_EVENTID_DTCID   \
const Dem_DtcIdType Dem_MapEventIdToDtcId[DEM_EVENTID_ARRAYLENGTH] = \
{ \
   DEM_DTCID_INVALID \
   ,DemConf_DemDTCClass_DemDTC_C110117      /* DemEventParameter_C110117 */ \
   ,DemConf_DemDTCClass_DemDTC_C110216      /* DemEventParameter_C110216 */ \
   ,DemConf_DemDTCClass_DemDTC_C153364      /* DemEventParameter_C153364 */ \
   ,DemConf_DemDTCClass_DemDTC_CANBusOff    /* DemEventParameter_CanBusoff */ \
   ,DEM_DTCID_INVALID                       /* DemEventParameter_CanController1_Busoff */ \
};


#define DEM_MAP_DTCGROUPID_DTCID \
{ {0u,0u}\
 ,{DemConf_DemDTCClass_DemDTC_C110117      , DemConf_DemDTCClass_DemDTC_CANBusOff}	/* DEM_DTC_GROUP_ALL_DTCS */\
}

#if (DEM_CFG_EVCOMB == DEM_CFG_EVCOMB_DISABLED)


#define DEM_MAP_DTCID_EVENTID        \
const Dem_MapDtcIdToEventIdType  Dem_MapDtcIdToEventId[DEM_DTCID_ARRAYLENGTH] = \
{ \
   DEM_EVENTID_INVALID \
   ,DemConf_DemEventParameter_DemEventParameter_C110117 /* DemDTC_C110117 */ \
   ,DemConf_DemEventParameter_DemEventParameter_C110216 /* DemDTC_C110216 */ \
   ,DemConf_DemEventParameter_DemEventParameter_C153364 /* DemDTC_C153364 */ \
   ,DemConf_DemEventParameter_DemEventParameter_CanBusoff /* DemDTC_CANBusOff */ \
};


#else

#define DEM_MAP_DTCID_EVENTID        \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_C110117[] = { \
   DemConf_DemEventParameter_DemEventParameter_C110117 \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_C110216[] = { \
   DemConf_DemEventParameter_DemEventParameter_C110216 \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_C153364[] = { \
   DemConf_DemEventParameter_DemEventParameter_C153364 \
}; \
 \
 \
static const  Dem_EventIdType  Dem_MapDtcIdToEventId_DemDTC_CANBusOff[] = { \
   DemConf_DemEventParameter_DemEventParameter_CanBusoff \
}; \
 \
 \
 \
const Dem_MapDtcIdToEventIdType  Dem_MapDtcIdToEventId[DEM_DTCID_ARRAYLENGTH] = \
{ \
   { \
      NULL_PTR, \
      0u \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_C110117[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_C110117)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_C110117[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_C110216[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_C110216)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_C110216[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_C153364[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_C153364)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_C153364[0])) \
   } \
   ,{ \
      &Dem_MapDtcIdToEventId_DemDTC_CANBusOff[0], \
      (uint16)(DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_CANBusOff)/DEM_SIZEOF_VAR(Dem_MapDtcIdToEventId_DemDTC_CANBusOff[0])) \
   } \
};


#endif



#endif

