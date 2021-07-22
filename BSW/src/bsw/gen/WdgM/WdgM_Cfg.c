

/*
 **********************************************************************************************************************
 * Includes
 **********************************************************************************************************************
*/
#include "WdgM.h"
#include "Os.h"
#if (!defined(OS_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MAJOR_VERSION != 4))
#error “AUTOSAR major version undefined or mismatched“
#endif
#if (!defined(OS_AR_RELEASE_MINOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != 2))
#error “AUTOSAR minor version undefined or mismatched“
#endif
#include "WdgM_Prv.h"

/*
 ***************************************************************************************************
 * Variables
 ***************************************************************************************************
 */


/* There is no deadline Supervision configured in valid WdgMMode so corresponding Variables, data types are not defined....!!! */



/*
 ***************************************************************************************************
 * Dynamic Variables
 ***************************************************************************************************
 */
#define WDGM_START_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"
/* TRACE[WDGM200] Values of local supervsion should be described in WdgM_LocalStatusType */
VAR(WdgM_SupervisedEntityDynType, WDGM_VAR_FAST_CLEARED_UNSPECIFIED) WdgM_SupervisedEntityDyn[1];  /* WDGM242 */
static VAR(WdgM_CheckpointDynType, WDGM_VAR_FAST_CLEARED_UNSPECIFIED) WdgM_CheckpointDyn[1];
#define WDGM_STOP_SEC_VAR_FAST_CLEARED_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"

/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/

#define WDGM_START_SEC_CONFIG_DATA_FAST_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"


CONST(WdgM_CheckpointType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_Checkpoint[1] =
{	
	/* PtrToCheckpointDyn                          Comment */ 
	
	{   &WdgM_CheckpointDyn[0]                       /* WdgMSupervisedEntityId: 0, WdgMCheckpointId: 0 */        }
};


CONST(WdgM_SupervisedEntityType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_SupervisedEntity[1]=
{	
    /* NoOfCheckpoint             PartionEnabled             TimerId                                        OsApplicationId                                PtrToCheckpoint                                PtrToSupervisedEntityDyn                         Comment */         
    
    {  1                        ,  FALSE                    ,  WDGM_INVALID_TIMER_ID                        ,  INVALID_OSAPPLICATION                        ,  &WdgM_Checkpoint[0]                          ,    &WdgM_SupervisedEntityDyn[0]                     /* WdgMSupervisedEntityId: 0 */              }
};
/* No WdgMInternalTransition configured for Internal Graph so corresponding code is not generated. */
/* No WdgMInternalTransitionDestRef configured for Internal Graph so corresponding code is not generated. */

CONST(WdgM_AliveSupervisionType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_AliveSupervision[2] =
{
    /* MinMargin          MaxMargin                  AliveSupervisionCheckpointId     SupervisedEntityId              ExpectedAliveIndications   SupervisionReferenceCycle   Comment */ 
   
    {   0                   ,  2                   ,  0                              ,  0                             ,  10                      ,  10                       /* WdgMMode: 0  AliveSuperVision: Alive_Supervision_Entity1 */                  },   
    {   1                   ,  1                   ,  0                              ,  0                             ,  9                       ,  10                       /* WdgMMode: 1  AliveSuperVision: Alive_Supervision_Entity1 */                  }
};

/* No WdgMDeadlineSupervision configured so corresponding code is not generated. */


CONST(WdgM_LocalStatusParamsType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_LocalStatusParams[2] =
{
    /* FailedAliveSupervisionRefCycleTol               SupervisedEntityId                              Comment */                                    
    
    {   2                                            ,  0                                              /* WdgMMode: 0  WdgMLocalStatusParams: WdgMLocalStatusParams_Alive_Supervision_Entity1 */ },    
    {   0                                            ,  0                                              /* WdgMMode: 1  WdgMLocalStatusParams: WdgMLocalStatusParams_Alive_Supervision_Entity1 */ }  
};


CONST(WdgM_TriggerType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_Trigger[2] =
{
    /* TriggerConditionValue(in mili seconds)          DeviceIdx                                       TriggerModeType             Comment */                                    
    
    {   40                                           ,  WdgIfConf_WdgIfDevice_WdgIfDevice            ,  WDGIF_FAST_MODE            /* WdgMMode: 0  WdgMTrigger: WdgMTrigger_FastMode */                            },    
    {   100                                          ,  WdgIfConf_WdgIfDevice_WdgIfDevice            ,  WDGIF_SLOW_MODE            /* WdgMMode: 1  WdgMTrigger: WdgMTrigger_SlowMode */                            } 
};


CONST(WdgM_PrvModeType, WDGM_CONST_FAST_UNSPECIFIED) WdgM_PrvMode[2] =
{	    /* ExpiredSupervisionCycleTol                  SchMWdgMSupervisionCycle                                 SupervisionCycle(in mili seconds)               NoOfAliveSupervision                            NoOfDeadlineSupervision                         NoOfLocalStatusParams                           NoOfTrigger                                     PtrToAliveSupervision                           PtrToDeadlineSupervision                        PtrToLocalStatusParams                          PtrToTrigger                                    Comment */                                    
    
    {   0                                            ,  RTE_MODE_WdgMSupervisionCycle_SUPERVISION_CYCLE_0      ,  WDGM_SUPERVISION_CYCLE_0                     ,  1                                            ,  0                                            ,  1                                            ,  1                                            ,  &WdgM_AliveSupervision[0]                    ,  NULL_PTR                                     ,  &WdgM_LocalStatusParams[0]                   ,  &WdgM_Trigger[0]                               /* WdgMMode: WdgMMode_FastMode */            },
    {   0                                            ,  RTE_MODE_WdgMSupervisionCycle_SUPERVISION_CYCLE_0      ,  WDGM_SUPERVISION_CYCLE_0                     ,  1                                            ,  0                                            ,  1                                            ,  1                                            ,  &WdgM_AliveSupervision[1]                    ,  NULL_PTR                                     ,  &WdgM_LocalStatusParams[1]                   ,  &WdgM_Trigger[1]                               /* WdgMMode: WdgMMode_SlowMode */            }
};

CONST(WdgM_ConfigType, WDGM_CONST_FAST_UNSPECIFIED)  WdgM_Config =
{
    1                                                           , /* InitialMode */
    2                                                           , /* NoOfMode */
    DemConf_DemEventParameter_null                              , /* ErrorImproperCaller */
    DemConf_DemEventParameter_DemEventParameter_C153364         , /* ErrorSupervision */
    DemConf_DemEventParameter_null                              , /* ErrorSetMode */
    NULL_PTR                                                    , /* PtrToRunningCounterValue */
    NULL_PTR                                                    , /* PtrToDeadlineIndices */
    &WdgM_PrvMode[0]                                              /* PtrToMode */
};


#define      WDGM_STOP_SEC_CONFIG_DATA_FAST_UNSPECIFIED
#include "WdgM_Cfg_MemMap.h"

