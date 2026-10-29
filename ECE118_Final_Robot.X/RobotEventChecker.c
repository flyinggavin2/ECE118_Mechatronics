/*
 * File:   TemplateEventChecker.c
 * Author: Jair + Gavin
 *
 * Template file to set up typical EventCheckers for the  Events and Services
 * Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the
 * names will have to be changed to match your code.
 *
 * This EventCheckers file will work with both FSM's and HSM's.
 *
 * Remember that EventCheckers should only return TRUE when an event has occured,
 * and that the event is a TRANSITION between two detectable differences. They
 * should also be atomic and run as fast as possible for good results.
 *
 * This file includes a test harness that will run the event detectors listed in the
 * ES_Configure file in the project, and will conditionally compile main if the macro
 * EVENTCHECKER_TEST is defined (either in the project or in the file). This will allow
 * you to check you event detectors in their own project, and then leave them untouched
 * for your project unless you need to alter their post functions.
 *
 * Created on September 27, 2013, 8:37 AM
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "RobotEventChecker.h"
#include "ES_Events.h"
#include "serial.h"
#include "AD.h"
#include "Tape_Sensor.h"
#include "Bumper_Sensor.h"
#include "Trackwire_Sensor.h"
#include "Beacon_Detector.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define BATTERY_DISCONNECT_THRESHOLD 175
#define OFF_TAPE_OUTPUT 0
#define ON_TAPE_OUTPUT 1
/*BUMPER HIT CODES*/
#define BL_CODE 0x01
#define BR_CODE 0x02
#define BOTH_HIT_CODE 0x03
/*TRACKWIRE THRESHOLDS AND CODES*/
#define RTW_DETECTED_HIGH_THRESHOLD 590 // RTW = Right Trackwire
#define RTW_DETECTED_LOW_THRESHOLD 575 
#define LTW_DETECTED_HIGH_THRESHOLD 600 // LTW = Left Trackwire
#define LTW_DETECTED_LOW_THRESHOLD 520
#define RTW_CODE 0x01
#define LTW_CODE 0x02


#define NUM_BUMPERS 2
#define DEBOUNCE_SAMPLES 4

typedef struct {
    uint8_t history; // packed last 8 readings (we only use 3-4 bits)
    uint8_t stableState; // 0 = not pressed, 1 = pressed
} DebouncedBumper_t;

static DebouncedBumper_t Bumpers[NUM_BUMPERS] = {0}; //default all members to 0 

static uint8_t lastBothState = 0;


/*******************************************************************************
 * EVENTCHECKER_TEST SPECIFIC CODE                                             *
 ******************************************************************************/

//#define EVENTCHECKER_TEST
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
#define SaveEvent(x) do {eventName=__func__; storedEvent=x;} while (0)

static const char *eventName;
static ES_Event storedEvent;
#endif

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this EventChecker. They should be functions
   relevant to the behavior of this particular event checker */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                    *
 ******************************************************************************/

