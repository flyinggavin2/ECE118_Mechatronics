/* ************************************************************************** */
/** Gavin Wang

  @File Name
    Beacon_Detector.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef BEACON_DETECTOR_H    /* Guard against multiple inclusion */
#define BEACON_DETECTOR_H




/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "BOARD.h" 
#include "IO_Ports.h"
#include <stdio.h>
#include <xc.h>
#include "AD.h"

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/

// Change this depending on where your sensor is connected
#define BEACON_AD_PIN AD_PORTV3

// Default threshold
#define BEACON_THRESHOLD 325
#define BEACON_HIGH 0
#define BEACON_LOW 1023

/**
 * @Function Tape_Sensors_Init(uint8_t Tape_Select)
 * @param Tape_Select (Selects the Tape sensor from the #defines)
 * @return ERROR or SUCCESS
 * @brief Initializes the Tape Sensor that is chosen from #defines (RIGHT, CENTER, LEFT)
 * @author Jair Orellana
 */

/**
 * @Function Beacon_Init(void)
 * @param none
 * @return SUCCESS or ERROR
 * @brief Initializes the beacon detector ADC pin
 */
char Beacon_Init(void);

/**
 * @Function Beacon_ReadRaw(void)
 * @param none
 * @return raw 10-bit ADC value
 * @brief Reads raw beacon sensor value
 */
uint16_t Beacon_ReadRaw(void);

uint16_t Beacon_ReadFiltered(void);

/**
 * @Function Beacon_Detected(void)
 * @param none
 * @return TRUE if beacon detected
 * @brief Checks beacon against threshold
 */
uint8_t Beacon_Detected(void);

/**
 * @Function Beacon_SetThreshold(uint16_t threshold)
 * @param threshold
 * @return none
 * @brief Sets beacon detection threshold
 */
void Beacon_SetThreshold(uint16_t threshold);

/**
 * @Function Beacon_GetThreshold(void)
 * @param none
 * @return current threshold
 */
uint16_t Beacon_GetThreshold(void);


#endif
/* *****************************************************************************
 End of File
 */
