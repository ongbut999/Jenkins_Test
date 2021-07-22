
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVDID_H
#define DEM_CFG_ENVDID_H

#define DEM_CFG_ENVDID2DATAELEMENT \
{ \
   DEM_DATAELEM_DEMDATAELEMENTCLASS_VEHICLESPEED,                                   /* VehicleSpeed */    \
   DEM_DATAELEM_DEMDATAELEMENTCLASS_SYSTEMFAULTRANK,                                   /* DemDidClass_SystemFaultRank */    \
   0 \
}


#define DEM_DID_VEHICLESPEED         1
#define DEM_DID_DEMDIDCLASS_SYSTEMFAULTRANK         2


#define DEM_CFG_ENVDID \
{ \
   { 0, 0 } \
   ,{ 1, 8976 }      /* DEM_DID_VEHICLESPEED */ \
   ,{ 2, 8977 }      /* DEM_DID_DEMDIDCLASS_SYSTEMFAULTRANK */ \
}

#define DEM_CFG_ENVDID_ARRAYLENGTH  (2+1)


#endif

