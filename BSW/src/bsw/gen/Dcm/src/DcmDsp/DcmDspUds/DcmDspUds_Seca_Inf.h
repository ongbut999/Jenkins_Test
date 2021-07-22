
/**
 ***********************************************************************************************************************
 *          Multiple Include Protection
 ***********************************************************************************************************************
 */
#ifndef DCMDSPUDS_SECA_INF_H
#define DCMDSPUDS_SECA_INF_H

/*
 ***********************************************************************************************************************
 * Public Includes
 ***********************************************************************************************************************
 */

#include "Dcm.h"
#if(DCM_CFG_RTESUPPORT_ENABLED != DCM_CFG_OFF)
#include "Rte_Dcm.h"
#endif

/*
 ***********************************************************************************************************************
 * Protected Includes (package wide includes)
 ***********************************************************************************************************************
 */
#if(DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF)

#include "DcmCore_DslDsd_Prot.h"
#include "DcmDspUds_Uds_Prot.h"

#endif

#if ( ( DCM_CFG_DSPUDSSUPPORT_ENABLED != DCM_CFG_OFF ) && ( DCM_CFG_DSP_SECURITYACCESS_ENABLED != DCM_CFG_OFF ) )
#include "DcmAppl.h"

#if (DCM_CFG_IN_PARAM_MAXLEN > 0u)
#include "rba_BswSrv.h"
#endif /* DCM_CFG_IN_PARAM_MAXLEN */

#endif
/*
 ***********************************************************************************************************************
 * Other Inline Functions
 ***********************************************************************************************************************
 */


/* _DCMDSPUDS_SECA_INF_H  */
#endif
