// Include the CPU specific .lsl file
// The CPU is specified by the __CPU__ macro
#ifndef __CPU__
# error No CPU defined, please link with -D__CPU__=<cpu>
#endif


// 100 bytes of DSPR is reserved for sbst_tc0_dspr

/* XCP-Data */
#define XCP_CAL_PARAM_Section_ADDRESS       0x801C0000   /* start address of calibration parameter */
#define XCP_CAL_RAM_Section_ADDRESS         0x70004000   /* start address of calibration parameter RAM */
#define XCP_CAL_PARAM_SIZE                  0x4000       /* size of 16K */

/* start address of interrupt table */
 #define INTTAB          0x80020300 

 #define INTTAB0         (INTTAB)
 #define INTTAB1         (INTTAB0 + 0x100)
 #define INTTAB2         (INTTAB1 + 0x100)
 #define TRAPTAB         (INTTAB2 + 0x100)      /* start address of trap table */
 #define TRAPTAB0        (TRAPTAB)
 #define TRAPTAB1        (TRAPTAB0 + 0x200)
 #define TRAPTAB2        (TRAPTAB1 + 0x200)

#define ISTACK_TC0 1k
#define ISTACK_TC1 1k
#define ISTACK_TC2 1k

#define USTACK_TC0 16k
#define USTACK_TC1 16k
#define USTACK_TC2 16k


#define CSA_START_TC0   0xD001B000              /* start address of CSA tc0 */
#define CSA_START_TC1   0xD001D000              /* start address of CSA tc1 */
#define CSA_START_TC2   0xD001D000              /* start address of CSA tc2 */

/* internal flash start address tc0 */
#define  __LINKONLY__
#define RESET           0x80000020 //it is also set the text.libc.reset in the tc27xd.lss

#include "tc27xd.lsl"


