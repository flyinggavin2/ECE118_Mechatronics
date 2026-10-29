/*
 * File: TemplateSubHSM.c
 * Author: J. Edward Carryer
 * Modified: Gabriel Elkaim and Soja-Marie Morgens
 *
 * Template file to set up a Heirarchical State Machine to work with the Events and
 * Services Framework (ES_Framework) on the Uno32 for the CMPE-118/L class. Note that
 * this file will need to be modified to fit your exact needs, and most of the names
 * will have to be changed to match your code.
 *
 * There is another template file for the SubHSM's that is slightly differet, and
 * should be used for all of the subordinate state machines (flat or heirarchical)
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

//HSM's
#include "TopHSM.h"
#include "SetupSubHSM.h" //#include all sub state machines called
#include "TapeFollowingSubHSM.h"
#include "ObstacleAvoidanceSubHSM.h"
#include "ShootingSubHSM.h"

//Motors and sensors 
#include "motors.h"
#include "Tape_Sensor.h"
#include "Bumper_Sensor.h"
#include "Trackwire_Sensor.h"
#include "Beacon_Detector.h"

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
//Include any defines you need to do

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/


typedef enum {
    InitPState,
    Ideal,        
    Setup,
    TapeFollowing,
    ObstacleAvoidance,
    Shooting
} TopHSMState_t;

static const char *StateNames[] = {
	"InitPState",
	"Ideal",
	"Setup",
	"TapeFollowing",
	"ObstacleAvoidance",
};


/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine
   Example: char RunAway(uint_8 seconds);*/
/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static TopHSMState_t CurrentState = InitPState; // <- change enum name to match ENUM
static uint8_t MyPriority;



uint8_t LeftTape = FALSE;
uint8_t RightTape = FALSE;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitTemplateHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunTemplateFSM function. Remember
 *        to rename this to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t InitTopHSM(uint8_t Priority)
{
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitPState;
    
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostTemplateHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Remember to rename to something appropriate.
 *        Returns TRUE if successful, FALSE otherwise
 * @author J. Edward Carryer, 2011.10.23 19:25 */
uint8_t PostTopHSM(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function RunTemplateHSM(ES_Event ThisEvent)
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
ES_Event RunTopHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    TopHSMState_t nextState; // <- change type to correct enum

    //ES_Tattle(); // trace call stack
    
    // usetimer to check for corners rather than on at same time
//    switch(ThisEvent.EventType)
//    {
//        case LTS_ON_TAPE:
//            LeftTape = TRUE;
//            printf("Left on TAPE\n\r");
//            
//            if (LeftTape && RightTape)
//            {
//                ThisEvent.EventType = HSM_AT_CORNER;
//            }
//            break;
//
//        case LTS_OFF_TAPE:
//            LeftTape = FALSE;
//            printf("Left off TAPE\n\r");
//            break;
//
//        case RTS_ON_TAPE:
//            RightTape = TRUE;
//            printf("Right on TAPE\n\r");
//            break;
//        
//        case RTS_OFF_TAPE:
//            RightTape = FALSE;
//            printf("Right off TAPE\n\r");
//            break;
//    }
    
    
    
    switch (CurrentState) 
    {
        case InitPState: // If current state is initial Pseudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // Initialize all sub-state machines for Setup 
                InitSetupSubHSM(); 
                InitTapeFollowingSubHSM();
                InitObstacleAvoidanceSubHSM();
                InitShootingSubHSM();
                
            
                // now put the machine into the actual initial state
                ES_Timer_InitTimer(TOPHSM_IDEAL_TIMER, 3000);
                
                nextState = Ideal;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
            
        case Ideal:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    Motors_Stop(); //stop all action from init
                    printf("Entered Ideal......\r\n");
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == TOPHSM_IDEAL_TIMER)
                    {
                        
                        //testing certain states: 
                        //nextState = Shooting;
                        nextState = Setup;
                        //nextState = TapeFollowing;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        
                    }
                    break;
                    
            }
            break;
            

        case Setup: // in the first state, replace this with correct names
            
            ThisEvent = RunSetupSubHSM(ThisEvent);
            
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("TOP HSM ENTERED: SETUP\r\n");
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case HSM_ON_TAPE:
                    
                    printf("TOP HSM EXITING: SETUP\r\n");
                    
                    nextState = TapeFollowing;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                            
                case ES_NO_EVENT:
                case ES_EXIT:
                default:
                    break;
            }
            break;
            
        
        case TapeFollowing:
            
            ThisEvent = RunTapeFollowingSubHSM(ThisEvent);
            
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    printf("TOP HSM: ENTERED TAPE FOLLOWING\r\n");
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case HSM_AT_ISZ:
                    printf("TOP HSM ----> going to shooting \r\n");
                    nextState = Shooting;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_EXIT:
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case LEFT_BUMPER_PRESSED:
                case RIGHT_BUMPER_PRESSED:
                    printf("BUMPER HIT, going to OA\n\r");
                    
                    Motors_SetSpeed(-350, -350); //back up
                    //ES_Timer_InitTimer(OA_BACKUP_TIMER, 350);//start timer in entry of OA
                    
                    nextState = ObstacleAvoidance;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    

                case ES_NO_EVENT:
                default:
                    break;
                
            }
            break;
            
        
        case ObstacleAvoidance:
            
            ThisEvent = RunObstacleAvoidanceSubHSM(ThisEvent);
            
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    printf("TOP HSM: ENTERED OBSTACLE AVOIDANCE\r\n");
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case HSM_ON_TAPE:
                   
                    
                    nextState = TapeFollowing;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_EXIT:
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;

                case ES_NO_EVENT:
                default:
                    break;
                
            }
            break;
            
            
        case Shooting:
            
            ThisEvent = RunShootingSubHSM(ThisEvent);
            
            switch (ThisEvent.EventType) 
            {

                case ES_ENTRY:
                    printf("TOP HSM: ENTERED SHOOTING STAGE");
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                
                case ES_NO_EVENT:
                case ES_EXIT:
                default:
                    break;
            }
            break;
            
                 
        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunTopHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunTopHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/
