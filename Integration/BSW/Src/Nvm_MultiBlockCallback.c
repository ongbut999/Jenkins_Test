#include "NvM.h"
#include "Rte_NvM_Type.h"
#include "TimingCalculation.h"
#include "MemIf.h"

uint16 ReadAllcounter,WriteAllcounter,WriteAllcounter2;
static uint32 NvM_WriteAll_ElapsedTime = 0;
static uint32 NvM_ReadAll_ElapsedTime = 0;

void IC_BswM_NvM_ReadAll ( void )
{
	NvM_Rb_StatusType status_NvM;
	MemIf_StatusType stMemIf_en;
	uint32 *CRC_ptr;
	uint32 CRC_data;
	uint32 CRC_cal;

	ReadAllcounter=0;
	/* disable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(0);

	IC_SetCurrentTime();
	NvM_ReadAll();
	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();
		NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();
		ReadAllcounter++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));
	NvM_ReadAll_ElapsedTime = IC_GetElapsedTime();

	/* enable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(1);

}


void IC_BswM_NvM_WriteAll ( void )
{
	NvM_Rb_StatusType status_NvM;
	MemIf_StatusType stMemIf_en;

	WriteAllcounter=0;

	/*
	 * Here RTE scheduling is stopped, so WdgM won't be triggered anymore.
	 * we need to prevent the Wdg from reseting the CPU.
	 * WDG_SLOW_MODE so Wdg increases the hardware timeout period
	 */

	/* disable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(0);

	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();

		NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();

		WriteAllcounter++;
		
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));


	/* in case of page swap is required a second loop to complete the
	 * write of the updated block after the page swap
	 */

	IC_SetCurrentTime();
	NvM_WriteAll();

	do
	{
		NvM_MainFunction();
		MemIf_Rb_MainFunction();

		NvM_Rb_GetStatus(&status_NvM);
		stMemIf_en = MemIf_Rb_GetStatus();

		WriteAllcounter2++;
	} while ( (status_NvM == NVM_RB_STATUS_BUSY ) || (stMemIf_en == MEMIF_BUSY));
	NvM_WriteAll_ElapsedTime = IC_GetElapsedTime();

	/* enable detection and report of timeout for FLS */
	Fls_ControlTimeoutDet(1);

}
