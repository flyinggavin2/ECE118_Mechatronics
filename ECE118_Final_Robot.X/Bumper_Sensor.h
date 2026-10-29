/* 
 * File:   Bumper_Sensor.h
 * Author: Gavin Wang
 * Brief: 
 * Created on May 18, 2026, 2:49 pm
 * Modified on <month> <day>, <year>, <hour> <pm/am>
 */

#ifndef BUMPER_SENSOR_H // Header guard
#define	BUMPER_SENSOR_H //

/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "BOARD.h" 
#include "IO_Ports.h"


/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define BUMPER_LEFT_PIN PIN6
#define BUMPER_RIGHT_PIN PIN8

#define BUMPER_PORT PORTX

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

/**
 * @Function someFunction(void)
 * @param foo, some value
 * @return TRUE or FALSE
 * @brief 
 * @note 
 * @author <Your Name>,
 * @modified <Your Name>, <year>.<month>.<day> <hour> <pm/am> */
uint8_t Bumper_Init(void);

uint16_t Bumper_Read(int16_t Bumper_Select);





#endif	/* BUMPER_SENSOR_H */ // End of header guard

