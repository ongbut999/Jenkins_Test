/*
 * This is Os_Cfg.h, auto-generated for:
 *   Project: Os_Config
 *   Target:  TriCoreHighTec
 *   Variant: TC27xD
 *   Version: 5.0.22
 *   [$UKS 650]
 */
#ifndef OS_CFG_H
#define OS_CFG_H
/* -- Start expansion of <Os_Safe_Cfg.h> -- */
/* -- Start expansion of <Os_Target_Cfg.h> -- */
#define OS_TARGET_TRICOREHIGHTEC
#define OS_TRICORE_UNTRUSTED_MASK 0x1000U
#define OS_TRICORE_TRUSTEDWITHPROTECTION_MASK 0x2800U
#define OS_INIT_SRC_GPSR02 (0x1401U)
#define OS_INIT_SRC_GPSR01 (0xc01U)
#define OS_INIT_SRC_GPSR00 (0x401U)
#define OS_INIT_SRC_GTMTOM00 (0x402U)
#define OS_INIT_SRC_STM0SR0 (0x403U)
#define OS_VEC_Os_CrossCoreISR2 (1U)
#define OS_CORE_Os_CrossCoreISR2 (2U)
#define OS_BISR_Os_CrossCoreISR2 (1U)
#define OS_VEC_Os_CrossCoreISR1 (1U)
#define OS_CORE_Os_CrossCoreISR1 (1U)
#define OS_BISR_Os_CrossCoreISR1 (1U)
#define OS_VEC_Os_CrossCoreISR0 (1U)
#define OS_CORE_Os_CrossCoreISR0 (0U)
#define OS_BISR_Os_CrossCoreISR0 (1U)
#define OS_VEC_GTMTOM0SR0_ISR (2U)
#define OS_CORE_GTMTOM0SR0_ISR (0U)
#define OS_BISR_GTMTOM0SR0_ISR (2U)
#define OS_VEC_Millisecond (3U)
#define OS_CORE_Millisecond (0U)
#define OS_BISR_Millisecond (255U)
#define Os_Core0_SRN (SRC_GPSR00)
DECLARE_CAT1_ISR(Os_CrossCoreISR0);
#define Os_Core1_SRN (SRC_GPSR01)
DECLARE_CAT1_ISR(Os_CrossCoreISR1);
#define Os_Core2_SRN (SRC_GPSR02)
DECLARE_CAT1_ISR(Os_CrossCoreISR2);
#define OS_NUM_SRNS (465U)

/* -- End expansion of <Os_Target_Cfg.h> -- */
#define OS_NUM_APPMODES (2U)
#define OS_NUM_APPLICATIONS (3U)
#define OS_NUM_SPINLOCKS (0U)
#define OS_NUM_TRUSTED_FUNCTIONS (0U)
#define OS_NUM_IOC_CALLBACK_FUNCTIONS (Os_const_ioc_function_count)
#define OS_NUM_EVENTS (0U)
#define OS_NUM_TASKS (11U)
#define OS_NUM_ISRS (2U)
#define OS_NUM_RESOURCES (7U)
#define OS_NUM_ALARMS (0U)
#define OS_NUM_SCHEDULETABLES (1U)
#define OS_NUM_PERIPHERALAREAS (0U)
#define OS_NUM_TRACEPOINTS (3U)
#define OS_NUM_TASKTRACEPOINTS (0U)
#define OS_NUM_INTERVALS (0U)
#define OS_NUM_TRACECATEGORIES (0U)
#define OS_TRACE_CATEGORY_ALWAYS ((Os_TraceCategoriesType)(0x80000000UL))
#define OS_TRACE_CATEGORY_NEVER  ((Os_TraceCategoriesType)(0x00000000UL))
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_TICKS2*) */
#define OS_NUM_COUNTERS (1U)
#define OSCYCLEDURATION (5) /* [$UKS 1224] */
#define OSCYCLESPERSECOND (200000000U) /* [$UKS 1225] */
#define OSSWTICKDURATION (10) /* [$UKS 1226] */
#define OSSWTICKSPERSECOND (100000000U) /* [$UKS 1227] */
#define OS_TICKS2NS_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1000000U)) /* [$UKS 843] */
#define OS_TICKS2US_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1000U)) /* [$UKS 843] */
#define OS_TICKS2MS_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) * 1U)) /* [$UKS 843] */
#define OS_TICKS2SEC_Rte_TickCounter(ticks) ((PhysicalTimeType)((ticks) / 1000U)) /* [$UKS 843] */
#define OSMAXALLOWEDVALUE_Rte_TickCounter (65535U) /* [$UKS 219] */
#define OSTICKSPERBASE_Rte_TickCounter (1U) /* [$UKS 220] */
#define OSTICKDURATION_Rte_TickCounter OS_TICKS2NS_Rte_TickCounter(1U) /* [$UKS 221] */
#define OSMINCYCLE_Rte_TickCounter (1U) /* [$UKS 222] */
#define OSMAXALLOWEDVALUE OSMAXALLOWEDVALUE_SystemCounter /* [$UKS 215] */
#define OSTICKSPERBASE OSTICKSPERBASE_SystemCounter /* [$UKS 216] */
#define OSMINCYCLE OSMINCYCLE_SystemCounter /* [$UKS 218] */
#define OSTICKDURATION OSTICKDURATION_SystemCounter /* [$UKS 217] */
#define OS_NUM_CORES (3U)
#define OS_NUM_OS_CORES (3U)
#define OS_CORE_ID_MASTER (0U)  /* [$UKS 1609] */
/* [$UKS 1611] */
#define OS_CORE_ID_0 (0U)
#define OS_CORE_ID_1 (1U)
#define OS_CORE_ID_2 (2U)

