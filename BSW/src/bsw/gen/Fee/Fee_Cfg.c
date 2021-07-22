

#include "Fee.h"
#include "Fee_Prv.h"



/* Properties of flash sectors */
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
CONST (Fee_FlashProp_tst, FEE_CONST) Fee_FlashProp_st[FEE_NUM_FLASH_BANKS_AVAILABLE] = {
    { FEE_PHYS_SEC_START0, FEE_PHYS_SEC_END0, FEE_LOG_SEC_START0, FEE_LOG_SEC_END0 }, /* sector 0 */
    { FEE_PHYS_SEC_START1, FEE_PHYS_SEC_END1, FEE_LOG_SEC_START1, FEE_LOG_SEC_END1 }, /* sector 1 */
};
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"

/* Linked functions of the Fee */
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
CONST (Fee_LinkedFunctions_tst, FEE_CONST) Fee_LinkedFunctions_cst = 
{
    NULL_PTR
};
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

/* Block properties for all Fee blocks
 *
 * Status Flags:
 * Block flags will help to specify a more detailed block configuration. The low Byte of these block flags is also stored
 * in the flash (status byte inside the block header). This information (in Flash) can be used to read/write the layout
 * without configuration (PAV, CB).
 *
 *
 *                                                 |<----- Block Status Byte in Block Header ----->|
 * |<---------------------------------------- Block Flags ---------------------------------------->|
 *    F     E     D     C     B     A     9     8  |  7     6     5     4     3     2     1     0  |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |     |     |Prio-| Job type  |Ign. |No F.| Rob |Surv.|(Inv)| DataFilter| Sec-|
 * |     |     |     |     |     |rity |           |Blk  |back |Attr.|Attr.|     |    Type   | lvl |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 *
 *
 *  0  ... SecurityLevel      => 0...SingleStorage, 1...DoubleStorage
 * 1+2 ... Data Filter Type   => 0...Dynamic:         Anybody can erase this block (e.g. during migration)
 *                               1...Static:          Only certain users (e.g. repair shops) can erase this block
 *                               2...Permanent:       Only very certain users (e.g. OEM) can erase this block
 *                               3...Super Permanent: Block can never be erased
 *  3  ... Invalid            => 0...Block OK, 1...Block is invalid  --> can be changed by function Fee_InvalidateBlock
 *  4  ... Survival Attribute => 0...No survival, 1... Survival (even without being part of the layout)
 *  5  ... Robustness Attribute (Robustness against data modification during write execution)
 *                            => 0...Deactivated:     No additional checksum is used
 *                            => 1...Activated:       Additional checksum is used
 *  6  ... NoFallback         => 0...Deactivated:     A fallback to old copies is allowed
 *                            => 1...Activated:       A fallback to old copies is not allowed
 *  7  ... Ignore Block       => 0...Deactivated:     Block is considered
 *                            => 1...Activated:       Block is ignored
 * 8+9 ... TypeOfBlock        => 0...InternalJob, 1...NvmJob, 2...AdapterJob (e.g. Mx17 Eep adapter)
 *  A  ... Priority           => Job priority:        0...FEE_NORMAL_PRIO_E --> FeeImmediateData = No
 *                                                    1...FEE_HIGH_PRIO_E   --> FeeImmediateData = Yes
 */
#ifdef FEE_PRV_USE_ROM_TABLE
#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
const Fee_BlockPropertiesType_tst Fee_BlockProperties_st[FEE_NUM_BLOCKS] = {
#else
#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
Fee_BlockPropertiesType_tst Fee_BlockProperties_st[FEE_NUM_BLOCKS] = {
#endif

             /* FeeRbBlockPersistentId,  StatusFlags,  BlkLength ,  FeeRbCallbackEnd    ,  FeeRbCallbackError  */
     /*   0 */{         0x3F0E         ,   0x0100   ,   0x0006   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_AllEventsStatusByte */,
     /*   1 */{         0x4128         ,   0x0100   ,   0x0004   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_DID_SystemFaultRank   */,
     /*   2 */{         0x8068         ,   0x0100   ,   0x0014   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_EvMemEventMemory2 */,
     /*   3 */{         0x8168         ,   0x0100   ,   0x0014   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_EvMemEventMemory3 */,
     /*   4 */{         0x8268         ,   0x0100   ,   0x0014   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_EvMemEventMemory0 */,
     /*   5 */{         0x8368         ,   0x0100   ,   0x0014   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_EvMemEventMemory1 */,
     /*   6 */{         0x8668         ,   0x0100   ,   0x0014   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_EvMemEventMemory4 */,
     /*   7 */{         0xA5CF         ,   0x0100   ,   0x0010   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_Dem_GenericNvData     */,
     /*   8 */{         0xB26F         ,   0x0100   ,   0x0011   ,NULL_PTR              ,NULL_PTR               } /* NvMBlockDescriptor_DID_VehicleSpeed      */,
     /*   9 */{         0xEA44         ,   0x0100   ,   0x0400   ,NULL_PTR              ,NULL_PTR               } /* NvM_NativeBlock_1024_1                   */,
     /*  10 */{         0xF2F7         ,   0x0100   ,   0x0004   ,NULL_PTR              ,NULL_PTR               } /* ECUM_CFG_NVM_BLOCK                       */,
     /*  11 */{         0xF8CF         ,   0x0100   ,   0x0400   ,NULL_PTR              ,NULL_PTR               } /* NvM_NativeBlock_1024_2                   */,
};

#ifdef FEE_PRV_USE_ROM_TABLE
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
#else
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
#endif

 /* This section is applicable only for FEE 2.0, ignore or dont configure this section for FEE 1.0 */

