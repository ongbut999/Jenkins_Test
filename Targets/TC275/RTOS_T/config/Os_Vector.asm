;
; TriCoreTasking Interrupts
;
; Copyright ETAS GmbH 2019
;


  .name "Os_Vector.asm"

  .extern Os_ISRWrapper0

;  #===========================================================================
;  # Os_InterruptVectorTable0
;  #===========================================================================
  .global Os_InterruptVectorTable0 ;# Start of the table
  .sdecl  '.text.inttab0.intvec.000',CODE
  .sect   '.text.inttab0.intvec.000'
  .align 128
Os_InterruptVectorTable0:

  .sdecl  '.text.inttab0.intvec.002',CODE
  .sect   '.text.inttab0.intvec.002'
  mfcr d15, #0xFE00
  bisr #255
  mov d5, d15
  mov d4,#0
  movh.a a14,#@his(Os_ISRWrapper0)
  lea a14,[a14]@los(Os_ISRWrapper0)
  ji a14
  .sdecl  '.text.inttab0.intvec.003',CODE
  .sect   '.text.inttab0.intvec.003'
  mfcr d15, #0xFE00
  bisr #255
  mov d5, d15
  mov d4,#1
  movh.a a14,#@his(Os_ISRWrapper0)
  lea a14,[a14]@los(Os_ISRWrapper0)
  ji a14
;  #===========================================================================
;  # Os_InterruptVectorTable1
;  #===========================================================================
  .global Os_InterruptVectorTable1 ;# Start of the table
  .sdecl  '.text.inttab1.intvec.000',CODE
  .sect   '.text.inttab1.intvec.000'
  .align 128
Os_InterruptVectorTable1:

;  #===========================================================================
;  # Os_InterruptVectorTable2
;  #===========================================================================
  .global Os_InterruptVectorTable2 ;# Start of the table
  .sdecl  '.text.inttab2.intvec.000',CODE
  .sect   '.text.inttab2.intvec.000'
  .align 128
Os_InterruptVectorTable2:




