
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_ASSERTIONCHK_H
#define DEM_CFG_ASSERTIONCHK_H

#include "Dem_Lib.h"

/* -------------------------------------------------- */
/* DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH       */
/* -------------------------------------------------- */
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON   STD_ON
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_OFF  STD_OFF
#define DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH  DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_OFF

#if(DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH == DEM_CFG_STATIC_ASSERTION_FOR_NVM_BLOCKLENGTH_ON)
/* Macros which defines the block size of each configured NvM Block */
#define  DEM_NVM_ID_DEM_GENERIC_NV_DATA_SIZE                16
#define  DEM_NVM_ID_EVMEM_LOC_0_SIZE                        20
#define  DEM_NVM_ID_EVMEM_LOC_1_SIZE                        20
#define  DEM_NVM_ID_EVMEM_LOC_2_SIZE                        20
#define  DEM_NVM_ID_EVMEM_LOC_3_SIZE                        20
#define  DEM_NVM_ID_EVMEM_LOC_4_SIZE                        20
#define  DEM_NVM_ID_EVT_STATUSBYTE_SIZE                     6

DEM_STATIC_ASSERT((DEM_SIZEOF_VAR(Dem_GenericNvData)==DEM_NVM_ID_DEM_GENERIC_NV_DATA_SIZE),DEM_NVM_ID_DEM_GENERIC_NV_DATA_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_0_SIZE),DEM_NVM_ID_EVMEM_LOC_0_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_1_SIZE),DEM_NVM_ID_EVMEM_LOC_1_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_2_SIZE),DEM_NVM_ID_EVMEM_LOC_2_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_3_SIZE),DEM_NVM_ID_EVMEM_LOC_3_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType)==DEM_NVM_ID_EVMEM_LOC_4_SIZE),DEM_NVM_ID_EVMEM_LOC_4_BlockLengthIsInvalid);
DEM_STATIC_ASSERT((DEM_SIZEOF_VAR(Dem_AllEventsStatusByte)==DEM_NVM_ID_EVT_STATUSBYTE_SIZE),DEM_NVM_ID_EVT_STATUSBYTE_BlockLengthIsInvalid);

#endif

#endif

