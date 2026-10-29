/* 
 * File:   filename.h
 * Author: Jair Orellana
 * Brief: 
 * Created on May 20, 2026, 10:48 am
 * Modified on <month> <day>, <year>, <hour> <pm/am>
 */

#ifndef TRACKWIRE_SENSOR_H // Header guard
#define	TRACKWIRE_SENSOR_H //

/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "BOARD.h" 
#include "AD.h"

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define TRACKWIRE_LEFT_PIN AD_PORTV4
#define TRACKWIRE_RIGHT_PIN AD_PORTV6

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
uint8_t Trackwire_Init(void);

unsigned int Trackwire_GetValue(unsigned int pin) ;



#endif	/* LIBRARYTEMPLATE_H */ // End of header guard

