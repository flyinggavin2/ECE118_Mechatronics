/* 
 * File:   Tape_Sensor.c
 * Author: Jair Orellana
 * Brief: 
 * Created on May 15, 2026, 8:28 pm
 * Modified on <month> <day>, <year>, <hour> <pm/am>
 */

/*******************************************************************************
 * #INCLUDES                                                                   *
 ******************************************************************************/

#include "Tape_Sensor.h" // The header file for this source file.
#include "BOARD.h"
#include "serial.h"

#include "IO_Ports.h"
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
#define TAPE_SENSOR_PORTS PORTX

/*******************************************************************************
 * PRIVATE TYPEDEFS                                                            *
 ******************************************************************************/

/*******************************************************************************
 * PRIVATE FUNCTIONS PROTOTYPES                                                 *
 ******************************************************************************/

/*******************************************************************************
 * PUBLIC FUNCTION IMPLEMENTATIONS                                             *
 ******************************************************************************/

/*******************************************************************************
 * PRIVATE FUNCTION IMPLEMENTATIONS                                            *
 ******************************************************************************/



char Tape_Sensor_Init(int8_t Tape_Select){
    
    if(IO_PortsSetPortInputs(TAPE_SENSOR_PORTS, Tape_Select) == SUCCESS){
        return SUCCESS;
    }
    
    return ERROR;
    
}


uint16_t Tape_Sensor_Read(int8_t Tape_Select) {
    if((IO_PortsReadPort(TAPE_SENSOR_PORTS) & Tape_Select) != 0) return 1;
    return 0;
}

//#define TAPE_SENSOR_TEST_HARNESS
#ifdef TAPE_SENSOR_TEST_HARNESS

void main(void) {
    BOARD_Init();

    Tape_Sensor_Init(TAPE_SENSOR_RIGHT);
    Tape_Sensor_Init(TAPE_SENSOR_CENTER);
    Tape_Sensor_Init(TAPE_SENSOR_LEFT);
    //printf("Hello World\n");
    while(1) {
        uint16_t Read_Left = Tape_Sensor_Read(TAPE_SENSOR_LEFT); //Output 64
        uint16_t Read_Right = Tape_Sensor_Read(TAPE_SENSOR_RIGHT); //Output 16
        uint16_t Read_Center = Tape_Sensor_Read(TAPE_SENSOR_CENTER); //Output 32
        
        printf("\r\nLeft: %d  Center: %d  Right: %d", Read_Left, Read_Center, Read_Right);
        for(int i = 0; i < 100000; i++) {
            asm("nop");
        }
        
    }
}




#endif
