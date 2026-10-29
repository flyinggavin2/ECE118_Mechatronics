/*
 * File: SetupSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 *
 * Template file to set up a Heirarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the names
 * will have to be changed to match your code.
 *
 * There is for a substate machine. Make sure it has a unique name
 *
 * This is provided as an example and a good place to start.
 *
 * History
 * When           Who     What/Why
 * -------------- ---     --------
 * 09/13/13 15:17 ghe      added tattletail functionality and recursive calls
 * 01/15/12 11:12 jec      revisions for Gen2 framework
 * 11/07/11 11:26 jec      made the queue static
 * 10/30/11 17:59 jec      fixed references to CurrentEvent in RunTemplateSM()
 * 10/23/11 18:20 jec      began conversion from SMTemplate.c (02/20/07 rev)
 */


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"

#include "ES_Framework.h"
#include "BOARD.h"
#include "TopHSM.h"
#include "SetupSubHSM.h"
#include "motors.h"
#include "Beacon_Detector.h"
#include "Tape_Sensor.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitPSubState,
    SpinSearch,
    BeaconFound,
    DriveToTape,
    TurningPerpendicular 
} ScanningSubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"SpinSearch",
	"BeaconFound",
	"DriveToTape",
};



/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static ScanningSubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;

static uint8_t beaconCount;

static uint8_t TurnDirection;
#define TURN_LEFT  0
#define TURN_RIGHT 1

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateSubHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitSetupSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunSetupSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @Function RunTemplateSubHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This function is where you implement the whole of the heirarchical state
 *        machine, as this is called any time a new event is passed to the event
 *        queue. This function will be called recursively to implement the correct
 *        order for a state transition to be: exit current state -> enter next state
 *        using the ES_EXIT and ES_ENTRY events.
 * @note Remember to rename to something appropriate.
 *       The lower level state machines are run first, to see if the event is dealt
 *       with there rather than at the current level. ES_EXIT and ES_ENTRY events are
 *       not consumed as these need to pass pack to the higher level state machine.
 * @author J. Edward Carryer, 2011.10.23 19:25
 * @author Gabriel H Elkaim, 2011.10.23 19:25 */
ES_Event RunSetupSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    ScanningSubHSMState_t nextState; // <- change type to correct enum

    //ES_Tattle(); // trace call stack

    switch (CurrentState) 
    {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                
                beaconCount = 0;

                // now put the machine into the actual initial state
                nextState = SpinSearch;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            break;

        case SpinSearch: 
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY: // Spin 360 and record strongest signal
                    printf("Spinning for beacon...\r\n");
                   
                    Motors_SetSpeed(250, -250); // start spinning
                    
                  
                    
                    ThisEvent.EventType = ES_NO_EVENT; //have parent clear it 
                    break;
                    
                    
                case BEACON_DETECTED: //localization algorithm
                    beaconCount++;
                    printf("beacon count +1: %u\r\n", beaconCount);
                    if (beaconCount == 1)
                    {
                        printf("Beacon detected!\r\n");
                        //Motors_SetSpeed(-350, -350);
                    
                    
                        nextState = BeaconFound;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                
                case ES_EXIT:
                case ES_NO_EVENT:
                default:
                    break;
            }
            break;
                    
                    
                    
        case BeaconFound:
            switch(ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("Beacon Found, backing up...\r\n");
                    Motors_SetSpeed(-350, -350);
                    ES_Timer_InitTimer(DRIVE_BACK_TIMER, 1000);
                    break;
                    
                case ES_TIMEOUT:
                    if(ThisEvent.EventParam == DRIVE_BACK_TIMER)
                    {
                        printf("Backup Done, driving up...\r\n");
                        
                        nextState = DriveToTape;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    break;
                case ES_EXIT:
                    printf("EXITING BEACON FOUND\r\n");
                    break;
                case ES_NO_EVENT:
                    break;
                default:
                    break;
            }
            break;
            
            
        case DriveToTape:
            switch(ThisEvent.EventType)
            {

                case ES_ENTRY:
                    printf("Driving to Tape\r\n");
                    Motors_SetSpeed(300, 300);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                //one sensor hit a corner, turn until the other sensor gets hit, now u are straight --> turn left
                case RTS_ON_TAPE:
                    printf("RTS HIT (perp)--> turning right \r\n");
                    Motors_SetSpeed(400, 0); //turn right by spin left motor 
                    TurnDirection = TURN_RIGHT;
                    
                    nextState = TurningPerpendicular;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    
                    break;
                    
                case LTS_ON_TAPE:
                    printf("LTS HIT (perp) --> turning left \r\n");
                    Motors_SetSpeed(0, 400);//turn left
                    TurnDirection = TURN_LEFT;
                    
                    nextState = TurningPerpendicular;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_EXIT:
                case ES_NO_EVENT:
                    break;
                
                default:
                    break;
            }
            break;
        
        case TurningPerpendicular:
            switch(ThisEvent.EventType)
            {
                case BEACON_DETECTED:
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_ENTRY:
                    if (TurnDirection == TURN_RIGHT) //check entry if we are pretty much already perp to tape
                    {
                        
                        Motors_SetSpeed(400, 0);
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
//                        if(Tape_Sensor_Read(TAPE_SENSOR_LEFT) == 1)
//                        {
//                            
//                            Motors_Stop();
//                            printf("left tape found\n\r");
//                            ThisEvent.EventType = HSM_ON_TAPE;
//                            break;
//                        }
//                        else
//                        {
//                            Motors_SetSpeed(300, 0);
//                            ThisEvent.EventType = ES_NO_EVENT;
//                            break;
//                        }
                        
                    }
                    else
                    {
                        Motors_SetSpeed(0, 400);
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
//                        if(Tape_Sensor_Read(TAPE_SENSOR_RIGHT) == 1)
//                        {
//                            Motors_Stop();
//                            printf("right tape found\n\r");
//                            ThisEvent.EventType = HSM_ON_TAPE;
//                            break;
//                        }
//                        else
//                        {
//                            Motors_SetSpeed(-200, 400);
//                            ThisEvent.EventType = ES_NO_EVENT;
//                            break;
//                        }
                    }
                    break;

                    
                    
                case RTS_ON_TAPE:
                    if (TurnDirection == TURN_LEFT)
                    {
                        Motors_Stop();
                        printf("Right tape found\n\r");
                        
                        //timer to ignore counter
                        ES_Timer_InitTimer(SETUP_COUNTER_IGNORE_TIMER, 1700); //--> set a flag for a timer
                        printf("===== CORNER TIMER STARTED =======\n\r");
                        
                        ThisEvent.EventType = HSM_ON_TAPE;
                        return ThisEvent;
                    }
                    break;
                    
                case LTS_ON_TAPE:
                    if (TurnDirection == TURN_RIGHT)
                    {
                        Motors_Stop();
                        printf("left tape found\n\r");
                        
                        
                        //timer to ignore counter
                        ES_Timer_InitTimer(SETUP_COUNTER_IGNORE_TIMER, 1700); //--> set a flag for a timer
                        printf("===== CORNER TIMER STARTED =======\n\r");
                        
                        ThisEvent.EventType = HSM_ON_TAPE;
                        return ThisEvent;
                    }
                    break;

                case ES_EXIT:
                case ES_NO_EVENT:
                    break;
                
                default:
                    break;
                
            }
            break;
            
        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunSetupSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunSetupSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}
    


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

