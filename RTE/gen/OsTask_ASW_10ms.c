/** @file     OsTask_ASW_10ms.c
  *
  * @brief    Task OsTask_ASW_10ms body
  *
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  *
  * @note     Generated by ETAS RTA-RTE
  * @note     Version 6.8.0 
  */

#define RTE_CORE

#include "Rte_Const.h"
#if !defined(RTE_VENDOR_MODE)
#pragma message "Compiling an individual task file but RTE_VENDOR_MODE not defined. Compiling a stale file?"
#endif /* !defined(RTE_VENDOR_MODE) */
#if defined(RTE_USE_TASK_HEADER)
#include "OsTask_ASW_10ms.h"
#else /* !defined(RTE_USE_TASK_HEADER) */
#include "Os.h"
#endif /* !defined(RTE_USE_TASK_HEADER) */
#if defined(RTE_REQUIRES_IOC)
#include "Ioc.h"
#endif /* defined(RTE_REQUIRES_IOC) */
#include "Rte.h"
#include "Rte_Intl.h"
#include "Rte_Type.h"
#include "Rte_DataHandleType.h"

#define RTE_OSTASK_ASW_10MS_START_SEC_VAR_CLEARED_8
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
extern VAR(uint8, RTE_DATA) Rte_RECount_OsTask_ASW_10ms_divby5_0;

#define RTE_OSTASK_ASW_10MS_STOP_SEC_VAR_CLEARED_8
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

/* Runnable entity prototypes */
#define ASW_COM_START_SEC_CODE
#include "ASW_COM_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_COM_CODE) RE_COM_SWC_func(void);
#define ASW_COM_STOP_SEC_CODE
#include "ASW_COM_MemMap.h" /*lint !e537 permit multiple inclusion */
#define ASW_Dem_START_SEC_CODE
#include "ASW_Dem_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_Dem_CODE) DemSwc_RE_Dem_SWC_func(void);
#define ASW_Dem_STOP_SEC_CODE
#include "ASW_Dem_MemMap.h" /*lint !e537 permit multiple inclusion */
#define ASW_Diag_START_SEC_CODE
#include "ASW_Diag_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_Diag_CODE) RE_Diag_SWC_func(void);
#define ASW_Diag_STOP_SEC_CODE
#include "ASW_Diag_MemMap.h" /*lint !e537 permit multiple inclusion */
#define ASW_NM_START_SEC_CODE
#include "ASW_NM_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_NM_CODE) RE_ASW_NM_func(void);
#define ASW_NM_STOP_SEC_CODE
#include "ASW_NM_MemMap.h" /*lint !e537 permit multiple inclusion */
#define ASW_NVM_START_SEC_CODE
#include "ASW_NVM_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_NVM_CODE) RE_ASW_NVM_func(void);
#define ASW_NVM_STOP_SEC_CODE
#include "ASW_NVM_MemMap.h" /*lint !e537 permit multiple inclusion */
#define ASW_WDG_START_SEC_CODE
#include "ASW_WDG_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_WDG_CODE) RE_ASW_WDG_Alive_Supervision_Entity1_func(void);
#define ASW_WDG_STOP_SEC_CODE
#include "ASW_WDG_MemMap.h" /*lint !e537 permit multiple inclusion */
#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, XCP_CODE) Xcp_EventChannel_10ms(void);
FUNC(void, XCP_CODE) Xcp_EventChannel_50ms(void);
#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h" /*lint !e537 permit multiple inclusion */

#define RTE_OSTASK_ASW_10MS_START_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
TASK(OsTask_ASW_10ms)
{
   /* Box: Implicit Buffer Initialization begin */
   /* Box: Implicit Buffer Initialization end */
   /* Box: Implicit Buffer Fill begin */
   /* Box: Implicit Buffer Fill end */
   {
      /* Box: CPT_ASW_COM begin */
      RE_COM_SWC_func();
      /* Box: CPT_ASW_COM end */
   }
   {
      /* Box: CPT_ASW_NM begin */
      RE_ASW_NM_func();
      /* Box: CPT_ASW_NM end */
   }
   {
      /* Box: CPT_ASW_WDG begin */
      RE_ASW_WDG_Alive_Supervision_Entity1_func();
      /* Box: CPT_ASW_WDG end */
   }
   {
      /* Box: CPT_ASW_NVM begin */
      RE_ASW_NVM_func();
      /* Box: CPT_ASW_NVM end */
   }
   {
      /* Box: CPT_Diag begin */
      RE_Diag_SWC_func();
      /* Box: CPT_Diag end */
   }
   {
      /* Box: CPT_Dem_SWC begin */
      DemSwc_RE_Dem_SWC_func();
      /* Box: CPT_Dem_SWC end */
   }
   {
      /* Box: BSWImpl8_Xcp begin */
      Xcp_EventChannel_10ms();
      /* Box: BSWImpl8_Xcp end */
   }
   /* Box: BSWImpl8_Xcp begin */
   if ( Rte_RECount_OsTask_ASW_10ms_divby5_0 == ((VAR(uint8, AUTOMATIC))0U) )
   {
      Xcp_EventChannel_50ms();
   }
   /* Box: BSWImpl8_Xcp end */
   /* Box: Implicit Buffer Flush begin */
   /* Box: Implicit Buffer Flush end */
   if ( Rte_RECount_OsTask_ASW_10ms_divby5_0 != ((VAR(uint8, AUTOMATIC))0U) )
   {
      Rte_RECount_OsTask_ASW_10ms_divby5_0--;
   }
   else
   {
      Rte_RECount_OsTask_ASW_10ms_divby5_0 = ((VAR(uint8, AUTOMATIC))4);
   }
   TerminateTask();
} /* OsTask_ASW_10ms */
#define RTE_OSTASK_ASW_10MS_STOP_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