section_layout mpe:vtc:linear
{
  
  group BMD (ordered,contiguous, run_addr=0x80000000)
  { 
    select ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED";
  } 
    group  FBL_RESERVED (ordered,contiguous, run_addr=0x80000020)
  {
  reserved "FBL_RESERVED" (alloc_allowed = absolute, size = 128K -32);
  }
  group  RESET_POINT (ordered,contiguous, run_addr=RESET)
  {
      select ".text.libc.reset";
  }
  group  RESERVED_STARTUP(ordered,contiguous, run_addr=0x80020000)
  {
    reserved "Reserved_startup" (alloc_allowed = ranged, size = 0x300);
  }
  group  PFLASH0_STARTUP(ordered,contiguous, run_addr=0x80020000)
  {
    select ".text.cstart";
  }

  //trapvector table for CPU0
  group PFLASH0_TRAP_INT_TAB(ordered,contiguous, run_addr=INTTAB)
  {
    reserved "Reserved_trap" (alloc_allowed = ranged, size = 2k);
  }
  group PFLASH0_CALIB(ordered,contiguous, run_addr=0x801C0000,fill=0x00)
  {
   section "REF_PPAGE" (size = 16K, attributes=r,fill=0x00)
    {
      select".rodata.*Calib_bool*";
      select".rodata.*Calib_8*";
      select".rodata.*Calib_16*";
      select".rodata.*Calib_32*";
      select".rodata.*Calib_unspec*";
    }
  }

  "__RODATA_CALIB_START" = "_lc_gb_PFLASH0_CALIB";
  group PFLASH0_CONST(ordered,contiguous, run_addr=0x80020B00)
  {
    section "CONST" (blocksize = 1, attributes=r,fill = 0)
    {
     select".rodata*";
     select"*.rodata*";
    }
  }

  group FLS_AC_ERASE_SOURCE (ordered,contiguous, run_addr=0x80038000)
  {
    section "AC_ERASE" (size = 0x200, attributes=r,fill = 0)
    {
      select ".text.FLS_AC_ERASE_SOURCE";
    }
  }

  group FLS_AC_WRITE_SOURCE (ordered,contiguous, run_addr=0x80038200)
  {
    section "AC_WRITE" (size = 0x300, attributes=r,fill = 0)
    {
      select ".text.FLS_AC_WRITE_SOURCE";
    }
  }

  group PFLASH0_CPU0_PRIVATE (ordered, run_addr=0x80038500)
  {
//-----------------------CPU0_TRUSTED_CODE---------------------------
  section "CPU0_TRUSTED_CODE" (blocksize = 1, attributes=r,fill = 0)
  {
    select".text.*.RE_ASW*";
    select".text.*.RE_BSW*";
    select".text.*.IC_BswM*";
    select".text.CPU0_Code";
    select".text.*.Os_Entry_OsTask*";
    select".text.*.Os_Entry_ECU_StartupTask*";
    select ".text.*.RE*Os*";
    select".text.*.*SWC_func*";
    select".text.*.*Mcal*";
    select".text.*.BswM*";
    select".text.*.CPU*";
    select".text.*.Can*";
    select".text.*.Com*";
    select".text.*.ComM*";
    select".text.*.Crc*";
    select".text.*.Dcm*";
    select".text.*.DCM*";
    select".text.*.Dem*";
    select".text.*.Det*";

    select".text.*.Fee*";
    select".text.*.Fls*";
    select".text.*.Gpt*";
    select".text.*.Gtm*";
    select".text.*.Icu*";
    select".text.*.Mcu*";
    select".text.*.MemIf*";
    select".text.*.Nm*";
    select".text.*.TestNm*";
    select".text.*.NM*";
    select".text.*.NvM*";
    select".text.*.NVM*";
    select".text.*.PduR*";
    select".text.*.Port*";
    
    select".text.*.Wdg*";
    select".text.*.WDG*";
    select".text.*.Xcp*";
    select".text.*.rba*";
    select".text.*.Diag*";
    select".text.*.RunnableEntity_0_func";

    select".text.*.GetSeed";
    select".text.*.Overlay*";
    select".text.*.Bfx*";
    select".text.*.CompareKey";
    select".text.*.UpdatePIMWithValue";
    select".text.*.CheckCondition";
    select".text.*.*Core0*";
    select".text.*.*CORE0*";

    select".text.*.IdleTick";

    
    select".text.*.*Dio*";

    select".text.BSW_*";
  }
  

//-----------------------CPU0_UNTRUSTED_CODE---------------------------
  section "CPU0_UNTRUSTED_CODE" (blocksize = 1, attributes=r,fill = 0)
  {
  //  select".text.CPU0*UNTRUSTED*";
  }
}

  group PFLASH0_CPU1_PRIVATE(ordered, run_addr=0x80080000)
  {
//-----------------------CPU1_TRUSTED_CODE---------------------------
  section "CPU1_TRUSTED_CODE" (blocksize = 1, attributes=r,fill = 0)
  {
    select".text.*.CPU1_Code";
    select".text.*.*Core1*";
    select".text.*.*CORE1*";
    select".text.*.Os_Entry_Core1_OsTask*";
  }

//-----------------------CPU1_UNTRUSTED_CODE---------------------------
  section "CPU1_UNTRUSTED_CODE" (blocksize = 1, attributes=r,fill = 0)
    {
      select".text.CPU1*UNTRUSTED*";
    }
  }

  group PFLASH0_CPU2_PRIVATE(ordered, run_addr=0x80100000)
  {
//-----------------------CPU2_TRUSTED_CODE---------------------------
    section "CPU2_TRUSTED_CODE" (blocksize = 1, attributes=r,fill = 0)
    {
      select".text.*.CPU2_Code";
      select".text.*.*Core2*";
      select".text.*.*CORE2*";
      select".text.*.Os_Entry_Core2_OsTask*";
    }
//-----------------------CPU2_UNTRUSTED_CODE---------------------------
    section "CPU2_UNTRUSTED_CODE" (blocksize = 1, attributes=r,fill = 0)
    {
      select".text.CPU2*UNTRUSTED*";
    }
  }

  group PFLASH0_SHARED_CODE(ordered, run_addr=0x80180000)
  {
 //-----------------------SHARED_CODE_TRUSTED---------------------------
  section "SHARED_CODE_TRUSTED" (blocksize = 1, attributes=r,fill = 0)
    {
        select".text";
        select".text.*.Os_*";
        select".text.*.Loop_EcuM*";
        select".text.*.SharedTrusted_Code*";
        select".text.*.EcuM*";
        select".text.*.VectorTable_Init";
        select".text.*lib*";
        select".text.*.*Hook*";
        select".text.Os_trap_handlers";
	select".text.*.IC*Time";
    }

 //-----------------------SHARED_CODE_UNTRUSTED---------------------------
   section "SHARED_CODE_UNTRUSTED" (blocksize = 1, attributes=r,fill = 0)
    {
      select".text.*.*Rte*";
      select".text.*.SchM*";
    }
  }

  group PFLASH0_RESERVED(ordered, run_addr=0x80200000)
  {
    reserved "OTA_RESERVER" (alloc_allowed = absolute, size = 128K);
  }
}

