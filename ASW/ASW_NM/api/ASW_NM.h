/*
 * ASW_NM.h
 *
 *  Created on: Jun 24, 2019
 *      Author: AGT1HC
 */

#ifndef ASW_ASW_NM_API_ASW_NM_H_
#define ASW_NM_START_SEC_CODE

typedef struct {
    char flag;
    Nm_StateType nm_PreviousState;
    Nm_StateType nm_CurrentState;
    boolean IsNmReceived;
    boolean release_b;
    boolean request_b;
    char nm_rx_data[8];
    char nm_tx_data[8];
    char nmState;
    char nmMode;
    char NotReceiveNMCounter;
}Nm_Test_t;

extern uint8 shutdown_b;
extern uint8 test_com;


#define ASW_NM_STOP_SEC_CODE
#define ASW_ASW_NM_API_ASW_NM_H_



#endif /* ASW_ASW_NM_API_ASW_NM_H_ */
