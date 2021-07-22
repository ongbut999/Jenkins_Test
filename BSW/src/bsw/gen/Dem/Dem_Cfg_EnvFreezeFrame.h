
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVFREEZEFRAME_H
#define DEM_CFG_ENVFREEZEFRAME_H

#define DEM_CFG_ENVFREEZEFRAME2DID \
{ \
   DEM_DID_DEMDIDCLASS_SYSTEMFAULTRANK,   DEM_DID_VEHICLESPEED, /* Set1_Freeze */ \
   0 \
}


#define DEM_FREEZEFRAME_SET1_FREEZE         1


#define DEM_CFG_ENVFREEZEFRAME \
{ \
   { 0,0 } \
   ,{ 2, 3 }   /* DEM_FREEZEFRAME_SET1_FREEZE */  \
}


#define DEM_CFG_ENVFREEZEFRAME_ARRAYLENGTH  (1+1)


#endif


