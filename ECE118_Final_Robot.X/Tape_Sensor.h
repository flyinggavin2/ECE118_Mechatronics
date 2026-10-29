/* 
 * File:   Tape_Sensor.h
 * Author: Jair Orellana
 * Brief: 
 * Created on May 15, 2026, 8:28 pm
 * Modified on <month> <day>, <year>, <hour> <pm/am>
 */

#ifndef ROBOT_H // Header guard
#define	ROBOT_H //

/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "BOARD.h" 
#include "IO_Ports.h"
#include <stdio.h>
#include <xc.h>

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/

#define TAPE_SENSOR_RIGHT PIN3
#define TAPE_SENSOR_CENTER PIN4
#define TAPE_SENSOR_LEFT PIN5



/**
 * @Function Robot_Init(uint8_t Tape_Select)
 * @param Tape_Select (Selects the Tape sensor from the #defines)
 * @return ERROR or SUCCESS
 * @brief Initializes the Tape Sensor that is chosen from #defines (RIGHT, CENTER, LEFT)
 * @author Jair Orellana
 */
char Tape_Sensor_Init(int8_t Tape_Select);

/**
 * @Function Tape_Sensor_Read(uint8_t Tape_Select)
 * @param Tape_Select (Select the Tape sensor from the #defines)
 * @return 0 or 1 for Off/On Tape
 * @brief Get the current reading of the tape sensor by entering one of the 
 *        #defines (RIGHT, CENTER, LEFT) in the parameter
 *        
 * @author Jair Orellana
 */
uint16_t Tape_Sensor_Read(int8_t Tape_Select);




#endif	/* LIBRARYTEMPLATE_H */ // End of header guard