section_layout mpe:vtc:linear
{
  group LMU_SRAM(ordered, run_addr=mem:mpe:lmuram/not_cached)
  {
//---------------------------SHARED_DATA_UNTRUSTED-----------------------------------
   section "SHARED_DATA_UNTRUSTED" (blocksize = 1, attributes=rw)
    {
      select".data.Rte*";
    }
//---------------------------SHARED_BSS_UNTRUSTED------------------------------------
   section "SHARED_BSS_UNTRUSTED" (blocksize = 1, attributes=rw)
    {
      select".bss.Rte*";
    }
//---------------------------SHARED_DATA_TRUSTED-------------------------------------
   section "SHARED_DATA_TRUSTED" (blocksize = 1, attributes=rw)
    {
    select".data.Os*";
    select".data.EcuM*";
    }
//---------------------------SHARED_BSS_TRUSTED-------------------------------------    
   section "SHARED_BSS_TRUSTED" (blocksize = 1, attributes=rw)
    {
    select".bss.*.Os*";
    select".bss.*.OS*";
    select".bss.*.Millisecond_count";
    select".bss.*.err_cnt*";
    select".bss.*.err_log*";
    select".bss.*.OS*";  
    select".bss.*.EcuM*";
    select".bss.*DEFAULT*"; 
    select".bss.Os*";
    }
  }
}

section_layout mpe:tc0:linear
{

  group FLS_AC_WRITE (ordered, run_addr = 0x70100240)
  {
    reserved "FLS_AC_WRITE" (alloc_allowed = absolute, size = 300);
  }

  group FLS_AC_ERASE (ordered, run_addr = 0x70100040)
  {
    reserved "FLS_AC_ERASE" (alloc_allowed = absolute, size = 200);
  }

	group OVERLAY_RAM_DATA(ordered,contiguous ,run_addr = 0x70004000) 
	{
		section "CAL_WP_SECTION" ( size = XCP_CAL_PARAM_SIZE, attributes = rw )
		{ 
			select "*.CAL_WP";
		}
	}
  "__OVERLAY_RAM_START" = "_lc_gb_OVERLAY_RAM_DATA";
}

