
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_NODES_H
#define DEM_CFG_NODES_H


/* ---------------------------------------- */
/* DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE  */
/* ---------------------------------------- */
#define DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE_OFF  STD_OFF
#define DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE_ON   STD_ON
#define DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE  DEM_CFG_DEPDEGRADATIONREASONRECOVERABLE_OFF


/* ---------------------------------------- */
/* DEM_CFG_DEPRECOVERYLIMIT                 */
/* ---------------------------------------- */
#define DEM_CFG_DEPRECOVERYLIMIT_OFF  STD_OFF
#define DEM_CFG_DEPRECOVERYLIMIT_ON   STD_ON
#define DEM_CFG_DEPRECOVERYLIMIT  DEM_CFG_DEPRECOVERYLIMIT_OFF



#define DEM_CFG_DEPENDENCY_PENDING_ON             FALSE


#define DEM_CFG_FAILUREDEPENDENCY_RECHECK_LIMIT  80u




/*                  ALLOWEDRECOVERIES             IGNORESPRIO    FAILEDCALLBACK_IDX                       */

#define DEM_CFG_NODEPARAMS \
{ \
    DEM_NODES_INIT (DEM_NODE_INFINITE_RECOVERIES, 0,             0                                       ) \
   ,DEM_NODES_INIT (255,                          0,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_Busoff_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (255,                          0,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_C110117_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (255,                          0,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_C110216_ComponentStatusChanged_IDX) \
   ,DEM_NODES_INIT (255,                          0,             DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_C153364_ComponentStatusChanged_IDX) \
}



#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_C110117_ComponentStatusChanged_IDX    1
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_C110216_ComponentStatusChanged_IDX    2
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_C153364_ComponentStatusChanged_IDX    3
#define  DEM_CFG_Rte_Call_Dem_CBStatusComp_DemComponent_Busoff_ComponentStatusChanged_IDX    4


#define  DEM_CFG_NODEFAILEDCALLBACK_COUNT  4
#define  DEM_CFG_NODEFAILEDCALLBACK_ARRAYLENGTH  (DEM_CFG_NODEFAILEDCALLBACK_COUNT+1)


#define DEM_CFG_NODEFAILEDCALLBACKS \
{ \
	NULL_PTR \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_C110117_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_C110216_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_C153364_ComponentStatusChanged \
    ,&Rte_Call_Dem_CBStatusComp_DemComponent_Busoff_ComponentStatusChanged \
}





#endif