/* ------------------------------------------------- */
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_START_SEC_CODE_LIB
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */
extern FUNC(StatusType, OS_CODE) Os_IncrementCounter_Rte_TickCounter(void);
extern FUNC(void, OS_CODE) Os_Entry_OsTask_Background_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_OsTask_ASW_100ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core2_OsTask_ASW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_ASW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_OsTask_ASW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core2_OsTask_BSW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_Core1_OsTask_BSW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_OsTask_BSW_10ms(void);
extern FUNC(void, OS_CODE) Os_Entry_OsTask_BSW_1ms(void);
extern FUNC(void, OS_CODE) Os_Entry_BSW_OsTask_SwcRequest(void);
extern FUNC(void, OS_CODE) Os_Entry_ECU_StartupTask(void);
extern FUNC(void, OS_CODE) Os_Entry_GTMTOM0SR0_ISR(void);
extern FUNC(void, OS_CODE) Os_Entry_Millisecond(void);
/* [MISRA 2012 Rule 20.1] */ /*lint -save -estring(9019, *) */
#define OS_STOP_SEC_CODE_LIB
#include "Os_MemMap.h" /* [MISRA 2012 Dir 4.10] */ /*lint !e537 !e451 */
/*lint -restore */

/* -- End expansion of <Os_Safe_Cfg.h> -- */
/* -------- Time Monitoring --------- */
#define OS_TIME_MONITORING  /* [$UKS 959] */
/* -------- Time Recording --------- */
#define OS_ELAPSED_TIME_RECORDING
/* -------- Stack Monitoring --------- */
#define OS_STACK_MONITORING  /* [$UKS 954] */

/* -------- AppMode declarations --------- */

/* ----- OS-Application declarations ----- */
#define OsApplication_Core0 ((ApplicationType)1U) /* [$UKS 412] */
#define OsApplication_Core1 ((ApplicationType)2U) /* [$UKS 412] */
#define OsApplication_Core2 ((ApplicationType)3U) /* [$UKS 412] */

/* ----- PeripheralArea declarations ----- */

/* ----- Spinlock declarations ----- */

/* -------- Event declarations --------- */

