/*----------------------------------------------------------------------------*/
/************** *SAMPLE* of MemMap.h. Not for production purposes *************/
/*----------------------------------------------------------------------------*/
#define MEM_VENDOR_ID        (11U)
#define MEM_AR_MAJOR_VERSION (4U)
#define MEM_AR_MINOR_VERSION (0U)
#define MEM_AR_PATCH_VERSION (3U)
#define MEM_SW_MAJOR_VERSION (5U)
#define MEM_SW_MINOR_VERSION (6U)
#define MEM_SW_PATCH_VERSION (3U)

/* -------------------------------------------------------------------------- */
/*             OS (Operating System)                                          */
/* -------------------------------------------------------------------------- */
//#include <Os_MemMap.h>

/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/


#if defined (START_WITH_IF)
/* -------------------------------------------------------------------------- */
/* RAM variables not initialized                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_NOINIT_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT

#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED

#elif defined (CAN_17_MCANP_START_SEC_VAR_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_8BIT
   #if defined __TASKING__
   #pragma section farbss="MCANP_RAM_8BIT_ALIGN_2"
   #pragma align 2
   #endif
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_8BIT
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #endif

#elif defined CALIB_START_SEC_CONST_UNSPECIFIED
   #undef  CALIB_START_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma section farrom="Calib_unspec"
      #pragma align 4
   #elif __GNUC__
      #pragma section ".rodata.Calib_unspec" a 4
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_STOP_SEC_CONST_UNSPECIFIED
    #undef CALIB_STOP_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
    #pragma align restore
    #pragma section farrom restore
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif

#elif defined CALIB_START_SEC_CONST_BOOL
   #undef  CALIB_START_SEC_CONST_BOOL
   #ifdef __TASKING__
      #pragma section farrom="Calib_bool"
      #pragma align 1
   #elif __GNUC__
      #pragma section ".rodata.Calib_bool" a 1
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_STOP_SEC_CONST_BOOL
    #undef CALIB_STOP_SEC_CONST_BOOL
   #ifdef __TASKING__
    #pragma align restore
    #pragma section farrom restore
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_START_SEC_CONST_8
   #undef  CALIB_START_SEC_CONST_8
   #ifdef __TASKING__
      #pragma section farrom="Calib_8"
      #pragma align 1
   #elif __GNUC__
      #pragma section ".rodata.Calib_8" a 1
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_STOP_SEC_CONST_8
   #undef CALIB_STOP_SEC_CONST_8
   #ifdef __TASKING__
      #pragma align restore
      #pragma section farrom restore
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_START_SEC_CONST_16
   #undef  CALIB_START_SEC_CONST_16
   #ifdef __TASKING__
      #pragma section farrom="Calib_16"
      #pragma align 2
   #elif __GNUC__
      #pragma section ".rodata.Calib_16" a 2
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_STOP_SEC_CONST_16
   #undef CALIB_STOP_SEC_CONST_16
   #ifdef __TASKING__
      #pragma align restore
      #pragma section farrom restore
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_START_SEC_CONST_32
   #undef  CALIB_START_SEC_CONST_32
   #ifdef __TASKING__
      #pragma section farrom="Calib_32"
      #pragma align 4
   #elif __GNUC__
    #pragma section ".rodata.Calib_32" a 4
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined CALIB_STOP_SEC_CONST_32
   #ifdef __TASKING__
      #pragma align restore
      #pragma section farrom restore
   #elif __GNUC__
    #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif
/* -------------------------------------------------------------------------- */
/* RAM variables power-on initialized                                         */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT

#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED

#elif defined (DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #ifdef __TASKING__
    #pragma section farbss="DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED"
  #elif __GNUC__   
    #pragma  section ".bss.DEFAULT_START_SEC_VAR_NO_INIT_UNSPECIFIED"
  #elif _DIABDATA_C_TRICORE_
  #endif

#elif defined (DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #ifdef __TASKING__
    #pragma section farbss restore
   #elif __GNUC__    
    #pragma  section
   #elif _DIABDATA_C_TRICORE_
   #endif

/* -------------------------------------------------------------------------- */
/* RAM variables initialized from ROM on reset                                */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_8BIT)
  #undef      DEFAULT_START_SEC_VAR_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_8BIT

#elif defined (DEFAULT_START_SEC_VAR_16BIT)
  #undef      DEFAULT_START_SEC_VAR_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_16BIT

#elif defined (DEFAULT_START_SEC_VAR_32BIT)
  #undef      DEFAULT_START_SEC_VAR_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_32BIT

#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED

/* -------------------------------------------------------------------------- */
/* RAM variables frequently used or accessed bitwise                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_VAR_FAST_BOOLEAN)
  #undef      DEFAULT_START_SEC_VAR_FAST_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_BOOLEAN

#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT)
  #undef      DEFAULT_START_SEC_VAR_FAST_8BIT
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT

#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT)
  #undef      DEFAULT_START_SEC_VAR_FAST_16BIT
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT

#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT)
  #undef      DEFAULT_START_SEC_VAR_FAST_32BIT
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT

#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED

/* -------------------------------------------------------------------------- */
/* ROM constants                                                              */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_BOOLEAN)
  #undef      DEFAULT_START_SEC_CONST_BOOLEAN
#elif defined (DEFAULT_STOP_SEC_CONST_BOOLEAN)
  #undef      DEFAULT_STOP_SEC_CONST_BOOLEAN

#elif defined (DEFAULT_START_SEC_CONST_8BIT)
  #undef      DEFAULT_START_SEC_CONST_8BIT
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT)
  #undef      DEFAULT_STOP_SEC_CONST_8BIT

#elif defined (DEFAULT_START_SEC_CONST_16BIT)
  #undef      DEFAULT_START_SEC_CONST_16BIT
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT)
  #undef      DEFAULT_STOP_SEC_CONST_16BIT

#elif defined (DEFAULT_START_SEC_CONST_32BIT)
  #undef      DEFAULT_START_SEC_CONST_32BIT
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT)
  #undef      DEFAULT_STOP_SEC_CONST_32BIT

#elif defined (DEFAULT_START_SEC_CONST_FAST_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_CONST_FAST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma section farrom=".DEFAULT_CONST_UNSPECIFIED"
      #pragma align 4
   #elif __GNUC__
      #pragma section ".rodata.DEFAULT_CONST_UNSPECIFIED" a
   #elif _DIABDATA_C_TRICORE_
   #endif

#elif defined (DEFAULT_STOP_SEC_CONST_FAST_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_CONST_FAST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma align restore
      #pragma section farrom restore
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif



#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma section farrom=".DEFAULT_CONST_UNSPECIFIED"
      #pragma align 4
   #elif __GNUC__
      #pragma section ".rodata.DEFAULT_CONST_UNSPECIFIED"
   #elif _DIABDATA_C_TRICORE_
   #endif


#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma align restore
      #pragma section farrom restore
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif

#elif defined (DEFAULT_START_SEC_VAR_CLEARED_8BIT_ALIGN_2)
   #undef      DEFAULT_START_SEC_VAR_CLEARED_8BIT_ALIGN_2
   #if defined __TASKING__
   #pragma section farbss="DEFAULT_VAR_CLEARED_8BIT_ALIGN_2"
   #pragma align 2
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_CLEARED_8BIT_ALIGN_2)
   #undef      DEFAULT_STOP_SEC_VAR_CLEARED_8BIT_ALIGN_2
   #if defined __TASKING__
   #pragma align restore
   #pragma section farbss restore
   #endif

