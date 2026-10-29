/* ************************************************************************** */
/** Gavin Wang
  @File Name
    Beacon_Detector.c
  @Summary
    Brief description of the file.
  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "Beacon_Detector.h"
#include "BOARD.h"
#include "serial.h"
#include "AD.h"

#include "IO_Ports.h"
#include <stdint.h>
#include <stdio.h>


/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
#define BEACON_FILTER_SIZE 10


/******************************************************************************
 * Private Variables
 *****************************************************************************/

static uint16_t BeaconThreshold = BEACON_THRESHOLD;
static uint16_t BeaconSamples[BEACON_FILTER_SIZE];
static uint32_t BeaconSum = 0;
static uint8_t BeaconIndex = 0;
static uint8_t FilterInitialized = FALSE;
/******************************************************************************
 * Public Functions
 *****************************************************************************/

char Beacon_Init(void)
{
    // Enable beacon ADC pin
    if (AD_AddPins(BEACON_AD_PIN) == ERROR) {
        return ERROR;
    }

    return SUCCESS;
}

uint16_t Beacon_ReadRaw(void)
{
    return AD_ReadADPin(BEACON_AD_PIN);
}


uint16_t Beacon_ReadFiltered(void)
{
    uint16_t newSample;

    newSample = Beacon_ReadRaw();

    // initialize filter buffer first time
    if (FilterInitialized == FALSE) {

        for (int i = 0; i < BEACON_FILTER_SIZE; i++) {
            BeaconSamples[i] = newSample;
            BeaconSum += newSample;
        }

        FilterInitialized = TRUE;
    }

    // subtract oldest sample
    BeaconSum -= BeaconSamples[BeaconIndex];

    // store new sample
    BeaconSamples[BeaconIndex] = newSample;

    // add new sample
    BeaconSum += newSample;

    // increment circular index
    BeaconIndex++;

    if (BeaconIndex >= BEACON_FILTER_SIZE) {
        BeaconIndex = 0;
    }

    // return average
    return (uint16_t)(BeaconSum / BEACON_FILTER_SIZE);
}

uint8_t Beacon_Detected(void)
{
    uint16_t value;

    value =  Beacon_ReadFiltered();

    if (value < BeaconThreshold) {
        return TRUE;
    }

    return FALSE;
}

void Beacon_SetThreshold(uint16_t threshold)
{
    BeaconThreshold = threshold;
}

uint16_t Beacon_GetThreshold(void)
{
    return BeaconThreshold;
}


//#define BEACON_TEST_HARNESS
#ifdef BEACON_TEST_HARNESS

void main(void) 
{
    BOARD_Init();
    //AD_Init();
    printf("Init: %d\r\n", Beacon_Init());

    while (1) 
    {
        uint16_t raw =  Beacon_ReadRaw();
        uint16_t val =  Beacon_ReadFiltered();
        printf("Filtered: %u\r  Raw:%u\n", val, raw);
//        if (Beacon_Detected()) {
//            printf("BEACON DETECTED\r\n");
//        }
        for(int i = 0; i < 100000; i++) {
            asm("nop");
        }

    }
}




#endif //BEACON_TEST_HARNESS
/* *****************************************************************************
 End of File
 */
