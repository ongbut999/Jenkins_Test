/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Mcal.c $                                                   **
**                                                                            **
**   $CC VERSION : \main\66 $                                                 **
**                                                                            **
**   $DATE       : 2015-04-07 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : This file contains the startup code, endinit protection    **
**                 functions                                                  **
**                                                                            **
**   SPECIFICATION(S) :  NA                                                   **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Std_Types.h */
#include "Std_Types.h"
#include "IfxCpu_reg.h"
#include "IfxScu_reg.h"
#include "IfxFlash_reg.h"
/* Inclusion of Mcal.h */
#include "Mcal.h"
#include "Os.h"
#include "Mcal_Options.h"
#if (IFX_MCAL_USED == STD_ON)
/* Inclusion of EcuM.h */
#include "EcuM.h"
#endif

/* Inclusion of Irq.h */
#include "Irq.h"
/* #if (GPT_DELIVERY == STD_ON) */

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define TRICORE_VERSION    (16U)


#define CPU_PSW_USER_MODE_MASK (0xFFFFF3FFU)
#define SET_USER_MODE_MASK ((1U  <<  10U))

#if (TRICORE_VERSION == 16U)
#define PCON0_PCBYP        (0x02U)
#define PCON0_NOPCBYP      (0x00U)
#define PCON1_PCINV        (0x01U)
#define PCON2_PCACHE_SIZE   (0x0008U)     /* Size = 8KB */
#define PCON2_PSCRATCH_SIZE (0x080000U)   /* Size = 8KB */
#define DCON2_DCACHE_SIZE   (0x0000U)     /* Size = 0KB */
#define DCON2_DSCRATCH_SIZE (0x700000U)   /* Size = 112KB */
#endif /* #if (TRICORE_VERSION == 16U) */

#define STACK_ALIGN (0xfffffff8U)
#define MCAL_CORE_ID_MASK   (0x7U)


#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
#define DEBUG()  __debug()
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#endif

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#define DEBUG() __asm__ volatile ("debug")
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
#define DEBUG() __debug()
#define __debug _debug
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Functon Definitions                            **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
extern void SafeTlib_main(uint8 CoreId);
extern void SAFET_core1_RunTimeTest(void);
extern void SAFET_core2_RunTimeTest(void);
#endif

#if (OS_DELIVERY == STD_ON)
extern void Ifx_OSTask_ApplicationInit(void);
#endif


extern int main(void);

/*
 With the following preprocessor definations, the code gets Enabled
*/
/* For CrossView utilty function */
/*#define _SYNC_ON_HALT*/

/*
With the following preprocessor definations, the code gets disabled
*/

/*
 Re-enable and reset the call depth counter and  make A0,A1,A8,A9
 write-able. It is required for CrossView that these RESET values are
 restored for each time the startup code is executed.
*/
/*#define _NO_PSW_RESET*/

/*
 user stack initialisation
*/
/*#define _NO_USP_INIT*/

/*
 Clear Previous Context Pointer Segment Address and Offset Field.
 It is required for CrossView stack trace that these RESET values
 are restored for each time the startup code is executed.
*/
/*#define _NO_PCX_RESET*/

/*
 Context Switch Area initialisation
*/
/*#define _NO_CSA_INIT*/

/*
 disable watchdog
*/
//#define NO_WATCHDOG_DISABLE

/*
 Load Base Address of Trap Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
#define _NO_BTV_INIT

/*
 Load Base Address of Interrupt Vector Table
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
#define _NO_BIV_INIT

/*
 Load interupt stack pointer
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
/*#define _NO_ISP_INIT*/

/*
 Wait States for read access to PFlash is 6
 Wait states for Pflash access with wordline hit should be same as WSPFlash
 Wait States for read access to DFlash is 6
*/
/*#define _NO_FLASH_CONF*/

/*
 Inititialize global address registers a0/a1 to support
 __a0/__a1 storage qualifiers of the C compiler.
*/
/*#define _NO_A0A1_ADDRESSING*/

/*
 Inititialize global address registers a8/a9 to support
 __a8/__a9 storage qualifiers of the C compiler. A8 and A9
 are reserved for OS use, or for application use in cases
 where the application ans OS are tightly coupled.
*/
#define _NO_A8A9_ADDRESSING

/*
 Initialize Bus configuration registers
*/
/*#define _NO_BUS_CONF*/

/*
 Initialize and clear C variables
*/
/*#define _NO_C_INIT*/

/*
 Enable ICACHE
*/
/* #define _ENABLE_ICACHE */

/*
 Enable DCACHE
*/
/* #define _ENABLE_DCACHE */

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

typedef struct {
  uint32 StackEndAddress;
  uint32 CsaStartAddress;
  uint32 CsaEndAddress;
  uint32 IStackAddress;
  uint32 SmallData0;
  uint32 SmallData2;
  uint32 CopyTable;  /* Start Address in case of Diab */
  uint32 ClearTable; /* End Address in case of Diab */
  int (*CoreFn)(void);
}Mcal_CoreInit_t;


/* BMI Header to be placed at location 0xA0000000 */
typedef struct 
{
  const uint32 stadabm;       /*User Code Start Address                             */
  const uint16 bmi;           /*Boot Mode Index (BMI)                               */
  const uint16 bmhdid;        /*Boot Mode Header ID B359H                           */
  const uint32 chkstart;      /*Memory Range to be checked - Start Address          */
  const uint32 chkend;        /*Memory Range to be checked - End Address            */
  const uint32 crcrange;      /*Check Result for the Memory Range                   */
  const uint32 crcrangeinv;   /*Inverted Check Result for the Memory Range          */
  const uint32 crchead;       /*Check Result for the ABM Header (offset 00H..17H)   */
  const uint32 crcheadinv;    /*Inverted Check Result for the ABM Header            */
}BMD_HDR;

