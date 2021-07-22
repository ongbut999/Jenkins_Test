

#ifndef CRC_8H2F_H
#define CRC_8H2F_H

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
/* TRACE [SWS_Crc_00042] */
/* Initial values for CRC calculation */
#define CRC_INITIAL_VALUE8H2F       ((uint8)0xFFU)

/* TRACE [SWS_Crc_00042] */
/* XOR values for CRC result modification */
#define CRC_XOR_VALUE8H2F           ((uint8)0xFFU)

/*
 **********************************************************************************************************************
 * TABLE Version
 **********************************************************************************************************************
 */
#define  CRC_8_H2F_TABLESIZE    256U  /* Table Size */


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
#define CRC_START_SEC_CONST_8
#include "Crc_MemMap.h"
extern const uint8 CRC_8_H2F_Tbl[];
#define CRC_STOP_SEC_CONST_8
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
extern uint8 Crc_CalculateCRC8H2F(const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8,
                                 boolean Crc_IsFirstCall);
#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


/* CRC_8H2F_H */
#endif
