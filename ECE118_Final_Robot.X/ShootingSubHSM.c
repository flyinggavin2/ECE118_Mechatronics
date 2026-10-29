/*
 * File: TemplateSubHSM.c
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
#include "ShootingSubHSM.h"
#include "Beacon_Detector.h"
#include "motors.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitPSubState,
    Center,
    CenterForward,
    FindBeacon,
    Jerk,
    Shoot,
    Unjam,
    BlindPivot,
    BlindShoot,
    BlindPivotBack,
    BlindShootAgain,
} ShootingSubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"SubFirstState",
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

static ShootingSubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;

static uint16_t Beacon_Detected_Value;

static uint8_t beacon_found_counter = 0;

static uint8_t beacon_not_found = FALSE;


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
uint8_t InitShootingSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunShootingSubHSM(INIT_EVENT);
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
ES_Event RunShootingSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    ShootingSubHSMState_t nextState; // <- change type to correct enum

    //ES_Tattle(); // trace call stack

    switch (CurrentState) 
    {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state
            Beacon_Detected_Value = 0;

            // now put the machine into the actual initial state
                nextState = Center;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
        break;

        case Center:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("SHOOTING: entered center\r\n");
                    Motors_SetSpeed(-350, 0);//turn left 
                            
                    //turn left timer 
                    ES_Timer_InitTimer(SHOOTING_TURNING_TIMER, 1350);
                    
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == SHOOTING_TURNING_TIMER)
                    {
                        printf("SHOOTING: driving to center\r\n");
                        Motors_Stop();
                        ES_Timer_InitTimer(SHOOTING_DRIVING_TIMER, 1750);
                        Motors_SetSpeed(400, 400); //drive straight to center 
                        
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    
                    if (ThisEvent.EventParam == SHOOTING_DRIVING_TIMER)
                    {
                        printf("SHOOTING: at center\r\n");
                        Motors_Stop();
                        
                        nextState = CenterForward;
                        makeTransition = TRUE;
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
            
        case CenterForward:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    //turn 90 degrees left then move forward 
                    ES_Timer_InitTimer(SHOOTING_TURNING_TIMER, 1250);
                    Motors_SetSpeed(-350, 0);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == SHOOTING_TURNING_TIMER) // turn left
                    {
                        ES_Timer_InitTimer(SHOOTING_DRIVING_TIMER, 1250);
                        Motors_SetSpeed(350, 350);
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    if (ThisEvent.EventParam == SHOOTING_DRIVING_TIMER) //drive forward
                    {
                        Motors_Stop();
                        nextState = FindBeacon;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;    
                
            }
            break;
            
           
                    
        case FindBeacon:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("SHOOTING: finding beacon (disp and fly off)...\r\n");

                    //reset detected value;
                    Beacon_Detected_Value = 0;
                    beacon_found_counter = FALSE;
                    beacon_not_found = FALSE;
                    
                    //ensure shooting is off
                    DispenseWheel_Stop();
                    Flywheel_Stop();
                    
                    //timer to stop:
                    ES_Timer_StopTimer(SHOOTING_REV_TIMER);
                    
                    //FOR WHEN WE CANT FIND BEACON
                    ES_Timer_InitTimer(SHOOTING_NO_BEACON_TIMER, 10000); //turn to face beacon (average place)
                    
                    
                    //scan for beacon
                    Motors_SetSpeed(-250, 250);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                    
                // ============= NO BEACON FOUND ===================
                case ES_TIMEOUT: //tune it so that the avg time is face the beacon 
                    if (ThisEvent.EventParam == SHOOTING_NO_BEACON_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_NO_BEACON_TIMER);
                        
                        beacon_not_found = TRUE;
                        printf("NO BEACON --> BLIND SHOOTING");
                        Motors_Stop();
                        
                        nextState = BlindPivot;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    break;
                 
                case BEACON_DETECTED:
                    if(!beacon_found_counter)
                    {
                        ES_Timer_StopTimer(SHOOTING_NO_BEACON_TIMER);
                        
                        beacon_found_counter = TRUE;
                        Motors_Stop();
                        Beacon_Detected_Value = ThisEvent.EventParam; //record beacon value
                        printf("Shooting - BEACON FOUND - Detected Value = %u\r\n starting timer\r\n", Beacon_Detected_Value);
                        
                        
                        //PIVOTING
                        Motors_SetSpeed(300, 0);
                        ES_Timer_InitTimer(SHOOTING_PIVOT_TIMER, 150); //130 good
                        
                        //go to jerk
                        nextState = Jerk;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                        
                    }
    
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                
                
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
                
            }
            break;
         
        case Jerk:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("SHOOTING: Entered Jerk\r\n");
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == SHOOTING_PIVOT_TIMER)
                    {
                        Motors_Stop();
                        printf("SHOOTING: Pivot Finished, going to shoot\r\n");
                        
                        //int flywheel_speed = (1 - ((BEACON_LOW - Beacon_Detected_Value)/BEACON_LOW)) * PWM_MAX; //ex: (1023 - 200)/1023 
                        int flywheel_speed = 580;
                        //turn on fly wheel and set rev timer 
                        Flywheel_SetSpeed(560);
                        printf("SHOOTING: flywheel reving...\r\n Calculated Flywheel Speed: %u\r\n", flywheel_speed);   
                        
                         ES_Timer_InitTimer(SHOOTING_REV_TIMER, 3000);
                        
                        nextState = Shoot;
                        makeTransition = TRUE;
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
            
            
            
        case Shoot:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("SHOOTING: Entered Shoot\r\n");
                    
                    //reset timer
                    ES_Timer_InitTimer(SHOOTING_RESET_TIMER, 10000);
                    
                    ES_Timer_InitTimer(SHOOTING_UNJAMING_TIMER, 6000); //unjam every 3 second
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_TIMEOUT:
                    
                    
                    
                    // ============ REVING INTO DISPENSE WHEEL =================
                    if (ThisEvent.EventParam == SHOOTING_REV_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_REV_TIMER);
                        printf("SHOOTING: flywheel ready\r\n");
                        DispenseWheel_SetSpeed(-85);
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
  
                    }
                    
                    // =============== UNJAMMING =====================
                    if (ThisEvent.EventParam == SHOOTING_UNJAMING_TIMER)
                    {
                        printf("Spinning Dispense Wheel +100\r\n");
                        ES_Timer_StopTimer(SHOOTING_UNJAMING_TIMER);
                        DispenseWheel_SetSpeed(100);
                        ES_Timer_InitTimer(SHOOTING_UNJAMING_TIMER2, 1300);
                        
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    if (ThisEvent.EventParam == SHOOTING_UNJAMING_TIMER2)
                    {
                        printf("Spinning Dispense Wheel -100\r\n");
                        ES_Timer_StopTimer(SHOOTING_UNJAMING_TIMER2);
                        ES_Timer_InitTimer(SHOOTING_UNJAMING_TIMER, 5000);
                        DispenseWheel_SetSpeed(-85);
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    
                    if( ThisEvent.EventParam == SHOOTING_RESET_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_RESET_TIMER);
                        
                        ES_Timer_StopTimer(SHOOTING_UNJAMING_TIMER);
                        ES_Timer_StopTimer(SHOOTING_UNJAMING_TIMER2);
                        ES_Timer_StopTimer(SHOOTING_REV_TIMER);
                        
                        
                        //reset find the beacon
                        DispenseWheel_SetSpeed(0);
                        Flywheel_SetSpeed(0);
                        
                        nextState = FindBeacon;
                        makeTransition = TRUE;
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
        
        
        case BlindPivot:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    printf("BLIND: pivoting\n\r");

                    Motors_SetSpeed(400,-400);
                    ES_Timer_InitTimer(SHOOTING_PIVOT_TIMER, 150);

                    break;

                case ES_TIMEOUT:
                    if(ThisEvent.EventParam == SHOOTING_PIVOT_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_PIVOT_TIMER);
                        
                        Motors_Stop();

                        nextState = BlindShoot;
                        makeTransition = TRUE;
                    }
                    break;
            }
            break; 
            
        case BlindShoot:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:

                    printf("BLIND: shooting\n\r");

                    Flywheel_SetSpeed(530);

                    ES_Timer_InitTimer(SHOOTING_REV_TIMER,3000);

                    break;

                case ES_TIMEOUT:

                    if(ThisEvent.EventParam == SHOOTING_REV_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_REV_TIMER);
                        DispenseWheel_SetSpeed(-85);

                        ES_Timer_InitTimer(SHOOTING_NO_BEACON_TIMER, 10000);
                    }

                    if(ThisEvent.EventParam == SHOOTING_NO_BEACON_TIMER)
                    {   
                        ES_Timer_StopTimer(SHOOTING_NO_BEACON_TIMER);
                        DispenseWheel_Stop();
                        Flywheel_Stop();
                        
                        nextState = BlindPivotBack;
                        makeTransition = TRUE;
                    }

                    break;
            }
            break; 
            
        case BlindPivotBack:

            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:

                    Motors_SetSpeed(-400,400);
                    DispenseWheel_SetSpeed(300);
                    ES_Timer_InitTimer(SHOOTING_PIVOT_TIMER, 150);

                    break;

                case ES_TIMEOUT:

                    if(ThisEvent.EventParam == SHOOTING_PIVOT_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_PIVOT_TIMER);
                        Motors_Stop();

                        nextState = BlindShootAgain;
                        makeTransition = TRUE;
                    }

                    break;
            }

            break; 
            
        case BlindShootAgain:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:

                    printf("BLIND: shooting\n\r");

                    //Flywheel_SetSpeed(540);

                    ES_Timer_InitTimer(SHOOTING_REV_TIMER,3000);
                    
                    Flywheel_SetSpeed(525);
                    

                    break;

                case ES_TIMEOUT:

                    if(ThisEvent.EventParam == SHOOTING_REV_TIMER)
                    {
                        ES_Timer_StopTimer(SHOOTING_REV_TIMER);
                        
                        DispenseWheel_SetSpeed(100);
                        ES_Timer_InitTimer(SHOOTING_NO_BEACON_TIMER, 10000);
                    }

                    if(ThisEvent.EventParam == SHOOTING_NO_BEACON_TIMER)
                    {   
                        ES_Timer_StopTimer(SHOOTING_NO_BEACON_TIMER);
                        
                        DispenseWheel_Stop();
                        Flywheel_Stop();
                        nextState = BlindPivot;
                        makeTransition = TRUE;
                    }

                    break;
            }
            break;    
            
        
        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunShootingSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunShootingSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