/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
#ifdef _SYNC_ON_HALT
void _sync_on_halt(void);    /* CrossView utilty function */
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/* Mcal specific startup code */
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
__attribute__((use_frame_pointer)) void cstart(void) ;
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
#define CSTART_START_SEC_CODE
#include "MemMap.h"
void cstart(void) ;
#define CSTART_STOP_SEC_CODE
#include "MemMap.h"
#endif
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
void _START(void) ;          /* app init start address */
void _Exit(void) ;           /* exit return address */
/* C initialization function */
void _c_init(uint32 CoreNumber, uint32 Copytable) ;         
#ifdef _DEFINE_CALL_ENDINIT
void  _CALL_ENDINIT(void) ;  /* User definition function */
#endif

#ifdef _DEFINE_CALL_INIT
void   _CALL_INIT(void) ;    /* User definition function */
#endif
#endif /*(_TASKING_C_TRICORE_ == 1U)*/
#endif /* _TASKING_C_TRICORE_ */

#ifdef _GNU_C_TRICORE_
#define STARTUP_START_SEC_CODE
#include "MemMap.h"
void _Gnu_CopyTable(uint32 Cleartable, uint32 CopyTable);
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"
#endif



extern __indirect void Test_InitTime(void);
extern void DemoApp_CallMenuFctCpu1 (void);
extern void DemoApp_CallMenuFctCpu2 (void);

/* interface to set/reset endinit of CPU/Safety watchdog */
#define STARTUP_START_SEC_CODE
#include "MemMap.h"
static void safety_endinit_reset(void); 
static void safety_endinit_set  (void);
static void endinit_reset  (void);
static void endinit_set  (void);
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (IFX_MCAL_USED == STD_ON)
#define BMD_HDR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_BMD_HDR_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

const BMD_HDR Bmiheader =
{
  0x80000020,
  0x0370,/*LCL1LSEN =1,LCL0LSEN =1 , HWCFG = Internal start from Flash, PINDIS= 0(Mode selection by HWCFG pins is enabled)*/
  0xB359,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x49E9B5B4,
  0xB6164A4B
};

#if (IFX_MCAL_USED == STD_ON)
#define BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_BMD_HDR_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_START_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_START_SEC_VAR_FAST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif

#if defined (_GNU_C_TRICORE_) || defined (_DIABDATA_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U) || (_DIABDATA_C_TRICORE_ == 1U)
static uint32 Mcal_SmallDataAddress;
static uint32 Mcal_LiteralDataAddress;
static uint32* Mcal_StackEndAddress;
#endif /* #if (_GNU_C_TRICORE_ == 1U) || (_DIABDATA_C_TRICORE_ == 1U) */
#endif

#if ( MCAL_NO_OF_CORES > 1U )
/* Semaphore to signal the completed of Init sequence of different Cores */
/* Element 0 signifies CPU0 -> This signifies if EcuM Init is completed by CPU0
   Element 1 signifies CPU1 -> This signifies if CPU1 startup code is executed
   Element 1 signifies CPU1 -> This signifies if CPU1 startup code is executed
   This is implemented as an array to prevent parallel updation by seperate
   cores
*/
volatile uint8  Mcal_CpuInitCompletedSem[MCAL_NO_OF_CORES];

#endif

#if (IFX_MCAL_USED == STD_ON)
#define MCAL_STOP_SEC_VAR_FAST_32BIT
#include "MemMap.h"
#else
#define IFX_MCAL_STOP_SEC_VAR_FAST_32BIT_ASIL_B
#include "Ifx_MemMap.h"
#endif


#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
extern void cpu0_trap_0 (void); /* trap table */
extern void inttab (void);      /* interrupt table */

extern uint8 * _SMALL_DATA_ ;       /* centre of A0 addressable area */
extern uint8 * _SMALL_DATA_TC1;
extern uint8 * _SMALL_DATA_TC2;
extern uint8 * _LITERAL_DATA_ ;     /* centre of A1 addressable area */
extern uint8 * _LITERAL_DATA_TC1;
extern uint8 * _LITERAL_DATA_TC2;
extern uint8 * _A8_DATA_ ;          /* centre of A8 addressable area */
extern uint8 * _A9_DATA_ ;          /* centre of A9 addressable area */
extern uint8 * _lc_ub_table ;
extern uint8 * _lc_ub_table_tc1 ;
extern uint8 * _lc_ub_table_tc2 ;

extern uint8 __far * _lc_ue_ustack_tc0 ; /* user stack end */
extern uint8 __far * _lc_ue_ustack_tc1 ; /* user stack end */
extern uint8 __far * _lc_ue_ustack_tc2 ; /* user stack end */
extern uint8 __far * _lc_ub_csa_01 ;       /* context save area begin */
extern uint8 __far * _lc_ue_csa_01 ;       /* context save area end */
extern uint8 __far * _lc_ue_csa_tc0 ;       /* context save area end */
extern uint8 __far * _lc_ue_csa_tc1 ;       /* context save area end */
extern uint8 __far * _lc_ue_csa_tc2 ;       /* context save area end */
extern uint8 __far * _lc_ub_csa_tc0 ;       /* context save area end */
extern uint8 __far * _lc_ub_csa_tc1 ;       /* context save area end */
extern uint8 __far * _lc_ub_csa_tc2 ;       /* context save area end */