#elif defined (DEFAULT_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      DEFAULT_START_SEC_VAR_CLEARED_UNSPECIFIED
   #ifdef __TASKING__
    #pragma section farbss=".DEFAULT_VAR_CLEARED_UNSPECIFIED"
   #elif __GNUC__
       #pragma section ".bss.DEFAULT_VAR_CLEARED_UNSPECIFIED"
   #elif _DIABDATA_C_TRICORE_
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      DEFAULT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #ifdef __TASKING__
    #pragma section farbss restore
   #elif __GNUC__
       #pragma section
   #elif _DIABDATA_C_TRICORE_
   #endif
/* -------------------------------------------------------------------------- */
/* ROM FAR constants                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CONST_BOOLEAN_FAR)
  #undef      DEFAULT_START_SEC_CONST_BOOLEAN_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_BOOLEAN_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_BOOLEAN_FAR

#elif defined (DEFAULT_START_SEC_CONST_8BIT_FAR)
  #undef      DEFAULT_START_SEC_CONST_8BIT_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_8BIT_FAR

#elif defined (DEFAULT_START_SEC_CONST_16BIT_FAR)
  #undef      DEFAULT_START_SEC_CONST_16BIT_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_16BIT_FAR

#elif defined (DEFAULT_START_SEC_CONST_32BIT_FAR)
  #undef      DEFAULT_START_SEC_CONST_32BIT_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_32BIT_FAR

#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR)
  #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_FAR
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR)
  #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_FAR

/* -------------------------------------------------------------------------- */
/* ROM code                                                                   */
/* -------------------------------------------------------------------------- */
#elif defined (DEFAULT_START_SEC_CODE)
  #undef      DEFAULT_START_SEC_CODE
#elif defined (DEFAULT_STOP_SEC_CODE)
  #undef      DEFAULT_STOP_SEC_CODE

#elif defined (DEFAULT_START_SEC_CODE_FAST)
  #undef      DEFAULT_START_SEC_CODE_FAST
#elif defined (DEFAULT_STOP_SEC_CODE_FAST)
  #undef      DEFAULT_STOP_SEC_CODE_FAST

#elif defined (DEFAULT_START_SEC_CODE_SLOW)
  #undef      DEFAULT_START_SEC_CODE_SLOW
#elif defined (DEFAULT_STOP_SEC_CODE_SLOW)
  #undef      DEFAULT_STOP_SEC_CODE_SLOW

#elif defined (DEFAULT_START_SEC_CODE_LIB)
  #undef      DEFAULT_START_SEC_CODE_LIB
#elif defined (DEFAULT_STOP_SEC_CODE_LIB)
  #undef      DEFAULT_STOP_SEC_CODE_LIB

#elif defined (DEFAULT_START_SEC_VECTORS)
  #undef      DEFAULT_START_SEC_VECTORS
#elif defined (DEFAULT_STOP_SEC_VECTORS)
  #undef      DEFAULT_STOP_SEC_VECTORS

#elif defined (BMD_HDR_START_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_START_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma section farrom="BMD_HDR_CONST_FAR_UNSPECIFIED"
   #elif __GNUC__
      #pragma section ".BMD_HDR_CONST_FAR_UNSPECIFIED"
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".BMD_HDR_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
#elif defined (BMD_HDR_STOP_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
      #pragma section farrom restore
   #elif __GNUC__
   #pragma section
   #define   BMD_HDR_STOP_SEC_BMI_HEADER
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


/*MCAL lib*/
#elif defined MCAL_START_SEC_VAR_FAST_32BIT
   #undef MCAL_START_SEC_VAR_FAST_32BIT
   #ifdef __TASKING__

   #pragma section farbss="CPU0_32"
   #pragma align 4
   #elif defined __GNUC__
   #pragma section ".data.CPU0_32" aw 4
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA ".data.CPU0_32" ".data.CPU0_32" far-absolute RW
   #endif
   #endif
#elif defined MCAL_STOP_SEC_VAR_FAST_32BIT
   #undef MCAL_STOP_SEC_VAR_FAST_32BIT
   #ifdef __TASKING__
   #pragma section farbss restore
   #pragma align restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #if(_DIABDATA_C_TRICORE_ == 1U)
   #pragma section DATA RW
   #endif
   #endif





