/** @file     Rte_ASW_WDG_Type.h
  *
  * @brief    Application types header file
  *
  * @note     AUTOMATICALLY GENERATED FILE! DO NOT EDIT!
  *
  * @note     Generated by ETAS RTA-RTE
  * @note     Version 6.8.0 
  */

#ifndef RTE_ASW_WDG_TYPE_H
#define RTE_ASW_WDG_TYPE_H

#include "Rte_Type.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* BEGIN: SWC specific types */
#ifndef RTE_CORE
#ifndef RTE_MODETYPE_WDGM_MODE
#define RTE_MODETYPE_WDGM_MODE

typedef uint8 Rte_ModeType_WdgM_Mode;

#endif /* !RTE_MODETYPE_WDGM_MODE */
#endif /* RTE_CORE */

/* END: SWC specific types */

/* BEGIN: SWC specific definitions */
#ifndef RTE_CORE
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
#define RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED 4U
#endif /* !RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED */
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
#define RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED     2U
#endif /* !RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED */
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
#define RTE_MODE_WdgM_Mode_SUPERVISION_FAILED      1U
#endif /* !RTE_MODE_WdgM_Mode_SUPERVISION_FAILED */
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_OK
#define RTE_MODE_WdgM_Mode_SUPERVISION_OK          0U
#endif /* !RTE_MODE_WdgM_Mode_SUPERVISION_OK */
#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
#define RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED     3U
#endif /* !RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED */
#ifndef RTE_TRANSITION_WdgM_Mode
#define RTE_TRANSITION_WdgM_Mode                   255U
#endif /* !RTE_TRANSITION_WdgM_Mode */
#endif /* RTE_CORE */

/* END: SWC specific definitions */

#ifdef __cplusplus
} /* extern C */
#endif /* __cplusplus */

#endif /* !RTE_ASW_WDG_TYPE_H */