/* -------- Task declarations --------- */
#define OsTask_Background_1ms (&Os_const_tasks0[0])
#define OS_CORE_FOR_OsTask_Background_1ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_OsTask_Background_1ms (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_OsTask_Background_1ms (0x8000U) /* [$UKS 2009] */
DeclareTask(OsTask_Background_1ms)
#define OsTask_ASW_100ms (&Os_const_tasks0[1])
#define OS_CORE_FOR_OsTask_ASW_100ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_OsTask_ASW_100ms (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_OsTask_ASW_100ms (0x8000U) /* [$UKS 2009] */
DeclareTask(OsTask_ASW_100ms)
#define Core2_OsTask_ASW_10ms (&Os_const_tasks2[0])
#define OS_CORE_FOR_Core2_OsTask_ASW_10ms (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core2_OsTask_ASW_10ms (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core2_OsTask_ASW_10ms (0x8000U) /* [$UKS 2009] */
DeclareTask(Core2_OsTask_ASW_10ms)
#define Core1_OsTask_ASW_10ms (&Os_const_tasks1[0])
#define OS_CORE_FOR_Core1_OsTask_ASW_10ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_ASW_10ms (0U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_ASW_10ms (0x8000U) /* [$UKS 2009] */
DeclareTask(Core1_OsTask_ASW_10ms)
#define OsTask_ASW_10ms (&Os_const_tasks0[2])
#define OS_CORE_FOR_OsTask_ASW_10ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_OsTask_ASW_10ms (2U) /* [$UKS 2007] */
#define OS_IMASK_FOR_OsTask_ASW_10ms (0x8000U) /* [$UKS 2009] */
DeclareTask(OsTask_ASW_10ms)
#define Core2_OsTask_BSW_10ms (&Os_const_tasks2[1])
#define OS_CORE_FOR_Core2_OsTask_BSW_10ms (2U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core2_OsTask_BSW_10ms (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core2_OsTask_BSW_10ms (0x8000U) /* [$UKS 2009] */
DeclareTask(Core2_OsTask_BSW_10ms)
#define Core1_OsTask_BSW_10ms (&Os_const_tasks1[1])
#define OS_CORE_FOR_Core1_OsTask_BSW_10ms (1U) /* [$UKS 1909] */
#define OS_TPL_FOR_Core1_OsTask_BSW_10ms (1U) /* [$UKS 2007] */
#define OS_IMASK_FOR_Core1_OsTask_BSW_10ms (0x8000U) /* [$UKS 2009] */
DeclareTask(Core1_OsTask_BSW_10ms)
#define OsTask_BSW_10ms (&Os_const_tasks0[3])
#define OS_CORE_FOR_OsTask_BSW_10ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_OsTask_BSW_10ms (3U) /* [$UKS 2007] */
#define OS_IMASK_FOR_OsTask_BSW_10ms (0x8000U) /* [$UKS 2009] */
DeclareTask(OsTask_BSW_10ms)
#define OsTask_BSW_1ms (&Os_const_tasks0[4])
#define OS_CORE_FOR_OsTask_BSW_1ms (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_OsTask_BSW_1ms (4U) /* [$UKS 2007] */
#define OS_IMASK_FOR_OsTask_BSW_1ms (0x8000U) /* [$UKS 2009] */
DeclareTask(OsTask_BSW_1ms)
#define BSW_OsTask_SwcRequest (&Os_const_tasks0[5])
#define OS_CORE_FOR_BSW_OsTask_SwcRequest (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_BSW_OsTask_SwcRequest (5U) /* [$UKS 2007] */
#define OS_IMASK_FOR_BSW_OsTask_SwcRequest (0x8000U) /* [$UKS 2009] */
DeclareTask(BSW_OsTask_SwcRequest)
#define ECU_StartupTask (&Os_const_tasks0[6])
#define OS_CORE_FOR_ECU_StartupTask (0U) /* [$UKS 1909] */
#define OS_TPL_FOR_ECU_StartupTask (6U) /* [$UKS 2007] */
#define OS_IMASK_FOR_ECU_StartupTask (0x8000U) /* [$UKS 2009] */
DeclareTask(ECU_StartupTask)
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_TPL_FOR_TASK, OS_IMASK_FOR_TASK) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_TPL_FOR_TASK) */
#define OS_TPL_FOR_TASK(n) OS_TPL_FOR_##n  /* [$UKS 2008] */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_IMASK_FOR_TASK) */
#define OS_IMASK_FOR_TASK(n) OS_IMASK_FOR_##n  /* [$UKS 2010] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_CORE_FOR_TASK) */
#define OS_CORE_FOR_TASK(t) (t)->core_id /* [$UKS 1921] */

/* -------- ISR declarations --------- */
#define GTMTOM0SR0_ISR (&Os_const_isrs[0U])
#define OS_IMASK_FOR_GTMTOM0SR0_ISR (0x8002U) /* [$UKS 2009] */
#define OS_CORE_FOR_GTMTOM0SR0_ISR (0U) /* [$UKS 1909] */
DeclareISR(GTMTOM0SR0_ISR)
#define Millisecond (&Os_const_isrs[1U])
#define OS_IMASK_FOR_Millisecond (0x80FFU) /* [$UKS 2009] */
#define OS_CORE_FOR_Millisecond (0U) /* [$UKS 1909] */
DeclareISR(Millisecond)
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_CORE_FOR_ISR) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_CORE_FOR_ISR) */
#define OS_CORE_FOR_ISR(i) OS_CORE_FOR_##i /* [$UKS 1922] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, OS_IMASK_FOR_ISR) */
/* [MISRA 2012 Rule 20.10] */ /*lint -estring(9024, OS_IMASK_FOR_ISR) */
#define OS_IMASK_FOR_ISR(n) OS_IMASK_FOR_##n  /* [$UKS 2011] */