#elif defined MCAL_START_SEC_VAR_CLEARED_32BIT
   #undef MCAL_START_SEC_VAR_CLEARED_32BIT
   #ifdef __TASKING__
   #pragma section nearbss="CPU0_32"
   #pragma for_uninitialized_data_use_memory near
   #pragma align 4
   #elif defined __GNUC__
	#pragma section ".bss.CPU0_32" awB 4
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section DATA ".bss.CPU0_32" ".bss.CPU0_32" near-absolute RW
   #endif
 #elif defined MCAL_STOP_SEC_VAR_CLEARED_32BIT
   #undef MCAL_STOP_SEC_VAR_CLEARED_32BIT
   #ifdef __TASKING__
   #if(__TASKING__ == 1U)
   #pragma align restore
   #pragma for_uninitialized_data_use_memory restore
   #pragma section nearbss restore
   #endif
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section DATA RW
   #endif



#elif defined MCAL_START_SEC_CONST_UNSPECIFIED
   #undef MCAL_START_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
   #pragma section farrom="CPU0_unspec"
   #pragma align 4
   #elif defined __GNUC__
   #pragma section ".rodata.CPU0_unspec" a 4
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CONST ".rodata.CPU0_unspec" far-absolute R
   #endif
#elif defined (MCAL_STOP_SEC_CONST_UNSPECIFIED)
   #undef      MCAL_STOP_SEC_CONST_UNSPECIFIED
   #ifdef __TASKING__
   #pragma align restore
   #pragma section farrom restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CONST R
   #endif


#elif defined MCAL_START_SEC_CODE
   #undef MCAL_START_SEC_CODE
   #ifdef __TASKING__
   #pragma section code="CPU0_Code"
   #pragma optimize R
   #elif defined __GNUC__
   #pragma section ".text.CPU0_Code" ax 4
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE ".text.CPU0_Code" RX
   #endif
#elif defined MCAL_STOP_SEC_CODE
   #undef MCAL_STOP_SEC_CODE
   #ifdef __TASKING__
   #pragma section code restore
   #pragma endoptimize
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE RX
   #endif

/*Start up*/
#elif defined STARTUP_START_SEC_CODE
   #undef STARTUP_START_SEC_CODE
   #undef MCAL_START_SEC_CODE
   #ifdef __TASKING__
   #pragma section code="CPU0_Code"
   #elif defined __GNUC__
   #pragma section ".text.CPU0_Code" ax 4
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE ".text.CPU0_Code" RX
   #endif
#elif defined STARTUP_STOP_SEC_CODE
   #undef STARTUP_STOP_SEC_CODE
   #ifdef __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE RX
   #endif


/*fix cstart address*/
#elif defined CSTART_START_SEC_CODE
   #undef CSTART_START_SEC_CODE
   #ifdef __TASKING__
   #pragma section code="cstart"
   #elif defined __GNUC__
   #pragma section ".text.cstart" ax 4
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE ".text.cstart" RX
   #endif
#elif defined CSTART_STOP_SEC_CODE
   #undef CSTART_STOP_SEC_CODE
   #ifdef __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE RX
   #endif


/*Main*/
#elif defined MAIN_START_SEC_CODE
   #undef MAIN_START_SEC_CODE
   #ifdef __TASKING__
   #pragma section code="CPU0_Code"
   #elif defined __GNUC__
   #pragma section ".text.CPU0_Code" ax 4
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE ".text.CPU0_Code" RX
   #endif
#elif defined MAIN_STOP_SEC_CODE
   #undef MAIN_STOP_SEC_CODE
   #ifdef __TASKING__
   #pragma section code restore
   #elif defined __GNUC__
   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   #pragma section CODE RX
   #endif