/* Any private module level variable that you might need for keeping track of
   events would be placed here. Private variables should be STATIC so that they
   are limited in scope to this module. */

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function TemplateCheckBattery(void)
 * @param none
 * @return TRUE or FALSE
 * @brief This function is a prototype event checker that checks the battery voltage
 *        against a fixed threshold (#defined in the .c file). Note that you need to
 *        keep track of previous history, and that the actual battery voltage is checked
 *        only once at the beginning of the function. The function will post an event
 *        of either BATTERY_CONNECTED or BATTERY_DISCONNECTED if the power switch is turned
 *        on or off with the USB cord plugged into the Uno32. Returns TRUE if there was an 
 *        event, FALSE otherwise.
 * @note Use this code as a template for your other event checkers, and modify as necessary.
 * @author Gabriel H Elkaim, 2013.09.27 09:18
 * @modified Gabriel H Elkaim/Max Dunne, 2016.09.12 20:08 */
uint8_t CheckBattery(void) {
    static ES_EventTyp_t lastEvent = BATTERY_DISCONNECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    uint16_t batVoltage = AD_ReadADPin(BAT_VOLTAGE); // read the battery voltage

    if (batVoltage > BATTERY_DISCONNECT_THRESHOLD) { // is battery connected?
        curEvent = BATTERY_CONNECTED;
    } else {
        curEvent = BATTERY_DISCONNECTED;
    }
    if (curEvent != lastEvent) { // check for change from last time
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = batVoltage;
        returnVal = TRUE;
        lastEvent = curEvent; // update history
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        //PostTopHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif   
    }
    return (returnVal);
}

uint8_t CheckRightTapeSensor(void) {
    static ES_EventTyp_t lastEvent = RTS_OFF_TAPE;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    uint16_t RTS_Reading = Tape_Sensor_Read(TAPE_SENSOR_RIGHT);
    
    if(RTS_Reading == 1) {
        curEvent = RTS_ON_TAPE;
    } else {
        curEvent = RTS_OFF_TAPE;
    }
    
    if(curEvent != lastEvent) {
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = RTS_Reading;
        returnVal = TRUE;
        lastEvent = curEvent;
        
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        PostTopHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif 
    }
    
    return returnVal;
    
}

uint8_t CheckCenterTapeSensor(void) {
    static ES_EventTyp_t lastEvent = CTS_OFF_TAPE;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    uint16_t CTS_Reading = Tape_Sensor_Read(TAPE_SENSOR_CENTER);
    
    if(CTS_Reading == 1) {
        curEvent = CTS_ON_TAPE;
    } else {
        curEvent = CTS_OFF_TAPE;
    }
    
    if(curEvent != lastEvent) {
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = CTS_Reading;
        returnVal = TRUE;
        lastEvent = curEvent;
        
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        PostTopHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif 
    }
    
    return returnVal;
    
}

uint8_t CheckLeftTapeSensor(void) {
    static ES_EventTyp_t lastEvent = LTS_OFF_TAPE;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    uint16_t LTS_Reading = Tape_Sensor_Read(TAPE_SENSOR_LEFT);
    
    if(LTS_Reading == 1) {
        curEvent = LTS_ON_TAPE;
    } else {
        curEvent = LTS_OFF_TAPE;
    }
    
    if(curEvent != lastEvent) {
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = LTS_Reading;
        returnVal = TRUE;
        lastEvent = curEvent;
        
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        PostTopHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif 
    }
    
    return returnVal;
    
}

// ================== BUMPERS =======================

uint8_t CheckBumpers(void){
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    uint8_t raw[NUM_BUMPERS];
    
    raw[0] = Bumper_Read(BUMPER_LEFT_PIN); //i = 0
    raw[1] = Bumper_Read(BUMPER_RIGHT_PIN); //i = 1
    
    const ES_EventTyp_t pressEvents[NUM_BUMPERS] = {
        LEFT_BUMPER_PRESSED, //i = 0
        RIGHT_BUMPER_PRESSED //i = 1 
    };

    const ES_EventTyp_t releaseEvents[NUM_BUMPERS] = {
        LEFT_BUMPER_RELEASED,
        RIGHT_BUMPER_RELEASED
    };
    
    // ---- Debounce ---
    
    for (int i = 0; i < NUM_BUMPERS; i++) //record and check data twice for each bumper
    {
        //records and shifts 1 value to hisotry and masks it to 3 bits 
        Bumpers[i].history = ((Bumpers[i].history << 1) | raw[i]) & ((1 << DEBOUNCE_SAMPLES) - 1);
        
        // ----- PRESSED DETECTED (when fro 000 --> 111 -----
        if(Bumpers[i].history == ((1<<DEBOUNCE_SAMPLES)-1) && Bumpers[i].stableState == 0)
        {
            Bumpers[i].stableState = 1; //mark as stable ON
             
            thisEvent.EventType = pressEvents[i];
            thisEvent.EventParam = 0;
            returnVal = TRUE; 

#ifndef EVENTCHECKER_TEST
        PostTopHSM(thisEvent);
#else
            SaveEvent(thisEvent);
#endif
            
        }
        
        // ---- RELEASE DETECTED -----
        else if (Bumpers[i].history == 0 && Bumpers[i].stableState == 1)
        {
            Bumpers[i].stableState = 0;

            thisEvent.EventType = releaseEvents[i];
            thisEvent.EventParam = 0;
            returnVal = TRUE;
            
#ifndef EVENTCHECKER_TEST
        PostTopHSM(thisEvent);
#else
            SaveEvent(thisEvent);
#endif
        }
        
        
    }
    
    // ---- BOTH BUMPERS PRESSED EVENT ----
    if (Bumpers[0].stableState == 1 && Bumpers[1].stableState == 1)
    {
        if (lastBothState == 0)   // transition into both pressed
        {
            lastBothState = 1;
            thisEvent.EventType = BOTH_BUMPERS_PRESSED;
            thisEvent.EventParam = 0;
            returnVal = TRUE;
            
#ifndef EVENTCHECKER_TEST
        PostTopHSM(thisEvent);
#else
            SaveEvent(thisEvent);
#endif            
        }
              
    }
    else 
    {
       lastBothState = 0;
    }
    
    return returnVal;
    
    
    
}
//uint8_t CheckBumper(void) {
//    static ES_EventTyp_t lastEvent = BUMPER_RELEASED;
//    ES_EventTyp_t curEvent;
//    ES_Event thisEvent;
//    uint8_t returnVal = FALSE;
//    uint16_t Right_Bumper = Bumper_Read(BUMPER_RIGHT_PIN);
//    uint16_t Left_Bumper = Bumper_Read(BUMPER_LEFT_PIN);
//    
//    if(Right_Bumper == 1 || Left_Bumper == 1) {
//        curEvent = BUMPER_HIT;
//    } else {
//        curEvent = BUMPER_RELEASED;
//    }
//
//    if (curEvent != lastEvent) { // check for change from last time
//        thisEvent.EventType = curEvent;
//        //thisEvent.EventParam = Right_Bumper;
//        if(Right_Bumper & !Left_Bumper) {
//            thisEvent.EventParam = BR_CODE;
//        } else if(!Right_Bumper & Left_Bumper) {
//            thisEvent.EventParam = BL_CODE;
//        } else {
//            thisEvent.EventParam = BOTH_HIT_CODE;
//        }
//        returnVal = TRUE;
//        lastEvent = curEvent; // update history
//#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
//        //PostGenericService(thisEvent);
//#else
//        SaveEvent(thisEvent);
//#endif   
//    }
//    return (returnVal);
//}

uint8_t CheckTrackwire(void) {
    static ES_EventTyp_t lastEvent = OFF_TRACKWIRE;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    uint16_t Right_Trackwire = Trackwire_GetValue(TRACKWIRE_RIGHT_PIN);
    uint16_t Left_Trackwire = Trackwire_GetValue(TRACKWIRE_LEFT_PIN);
    
    if(Right_Trackwire > RTW_DETECTED_HIGH_THRESHOLD) {
        curEvent = ON_TRACKWIRE;
    } else {
        curEvent = OFF_TRACKWIRE;
    }
//    else if(Right_Trackwire < RTW_DETECTED_LOW_THRESHOLD) {
//        curEvent = OFF_TRACKWIRE;
//        
//    }

    if (curEvent != lastEvent) { // check for change from last time
        thisEvent.EventType = curEvent;
        if(Right_Trackwire > RTW_DETECTED_HIGH_THRESHOLD) {
            thisEvent.EventParam = Left_Trackwire;
        } 
//        else if(Left_Trackwire  > LTW_DETECTED_HIGH_THRESHOLD) {
//            thisEvent.EventParam = Left_Trackwire;
//        } 
        returnVal = TRUE;
        lastEvent = curEvent; // update history
#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
        PostTopHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif   
    }
    return (returnVal);
}

uint8_t CheckBeaconDetector(void)
{
    static ES_EventTyp_t lastEvent = BEACON_LOST;

    ES_EventTyp_t curEvent;
    ES_Event thisEvent;

    uint8_t returnVal = FALSE;

    uint8_t beaconDetected = Beacon_Detected();

    if (beaconDetected == TRUE) {
        curEvent = BEACON_DETECTED;
    } else {
        curEvent = BEACON_LOST;
    }

    // transition detected
    if (curEvent != lastEvent) {

        thisEvent.EventType = curEvent;

        // optional: store raw ADC value
        thisEvent.EventParam = Beacon_ReadRaw();

        returnVal = TRUE;

        lastEvent = curEvent;

#ifndef EVENTCHECKER_TEST
        PostTopHSM(thisEvent);
#else
        SaveEvent(thisEvent);
#endif
    }

    return returnVal;
}







//uint8_t CheckTapeSensors(void) {
//    static ES_EventTyp_t lastEvent = OFF_TAPE;
//    ES_EventTyp_t curEvent;
//    ES_Event thisEvent;
//    uint8_t returnVal = FALSE;
//    uint16_t LTS_Reading = Tape_Sensor_Read(TAPE_SENSOR_LEFT);
//    uint16_t CTS_Reading = Tape_Sensor_Read(TAPE_SENSOR_CENTER);
//    uint16_t RTS_Reading = Tape_Sensor_Read(TAPE_SENSOR_RIGHT);
//    
//    if(LTS_Reading == 1 || CTS_Reading) {
//        curEvent = LTS_ON_TAPE;
//    } else {
//        curEvent = LTS_OFF_TAPE;
//    }
//    
//    if(curEvent != lastEvent) {
//        thisEvent.EventType = curEvent;
//        thisEvent.EventParam = LTS_Reading;
//        returnVal = TRUE;
//        lastEvent = curEvent;
//        
//#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
////PostGenericService(thisEvent);
//#else
//        SaveEvent(thisEvent);
//#endif 
//    }
//    
//    return returnVal;
//    
//}



/* 
 * The Test Harness for the event checkers is conditionally compiled using
 * the EVENTCHECKER_TEST macro (defined either in the file or at the project level).
 * No other main() can exist within the project.
 * 
 * It requires a valid ES_Configure.h file in the project with the correct events in 
 * the enum, and the correct list of event checkers in the EVENT_CHECK_LIST.
 * 
 * The test harness will run each of your event detectors identically to the way the
 * ES_Framework will call them, and if an event is detected it will print out the function
 * name, event, and event parameter. Use this to test your event checking code and
 * ensure that it is fully functional.
 * 
 * If you are locking up the output, most likely you are generating too many events.
 * Remember that events are detectable changes, not a state in itself.
 * 
 * Once you have fully tested your event checking code, you can leave it in its own
 * project and point to it from your other projects. If the EVENTCHECKER_TEST marco is
 * defined in the project, no changes are necessary for your event checkers to work
 * with your other projects.
 */

#ifdef EVENTCHECKER_TEST
#include <stdio.h>
static uint8_t(*EventList[])(void) = {EVENT_CHECK_LIST};

void PrintEvent(void);

void main(void) {
    BOARD_Init();
    /* user initialization code goes here */
    Tape_Sensor_Init(TAPE_SENSOR_RIGHT);
    Tape_Sensor_Init(TAPE_SENSOR_CENTER);
    Tape_Sensor_Init(TAPE_SENSOR_LEFT);
    Bumper_Init();
    Trackwire_Init();
    Beacon_Init();
    
    

    // Do not alter anything below this line
    int i;

    printf("\r\nEvent checking test harness for %s", __FILE__);

    while (1) {
        if (IsTransmitEmpty()) {
            for (i = 0; i< sizeof (EventList) >> 2; i++) {
                if (EventList[i]() == TRUE) {
                    PrintEvent();
//                    for(int i = 0; i < 3000; i++) {
//                        asm("nop");
//                    }
                    break;
                }

            }
        }
    }
}

void PrintEvent(void) {
    printf("\r\nFunc: %s\tEvent: %s\tParam: 0x%X", eventName,
            EventNames[storedEvent.EventType], storedEvent.EventParam);
    
    
}
#endif