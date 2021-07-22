/** @file     SchM_Com.h
  *
  * @brief    Basic Software Scheduler Module Interlink header file
  *
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  *
  * @note     Generated by ETAS RTA-RTE
  * @note     Version 6.8.0 
  */

#ifndef SchM_Com
#define SchM_Com

#include "SchM_Com_Type.h"
#include "Rte_Intl.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(RTE_RUNNABLEAPI_BSWSE_MainFunctionRx)
   /* Do nothing for this and all elif clauses below (rte_sws_2751) */
#elif defined(RTE_RUNNABLEAPI_BSWSE_MainFunctionTx)
#else
   /* None of above defined so define value including all APIs (rte_sws_2751) */
   #define RTE_PRV_ALL_API
#endif

/* API Mapping Macros */
#ifndef RTE_CORE

#endif /* RTE_CORE */

/*******************************************************
 ***
 *** Schedulable Entity Prototypes
 ***
 *******************************************************/

#define COM_START_SEC_CODE
#include "Com_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, COM_CODE) Com_MainFunctionRx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h" /*lint !e537 permit multiple inclusion */
#define COM_START_SEC_CODE
#include "Com_MemMap.h" /*lint !e537 permit multiple inclusion */
FUNC(void, COM_CODE) Com_MainFunctionTx(void);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h" /*lint !e537 permit multiple inclusion */

#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif /* !SchM_Com */