/* -------- Resource declarations --------- */
#define RTE_RESOURCE_OS_APP_OsApplication_Core1 (&Os_const_resources[0U])
DeclareResource(RTE_RESOURCE_OS_APP_OsApplication_Core1)
#define RTE_RESOURCE_OS_APP_OsApplication_Core2 (&Os_const_resources[1U])
DeclareResource(RTE_RESOURCE_OS_APP_OsApplication_Core2)
#define Rte_EA_BSWImpl5_BSWIMPL_Can_CAN_EXCLUSIVE_AREA_0 (&Os_const_resources[2U])
DeclareResource(Rte_EA_BSWImpl5_BSWIMPL_Can_CAN_EXCLUSIVE_AREA_0)
#define RTE_RESOURCE_OS_APP_OsApplication_Core0 (&Os_const_resources[3U])
DeclareResource(RTE_RESOURCE_OS_APP_OsApplication_Core0)
#define Os_Core0_RES_SCHEDULER (&Os_const_resources[4U])
DeclareResource(Os_Core0_RES_SCHEDULER)
#define Os_Core1_RES_SCHEDULER (&Os_const_resources[5U])
DeclareResource(Os_Core1_RES_SCHEDULER)
#define Os_Core2_RES_SCHEDULER (&Os_const_resources[6U])
DeclareResource(Os_Core2_RES_SCHEDULER)
#define RES_SCHEDULER (&Os_const_resources[GetCoreID() + 4U])

/* -------- Counter declarations --------- */
#define Rte_TickCounter (&Os_const_counters[0U])
DeclareCounter(Rte_TickCounter)

/* -------- Alarm declaration --------- */

/* -------- ScheduleTable declaration --------- */
#define Rte_ScheduleTable (&Os_const_scheduletables[0U])
#define OS_DURATION_Rte_ScheduleTable (100U)
DeclareScheduleTable(Rte_ScheduleTable)

/* -------- Tracepoint declarations --------- */
#define OSApp_OsApplication_Core0 (1U)
#define OSApp_OsApplication_Core1 (2U)
#define OSApp_OsApplication_Core2 (3U)

/* -------- TaskTracepoint declarations --------- */

/* -------- Interval declarations --------- */

/* -------- Filtered APIs --------- */
#define Os_LogTracepoint(TpointID,Category) /* never */
#define Os_LogTracepointValue(TpointID,Value,Category) /* never */
#define Os_LogTracepointData(TpointID,Data,Length,Category) /* never */
#define Os_LogTaskTracepoint(TTpointID,Category) /* never */
#define Os_LogTaskTracepointValue(TTpointID,Value,Category) /* never */
#define Os_LogTaskTracepointData(TTpointID,Data,Length,Category) /* never */
#define Os_LogIntervalStart(IntervalID,Category) /* never */
#define Os_LogIntervalStartValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalStartData(IntervalID,Data,Length,Category) /* never */
#define Os_LogIntervalEnd(IntervalID,Category) /* never */
#define Os_LogIntervalEndValue(IntervalID,Value,Category) /* never */
#define Os_LogIntervalEndData(IntervalID,Data,Length,Category) /* never */
#ifndef OS_TRACE_NAMESPACE_PURE /* [$UKS 1154] */
/* [MISRA 2012 Dir 4.9] */ /*lint -estring(9026, LogTrace*, LogTaskTrace*, LogInterval*) */  #define LogTracepoint(TpointID,Category) Os_LogTracepoint(TpointID,Category)
  #define LogTracepointValue(TpointID,Value,Category) Os_LogTracepointValue(TpointID,Value,Category)
  #define LogTracepointData(TpointID,Data,Length,Category) Os_LogTracepointData(TpointID,Data,Length,Category)
  #define LogTaskTracepoint(TTpointID,Category) Os_LogTaskTracepoint(TTpointID,Category)
  #define LogTaskTracepointValue(TTpointID,Value,Category) Os_LogTaskTracepointValue(TTpointID,Value,Category)
  #define LogTaskTracepointData(TTpointID,Data,Length,Category) Os_LogTaskTracepointData(TTpointID,Data,Length,Category)
  #define LogIntervalStart(IntervalID,Category) Os_LogIntervalStart(IntervalID,Category)
  #define LogIntervalStartValue(IntervalID,Value,Category) Os_LogIntervalStartValue(IntervalID,Value,Category)
  #define LogIntervalStartData(IntervalID,Data,Length,Category) Os_LogIntervalStartData(IntervalID,Data,Length,Category)
  #define LogIntervalEnd(IntervalID,Category) Os_LogIntervalEnd(IntervalID,Category)
  #define LogIntervalEndValue(IntervalID,Value,Category) Os_LogIntervalEndValue(IntervalID,Value,Category)
  #define LogIntervalEndData(IntervalID,Data,Length,Category) Os_LogIntervalEndData(IntervalID,Data,Length,Category)
#endif

#endif /* OS_CFG_H */
