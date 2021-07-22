

#include "Dem_Cfg_Events_DataStructures.h"
#include "Dem_Cfg_EventsCallback.h"
#include "Dem_Cfg_ExtPrototypes.h"
#include "Rte_Dem.h"

const Dem_EvtParam_8Type Dem_EvtParam_8[6] = {
	/*MR12 RULE 11.9 VIOLATION: The first row is a invalid index and will never be used*/ 
	{ 0 },
	{ 40u },  /* DemEventParameter_C110117 */
	{ 40u },  /* DemEventParameter_C110216 */
	{ 40u },  /* DemEventParameter_C153364 */
	{ 40u },  /* DemEventParameter_CanBusoff */
	{ 1u }  /* DemEventParameter_CanController1_Busoff */
};

const Dem_EvtParam_16Type Dem_EvtParam_16[6] = {
	/*MR12 RULE 11.9 VIOLATION: The first row is a invalid index and will never be used*/ 
	{ 0 },
	{ ( (uint32)(1u&0x1u) << 0) + ( (uint32)(1uL&0x1u) << 1) + ( (uint32)(1uL&0x1u) << 2) + ( (uint32)(0uL&0x1u) << 3) + ( (uint32)(DEM_DEBPARAM_IDX_DEMEVENTPARAMETER_C110117&0x7u) << 4) + ( (uint32)(1u&0x7u) << 7) + ( (uint32)(2u&0x3u) << 10) },  /* DemEventParameter_C110117 */
	{ ( (uint32)(1u&0x1u) << 0) + ( (uint32)(1uL&0x1u) << 1) + ( (uint32)(1uL&0x1u) << 2) + ( (uint32)(0uL&0x1u) << 3) + ( (uint32)(DEM_DEBPARAM_IDX_DEMEVENTPARAMETER_C110216&0x7u) << 4) + ( (uint32)(2u&0x7u) << 7) + ( (uint32)(2u&0x3u) << 10) },  /* DemEventParameter_C110216 */
	{ ( (uint32)(1u&0x1u) << 0) + ( (uint32)(1uL&0x1u) << 1) + ( (uint32)(1uL&0x1u) << 2) + ( (uint32)(0uL&0x1u) << 3) + ( (uint32)(DEM_DEBPARAM_IDX_DEMEVENTPARAMETER_C153364&0x7u) << 4) + ( (uint32)(3u&0x7u) << 7) + ( (uint32)(2u&0x3u) << 10) },  /* DemEventParameter_C153364 */
	{ ( (uint32)(1u&0x1u) << 0) + ( (uint32)(1uL&0x1u) << 1) + ( (uint32)(1uL&0x1u) << 2) + ( (uint32)(0uL&0x1u) << 3) + ( (uint32)(DEM_DEBPARAM_IDX_DEMEVENTPARAMETER_CANBUSOFF&0x7u) << 4) + ( (uint32)(4u&0x7u) << 7) + ( (uint32)(2u&0x3u) << 10) },  /* DemEventParameter_CanBusoff */
	{ ( (uint32)(0u&0x1u) << 0) + ( (uint32)(0uL&0x1u) << 1) + ( (uint32)(0uL&0x1u) << 2) + ( (uint32)(1uL&0x1u) << 3) + ( (uint32)(DEM_DEBPARAM_IDX_DEMEVENTPARAMETER_CANCONTROLLER1_BUSOFF&0x7u) << 4) + ( (uint32)(255u&0x7u) << 7) + ( (uint32)(0u&0x3u) << 10) }  /* DemEventParameter_CanController1_Busoff */
};