section_layout mpe:vtc:linear
{
  group CPU0_DMI_DSPR(ordered,run_addr=mem:mpe:dspr0[0x8000..0x16C00], align=4 )
  {
//--------------------------CPU0_TRUSTED_DATA-------------------------------------
   section "CPU0_TRUSTED_DATA" (blocksize = 1, attributes=rw)
    {
      select".data.*.SWC_func*";
      select".data.*.Mcal*";
      select".data.*.Bsw*";
      select".data.*.CPU*";
      select".data.*.Can*";
      select".data.*.Com*";
      select".data.*.ComM*";
      select".data.*.Crc*";
      select".data.*.Dcm*";
      select".data.*.Dem*";
      select".data.*.Det*";
      select".data.*.Fee*";
      select".data.*.Fls*";
      select".data.*.Gpt*";
      select".data.*.Gtm*";
      select".data.*.Icu*";
      select".data.*.Mcu*";
      select".data.*.MemIf*";
      select".data.*.Nm*";
      select".data.*.NM*";
      select".data.*.NvM*";
      select".data.*.NVM*";
      select".data.*.Nvm*";
      select".data.*.PduR*";
      select".data.*.Port*";

      select".data.*.SchM*";
      select".data.*.Wdg*";
      select".data.*.WDG*";
      select".data.*.Xcp*";
      select".data.*.rba*";
      select".data.*.Diag*";
      select".data.*.*Core0*";
      select".data.*.*CORE0*";
      select".data.*.Dio*";

      select".data.*.*Inte*";
      select".data.*.*SWC_*";
      select".data.*.*libc*";

      select".data.*.x*";
      select".data.*.write*";
      select".data.*.*dsd*";
      select".data.*.SetOsTest";
      select".data.*.Condition";
      select".data.*.stDsdSubState_u8";

      select".data.ASW_NVM*";
      select".data.ASW_WDG*";
      select".data.BswM*";
      select".data.Can*";
      select".data.Dcm*";
      select".data.Dem*";

      select".data.Integration*";
      select".data.SWC_Base*";
      select".data.rba_*";
      select".data.Gpt*";
    }
//--------------------------CPU0_TRUSTED_BSS-------------------------------------
   section "CPU0_TRUSTED_BSS" (blocksize = 1, attributes=rw)
   {
    select".bss.*.SWC_func*";
    select".bss.*.Mcal*";
    select".bss.*.Bsw*";
    select".bss.*.CPU*";
    select".bss.*.Can*";
    select".bss.MCANP*";
    select".bss.*.Com*";
    select".bss.*.ComM*";
    select".bss.*.Crc*";
    select".bss.*.Dcm*";
    select".bss.*.Dem*";
    select".bss.*.Det*";
    select".bss.*.Fee*";
    select".bss.*.Fls*";
    select".bss.*.Gpt*";
    select".bss.*.Gtm*";
    select".bss.*.Icu*";
    select".bss.*.Mcu*";
    select".bss.*.MemIf*";
    select".bss.*.Nm*";
    select".bss.*.NM*";
    select".bss.*.NvM*";
    select".bss.*.NVM*";
    select".bss.*.Nvm*";
    select".bss.*.PduR*";
    select".bss.*.Port*";
    select".bss.*.Rte*";
    select".bss.*.SchM*";
    select".bss.*.Wdg*";
    select".bss.*.WDG*";
    select".bss.*.Xcp*";
    select".bss.*.rba*";
    select".bss.*.Diag*";
    select".bss.*.*Core0*";
    select".bss.*.*CORE0*";
    select".bss.*.Dio*"; 

    select".bss.*.Os_*"; 
    select".bss.*.SWC*"; 

    select".bss.*.main*"; 
    select".bss.*.stub_*"; 
    select".bss.*.*libc*"; 

    select".bss.*.Test_*"; 
    select".bss.*.test*";
    select".bss.*.count*"; 
    select".bss.*.ret*"; 
    select".bss.*.read*";
    select".bss.*.Read*";
    select".bss.*.write*";
    select".bss.*.Write*";
    select".bss.*.Pfc*";
    select".bss.*.*DID*"; 
    select".bss.*.shutdown_b";
    select".bss.*.genUint8"; 
    select".bss.*.VacuumPumpPressure_Data"; 
    select".bss.*.Pfc*";
    select".bss.*.status*";
    select".bss.*.Counter*";
    select".bss.*.TEST_DATA_NVM*";
    select".bss.*.InvalidData";
    select".bss.*.MngData*";
    select".bss.*.Entity1_Count*";
    select".bss.*.s_*";
    select".bss.*.Dsp*";
    select".bss.*.stDsd*";
    select".bss.*.dataRet*";  
    select".bss.*.retRead*";  
    select".bss.*.stDsdState_en*";
    select".bss.*.Task_*ms_cnt*";
    select".bss.*.osTask_*ms_cnt*";
    select".bss.*.Task*ms_flag*";
    select".bss.*.cnt*";
    select".bss.*.Entity1_Count*";
    select".bss.*.dataRet*";
    select".bss.*.genUint8";
    select".bss.*.isQualified";
    select".bss.*.lastIndexPreviousMain";
    select".bss.*.mode_routine";
    select".bss.*.tmp*";
    select".bss.*.MDF*";
    select".bss.*.Measured*";
    select".bss.*.lastIndexPreviousMain*";
    select".bss.*.passive*";
    select".bss.*.active*";
    select".bss.*.x*";
    select".bss.*.preTotalTick*";
    select".bss.*.Swdt*";
    select".bss.*.Wdt*";

    select".bss.SWC_Base*";
    select".bss.ASW_WDG*";
    select".bss.rba*";
    select".bss.Dcm*";
    select".bss.Xcp*";
    select".bss.Dcm*";
    select".bss.CPU0*";
   }


//--------------------------_CPU0_UNTRUSTED_DATA-------------------------------------
   section "CPU0_UNTRUSTED_DATA" (blocksize = 1, attributes=rw)
   {
     select ".data.CPU0*UNTRUSTED*";
   }	
//--------------------------_CPU0_UNTRUSTED_BSS-------------------------------------
   section "CPU0_UNTRUSTED_BSS" (blocksize = 1, attributes=rw)
   {
    select ".bss.CPU0*UNTRUSTED*";
   }
  }
}
section_layout mpe:tc0:linear
{
  group CPU0_DSPR_STACK(ordered, run_addr=mem:mpe:dspr0[0x16C00..0x1B000])
  {
    stack "istack_tc0" ( size = ISTACK_TC0 );
    stack "ustack_tc0" ( size = USTACK_TC0 );
  }
}