/*CAT1_ISR*/
#elif defined CAT1_ISR_START_SEC_CODE
   #undef CAT1_ISR_START_SEC_CODE
   #ifdef __TASKING__
   	   #pragma section code="CPU0_Code"
   #elif defined __GNUC__
   	   #pragma section ".text.CPU0_Code" ax 4
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE ".text.CPU0_Code" RX
   #endif
#elif defined CAT1_ISR_STOP_SEC_CODE
   #undef CAT1_ISR_STOP_SEC_CODE
   #ifdef __TASKING__
   	   #pragma section code restore
   #elif defined __GNUC__
   	   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE RX
   #endif
/* ---The following sections attempt to locate FLS Write and Erase command-----
   ---Cycles in an order. It is essential to enforce the correct sequence------
   ---so that the FLS driver can perform as requird.-------------------------*/
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN
   #ifdef __TASKING__
   	   #pragma section code "FLS_AC_WRITE_SOURCE"
   	   #pragma optimize R
   #elif defined __GNUC__
   	   #pragma section ".text.FLS_AC_WRITE_SOURCE" ax 4
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE ".FLS_AC_WRITE_SOURCE" far-absolute RX
   #endif
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN
   #ifdef __TASKING__
   	   #pragma section code restore
   	   #pragma endoptimize
   #elif defined __GNUC__
   	   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE RX
   #endif

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN
   #ifdef __TASKING__
      #pragma section code "FLS_AC_ERASE_SOURCE"
      #pragma optimize R
   #elif __GNUC__
      #pragma section ".text.FLS_AC_ERASE_SOURCE" ax 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FLS_AC_ERASE_SOURCE" far-absolute RX
   #endif
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN
   #ifdef __TASKING__
      #pragma section code restore
      #pragma endoptimize
   #elif __GNUC__
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU0
   #if defined __TASKING__
   	   #pragma section code="CPU0_TRAP_HANDLER_CODE_ROM"
   #elif defined __GNUC__
   	   #pragma section ".text.CPU0_TRAP_HANDLER_CODE_ROM" ax 32
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE ".text.CPU0_TRAP_HANDLER_CODE_ROM" X
   	   #pragma align_functions 32
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU0
   #if defined __TASKING__
      #pragma section code restore
   #elif defined __GNUC__
   	   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma align_functions 0
   	   #pragma section CODE X
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU1
   #if defined __TASKING__
   	   #pragma section code="CPU1_TRAP_HANDLER_CODE_ROM"
   #elif defined __GNUC__
   	   #pragma section ".text.CPU1_TRAP_HANDLER_CODE_ROM" ax 32
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE ".text.CPU1_TRAP_HANDLER_CODE_ROM" X
   	   #pragma align_functions 32
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU1
   #if defined __TASKING__
      #pragma section code restore
   #elif defined __GNUC__
   	   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma align_functions 0
   	   #pragma section CODE X
   #endif


#elif defined (MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_START_SEC_TRAP_HANDLER_CPU2
   #if defined __TASKING__
   	   #pragma section code="CPU2_TRAP_HANDLER_CODE_ROM"
   #elif defined __GNUC__
   	   #pragma section ".text.CPU2_TRAP_HANDLER_CODE_ROM" ax 32
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma section CODE ".text.CPU2_TRAP_HANDLER_CODE_ROM" X
   	   #pragma align_functions 32
   #endif
#elif defined (MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2)
   #undef      MCAL_TRAP_STOP_SEC_TRAP_HANDLER_CPU2
   #if defined __TASKING__
   	   #pragma section code restore
   #elif defined __GNUC__
   	   #pragma section
   #elif defined _DIABDATA_C_TRICORE_
   	   #pragma align_functions 0
   #pragma section CODE X
   #endif
#else

/* -------------------------------------------------------------------------- */
/* End of default section mapping                                             */
/* -------------------------------------------------------------------------- */
#endif  /* START_WITH_IF */

/*** End of file **************************************************************/
