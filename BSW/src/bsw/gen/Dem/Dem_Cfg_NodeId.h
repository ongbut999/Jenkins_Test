
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_NODEID_H
#define DEM_CFG_NODEID_H

#include "Std_Types.h"

#define DEM_NODEID_INVALID             0
#define DEM_NODEID_COUNT               4u
#define DEM_NODEID_ARRAYLENGTH         (DEM_NODEID_COUNT+1u)

/* define type depends on projectspecific number of nodes */
#if (DEM_NODEID_ARRAYLENGTH <= 255)
typedef uint8 Dem_ComponentIdType;
#else
typedef uint16 Dem_ComponentIdType;
#endif

#define DemConf_DemNode_DemComponent_Busoff 1
#define DemConf_DemNode_DemComponent_C110117 2
#define DemConf_DemNode_DemComponent_C110216 3
#define DemConf_DemNode_DemComponent_C153364 4






#endif

