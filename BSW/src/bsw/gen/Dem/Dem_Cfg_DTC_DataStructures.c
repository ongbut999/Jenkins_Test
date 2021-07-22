
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#include "Dem_Cfg_DTC_DataStructures.h"
#define DEM_START_SEC_ROM_CONST
#include "Dem_Cfg_MemMap.h"

/* MR12 RULE 10.3 VIOLATION: due to the invalid index beeing used the first row includes values not matching the datatype, this row is never used */
const Dem_Cfg_DtcType Dem_Cfg_Dtc[5] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0xD0100, DEM_SEVERITY_CHECK_IMMEDIATELY, DEM_DTC_KIND_ALL_DTCS, FALSE, 0x00, TRUE },  /* DemDTC_C110117 */
	{ 0xD0200, DEM_SEVERITY_CHECK_IMMEDIATELY, DEM_DTC_KIND_ALL_DTCS, FALSE, 0x00, TRUE },  /* DemDTC_C110216 */
	{ 0xD0300, DEM_SEVERITY_CHECK_IMMEDIATELY, DEM_DTC_KIND_ALL_DTCS, FALSE, 0x00, TRUE },  /* DemDTC_C153364 */
	{ 0xD0400, DEM_SEVERITY_CHECK_IMMEDIATELY, DEM_DTC_KIND_ALL_DTCS, FALSE, 0x00, TRUE }  /* DemDTC_CANBusOff */
};

#define DEM_STOP_SEC_ROM_CONST
#include "Dem_Cfg_MemMap.h"
