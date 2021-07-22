 

 #ifndef WDGIF_TYPES_H
 #define WDGIF_TYPES_H
 /*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "Std_Types.h"
#if (!defined(STD_TYPES_AR_RELEASE_MAJOR_VERSION) || (STD_TYPES_AR_RELEASE_MAJOR_VERSION != 4))
#error “AUTOSAR major version undefined or mismatched“
#endif
#if (!defined(STD_TYPES_AR_RELEASE_MINOR_VERSION) || (STD_TYPES_AR_RELEASE_MINOR_VERSION != 2))
#error “AUTOSAR minor version undefined or mismatched“
#endif

 /*
 ***************************************************************************************************
 * Type definitions
 ***************************************************************************************************
 */

 /*TRACE[WDGIF016] Definations of WdgIf Mode Type*/
 typedef enum
 {
        WDGIF_OFF_MODE,
        WDGIF_SLOW_MODE,
        WDGIF_FAST_MODE
 }WdgIf_ModeType;

 /* This enum is used to check(read) the status of switches */
 typedef enum
 {
     WDGIF_RB_ALLSWTCLSD_E = 0,                  /* All switches closed (switches MM2ERR and ERR2WDA are closed) */
     WDGIF_RB_MM2ERRSWTOPN_E,        /* MM2ERR switch open, remaining (ERR2WDA) close */
     WDGIF_RB_ERR2WDASWTOPN_E,     /* ERR2WDA switch open, remaining (MM2ERR) close */
     WDGIF_RB_ALLSWTOPN_E                     /* All switches opened (switches MM2ERR and ERR2WDA are opened) */
 } WdgIf_Rb_SwtPosn_ten;



  typedef struct
  {
      VAR(uint32,AUTOMATIC)  tiResp_u32;          /* current response time in microsec */
      VAR(uint32,AUTOMATIC)  tiStampLastTx_u32;   /* timestamp of last SPI transmission in timer ticks */
      VAR(uint8,AUTOMATIC)   xCurrReq_u8;         /* current request of monitoring module (0..16) */
      VAR(uint8,AUTOMATIC)   cntrErr_u8;          /* value of error counter (0..7) */
      VAR(uint8,AUTOMATIC)   stMm_u8;             /* status bits of the monitoring module (bit coded) */
  } WdgIf_Rb_RequestType_tst;

#endif  /* WDGIF_TYPES_H */
