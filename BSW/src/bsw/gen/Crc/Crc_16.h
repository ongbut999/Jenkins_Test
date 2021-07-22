

#ifndef CRC_16_H
#define CRC_16_H

/*
**********************************************************************************************************************
* Includes
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Defines/Macros
**********************************************************************************************************************
*/

/* TRACE [SWS_Crc_00002] */
/* Initial values for CRC calculation */
#define CRC_INITIAL_VALUE16      ((uint16)0xFFFFU)

/* TRACE [SWS_Crc_00002] */
/* XOR values for CRC result modification */
#define CRC_XOR_VALUE16          ((uint16)0U)

/* Implementation specific define, used as well for TABLE as for RUNTIME version */
#define  CRC_16_H1021_JUNK       8U                  /* size of transmitted junks via of the data stream */
#define  CRC_16_H1021_JUNKREST   8U                  /* rest (polynomial - junk) required */

/*
 **********************************************************************************************************************
 * TABLE Version
 **********************************************************************************************************************
 */
#define  CRC_16_TABLESIZE         256U   /* CRC Table Sizes */
#define  CRC_16_TABLEMASK         0xFFU  /* Implementation specific mask */


/*
**********************************************************************************************************************
* Type definitions
**********************************************************************************************************************
*/


/*
**********************************************************************************************************************
* Variables
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * TABLE Version
 **********************************************************************************************************************
 */
#define CRC_START_SEC_CONST_16
#include "Crc_MemMap.h"
extern const uint16 CRC_16_H1021_Tbl[];
#define CRC_STOP_SEC_CONST_16
#include "Crc_MemMap.h"

/*
**********************************************************************************************************************
* Extern declarations
**********************************************************************************************************************
*/


/*
 **********************************************************************************************************************
 * Prototypes
 **********************************************************************************************************************
*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"
extern uint16 Crc_CalculateCRC16(const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16,
                                 boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


/* CRC_16_H */
#endif