extern uint8 __far * _lc_u_trap_tab_tc0; /* trap table */
extern uint8 __far * _lc_u_trap_tab_tc1; /* trap table */
extern uint8 __far * _lc_u_trap_tab_tc2; /* trap table */

extern uint8 __far * _lc_u_int_tab ; /* interrupt table */
extern uint8 __far * _lc_ue_istack_tc0 ; /* interrupt stack end */
extern uint8 __far * _lc_ue_istack_tc1 ; /* interrupt stack end */
extern uint8 __far * _lc_ue_istack_tc2 ; /* interrupt stack end */

extern uint32 __far  *_lc_cp ;       /* copy table (cinit) */
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE)
extern uint32 __far *_lc_gb_FLS_STATE_VAR ; /* FLS state variable */
#endif
#define __INTTAB _lc_u_int_tab
#define __TRAPTAB cpu0_trap_0
#define __CPU0_ISTACK (&_lc_ue_istack_tc0)
#define __CPU1_ISTACK (&_lc_ue_istack_tc1)
#define __CPU2_ISTACK (&_lc_ue_istack_tc2)

#define __CPU0_TRAPTAB (&_lc_u_trap_tab_tc0)
#define __CPU1_TRAPTAB (&_lc_u_trap_tab_tc1)
#define __CPU2_TRAPTAB (&_lc_u_trap_tab_tc2)

#define __CPU0_USTACK (&_lc_ue_ustack_tc0)
#define __CPU1_USTACK (&_lc_ue_ustack_tc1)
#define __CPU2_USTACK (&_lc_ue_ustack_tc2)

#define CPU0_BASE_MEM_ADRRESS     (0x70000000U)
#define CPU1_BASE_MEM_ADRRESS     (0x60000000U)
#define CPU2_BASE_MEM_ADRRESS     (0x50000000U)
#define CPUX_BASE_MEM_ADDR_MASK   (0xF0000000U)
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)


extern void *__CPU0_USTACK;          /* user stack end */
extern void *__CPU1_USTACK;          /* user stack end */
extern void *__CPU2_USTACK;          /* user stack end */

extern void *__INTTAB_CPU0;          /* interrupt vector table */

extern uint32 __CPU0_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU1_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU2_ISTACK[];       /* interrupt stack end */

extern void *__CPU0_SMALL_DATA;      /* centre of A0 addressable area */
extern void *__CPU1_SMALL_DATA;      /* centre of A0 addressable area */
extern void *__CPU2_SMALL_DATA;      /* centre of A0 addressable area */

extern void *__CPU0_SMALL_DATA2;     /* centre of A1 addressable area */
extern void *__CPU1_SMALL_DATA2;     /* centre of A1 addressable area */
extern void *__CPU2_SMALL_DATA2;     /* centre of A1 addressable area */

extern void *_SMALL_DATA3_;     /* centre of A8 addressable area */
extern void *_SMALL_DATA4_;     /* centre of A9 addressable area */

extern uint32 __shared_clear_table[];  /* clear table entry */
extern uint32 __cpu0_clear_table[];  /* clear table entry */
extern uint32 __cpu1_clear_table[];  /* clear table entry */
extern uint32 __cpu2_clear_table[];  /* clear table entry */


extern uint32 __shared_copy_table[];   /* copy table entry */
extern uint32 __cpu0_copy_table[];   /* copy table entry */
extern uint32 __cpu1_copy_table[];   /* copy table entry */
extern uint32 __cpu2_copy_table[];   /* copy table entry */


extern uint32 __CPU0_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU0_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU1_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU1_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU2_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU2_CSA_END[];      /* context save area 1 begin */

