 


#ifndef DEM_FWDTONVM_H
#define DEM_FWDTONVM_H

#include "Dem_EventStatus.h"
#include "Dem_EvMemBase.h"
#include "Dem_GenericNvData.h"
#include "Dem_DisturbanceMemory.h"
#include "Dem_EvBuff.h"

#if (DEM_CFG_OBD == DEM_CFG_OBD_ON)
/* FC_VariationPoint_START */
#include "Dem_Obd.h"
/* FC_VariationPoint_END */
#endif

#if( DEM_BFM_ENABLED == DEM_BFM_ON )
/* FC_VariationPoint_START */
#include "Dem_Bfm.h"
/* FC_VariationPoint_END */
#endif

#endif
