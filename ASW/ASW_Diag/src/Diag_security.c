
#include "Std_Types.h"
#include "rte_Type.h"
#include "rte.h"
#include "Dcm_Lcfg_DspUds.h"

#define SWC_COMPARE_KEY_FAILED 11


const uint8 DcmSeed[8] =
{
	0x11,0x11,
	0x22,0x22,
	0x33,0x33,
	0x44,0x44

};

/* Key values for Service 0x27 */

const uint8 DcmKey[8] =
{
	0x10, 0x10,
	0x20, 0x20,
	0x30, 0x30,
	0x40, 0x40

};

FUNC(Std_ReturnType, DCM_APPL_CODE) CompareKey(VAR(uint32,AUTOMATIC) KeyLen_32,P2VAR(uint8,AUTOMATIC,DCM_INTERN_CONST) Key,VAR(Dcm_OpStatusType, AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
{

	Std_ReturnType retValue = RTE_E_OK;

	if ( ( Key[ 0 ] != DcmKey[ 0 ] ) || ( Key[ 1 ] != DcmKey[ 1 ] )||( Key[ 2 ] != DcmKey[ 2 ] ) || ( Key[ 3 ] != DcmKey[ 3 ] ) )
	{
		retValue = SWC_COMPARE_KEY_FAILED;
	}
	else{ /* Do nothing. Key is correct. */ }

	return ( retValue );
}
FUNC(Std_ReturnType, DCM_APPL_CODE) GetSeed(VAR(Dcm_SecLevelType,AUTOMATIC) SecLevel_u8,VAR(uint32,AUTOMATIC) Seedlen_u32,VAR(uint32,AUTOMATIC) AccDataRecsize_u32,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) SecurityAccessDataRecord,P2VAR(uint8,AUTOMATIC,DCM_INTERN_DATA) Seed,VAR(Dcm_OpStatusType,AUTOMATIC) OpStatus,P2VAR(Dcm_NegativeResponseCodeType,AUTOMATIC,DCM_INTERN_DATA) ErrorCode)
		{
	Std_ReturnType retValue = RTE_E_OK;
	*Seed = DcmSeed[0];
	*(Seed+1) = DcmSeed[1];
	*(Seed+2) = DcmSeed[2];
	*(Seed+3) = DcmSeed[3];
	return (retValue);
}
