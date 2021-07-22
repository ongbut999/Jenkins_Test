#include "rba_BswSrv.h"
#include "Fls.h"

/**
 *********************************************************************
 * Fee_Fls_SyncRead(): Service for synchronous data read
 *
 * This function performed synchronous read data from Data Flash.
 * Below is a template implementation. Integrators shall
 * implement this function in order to match with the target MCAL.
 *
 * \param    SourceAddress:     Relative address of the data to be read in flash memory.
 * 								This address offset will be added to the flash memory base address.
 * \param    TargetAddressPtr:  Pointer to target data buffer.
 * \param    Length:            Length in bytes to be read from Data Flash memory.
 * \return   Function success
 * \retval   E_OK:              Read command has been accepted.
 * \retval   E_NOT_OK:          Read command has not been accepted.
 * \seealso
 * \usedresources
 *********************************************************************
 */

Std_ReturnType Fee_Fls_SyncRead(Fls_AddressType SourceAddress,
                                uint8* TargetAddressPtr,
								uint32 Length
                               )
{

    Std_ReturnType RetVal = E_OK;

    if(TargetAddressPtr == NULL_PTR)
    {
        RetVal = E_NOT_OK;
    }else{
        rba_BswSrv_MemCopy8(TargetAddressPtr, FLS_BASE_ADDRESS + SourceAddress, Length);
    }

    return RetVal;
}
