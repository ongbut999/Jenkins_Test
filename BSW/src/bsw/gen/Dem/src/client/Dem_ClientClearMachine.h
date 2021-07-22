

#ifndef DEM_CLIENTCLEARMACHINE_H
#define DEM_CLIENTCLEARMACHINE_H

#include "Dem_ClientHandlingTypes.h"
#include "Dem_ClientBaseHandling.h"
#include "Dem_Client.h"
#include "Dem_Types.h"
#include "Dem_Mapping.h"
#include "Dem_Nvm.h"
#include "Dem_Cfg_Clear.h"

/******************************************************************************************/
/****************  Machine States  ********************************************************/
#define DEM_CLEAR_DTC_MACHINE_STATE_IDLE            0x00u
#define DEM_CLEAR_DTC_MACHINE_STATE_EXEC            0x01u
#define DEM_CLEAR_DTC_MACHINE_STATE_WAITINGFORNVM   0x02u

typedef struct
{
  uint8                           activeClient;
  uint8                           machine_state;
  /* Boolean variable to indicate the clear is requested newly and the iterators has to be initialized */
  boolean                         IsNewClearRequest;
  /* Boolean variable to indicate the limit to procees the events per cycle has reached */
  boolean                         IsClearInterrupted;
  /* Variable to indicate the no of events cleared in a cycle */
  uint16                          NumberOfEventsProcessed;
  /* Iterators */
  Dem_DtcIdListIterator           DtcIt;
  Dem_EventIdIterator             EvtIt;
  Dem_EventIdListIterator         EvtListIt;
#if(DEM_CFG_J1939DCM_CLEAR_SUPPORT != DEM_CFG_J1939DCM_OFF)
  Dem_DtcIdListIterator2          DtcIt2;
#endif
} Dem_ClientClearMachineType;

#define DEM_START_SEC_RAM_CLEARED
#include "Dem_Cfg_MemMap.h"

extern Dem_ClientClearMachineType Dem_ClientClearMachine;

#define DEM_STOP_SEC_RAM_CLEARED
#include "Dem_Cfg_MemMap.h"

#define DEM_START_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

/**************************************************************************************************/
/****************  Dem_ClientClearMachine  *************************************************************/

DEM_INLINE void Dem_ClientClearMachine_SetMachineActiveClient(Dem_ClientIdType ClientId)
{
    Dem_ClientClearMachine.activeClient = ClientId;
}

DEM_INLINE boolean Dem_ClientClearMachine_isProcessingClient(Dem_ClientIdType ClientId)
{
    return (Dem_ClientClearMachine.activeClient == ClientId);
}

DEM_INLINE uint8 Dem_ClientClearMachine_GetMachineActiveClient(void)
{
    return Dem_ClientClearMachine.activeClient;
}

DEM_INLINE void Dem_ClientClearMachine_SetMachineState(uint8 state)
{
    Dem_ClientClearMachine.machine_state = state;
}

DEM_INLINE uint8 Dem_ClientClearMachine_GetMachineState(void)
{
    return Dem_ClientClearMachine.machine_state;
}

DEM_INLINE boolean Dem_ClientClearMachine_isClearDtcGroupAllDtcsSelected(Dem_ClientIdType ClientId)
{
boolean status = TRUE;
#if(DEM_CFG_J1939DCM != DEM_CFG_J1939DCM_OFF)
if (ClientId != DEM_CLIENTID_J1939)
#endif
{
    if ((Dem_LibGetParamUI8(DEM_CFG_CLEAR_DTC_LIMITATION)
            == Dem_LibGetParamUI8(DEM_CFG_CLEAR_DTC_LIMITATION_ONLY_CLEAR_ALL_DTCS))
            && (Dem_ClientSelectionType_getTypeOfSelection(Dem_Clients[ClientId].selection)
                    != DEM_CLIENT_SELECTION_TYPE_ALL_DTCS))
    {
        Dem_ClientResultType_setResult(&Dem_Clients[ClientId].result, Dem_Clients[ClientId].request, DEM_WRONG_DTC);
        status = FALSE;
    }
}
return status;
}

DEM_INLINE void Dem_ClientClearMachine_SetClientRequest(Dem_ClientIdType ClientId, uint8 state)
{
if (Dem_ClientClearMachine_isClearDtcGroupAllDtcsSelected(ClientId))
{
    if (state == DEM_CLEAR_DTC_MACHINE_STATE_IDLE)
    {
        Dem_ClientSelectionType_invalidateSelectionResult(&Dem_Client_getClient(ClientId)->selection);
        Dem_ClientClearMachine_SetMachineActiveClient(DEM_CLIENTID_INVALID);
        Dem_ClientClearMachine_SetMachineState(state);
    }
    else if (state == DEM_CLEAR_DTC_MACHINE_STATE_EXEC)
    {
        Dem_ClientClearMachine.IsNewClearRequest = TRUE;
        Dem_ClientClearMachine_SetMachineActiveClient(ClientId);
        Dem_NvMStartClear();
        Dem_ClientClearMachine_SetMachineState(state);
    }
    else if (state == DEM_CLEAR_DTC_MACHINE_STATE_WAITINGFORNVM)
    {
        Dem_ClientClearMachine_SetMachineState(state);
    }
    else
    {
        /* Comment to avoid MISRA warning for Empty else statement */
    }
}
}

#define DEM_STOP_SEC_ROM_CODE
#include "Dem_Cfg_MemMap.h"

#endif
