
/********************************************************************************************************************/
/*                                                                                                                  */
/* TOOL-GENERATED SOURCECODE, DO NOT CHANGE                                                                         */
/*                                                                                                                  */
/********************************************************************************************************************/


#ifndef DEM_CFG_NVM_H
#define DEM_CFG_NVM_H


#define  DEM_NVM_ID_DEM_GENERIC_NV_DATA           0u
#define  DEM_NVM_ID_EVMEM_LOC_0                   1u
#define  DEM_NVM_ID_EVMEM_LOC_1                   2u
#define  DEM_NVM_ID_EVMEM_LOC_2                   3u
#define  DEM_NVM_ID_EVMEM_LOC_3                   4u
#define  DEM_NVM_ID_EVMEM_LOC_4                   5u
#define  DEM_NVM_ID_EVT_STATUSBYTE                6u

#define  DEM_NVM_CFG_BLOCKID_TYPE                 uint8
#define  DEM_NVM_CFG_NUM_BLOCKS_TOTAL             7
#define  DEM_NVM_CFG_NUM_BLOCKS_EXTENDED          6

#define  DEM_NVM_CFG_NVM_BLOCK_IDS                \
{\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_GenericNvData,\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory0,\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory1,\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory2,\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory3,\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_EvMemEventMemory4,\
    NvMConf_NvMBlockDescriptor_NvMBlockDescriptor_Dem_AllEventsStatusByte\
}

#define  DEM_NVM_CFG_BLOCKS_EXTENDED              \
{\
    {&Dem_GenericNvData, DEM_SIZEOF_VAR(Dem_GenericNvData), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[0], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[1], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[2], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[3], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY},\
    {&Dem_EvMemEventMemory[4], DEM_SIZEOF_TYPE(Dem_EvMemEventMemoryType), DEM_CFG_COPY_FCT_ID_MEMCOPY}\
}


#define  DEM_NVM_CFG_NUM_STORAGEBUFFER            2


/* 2 block types supported: normal Dem and Bfm Record */
#define DEM_CFG_COPY_FCT_ID_MEMCOPY           0   /* normal mem copy*/


#define DEM_NVM_CFG_COPYFCT_NUM  1 

#define DEM_NVM_CFG_COPYFCT_INIT  { (&Dem_NvMNormalMemCopy)   }




#endif


