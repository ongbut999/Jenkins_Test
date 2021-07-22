/***************************************************************************************************
 * Component : OverlayManager.c
 * Date      : Mar 15 2019
 * Version   : 1.0
 * Description  : This module implements the overlay functions.
 *
 **************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "OverlayManager.h"
#include "Xcp_Priv.h"


/**********************************************************************************************************************
 *  OverlayManager
 *********************************************************************************************************************/
/*! Init function for overlay.
 *   
 *  \param [in]  none
 *  \param [out] none
 *  \return     1
 *  \retval     //
 *  \note       .
 *********************************************************************************************************************/
void Overlay_Init(void)
{
/* The calibration size is 16KB,
	 * Flash CAL: 0x801C_0000H - 0x801C_3FFFH, 16KB
	 * Ram CAL  : 0x7000_4000H - 0x7000_7FFFH, 16KB
	 */


	/* The calibration size is 16KB
	 * Here 1 overlay blocks are configured
	 * Block 0: size 16KB
	 */

	Mcal_ResetCpuENDINIT(-1);
	Mcal_ResetCpuENDINIT(0);
	SCU_OVCENABLE.B.OVEN0 = 1;
	Mcal_SetCpuENDINIT(0);
	Mcal_SetCpuENDINIT(-1);
	/* ----------------------------Start Configuration for Block 0 -----------------------------------*/

	OVC0_OSEL.B.SHOVEN0 	= 1; /* Enable overlay on Block 0 */

	OVC0_OMASK0.B.OMASK 	=  0xE00; /* 111000000000B, 16K block size */

	/* Base Address
	 * 								  |<-- OMASK--->|
	 * 0x801C_0000= 1000|0000|0001|1100|0000|0000|0000|0000
	 * OMASK      = 0000|1111|1111|1111|1100|0000|0000|0000 (0xE00)
	 * TBASE      = ****|0000|0001|1100|0000|0000|000*|****
	 * 			  = 	  000 0000 1110 0000 0000 0000 = 0x00E000
	 */
	OVC0_BLK0_OTAR.B.TBASE 	= 0x00E000;

	/* Redirection to Core 0 DSPR/PSPR memory for Block 0 - 4kB */
	OVC0_BLK0_RABR.B.OMEM 	= 0x0;  /* 0, Core 0 DSPR; 1, Core 1 DSPR; 6 - Redirect to LMU memory; 7 - Redirection to EMEM; 3..5H Reserved, do not use */

	/* Overlay Address
	 * 								  |<-- OMASK--->|
	 * 0x70004000 = 0111|0000|0000|0000|0100|0000|0000|0000
	 * OMASK      = 0000|1111|1111|1111|1100|0000|0000|0000 (0xE00)
	 * OBASE      = ****|****|**00|0000|0100|0000|000*|****
	 * 			  =		         0 0000 0010 0000 000 =0x200
	 */
	OVC0_BLK0_RABR.B.OBASE 	= 0x200;

	/* ---------------------------- End Configuration for Block 0 -------------------------------------*/
	/* ---------------------------- Start Configuration for Block 1 -----------------------------------*/

//	OVC0_OSEL.B.SHOVEN1 	= 1; /* Enable overlay on Block 1 */
//
//	OVC0_OMASK1.B.OMASK 	=  0xF00; /* 111100000000B, 8K block size */
//
//	/* Base Address
//	 * 								  |<-- OMASK---->|
//	 * BaseAddr   = 1010|1111|0000|0101|1100|0000|0000|0000 (0xAF05C000)
//	 * OMASK      = 0000|1111|1111|1111|1110|0000|0000|0000 (0xF00)
//	 * TBASE      = ****|1111 0000 0101 1100 0000 000*|****
//	 * 			  = 	  111 1000 0010 1110 0000 0000 = 0x782E00
//	 */
//	OVC0_BLK1_OTAR.B.TBASE 	= 0x782E00;
//	/* Redirection to Core 0 DSPR/PSPR memory for Block 1 - 8kB */
//	OVC0_BLK1_RABR.B.OMEM 	= 0x0;  /* 0, Core 0 DSPR; 1, Core 1 DSPR; 6 - Redirect to LMU memory; 7 - Redirection to EMEM; 3..5H Reserved, do not use */
//
//	/* Overlay Address
//	 * 								  |<-- OMASK---->|
//	 * OverAddr   = 0111|0000|0000|0000|0100|0000|0000|0000	(0x70004000)
//	 * OMASK      = 0000|1111|1111|1111|1110|0000|0000|0000 (0xF00)
//	 * OBASE      = ****|****|**00 0000 0100 0000 000*|****
//	 * 			  =		        00 0000 0100 0000 000 =0x200
//	 */
//
//	OVC0_BLK1_RABR.B.OBASE 	= 0x200;
	/* ---------------------------- End Configuration for Block 1 -------------------------------------*/

	SCU_OVCCON.B.CSEL0 = 1; /* Select CPU0 */
	SCU_OVCCON.B.DCINVAL = 1; /* only use non-cached access */

	SCU_OVCCON.U = 0x03000001;
}


void Overlay_Enable()
{
	/* XcpApp_CurrentCalPage is WORKING_CAL_PAGE; */
	SCU_OVCCON.U = 0x00050001;//Overlay Start, OVSTRT = 0
}

void Overlay_Disable()
{
	/* XcpApp_CurrentCalPage is REFERENCE_CAL_PAGE; */
	SCU_OVCCON.U = 0x00060001; //Overlay Stop, OVSTP = 1
}

/*******************************************************************************
  Function name     :   Overlay_CheckEnabled

  Description       :
  Parameter         :   *enabled
  Return value      :   none

*******************************************************************************/
void Overlay_CheckEnabled(boolean *enabled)
{
    boolean overlay_enabled = FALSE;

    if (SCU_OVCCON.U == 0x00050001)
    {
        overlay_enabled = TRUE;
    }

    *enabled = overlay_enabled;
}

/*******************************************************************************
  Function name     :   OverlayMem_Sync

  Description       :
  Parameter         :   none
  Return value      :   none

*******************************************************************************/
void Overlay_Sync(void)
{
    Xcp_MemCopy((uint32*)CALRAM_START_ADDR,
                (uint32*)CALFLASH_START_ADDR,
                CAL_MEM_SIZE);
}


/**********************************************************************************************************************
 *  END OF FILE: *.c
 *********************************************************************************************************************/

