/** @file     OsTask_ASW_100ms.c
  *
  * @brief    Task OsTask_ASW_100ms body
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
#include "OsTask_ASW_100ms.h"
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

/* Runnable entity prototypes */
#define ASW_BASE_START_SEC_CODE
#include "ASW_BASE_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_BASE_CODE) RE_Base_SWC_func(void);
#define ASW_BASE_STOP_SEC_CODE
#include "ASW_BASE_MemMap.h" /*lint !e537 permit multiple inclusion */
#define ASW_XCP_START_SEC_CODE
#include "ASW_XCP_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, ASW_XCP_CODE) RE_XCP_SWC_func(void);
#define ASW_XCP_STOP_SEC_CODE
#include "ASW_XCP_MemMap.h" /*lint !e537 permit multiple inclusion */
#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, XCP_CODE) Xcp_EventChannel_100ms(void);
#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h" /*lint !e537 permit multiple inclusion */

#define RTE_OSTASK_ASW_100MS_START_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */
TASK(OsTask_ASW_100ms)
{
   /* Box: Implicit Buffer Initialization begin */
   /* Box: Implicit Buffer Initialization end */
   /* Box: Implicit Buffer Fill begin */
   /* Box: Implicit Buffer Fill end */
   {
      /* Box: CPT_ASW_BASE begin */
      RE_Base_SWC_func();
      /* Box: CPT_ASW_BASE end */
   }
   {
      /* Box: CPT_XCP begin */
      RE_XCP_SWC_func();
      /* Box: CPT_XCP end */
   }
   {
      /* Box: BSWImpl8_Xcp begin */
      Xcp_EventChannel_100ms();
      /* Box: BSWImpl8_Xcp end */
   }
   /* Box: Implicit Buffer Flush begin */
   /* Box: Implicit Buffer Flush end */
   TerminateTask();
} /* OsTask_ASW_100ms */
#define RTE_OSTASK_ASW_100MS_STOP_SEC_CODE
#include "Rte_MemMap.h" /*lint !e537 permit multiple inclusion */

