
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ENVDATAELEMENT_H
#define DEM_CFG_ENVDATAELEMENT_H

#include "Std_Types.h"


#define DEM_CFG_ENV_DATAELEMENTS_EXTERN_AVAILABILITY   STD_ON
#define DEM_CFG_ENV_DATAELEMENTS_INTERN_AVAILABILITY  STD_ON

#define DEM_CFG_READDEM_AGINGCTR_UPCNT_SUPPORTED                         TRUE
#define DEM_CFG_READDEM_AGINGCTR_DOWNCNT_SUPPORTED                       FALSE
#define DEM_CFG_READDEM_OCCCTR_SUPPORTED                                 FALSE
#define DEM_CFG_READDEM_OVFLIND_SUPPORTED                                FALSE
#define DEM_CFG_READDEM_SIGNIFICANCE_SUPPORTED                           FALSE
#define DEM_CFG_READDEM_DEBUG0_SUPPORTED                                 FALSE
#define DEM_CFG_READDEM_DEBUG1_SUPPORTED                                 FALSE
#define DEM_CFG_READDEM_EVENT_ID_SUPPORTED                               FALSE
#define DEM_CFG_READDEM_CURRENT_FDC_SUPPORTED                            FALSE
#define DEM_CFG_READDEM_MAX_FDC_DURING_CURRENT_CYCLE_SUPPORTED           FALSE
#define DEM_CFG_READDEM_MAX_FDC_SINCE_LAST_CLEAR_SUPPORTED               FALSE
#define DEM_CFG_READDEM_CYCLES_SINCE_FIRST_FAILED_SUPPORTED              FALSE
#define DEM_CFG_READDEM_CYCLES_SINCE_LAST_FAILED_SUPPORTED               FALSE
#define DEM_CFG_READDEM_CYCLES_SINCE_LAST_FAILED_EXCLUDING_TNC_SUPPORTED   FALSE
#define DEM_CFG_READDEM_FAILED_CYCLES_SUPPORTED                          FALSE
#define DEM_CFG_READDEM_PRJ_SPECIFIC_DATA_ON_RETRIEVE_SUPPORTED          FALSE
#define DEM_CFG_READDEM_PRJ_SPECIFIC_DATA_ON_REPORT_SUPPORTED            FALSE


#define DEM_DATAELEM_DEMDATAELEMENTCLASS_SYSTEMFAULTRANK  1
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_VEHICLESPEED  2
#define DEM_DATAELEM_DEMDATAELEMENTCLASS_AGING_COUNTER  3

#define DEM_CFG_ENV_DATAELEMENTS \
{ \
   { DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR) 0, FALSE } \
   ,{ &Rte_Call_DataServices_DemDataElementClass_SystemFaultRank_ReadData, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR)1, FALSE } \
   ,{ &Rte_Call_DataServices_DemDataElementClass_VehicleSpeed_ReadData, DEM_ENV_DATAELEMENTS_INTERN_INIT(NULL_PTR)2, FALSE } \
   ,{ DEM_ENV_DATAELEMENTS_EXTCS_INIT(NULL_PTR) &Dem_ReadAgingCtrUpCnt, 1, TRUE } \
}

#define DEM_CFG_ENV_DATAELEMENTS_ARRAYLENGTH      (3+1)


#endif


