
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_DTC_DATASTRUCTURES_H
#define DEM_CFG_DTC_DATASTRUCTURES_H


#include "Dem_Cfg_DTCs.h"
#include "Dem_Prv_Det.h"
#include "Dem_Types.h"
#include "Dem_Lib.h"

/*
#include "Dem_Lock.h"
#include "Dem_Cfg_StorageCondition.h"
#include "Dem_Cfg_EnableCondition.h"
#include "Dem.h"
#include "rba_DiagLib.h"


#include "Dem_Lib.h"  */

/*
#define DEM_CFG_STOREWAITINGFORMONITORINGEVENT  FALSE
#define DEM_CFG_DTCFILTER_EXTERNALPROCESSING_OFF  STD_OFF
#define DEM_CFG_DTCFILTER_EXTERNALPROCESSING_ON   STD_ON
#define DEM_CFG_DTCFILTER_EXTERNALPROCESSING      DEM_CFG_DTCFILTER_EXTERNALPROCESSING_OFF
#define DEM_CFG_DTCSTATUS_AVAILABILITYMASK     0xFFu
#define DEM_CFG_DTC_TRANSLATION_TYPE           DEM_DTC_TRANSLATION_SAEJ1939_73
#define DEM_CFG_DTCSTATEMANGER_DTCS_PER_CYCLE   5u
#define DEM_DTC_BP_STATE_SUPPRESSED             0u
#define DEM_DTC_BP_GROUP_DTCSETTING_DISABLED    1u
#define DEM_DTC_GROUP_DemGroupOfDTC_0_DTCS           0xFA0u
#define DEM_DTC_GROUP_DemGroupOfDTC_1_DTCS           0x1388u  */

/* --------------------------------------------------- */
/* DEM_CFG_REPORT_CHRONOLOGICAL_ORDER_HOOKS_ENABLED    */
/* --------------------------------------------------- */
// #define DEM_CFG_REPORT_CHRONOLOGICAL_ORDER_HOOKS_ENABLED   FALSE


typedef struct
{
	Dem_DtcCodeType DtcCode;
	Dem_DTCSeverityType Severity;
	Dem_DTCKindType Kind;
	boolean DtcCode_Is_Index;
	uint8 Func_Unit;
	boolean Nv_Storage;
} Dem_Cfg_DtcType;

#define DEM_START_SEC_ROM_CONST
#include "Dem_Cfg_MemMap.h"
extern const Dem_Cfg_DtcType Dem_Cfg_Dtc[5];
#define DEM_STOP_SEC_ROM_CONST
#include "Dem_Cfg_MemMap.h"
LOCAL_INLINE Dem_DTCKindType Dem_Cfg_Dtc_GetKind(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return Dem_Cfg_Dtc[indx].Kind;
}

LOCAL_INLINE Dem_DTCSeverityType Dem_Cfg_Dtc_GetSeverity(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return Dem_Cfg_Dtc[indx].Severity;
}

LOCAL_INLINE boolean Dem_Cfg_Dtc_GetNv_Storage(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return Dem_Cfg_Dtc[indx].Nv_Storage;
}

LOCAL_INLINE uint8 Dem_Cfg_Dtc_GetFunc_Unit(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return Dem_Cfg_Dtc[indx].Func_Unit;
}

LOCAL_INLINE boolean Dem_Cfg_Dtc_GetDtcCode_Is_Index(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return Dem_Cfg_Dtc[indx].DtcCode_Is_Index;
}

/* MR12 RULE 2.7 VIOLATION: the parameter 'indx' is not used because the retrun value is the same for all indices due to the config, it is kept because the code calling the function is not config base but static */ 
LOCAL_INLINE Dem_DtcCodeType Dem_Cfg_Dtc_GetObd_DtcCode(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return DEM_INVALID_DTC; /* feature deactivated */
}

LOCAL_INLINE Dem_DtcCodeType Dem_Cfg_Dtc_GetDtcCode(Dem_DtcIdType indx)
{
	DEM_ASSERT_RANGECHECK((0 < indx) && (indx < 5));
	return Dem_Cfg_Dtc[indx].DtcCode;
}



// #define DEM_DTC_DTCSETTING_CALLBACK_SUPPORTED_OFF STD_OFF
// #define DEM_DTC_DTCSETTING_CALLBACK_SUPPORTED_ON STD_ON


#endif
