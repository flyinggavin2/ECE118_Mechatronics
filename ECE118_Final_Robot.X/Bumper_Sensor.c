/* 
 * File:   LibraryTemplate.c
 * Author: Gavin Wang
 * Brief: 
 * Created on <month> <day>, <year>, <hour> <pm/am>
 * Modified on <month> <day>, <year>, <hour> <pm/am>
 */

/*******************************************************************************
 * #INCLUDES                                                                   *
 ******************************************************************************/

#include "Bumper_Sensor.h" // The header file for this source file. 
#include "BOARD.h"
#include "IO_Ports.h"
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/


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



/**
 * @Function someFunction(void)
 * @param foo, some value
 * @return TRUE or FALSE
 * @brief 
 * @note 
 * @author <Your Name>
 * @modified <Your Name>, <year>.<month>.<day> <hour> <pm/am> */
uint8_t Bumper_Init(void) {
    return ((IO_PortsSetPortInputs(BUMPER_PORT, BUMPER_LEFT_PIN) == SUCCESS) &&
            (IO_PortsSetPortInputs(BUMPER_PORT, BUMPER_RIGHT_PIN) == SUCCESS)) ? SUCCESS : ERROR;
}

uint16_t Bumper_Read(int16_t Bumper_Select) {
    if((IO_PortsReadPort(BUMPER_PORT) & Bumper_Select) != 0) return 1;
    return 0;
}


//#define BUMPER_TEST_HARNESS //works need debouncing 
#ifdef BUMPER_TEST_HARNESS

void main(void) {
    BOARD_Init();
    Bumper_Init();

    while(1) {
        printf("RUNNING BUMPER.C TEST\n");
        uint16_t Read_Left = Bumper_Read(BUMPER_LEFT_PIN); 
        uint16_t Read_Right = Bumper_Read(BUMPER_RIGHT_PIN); 
        
        //rintf("Left: %u  Right: %u\n", Read_Left, Read_Right);
        
        if (Read_Right)
        {
            printf("HIT BUMPER RIGHT\n");
        }
        if (Read_Left)
        {
            printf("HIT BUMPER LEFT\n");
        }
       
        
        
    }

}



#endif