section_layout mpe:vtc:linear
{
  group CPU1_DMI_DSPR(ordered,run_addr=mem:mpe:dspr1[0x100..0x18C00])
  {
//----------------------CPU1_TRUSTED_DATA-------------------------------
   section "CPU1_TRUSTED_DATA" (blocksize = 1, attributes=rw)
   {
    select ".data.CPU1_unspec*";
    select ".data.CPU1_bool*";
    select ".data.CPU1_8*";
    select ".data.CPU1_16*";
    select ".data.CPU1_32*";
    select ".bdata.CPU1*";
   }
//-----------------------CPU1_TRUSTED_BSS--------------------------------
   section "CPU1_TRUSTED_BSS" (blocksize = 1, attributes=rw)
   {
    select".bss.CPU1_unspec*";
    select".bss.CPU1_bool*";
    select".bss.CPU1_8*";
    select".bss.CPU1_16*";
    select".bss.CPU1_32*";
    select".bss.CPU1.CPU1*";
   }
//----------------------CPU1_UNTRUSTED_DATA-------------------------------
   section "CPU1_UNTRUSTED_DATA" (blocksize = 1, attributes=rw)
   {
	  select ".data.CPU1*UNTRUSTED*";
   }
//----------------------CPU1_UNTRUSTED_BSS-------------------------------
   section "CPU1_UNTRUSTED_BSS" (blocksize = 1, attributes=rw)
   {
     select ".bss.CPU1*UNTRUSTED*";
   }
  }
}
section_layout mpe:tc1:linear
{
  group CPU1_DSPR_STACK(ordered,run_addr=mem:mpe:dspr1[0x18C00..0x1D000])
  {
    stack "istack_tc1" ( size = ISTACK_TC1 );
    stack "ustack_tc1" ( size = USTACK_TC1 );
  }
}

section_layout mpe:vtc:linear
{
  group CPU2_DMI_DSPR(ordered,run_addr=mem:mpe:dspr2[0x100..0x18C00])
  {
//----------------------CPU2_TRUSTED_DATA-------------------------------
   section "CPU2_TRUSTED_DATA" (blocksize = 1, attributes=rw)
   {
    select ".data.CPU2_unspec*";
    select ".data.CPU2_bool*";
    select ".data.CPU2_8*";
    select ".data.CPU2_16*";
    select ".data.CPU2_32*";
   }
//----------------------CPU2_TRUSTED_BSS-------------------------------
   section "CPU2_TRUSTED_BSS" (blocksize = 1, attributes=rw)
   {
    select".bss.CPU2_unspec*";
    select".bss.CPU2_bool*";
    select".bss.CPU2_8*";
    select".bss.CPU2_16*";
    select".bss.CPU2_32*";
   }
//----------------------CPU2_UNTRUSTED_DATA-------------------------------
   section "CPU2_UNTRUSTED_DATA" (blocksize = 1, attributes=rw)
   {
    select ".data.CPU2*UNTRUSTED*";
   }
//----------------------CPU2_UNTRUSTED_BSS-------------------------------
   section "CPU2_UNTRUSTED_BSS" (blocksize = 1, attributes=rw)
   {
    select ".bss.CPU2*UNTRUSTED*";
   }
  }
}
section_layout mpe:tc2:linear
{
  group CPU2_DSPR_STACK(ordered,run_addr=mem:mpe:dspr2[0x18C00..0x1D000])
  {
    stack "istack_tc2" ( size = ISTACK_TC2 );
    stack "ustack_tc2" ( size = USTACK_TC2 );
  }
}


/*******************************************************************************
*		                              END OF FILE				   											   *
*******************************************************************************/