#define __setareg(areg,val) \
{ \
  __asm volatile (" movh.a\t %%"#areg",hi:"#val"\n\tlea\t %%"#areg",\
                                        [%%"#areg"]lo:"#val"" : : : "memory"); \
}

#define __setreg(areg,val) \
{ \
  __asm volatile ("mov.aa %%"#areg", %0" :: "a" (val)); \
}


__asm ("\t .weak _SMALL_DATA3_,_SMALL_DATA4_");



#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
/* first trap table */
extern void cpu0_trap_0 (void) __attribute__ ((section (".cpu0_trap_0")));
extern void cpu1_trap_0 (void) __attribute__ ((section (".cpu1_trap_0")));
extern void cpu2_trap_0 (void) __attribute__ ((section (".cpu2_trap_0")));
/* interrupt table */
extern void inttab (void) __attribute__ ((section (".inttab")));
extern int __init_main(void);
void copy_to_ram(void);
extern uint32 __INTTAB_CPU0;          /* interrupt vector table */

extern char __LMU[], __LMU__END__[];
extern char __CORE0[], __CORE0__END__[];
extern char __CORE1[], __CORE1__END__[];
extern char __CORE2[], __CORE2__END__[];


__asm ("\t .weak __LMU, __LMU__END__, __PMIDMI, __PMIDMI__END__");
__asm ("\t .weak __CORE0, __CORE0__END__, __CORE1, __CORE1__END__");
__asm ("\t .weak __CORE2, __CORE2__END__");



#define __INTTAB __INTTAB_CPU0
#define __CPU0_TRAPTAB (uint32*)cpu0_trap_0
#define __CPU1_TRAPTAB (uint32*)cpu1_trap_0
#define __CPU2_TRAPTAB (uint32*)cpu2_trap_0
#define _SMALL_DATA3_ __SDA8_BASE
#define _SMALL_DATA4_ __SDA9_BASE

extern uint32 __CPU0_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU0_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU1_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU1_CSA_END[];      /* context save area 1 begin */
extern uint32 __CPU2_CSA_BEGIN[];    /* context save area 1 begin */
extern uint32 __CPU2_CSA_END[];      /* context save area 1 begin */

extern uint32 const __CPU0_USTACK;          /* user stack end */
extern uint32 const __CPU1_USTACK;          /* user stack end */
extern uint32 const __CPU2_USTACK;          /* user stack end */


extern uint32 __CPU0_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU1_ISTACK[];       /* interrupt stack end */
extern uint32 __CPU2_ISTACK[];       /* interrupt stack end */

extern uint32 __CPU0_SMALL_DATA;      /* centre of A0 addressable area */
extern uint32 __CPU1_SMALL_DATA;      /* centre of A0 addressable area */
extern uint32 __CPU2_SMALL_DATA;      /* centre of A0 addressable area */

extern uint32 __CPU0_SMALL_DATA2;     /* centre of A1 addressable area */
extern uint32 __CPU1_SMALL_DATA2;     /* centre of A1 addressable area */
extern uint32 __CPU2_SMALL_DATA2;     /* centre of A1 addressable area */

extern uint32 __SOURCE[];
extern uint32 __END_SOURCE[];
extern uint32 __DESTINATION[];



__asm ("\t .weak __SDA8_BASE, __SDA9_BASE");

#define __setareg(areg,val) ___setareg(areg,val)
/* we need to use a15 for the address register and not direct that the compiler this will not remove */
#define ___setareg(areg,val) \
  { __asm("#$$bp");                \
          __asm ("  movh.a\t %a15,"#val"@ha\n"); \
    __asm ("  lea\t %a15,[%a15]"#val"@l\n"); \
    __asm ("  mov.aa %"#areg", %a15\n"); \
    __asm ("#$$ep"); }


#define __setreg(areg,val) \
{ __asm("#$$bp"); \
  __asm ("ld.w %d0, "#val"@abs"); \
  __asm ("mov.a %"#areg", %d0"); \
  __asm ("#$$ep"); }
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */

#else
#pragma error "No Compiler specified."
#endif

/* Semaphore Operations */
#define MCAL_SET_SEMAPHORE(Sem)   (Sem = 1U)
#define MCAL_CLEAR_SEMAPHORE(Sem) (Sem = 0U)

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_MCAL_START_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
const Mcal_CoreInit_t Mcal_CoreInit[MCAL_NO_OF_CORES] = {
  {
    (uint32)__CPU0_USTACK,
    (uint32)&_lc_ub_csa_tc0,
    (uint32)&_lc_ue_csa_tc0,
    (uint32)__CPU0_ISTACK,
    (uint32)&_SMALL_DATA_,
    (uint32)&_LITERAL_DATA_,
    (uint32)&_lc_ub_table,
    0,
    &main
#if ( MCAL_NO_OF_CORES > 1U )      
  },
  {
    (uint32)__CPU1_USTACK,
    (uint32)&_lc_ub_csa_tc1,
    (uint32)&_lc_ue_csa_tc1,
    (uint32)__CPU1_ISTACK,
    (uint32)&_SMALL_DATA_TC1,
    (uint32)&_LITERAL_DATA_TC1,
    (uint32)&_lc_ub_table,
    0,
    &main
#if ( MCAL_NO_OF_CORES == 3U )   
  },
  {
    (uint32)__CPU2_USTACK,
    (uint32)&_lc_ub_csa_tc2,
    (uint32)&_lc_ue_csa_tc2,
    (uint32)__CPU2_ISTACK,
    (uint32)&_SMALL_DATA_TC2,
    (uint32)&_LITERAL_DATA_TC2,
    (uint32)&_lc_ub_table,
    0,
    &main
#endif /* ( MCAL_NO_OF_CORES == 3U )  */ 
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
  }
};
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)

Mcal_CoreInit_t const Mcal_CoreInit[MCAL_NO_OF_CORES] = {
  {
    (uint32)&__CPU0_USTACK,
    (uint32)__CPU0_CSA_BEGIN,
    (uint32)__CPU0_CSA_END,
    (uint32)__CPU0_ISTACK,
    (uint32)&__CPU0_SMALL_DATA,
    (uint32)&__CPU0_SMALL_DATA2,
    (uint32)__cpu0_copy_table,
    (uint32)__cpu0_clear_table,
    &main
#if ( MCAL_NO_OF_CORES > 1U )    
  },
  {
    (uint32)&__CPU1_USTACK,
    (uint32)__CPU1_CSA_BEGIN,
    (uint32)__CPU1_CSA_END,
    (uint32)__CPU1_ISTACK,
    (uint32)&__CPU1_SMALL_DATA,
    (uint32)&__CPU1_SMALL_DATA2,
    (uint32)__cpu1_copy_table,
    (uint32)__cpu1_clear_table,
    &main
#if ( MCAL_NO_OF_CORES == 3U )   
  },
  {
    (uint32)&__CPU2_USTACK,
    (uint32)__CPU2_CSA_BEGIN,
    (uint32)__CPU2_CSA_END,
    (uint32)__CPU2_ISTACK,
    (uint32)&__CPU2_SMALL_DATA,
    (uint32)&__CPU2_SMALL_DATA2,
    (uint32)__cpu2_copy_table,
    (uint32)__cpu2_clear_table,
    &main
#endif /* ( MCAL_NO_OF_CORES == 3U )   */
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
  }
};
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
const Mcal_CoreInit_t Mcal_CoreInit[MCAL_NO_OF_CORES] = {
  {
    (uint32)&__CPU0_USTACK,
    (uint32)__CPU0_CSA_BEGIN,
    (uint32)__CPU0_CSA_END,
    __CPU0_TRAPTAB,
    (uint32)__CPU0_ISTACK,
    (uint32)&__CPU0_SMALL_DATA,
    (uint32)&__CPU0_SMALL_DATA2,
    (uint32)__CORE0,
    (uint32)__CORE0__END__,
    &Mcal_Core0Container
#if ( MCAL_NO_OF_CORES > 1U )      
  },
  {
    (uint32)&__CPU1_USTACK,
    (uint32)__CPU1_CSA_BEGIN,
    (uint32)__CPU1_CSA_END,
    __CPU1_TRAPTAB,
    (uint32)__CPU1_ISTACK,
    (uint32)&__CPU1_SMALL_DATA,
    (uint32)&__CPU1_SMALL_DATA2,
    (uint32)__CORE1,
    (uint32)__CORE1__END__,
    &Mcal_Core1Container
#if ( MCAL_NO_OF_CORES == 3U )   
  },
  {
    (uint32)&__CPU2_USTACK,
    (uint32)__CPU2_CSA_BEGIN,
    (uint32)__CPU2_CSA_END,
    __CPU2_TRAPTAB,
    (uint32)__CPU2_ISTACK,
    (uint32)&__CPU2_SMALL_DATA,
    (uint32)&__CPU2_SMALL_DATA2,
    (uint32)__CORE2,
    (uint32)__CORE2__END__,
    &Mcal_Core2Container
#endif /* ( MCAL_NO_OF_CORES == 3U )   */
#endif /* ( MCAL_NO_OF_CORES > 1U )  */
  }
};
#endif
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#if (IFX_MCAL_USED == STD_ON)
#define MCAL_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#else
#define IFX_MCAL_STOP_SEC_CONST_UNSPECIFIED_ASIL_B
#include "Ifx_MemMap.h"
#endif

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
#define MCAL_START_SEC_CODE
#include "MemMap.h"
uint8 Mcal_lGetEcumCfgSelector(void);
#define MCAL_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* Semaphore to halt the processing of other cores until CORE0 completes
   initialization */



#define MCAL_START_SEC_CODE
#include "MemMap.h"
void Mcal_EcuMInit(void);
#define MCAL_STOP_SEC_CODE
#include "MemMap.h"


#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _START(void)                                                 **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/

#pragma section code "libc.reset"
#pragma align 4

void _START(void)
{
  __asm("j cstart");      /* jump to reset start address */
}


#pragma section code "libc"
#pragma align 4
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#else

#ifdef _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
#pragma section ".startup_code" awx
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
#pragma section CODE ".startup_code" X
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Syntax : int _RESET(void)                                                  **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/
void _RESET (void)
{
  __asm (".global _START");
  /* we must make a jump to cached segment, why trap_tab follow */
#ifdef _GNU_C_TRICORE_

  __asm ("_START: ja cstart");

#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
  __asm ("_START: movh.a %a15,cstart@ha");
  __asm ("  lea  %a15,[%a15]cstart@l");
  __asm ("  ji %a15");
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif
}
#ifdef _GNU_C_TRICORE_

#pragma section
#endif




#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : int main(void)                                                    **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Reset vector address                                         **
**                                                                            **
*******************************************************************************/
int main(void)
{
}

/* we switch to normal region to habe cpu0 traptab on 0x80000100 */
#pragma section CODE X
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif

#endif
/*******************************************************************************
** Syntax : void cstart(void)                                            **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :  MCAL Specific Start up code (Sample Test Code)              **
**                CrossView Requirement: Re-enable and reset the call depth   **
**                counter and  make A0,A1,A8,A9 accessible. User Stack        **
**                Pointer Initialization. PCX Reset: Clear Previous Context   **
**                Pointer Segment Address and Offset Field. CSA               **
**                initialization followed by clearing endinit bit.            **
**                Disable Watchdog.                                           **
**                Trap vector base address initialization.                    **
**                ISP - initlaization                                         **
**                Base Interrupt vector table initalization.                  **
**                Flash waitstates configuration followed by endinit set      **
**                A0,A1 addressing.                                           **
**                A8,A9 addressing.                                           **
**                Bus and LMB configuration                                   **
**                Initialization of RAM variables.                            **
**                Call to Mcal_Main                                           **
**                                                                            **
*******************************************************************************/
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
__attribute__((use_frame_pointer)) void cstart(void)
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#else
#define CSTART_START_SEC_CODE
#include "MemMap.h"
void cstart(void)
#endif
{


  const Mcal_CoreInit_t * CoreTable;
  #ifdef _TASKING_C_TRICORE_
  #if (_TASKING_C_TRICORE_ == 1U)
  uint32 sp;
  #ifndef _NO_A0A1_ADDRESSING
    void *a0 ;
    void *a1;
  #endif
  #endif
  #endif /* #if (_TASKING_C_TRICORE_ == 1U) */
  uint8 CoreNumber;

  uint32 *loop;

  CoreNumber = MFCR(CPU_CORE_ID);

  CoreTable = &(Mcal_CoreInit[CoreNumber]);

  /* Core 2 waits till Core 1 finishes initialization */
  if(CoreNumber == 2) {
	  while(Mcal_CpuInitCompletedSem[1] != 1){};
  }





#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
  /*
   Re-enable and reset the call depth counter and  make A0,A1,A8,A9
   write-able. It is required for CrossView that these RESET values are
   restored for each time the startup code is executed.
  */
  #ifndef _NO_PSW_RESET
     MTCR(CPU_PSW, 0x00000980);        /* clear PSW.IS and set to User Stack*/
  #endif

  /*
   user stack init
  */
  #ifndef _NO_USP_INIT
    sp = (uint32)(CoreTable->StackEndAddress) & STACK_ALIGN;
    __asm("mov.a\tsp,%0"::"d"(sp));
  #endif


  /*
   Clear Previous Context Pointer Segment Address and Offset Field.
   It is required for CrossView stack trace that these RESET values
   are restored for each time the startup code is executed.
  */

  #ifndef _NO_PCX_RESET
  {
      sint32 PCXValue ;
      PCXValue = __mfcr(CPU_PCXI) ;
      MTCR(CPU_PCXI, (sint32)((uint32)PCXValue & 0xfff00000UL)) ;
      __isync() ;
  }
  #endif

  #ifndef _NO_CSA_INIT
  {
      uint32 loopCount ;
      uint32 x ;
      uint32 _csa_index;
      uint32 _lcx_index;
      uint32 * _prev_csa;

  /*
   The total no of CSA's is computed between the difference of CSA boundary
   address.
   The logic goes like this , assume the CSA starts as 0xd0004000 and ends at
   0xd0005000. 64 CSA's and each CSA occupying 64 bytes ( total 0x1000 bytes)
   At the address 0xd0004000 ZERO is written, to indicate last CSA.
   At 0xd0004040 - link to the 0th CSA is written as 0x000D0100. ( D stands for segment number)
   At 0xd0004080 - link to the 1st CSA is written as 0x000D0101. 
   The list continues finally 
   At 0xd0004fc0 , link to the 62nd CSA is written as 0x000D013E
  */
      _prev_csa = (uint32 *)(CoreTable->CsaStartAddress) ;
      /*
       Load the count with the value of total CSA
      */
      loopCount = (((uint32)(CoreTable->CsaEndAddress - CoreTable->CsaStartAddress) >> 6) - 1UL) ;
      x = (((uint32)(CoreTable->CsaStartAddress) >> 28) << 16) ;

      /*   Load the null pointer for initial CSA (0th)      */
      *(_prev_csa) = 0 ;
      /* Fill the complete list */
      while(loopCount != 0)
      {
        _csa_index = ((((uint32)(_prev_csa) << 10) >> 16) | x ) ;
        _prev_csa += 0x10 ;
        *(_prev_csa) = _csa_index ;
        loopCount-- ;
      }
      _csa_index = ((((uint32)(_prev_csa) << 10) >> 16) | x ) ;
      
      /* Load the last but 2 CSA link into LCX register */
      _lcx_index = (uint32)( (uint32 *)(CoreTable->CsaStartAddress) + 0x20);
      _lcx_index = (uint32)(((_lcx_index << 10) >> 16) | x );
      MTCR(CPU_LCX,(sint32)_lcx_index) ;
      __isync() ;

      /*
       Load FCX with the free context pointer
       Write the last segment number into FCX register
      */
      MTCR(CPU_FCX,(sint32)_csa_index) ;
      __isync() ;

  }
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#endif
/* #elif _DIABDATA_C_TRICORE_ or _GNU_C_TRICORE_*/
#else

  uint32 pcxi;
  sint32 k;
  sint32 no_of_csas;
  sint32 *pCsa;
  uint32 seg_nr, seg_idx, pcxi_val = 0;
  sint32 *csa_area_begin = (sint32 *)(CoreTable->CsaStartAddress);
  sint32 *csa_area_end = (sint32 *)(CoreTable->CsaEndAddress);

  #ifndef _NO_USP_INIT
  Mcal_StackEndAddress = (uint32*)CoreTable->StackEndAddress;
  __setreg (sp, Mcal_StackEndAddress);

  DSYNC();
  #endif

  #ifndef _NO_PSW_RESET
  /* Set the PSW to its reset value in case of a warm start */
  MTCR (CPU_PSW, 0x00000B80);     /* clear PSW.IS */
  ISYNC();
  #endif

  /* Set the PCXS and PCXO to its reset value in case of a warm start */
  pcxi = __mfcr (CPU_PCXI);
  pcxi &= 0xfff00000;
  MTCR (CPU_PCXI, pcxi);

  /* Setup the context save area linked list. */
  /* first calculate nr of CSAs in this area */
  no_of_csas = (csa_area_end - csa_area_begin) >> 4;
  pCsa = csa_area_begin;

  for (k = 0; k < no_of_csas; k++)
  {
    /* Store null pointer in last CSA (= very first time!) */
    *pCsa = pcxi_val;
    /* get segment number */
    seg_nr = EXTRACT((sint32)pCsa, 28, 4) << 16;
    /* get idx number */
    seg_idx = EXTRACT((sint32)pCsa, 6, 16);
    /* calculate va�id pcxi value */
    pcxi_val = seg_nr | seg_idx;
    /* if this is the last but 2 csa, then we store the new pcxi value to LCX */
    if (k == 2)
    {
      MTCR (CPU_LCX, pcxi_val);
    }
    /* next CSA */
    pCsa += 16;
  }
  /* store actual pcxi value to the FCX (this is our first free context) */
  MTCR (CPU_FCX, pcxi_val);
  ISYNC();

#endif /* _TASKING_C_TRICORE_ */

  if(CoreNumber == 0)
  {
	  safety_endinit_reset();
#ifndef NO_WATCHDOG_DISABLE
    /*
     disable Safety watchdog & Cpu0 watchdog
    */
      SCU_WDTSCON1.U |= 0x00000008 ;
      safety_endinit_set();
      safety_endinit_reset();


#endif
  }
  endinit_reset();
#ifndef NO_WATCHDOG_DISABLE
  MODULE_SCU.WDTCPU[CoreNumber].CON1.U |= 0x00000008;
  endinit_set();
  endinit_reset();
#endif
  /* Icache enabling steps */
  /* Step 1: Set PCBYP to 1 */
  MTCR(CPU_PCON0,PCON0_PCBYP);
  /* Step 2: Call Isync */
  ISYNC();


  endinit_set();

  /* Step 3: Invalidate current settings */
  MTCR(CPU_PCON1,PCON1_PCINV);

  /* Step 5: wait till PCINV becomes zero */
  while((__mfcr(CPU_PCON1) & PCON1_PCINV) == PCON1_PCINV);

  /*
   Clear the ENDINIT bit in the WDT_CON0 register in order
   to disable the write-protection for registers protected
   via the EndInit feature (for example: WDT_CON1).
  */
  endinit_reset();

/*
 Load interupt stack pointer
 Disable this if not started from RESET vector. (E.g.
 ROM monitors require to keep in control of vectors)
*/
#ifndef _NO_ISP_INIT
  MTCR(CPU_ISP,(uint32)((uint32)(CoreTable->IStackAddress))) ;
#endif



#ifdef _ENABLE_ICACHE
   /* After setting the size, enable end init protection */

   /* Step 6: Enable ICACHE memory, followed by ISYNC instruction */
   MTCR(CPU_PCON0,0);

   ISYNC(); 
#endif

#ifdef _ENABLE_DCACHE
   /* After setting the size, enable end init protection */

   /* Step 6: Enable DCACHE memory, followed by ISYNC instruction */
   MTCR(CPU_DCON0,0);

  ISYNC(); 
  DSYNC();
#endif

/*
 Set the ENDINIT bit in the WDT_CON0 register again
 to enable the write-protection and to prevent a time-out.
*/
    endinit_set();
    
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*
 Inititialize global address registers a0/a1 to support
 __a0/__a1 storage qualifiers of the C compiler.
*/
#ifndef _NO_A0A1_ADDRESSING
      a0 = (uint32*)CoreTable->SmallData0;
    __asm( "mov.aa\ta0,%0"::"a"(a0) );

      a1 = (uint32*)CoreTable->SmallData2;
    __asm( "mov.aa\ta1,%0"::"a"(a1) );

#endif

/*
 Inititialize global address registers a8/a9 to support
 __a8/__a9 storage qualifiers of the C compiler. A8 and A9
 are reserved for OS use, or for application use in cases
 where the application ans OS are tightly coupled.
*/
#ifndef _NO_A8A9_ADDRESSING
    void * a8 = _A8_DATA_;
    __asm( "mov.aa\ta8,%0"::"a"(a8) );

    void * a9 = _A9_DATA_;
    __asm( "mov.aa\ta9,%0"::"a"(a9) );
#endif

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */
#else
 /*
   * initialize SDA base pointers
   */
  Mcal_SmallDataAddress = CoreTable->SmallData0;
  Mcal_LiteralDataAddress = CoreTable->SmallData2;

  __setareg (a8, _SMALL_DATA3_);

  __setareg (a9, _SMALL_DATA4_);

  __setreg(a0, Mcal_SmallDataAddress);
  __setreg(a1, Mcal_LiteralDataAddress);





#endif /* _TASKING_C_TRICORE_ */

  endinit_reset();
  FLASH0_FCON.U |= 0x00000002;
  endinit_set();

  if(CoreNumber == 0)
  {
	  safety_endinit_set();

  }

/*
 Enabling LMB split mode means all LMB reads accepted by LFI where the LMB
 Master is not asserting lmb_no_split_n are taken as split transactions.
 Default state is All LMB reads accepted by LFI are taken as no split
 transactions.
 Modification of LFI_CON register is done only when the LMB mode is enabled.
 Its left to default state if the split is not  enabled hence code will not
 be generated
 In LFI_CON.U register the bit 0 is modified for the same, if LMB split
 is enabled.
*/

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*
 Initialize and clear C variables
*/
#ifndef _NO_C_INIT
    /* initialize data for all cores */
   {
     _c_init(CoreNumber, CoreTable->CopyTable) ;
   }
#endif
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
    /* initialize data */
#if ( MCAL_NO_OF_CORES == 3U )   
   if(CoreNumber == 0)
   {
     _Gnu_CopyTable((uint32)__shared_clear_table, (uint32)__shared_copy_table);
   }
#endif /* ( MCAL_NO_OF_CORES == 3U ) */
  _Gnu_CopyTable(CoreTable->ClearTable, CoreTable->CopyTable);

#endif /* #if (_GNU_C_TRICORE_ == 1U) */

#elif defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)
    __isync ();  /* mtcr will don't do this for us */
    /* initialize data */
    copy_to_ram();
    __init_main();
#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
#endif /* _TASKING_C_TRICORE_ */
  /* IFX_SAFETLIB_USED enable in case of SafeTlib standalone and Integration */
  #if (IFX_SAFETLIB_USED == STD_ON)
    #if ( MCAL_NO_OF_CORES > 1U )
    if(CoreNumber == 0)
    {
      /* Set program counter of core 1 */
      //CPU1_PC.U = (unsigned int)cstart; /* start core 1 inside EcuM_Init - ogd1hc */
        
      #if ( MCAL_NO_OF_CORES == 3U )   
      /* Set program counter of core 2 */
      //CPU2_PC.U = (unsigned int)cstart; /* start core 2 inside EcuM_Init - ogd1hc */
      #endif
    }
    #endif /* #if ( MCAL_NO_OF_CORES > 1U ) */
    SafeTlib_main(CoreNumber);
  #endif/* #if (IFX_SAFETLIB_USED == STD_ON) */

  Mcal_CpuInitCompletedSem[CoreNumber] = 1;
  /* Call the Core specifc functionalities */
  CoreTable->CoreFn();
}
#define CSTART_STOP_SEC_CODE
#include "MemMap.h"
/*
 End of Function Start
*/
#if defined(_DIABDATA_C_TRICORE_)
#if (_DIABDATA_C_TRICORE_ == 1U)

void copy_to_ram(void)
{
  uint32 i;
  uint32 n;
  /* Calculate length of the region in ints */
  n = (__END_SOURCE) - (__DESTINATION);
  for (i = 0; i < n; i++)
  {
    __DESTINATION[i] = __SOURCE[i];
  }
}
#endif
#endif

#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _Exit(void)                                                  **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:                                                                **
**                                                                            **
** Reentrancy:                                                                **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Exits and calls debug16 instruction                          **
**                                                                            **
*******************************************************************************/
void _Exit(void)
{
  while(1)
  {
    __asm("debug16") ;
  }
}



#pragma section code "libc"
#pragma align 4
#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

#elif defined(_GNU_C_TRICORE_)
#if (_GNU_C_TRICORE_ == 1U)
/*******************************************************************************
** Syntax : void _Gnu_CopyTable(uint32 ClearTable, uint32 CopyTable)          **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Initialize or clear data segments as specified by the copy   **
**               table, It is an array of 4 word entries generated by the     **
**               locator. offset  0: type- 0=end, 1=copy, 2=clear             **
**               offset  4: destination address                               **
**               offset  8: source address (copy only)                        **
**               offset 12: length             - length in bytes.             **
**                                                                            **
*******************************************************************************/
#define STARTUP_START_SEC_CODE
#include "MemMap.h"
void _Gnu_CopyTable(uint32 ClearTable, uint32 CopyTable)
{
  typedef volatile union
  {
    uint8 *ucPtr;
    uint16 *usPtr;
    uint32 *uiPtr;
    unsigned long long *ullPtr;
  } TABLE_PTR;

  uint32 uiLength, uiCnt;
  uint32 *pTable;
  TABLE_PTR pBlockDest;
  TABLE_PTR pBlockSrc;
  /* clear table */
  pTable = (uint32*)ClearTable;
  while (pTable)
  {
    pBlockDest.uiPtr = (uint32 *)*pTable++;
    uiLength = *pTable++;
    /* we are finished when length == -1 */
    if (uiLength == 0xFFFFFFFF)
    {
      break;
    }

    uiCnt = uiLength / 8;

    while (uiCnt--)
    {
      *pBlockDest.ullPtr++ = 0;
    }

    if ((uiLength) & 0x4)
    {
      *pBlockDest.uiPtr++ = 0;
    }

    if ((uiLength) & 0x2)
    {
      *pBlockDest.usPtr++ = 0;
    }

    if ((uiLength) & 0x1)
    {
      *pBlockDest.ucPtr = 0;
    }
  }
  /* copy table */
  pTable = (uint32*)CopyTable;
  while (pTable)
  {
    pBlockSrc.uiPtr = (uint32 *)*pTable++;
    pBlockDest.uiPtr = (uint32 *)*pTable++;
    uiLength = *pTable++;
    /* we are finished when length == -1 */
    if (uiLength == 0xFFFFFFFF)
    {
      break;
    }

    uiCnt = uiLength / 8;

    while (uiCnt--)
    {
      *pBlockDest.ullPtr++ = *pBlockSrc.ullPtr++;
    }

    if ((uiLength) & 0x4)
    {
      *pBlockDest.uiPtr++ = *pBlockSrc.uiPtr++;
    }

    if ((uiLength) & 0x2)
    {
      *pBlockDest.usPtr++ = *pBlockSrc.usPtr++;
    }

    if ((uiLength) & 0x1)
    {
      *pBlockDest.ucPtr = *pBlockSrc.ucPtr;
    }
  }
}
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
** Syntax           : uint8 EcuM_lGetCfgSelector(void)                        **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **                                                                                                                                 **
*******************************************************************************/
#if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
#define MCAL_START_SEC_CODE
#include "MemMap.h"
uint8 Mcal_lGetEcumCfgSelector(void)
{
 /* Get Selector based on ......*/

 return(0);
}
#define MCAL_STOP_SEC_CODE
#include "MemMap.h"
#endif


#if (IFX_MCAL_USED == STD_ON)
#define MCAL_START_SEC_CODE
#include "MemMap.h"
void Mcal_EcuMInit()
{
  #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
  uint8 CfgSelector;
  #endif

   /*Initialize ECUM Module*/
  EcuM_Init();
}
#define MCAL_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* Function to reset the endinit bit of Safety watchdog */
static void safety_endinit_reset(void) 
{ 
	Mcal_ResetCpuENDINIT( -1 );
}

/* Function to set the endinit bit of Safety watchdog */
static void safety_endinit_set  (void) 
{ 
	Mcal_SetCpuENDINIT( -1 );
}

/* Function to reset the endinit bit of executing CPU watchdog */
static void endinit_reset(void) 
{ 
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & MCAL_CORE_ID_MASK);
  Mcal_ResetCpuENDINIT( (sint8)CoreID );
}
/* Function to set the endinit bit of executing CPU watchdog */
static void endinit_set  (void) 
{ 
  uint32 CoreID = ((uint32)MFCR(CPU_CORE_ID) & MCAL_CORE_ID_MASK);
  Mcal_SetCpuENDINIT( (sint8)CoreID );
}
#define STARTUP_STOP_SEC_CODE
#include "MemMap.h"
