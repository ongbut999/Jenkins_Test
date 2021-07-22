
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVMAIN_H
#define DEM_CFG_ENVMAIN_H


/* min number of bytes required for storing any eventIds ExtendedData and one FreezeFrame (=> EvBuff) */
#define DEM_CFG_ENVMINSIZE_OF_RAWENVDATA           (4u + 0u + 0u)

/* min number of bytes required for storing any eventIds ExtendedData and multiple FreezeFrame (=> EvMem) */
#define DEM_CFG_ENVMINSIZE_OF_MULTIPLE_RAWENVDATA   (7u + 0u + 0u)

/*min number of bytes required for OBD related data - This is generated for getting Offset for handling J1939 data*/
#define DEM_CFG_OFFSET_OBDRAWENVDATA         0u




#define DEM_CFG_ENVEVENTID2ENVDATA \
{ \
   { 0u,0u }                                                      /* DEM_EVENTID_INVALID */ \
   ,{  DEM_EXTDATA_SET1_EXTD, DEM_FREEZEFRAME_SET1_FREEZE }        /* DemEventParameter_C110117 */ \
   ,{  DEM_EXTDATA_SET1_EXTD, DEM_FREEZEFRAME_SET1_FREEZE }        /* DemEventParameter_C110216 */ \
   ,{  DEM_EXTDATA_SET1_EXTD, DEM_FREEZEFRAME_SET1_FREEZE }        /* DemEventParameter_C153364 */ \
   ,{  DEM_EXTDATA_SET1_EXTD, DEM_FREEZEFRAME_SET1_FREEZE }        /* DemEventParameter_CanBusoff */ \
   ,{  0u, 0u }                                                    /* DemEventParameter_CanController1_Busoff */ \
}

/*------         Freeze frame        ,         Expanded Freeze frame -------------*/
#define DEM_CFG_J1939_ENVEVENTID2ENVDATA \
{ \
   { 0u,0u }                                                      /* DEM_EVENTID_INVALID */ \
   ,{  0u, 0u }                                                    /* DemEventParameter_C110117 */ \
   ,{  0u, 0u }                                                    /* DemEventParameter_C110216 */ \
   ,{  0u, 0u }                                                    /* DemEventParameter_C153364 */ \
   ,{  0u, 0u }                                                    /* DemEventParameter_CanBusoff */ \
   ,{  0u, 0u }                                                    /* DemEventParameter_CanController1_Busoff */ \
}

#endif

