/* 
 * File:   LibraryTemplate.c
 * Author: <Your Name>
 * Brief: 
 * Created on <month> <day>, <year>, <hour> <pm/am>
 * Modified on <month> <day>, <year>, <hour> <pm/am>
 */

/*******************************************************************************
 * #INCLUDES                                                                   *
 ******************************************************************************/

#include "Trackwire_Sensor.h" // The header file for this source file. 
#include "BOARD.h"
#include "AD.h"
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



uint8_t Trackwire_Init(void) {
    AD_Init();
    return ((AD_AddPins(TRACKWIRE_LEFT_PIN) == SUCCESS) &&
            (AD_AddPins(TRACKWIRE_RIGHT_PIN) == SUCCESS)) ? SUCCESS : ERROR;
}

unsigned int Trackwire_GetValue(unsigned int pin) {
    if(AD_IsNewDataReady) {
        return AD_ReadADPin(pin);
    }
   
}
    
#define TRACKWIRE_TEST_HARNESS
#ifdef TRACKWIRE_TEST_HARNESS


void main(void) {
    BOARD_Init();
    Trackwire_Init();

    while(1) {
        uint16_t Read_Left = Trackwire_GetValue(TRACKWIRE_LEFT_PIN); 
        uint16_t Read_Right = Trackwire_GetValue(TRACKWIRE_RIGHT_PIN); 
        
        printf("\r\nLeft: %u  Right: %u", Read_Left, Read_Right);
        for(int i = 0; i < 100000; i++) {
            asm("nop");
        }
        
    }

}


#endif


