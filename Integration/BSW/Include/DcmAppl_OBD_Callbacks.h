/*
 * This is a template file. It defines integration functions necessary to complete RTA-BSW.
 * The integrator must complete the templates before deploying software containing functions defined in this file.
 * Once templates have been completed, the integrator should delete the #error line.
 * Note: The integrator is responsible for updates made to this file.
 *
 * To remove the following error define the macro NOT_READY_FOR_TESTING_OR_DEPLOYMENT with a compiler option (e.g. -D NOT_READY_FOR_TESTING_OR_DEPLOYMENT)
 * The removal of the error only allows the user to proceed with the building phase
 */

#ifndef RBA_OBD_CALLBACK_H
#define RBA_OBD_CALLBACK_H

#if (DEM_CFG_OBD != DEM_CFG_OBD_OFF)
#include "rba_DemObdBasic_Types.h"

#define DEM_START_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

/**
 * @ingroup DEM_H
 *
 * Dem319: Service to report the value of PID $21 - Distance Traveled While MIL is Activated (2 bytes) - computed by the Dem.
 *
 * @param [out] PID21value Buffer containing the contents of PID $21 computed by the Dem.
 *                         The buffer is provided by the Dcm with the appropriate size, i.e.
 *                         during configuration, the Dcm identifies the required size from the
 *                         largest PID in order to configure a PIDBuffer.
 *
 * @return  E_NOT_OK is returned when MASTER ECU OBD support is not enabled in Dem. Otherwise, E_OK is returned.
 */
extern Std_ReturnType Dem_DcmReadDataOfPID21 (uint8* PID21value);

/**
 * @ingroup DEM_H
 *
 * Dem321: Service to report the value of PID $31 - Distance traveled since DTCs cleared (2 bytes) - computed by the Dem.
 *
 * @param [out] PID31value Buffer containing the contents of PID $31 computed by the Dem.
 *                         The buffer is provided by the Dcm with the appropriate size, i.e.
 *                         during configuration, the Dcm identifies the required size from the
 *                         largest PID in order to configure a PIDBuffer.
 *
 * @return  E_NOT_OK is returned when MASTER ECU OBD support is not enabled in Dem. Otherwise, E_OK is returned.
 */
extern Std_ReturnType Dem_DcmReadDataOfPID31 (uint8* PID31value);

/**
 * @ingroup DEM_H
 *
 * Dem323: Service to report the value of PID $4D - Engine run time while MIL is activated (2 bytes) - computed by the Dem.
 *
 * @param [out] PID4Dvalue Buffer containing the contents of PID $4D computed by the Dem.
 *                         The buffer is provided by the Dcm with the appropriate size, i.e.
 *                         during configuration, the Dcm identifies the required size from the
 *                         largest PID in order to configure a PIDBuffer.
 *
 * @return  E_NOT_OK is returned when MASTER ECU OBD support is not enabled in Dem. Otherwise, E_OK is returned.
 */
extern Std_ReturnType Dem_DcmReadDataOfPID4D (uint8* PID4Dvalue);


/**
 * @ingroup DEM_H
 *
 * Dem324: Service to report the value of PID $4E - Engine run time since DTCs cleared (2 bytes) - computed by the Dem.
 *
 * @param [out] PID4Evalue Buffer containing the contents of PID $4E computed by the Dem.
 *                         The buffer is provided by the Dcm with the appropriate size, i.e.
 *                         during configuration, the Dcm identifies the required size from the
 *                         largest PID in order to configure a PIDBuffer.
 *
 * @return  E_NOT_OK is returned when MASTER ECU OBD support is not enabled in Dem. Otherwise, E_OK is returned.
 */
extern Std_ReturnType Dem_DcmReadDataOfPID4E (uint8* PID4Evalue);

#define DEM_STOP_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

#endif

#endif