
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENABLECONDITION_H
#define DEM_CFG_ENABLECONDITION_H


#include "Std_Types.h"


#define DEM_CFG_ENABLECONDITION_ON    STD_ON
#define DEM_CFG_ENABLECONDITION_OFF   STD_OFF
#define DEM_CFG_ENABLECONDITION       DEM_CFG_ENABLECONDITION_OFF




#define DEM_ENABLECONDITION_COUNT         0u
#define DEM_ENABLECONDITION_ARRAYLENGTH   (DEM_ENABLECONDITION_COUNT)


/* define type depends on projectspecific number of storageconditions */
/* if no storage conditions are support use uint8 to allow empty inline functions */
#if (DEM_ENABLECONDITION_ARRAYLENGTH <= 8) \
	|| (DEM_CFG_ENABLECONDITION == DEM_CFG_ENABLECONDITION_OFF)
typedef uint8 Dem_EnCoList;
#elif (DEM_ENABLECONDITION_ARRAYLENGTH <= 16)
typedef uint16 Dem_EnCoList;
#elif (DEM_ENABLECONDITION_ARRAYLENGTH <= 32)
typedef uint32 Dem_EnCoList;
#else
#error DEM currently only supports up to 32 EnableConditions
#endif


#if (DEM_CFG_ENABLECONDITION == DEM_CFG_ENABLECONDITION_ON)




#define DEM_ENCO_DemEventParameter_C110117      (0u)
#define DEM_ENCO_DemEventParameter_C110216      (0u)
#define DEM_ENCO_DemEventParameter_C153364      (0u)
#define DEM_ENCO_DemEventParameter_CanBusoff    (0u)
#define DEM_ENCO_DemEventParameter_CanController1_Busoff  (0u)



#define DEM_CFG_ENCO_INITIALSTATE    (   0u \
                                      )

#endif

#endif

