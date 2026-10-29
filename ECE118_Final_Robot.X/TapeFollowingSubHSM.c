/*
 * File: TapeFollowingSubHSM.c
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
#include "TapeFollowingSubHSM.h"
#include "motors.h"
#include "Beacon_Detector.h"
#include "Tape_Sensor.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitPSubState,
    Localize,
    AlignStraight,
    CornerCheck,        
    Corner,
    AtISZ
            
} TemplateSubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"Localize",
	"AlignStraight",
	"CornerCheck",
	"Corner",
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

static TemplateSubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;

static uint8_t Corner_Count = 0;

uint8_t Corner_Flag = FALSE;

static uint8_t LeftOnTape = FALSE;
static uint8_t RightOnTape = FALSE;

static uint8_t cornerPending = FALSE;


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
uint8_t InitTapeFollowingSubHSM(void)
{
    
    
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunTapeFollowingSubHSM(INIT_EVENT);
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
ES_Event RunTapeFollowingSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    TemplateSubHSMState_t nextState; // <- change type to correct enum

    //ES_Tattle(); // trace call stack
    
    // ================ CORNER CHECKING ================
//    switch(ThisEvent.EventType)
//    {
//        case LTS_ON_TAPE:
//            LeftOnTape = TRUE;
//            break;
//
//        case LTS_OFF_TAPE:
//            LeftOnTape = FALSE;
//            break;
//
//        case RTS_ON_TAPE:
//            RightOnTape = TRUE;
//            break;
//
//        case RTS_OFF_TAPE:
//            RightOnTape = FALSE;
//            break;
//
//        default:
//            break;
//    }
//    
//    if(CornerArmed && LeftOnTape && RightOnTape && Corner_Flag)
//    {
//        printf("AT CORNER\r\n");
//        ES_Event cornerEvent;
//
//        cornerEvent.EventType = HSM_AT_CORNER;
//        cornerEvent.EventParam = 0;
//
//        PostTopHSM(cornerEvent);
//
//        CornerArmed = FALSE;
//    }
    
    
    
    
    switch (CurrentState) 
    {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                Corner_Flag = FALSE;
                
                // now put into the actual initial state
                printf("Init TapeFollwingSubstate\r\n");
                nextState = Localize;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Localize: // in the first state, replace this with correct names

            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("LOCALIZE!\r\n");
                    Motors_SetSpeed(400, 300);
                    //ThisEvent.EventType = ES_NO_EVENT; //have top to handle this 
                    break;
                
                   
                case CTS_ON_TAPE:
                    printf("CTS FOUND - Turning Left!\r\n");
                    
                    nextState = AlignStraight;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case LTS_ON_TAPE:
                    if (Corner_Flag == TRUE) //ignoring this count
                    {
                        cornerPending = TRUE;
                        printf("Possible corner detected\r\n");
                        nextState = CornerCheck;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    break;

                    
                    
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == SETUP_COUNTER_IGNORE_TIMER)
                    {
                        printf("=====CORNER FLAG CLEARED =====\r\n");
                        Corner_Flag = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                   break;
                  
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
        
        case AlignStraight:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    printf("Aligning Straight\r\n");
                    Motors_SetSpeed(-300, 0);//turn left  
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                     
                
                case RTS_ON_TAPE:
                    nextState = Localize;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                
                case LTS_ON_TAPE:
                    if (Corner_Flag == TRUE)  //we rotate into a corner
                    {
                        cornerPending = TRUE;
                        printf("LTS detected\r\n");
                        nextState = CornerCheck;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    break;
                
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == SETUP_COUNTER_IGNORE_TIMER)
                    {
                        printf("=====CORNER FLAG CLEARED =====\r\n");
                        Corner_Flag = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
        
            //go to corner check case
            //if es time out --> go to localize
            // if left tape sensor is off, corner++, if corner ==2 go to corner state, else go to localize 
            
        
        case CornerCheck:
            switch (ThisEvent.EventType)
            {
                case ES_ENTRY:
                    Motors_Stop();
                    
                    Corner_Count++;
                    printf("CORNER FOUND ------ COUNT: %u\r\n", Corner_Count);

                    if (Corner_Count == 4)
                    {
                        Motors_Stop();
                        nextState = AtISZ;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    else
                    {
                        Motors_SetSpeed(-200, 0);
                        nextState = Corner;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }

                        makeTransition = TRUE;
                              
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            
            
            

        case Corner:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    Motors_SetSpeed(-300, 300);
                    printf("TAPE FOLLOWING: CORNER ENTERED! -- Turning Left\r\n");
                    
                    ES_Timer_InitTimer(CORNER_TURN_TIMER, 800);
                    
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                
                case ES_TIMEOUT:
                {
                    if(ThisEvent.EventParam == CORNER_TURN_TIMER)
                    {
                        printf("CORNER EXITED!\r\n");
                        Motors_SetSpeed(300, 250);//drive forward
                        nextState = Localize;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    
                }  
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
                
            }
            break;
            
        case AtISZ:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    
                    Motors_Stop();
                    ThisEvent.EventType = HSM_AT_ISZ; //proper bubling
                    printf("=====>>>> going to shooting\r\n");
                    PostTopHSM(ThisEvent);
                    break;
                   
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
                
                    
            
            
        default: // all unhandled states fall into here
            break;
            
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunTapeFollowingSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunTapeFollowingSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

