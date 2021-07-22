
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_STORAGECONDITION_H
#define DEM_CFG_STORAGECONDITION_H


#include "Std_Types.h"


#define DEM_CFG_STORAGECONDITION_ON    STD_ON
#define DEM_CFG_STORAGECONDITION_OFF   STD_OFF
#define DEM_CFG_STORAGECONDITION       DEM_CFG_STORAGECONDITION_OFF


#define DemConf_DemStorageCondition_DemStorageCondition_0   0u


#define DEM_STORAGECONDITION_COUNT         1u
#define DEM_STORAGECONDITION_ARRAYLENGTH   (DEM_STORAGECONDITION_COUNT)


/* define type depends on projectspecific number of storageconditions */
/* if no storage conditions are support use uint8 to allow empty inline functions */
#if (DEM_STORAGECONDITION_ARRAYLENGTH <= 8) \
	|| (DEM_CFG_STORAGECONDITION == DEM_CFG_STORAGECONDITION_OFF)
typedef uint8 Dem_StoCoList;
#elif (DEM_STORAGECONDITION_ARRAYLENGTH <= 16)
typedef uint16 Dem_StoCoList;
#elif (DEM_STORAGECONDITION_ARRAYLENGTH <= 32)
typedef uint32 Dem_StoCoList;
#else
#error DEM currently only supports up to 32 StorageConditions
#endif

#if (DEM_CFG_STORAGECONDITION == DEM_CFG_STORAGECONDITION_ON)


#define DEM_STOCOBM_DemStorageCondition_0               ((Dem_StoCoList)(1u << DemConf_DemStorageCondition_DemStorageCondition_0))


#define DEM_STOCO_DemEventParameter_C110117                 (0u)
#define DEM_STOCO_DemEventParameter_C110216                 (0u)
#define DEM_STOCO_DemEventParameter_C153364                 (0u)
#define DEM_STOCO_DemEventParameter_CanBusoff               (0u)
#define DEM_STOCO_DemEventParameter_CanController1_Busoff             (0u)


#define DEM_CFG_STOCO_INITIALSTATE    (   0u \
                                       + (1u * DEM_STOCOBM_DemStorageCondition_0) \
                                      )


/* definition of replacement failures */
#define DEM_CFG_STOCO_PARAMS \
{ \
   { \
   DEM_EVENTID_INVALID, \
   } \
}


#endif

#endif

