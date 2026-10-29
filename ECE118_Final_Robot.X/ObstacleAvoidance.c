/*
 * File: ObstacleAvoidanceSubHSM.c
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
#include "ObstacleAvoidanceSubHSM.h"
#include "motors.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
typedef enum {
    InitPSubState,
    BackUp,
    Turn90Left,
    Validate90Turn,
    DrivePastObstacle,
    ValidateDrivePastObstacle,  
    Jerk,
    JerkObstacle,
    NorthObstacleRecovery,
    Turn90Right,
    GetToTape,
    IgnoreCenterTape

} OASubHSMState_t;

static const char *StateNames[] = {
	"InitPSubState",
	"SubFirstState",
};



/*
 * I assume we dont hit an obstacle during the first driving past obstacle and getting back to tape
 * Bumper event handle:
 * 1. when we are in drivng psat obstacle or in jerk after the first right turn (so on the short leg of the obstacle)
 * --> we go back to back up and restart from there 
 * 2. when we are turning right on the second right turn and we hit an obstacle
 * --> we need to back up, pivot a small amount, and drivng forward again until not bumper events 
 * --> we handle this before the right turn 90 degrees is expired, if expired we are clear to go forward
 * --> need to reset the 90 degree timer, stop it and rerun the state again
 
 
 */

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

static OASubHSMState_t CurrentState = InitPSubState; // <- change name to match ENUM
static uint8_t MyPriority;

static uint8_t turn90rightCount;

static uint8_t jerkCount;

static uint8_t obstacleLevel = 0;


static uint8_t IgnoreTapeFlag = FALSE;
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
uint8_t InitObstacleAvoidanceSubHSM(void)
{
    ES_Event returnEvent;

    CurrentState = InitPSubState;
    returnEvent = RunObstacleAvoidanceSubHSM(INIT_EVENT);
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
ES_Event RunObstacleAvoidanceSubHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    OASubHSMState_t nextState; // <- change type to correct enum

    //ES_Tattle(); // trace call stack

    switch (CurrentState) 
    {
        case InitPSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                // this is where you would put any actions associated with the
                // transition from the initial pseudo-state into the actual
                // initial state
                
                turn90rightCount = 0;
                jerkCount = 0;

                // now put the machine into the actual initial state
                nextState = BackUp;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
            
        case BackUp:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    
                    printf("OA: Backing Up\r\n");
                    ES_Timer_InitTimer(OA_BACKUP_TIMER, 450);
                    
                    
                    //back up --> set timer
                    Motors_SetSpeed(-325, -325);
//                    ES_Timer_InitTimer(OA_BACKUP_TIMER, 650); //moves these behaviors to topHSM during trnaistion
                    ThisEvent.EventType = ES_NO_EVENT; //maybe commented out to have it handled at topHSM
                    break;
                    
                case ES_TIMEOUT: //or upon bumper release 
                    if (ThisEvent.EventParam == OA_BACKUP_TIMER)
                    {
                        ES_Timer_StopTimer(OA_BACKUP_TIMER);
                        Motors_Stop();
                        
                        nextState = Turn90Left;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        
                        break;
                        
                    }
                    
//                case LEFT_BUMPER_RELEASED:
//                case RIGHT_BUMPER_RELEASED:
//                    Motors_Stop();
//                        
//                    nextState = TurnOne;
//                    makeTransition = TRUE;
//                    ThisEvent.EventType = ES_NO_EVENT;
//                    break;
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;

        case Turn90Left: 
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("OA: Turn 90 Left\r\n");
                    
                    ES_Timer_InitTimer(OA_90TURN_TIMER, 700); //set 90 degree turn timer
                    Motors_SetSpeed(-300, 300); //turn left 
                   
                    ThisEvent.EventType = ES_NO_EVENT; 
                    break;
                
                        
                //set a known timer to know when a valid track wire on event is posted 
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == OA_90TURN_TIMER) //90 degree turn complete (1500 tested)
                    {
                        nextState = DrivePastObstacle; //Force a 90 degree turn 
                        //nextState = Validate90Turn;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    }
                    break;              
                case ES_NO_EVENT:
                case ES_EXIT:
                default: 
                    break;
            }
            break;
            
        case Validate90Turn: //NOT USED
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("OA: Validating 90 Left....\r\n");
                    ThisEvent.EventType = ES_NO_EVENT; 
                    break;
                
                case ON_TRACKWIRE:
                    Motors_Stop();
                    printf("OA: Valid 90 Turn Left\r\n");  
                    
                    nextState = DrivePastObstacle;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
                    
                
            }
            break;
                 
            
        case DrivePastObstacle:
            switch(ThisEvent.EventType)
            {
                case ES_ENTRY:
                    printf("OA: Driving Past Obstacle\r\n");

                    Motors_SetSpeed(250, 250);
                    
                    if (turn90rightCount == 1)
                    {
                        ES_Timer_InitTimer(OA_DRIVE_TIMER, 500); //use a shorter validation timer for 1st right turn
                        
                    }
                    else
                    {
                        ES_Timer_InitTimer(OA_DRIVE_TIMER, 600); // set a timer for when an expect event should happen
                    }
                    

                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == OA_DRIVE_TIMER)
                    {
                        printf("OA: TIMER DONE\r\n");
                        nextState = ValidateDrivePastObstacle;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    break;
                
                    
                //need to handle if bumper is pressed while driving past obstacle 
                case LEFT_BUMPER_PRESSED:
                case RIGHT_BUMPER_PRESSED:
                    if (turn90rightCount == 1) //driving forward after first 90 degree turn
                    {
                        printf("OA: Another Obstacle Hit on 1st 90 right turn \r\n");
                        Motors_Stop();
                        nextState = BackUp;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT; 
                        break;
                        
                        
                    }
                        
                    
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
            }
            break;
        
        case ValidateDrivePastObstacle:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    printf("OA: Validating Driving Pass Obstacle....\r\n");
                    ThisEvent.EventType = ES_NO_EVENT; 
                    break;
                
                case OFF_TRACKWIRE:
                    printf("OA: Valid Past Obstacle, Adjusting...\r\n"); 
                    nextState = Jerk;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case LEFT_BUMPER_PRESSED:
                case RIGHT_BUMPER_PRESSED:
                    if (turn90rightCount == 1) //driving forward after first 90 degree turn
                    {
                        printf("OA: Another Obstacle Hit on 1st 90 righ turn during validation DPO \r\n");
                        Motors_Stop();
                        nextState = BackUp;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT; 
                        
                        printf("OA: Obstacle depth %u\r\n", obstacleLevel);
                        turn90rightCount = 0;
                        jerkCount = 0;
                        obstacleLevel++;
                        
                        break;
                        
                        
                    }
                    

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
                    jerkCount++;
                    printf("OA: Entered Jerk\r\n");
                    
                    if (jerkCount == 1) //right turn 1
                    {
                        ES_Timer_InitTimer(OA_ADJUSTMENT_TIMER, 550); //jerk forward a bit 
                    }
                    if (jerkCount == 2) //right turn 2
                    {
                        ES_Timer_InitTimer(OA_ADJUSTMENT_TIMER, 550); //jerk forward a bit 
                    }
                    
                    Motors_SetSpeed(450, 450);
                    ThisEvent.EventType = ES_NO_EVENT; 
                    break;
                
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == OA_ADJUSTMENT_TIMER)
                    {
                        printf("Turning Right 90\r\n");
                        nextState = Turn90Right;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                    }
                    break;
                    
                    
                //bumper event go back to drive up
                case LEFT_BUMPER_PRESSED:
                case RIGHT_BUMPER_PRESSED:
                    if (turn90rightCount == 1) //driving forward after first 90 degree turn 
                    {
                        printf("OA: Another Obstacle Hit on 1st 90 right turn during Jerk \r\n");
                        Motors_Stop();
                        nextState = BackUp;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT; 
                        
                        printf("OA: Obstacle depth %u\r\n", obstacleLevel);
                        turn90rightCount = 0;
                        jerkCount = 0;
                        obstacleLevel++;
                        
                        break;
                        
                        
                    }
                    if (turn90rightCount == 0)
                    {
                        printf("OA: Obstacle while driving north\r\n");
                        jerkCount = 0;
                        nextState = NorthObstacleRecovery;
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
         
        case NorthObstacleRecovery:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    Motors_SetSpeed(-300, -300);
                    ES_Timer_InitTimer(OA_RECOVERY_BACKUP_TIMER, 300);
                    break;
                
                case ES_TIMEOUT: 
                    if(ThisEvent.EventParam == OA_RECOVERY_BACKUP_TIMER) //jerk back up done
                    {
                        Motors_SetSpeed(250, -250); 
                        ES_Timer_InitTimer(OA_RECOVERY_BACKUP_TIMER2, 300);
                        
                    }
                    else if(ThisEvent.EventParam == OA_RECOVERY_BACKUP_TIMER2) //jerk back up done
                    {
                        Motors_SetSpeed(300, 300);
                        nextState = Jerk;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                    break;    
                        
                    } 
                    
                
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;    
            }
            break;
                
        case JerkObstacle: 
            switch (ThisEvent.EventType) 
            {
                //back up then drive forward
                case ES_ENTRY:
                    printf("Jerk: entered obstacle jerk -- backing up\r\n");
     
                    Motors_SetSpeed(-300, -300);
                    
                    ES_Timer_InitTimer(OA_JERK_OBSTACLE_TIMER, 500);
                    
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_TIMEOUT: 
                    if(ThisEvent.EventParam == OA_JERK_OBSTACLE_TIMER) //jerk back up done
                    {
                        //turn right
                        printf("Jerk: obstacle jerk -- turning right\r\n");
                        Motors_SetSpeed(300, -300);
                        ES_Timer_InitTimer(OA_JERK_OBSTACLE_TIMER2, 250);
                        
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;
                        
                    }
                    
                    if(ThisEvent.EventParam == OA_JERK_OBSTACLE_TIMER2)
                    {
                        printf("Jerk: obstacle jerk -- driving forward -- going to get to tape\r\n");
                        Motors_SetSpeed(300, 300);
                        nextState = IgnoreCenterTape;
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
            
            
            
           
            
        case Turn90Right:
            switch (ThisEvent.EventType) 
            {
                
                case ES_ENTRY:
                    printf("OA: Turn 90 Right - Count:%u\r\n", turn90rightCount);
                    ES_Timer_InitTimer(OA_90TURN_TIMER, 1350);
                    Motors_SetSpeed(600, 0); //turn right
                    
                    ThisEvent.EventType = ES_NO_EVENT; 
                    break;
                    

                    
                 case ES_TIMEOUT: //90 turn DONE
                     
                    if(ThisEvent.EventParam == OA_90TURN_TIMER) //90 degree turn complete 
                    {
                        Motors_SetSpeed(300, 300); //drive forward 
                        turn90rightCount++;
                        printf("Right Turn Count:%u\r\n", turn90rightCount);
                        
                    
                    
                        if (turn90rightCount == 2)
                        {
                            if (obstacleLevel >= 1)
                            {
                                printf("OA: 2 right turns complete - finished obstacle path - ignoring mid tape\r\n");
                                nextState = IgnoreCenterTape;
                                makeTransition = TRUE;
                                ThisEvent.EventType = ES_NO_EVENT;
                                break;
                                
                            }
                            else
                            {
                                printf("OA: 2 right turns complete - finished obstacle path\r\n");
                                //Motors_Stop();
                                nextState = IgnoreCenterTape;
                                makeTransition = TRUE;
                                ThisEvent.EventType = ES_NO_EVENT;
                                break;   
                            }
                            
                            
                        
                        }
                        else
                        {
                            printf("90 turn right done");
                            Motors_Stop();
                            nextState = DrivePastObstacle;
                            makeTransition = TRUE;
                            ThisEvent.EventType = ES_NO_EVENT;
                        
                        }  
                        break;
                    }
                    ThisEvent.EventType = ES_NO_EVENT; 
                    break;
  
                case LEFT_BUMPER_PRESSED:
                case RIGHT_BUMPER_PRESSED:
                    nextState = JerkObstacle;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;
                
            }
            break;
         
        case GetToTape:
            switch (ThisEvent.EventType) 
            {
                case ES_ENTRY:
                    InitTapeFollowingSubHSM();  //reset the corner counter flag
                    printf("OA: Getting back to tape\r\n");
                    Motors_SetSpeed(300, 300);
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                case RTS_ON_TAPE:
                case LTS_ON_TAPE:

                    Motors_Stop();
                    printf("BACK ON TAPE!!!!\r\n");
                    
                    
                    obstacleLevel = 0;
                    turn90rightCount = 0;
                    jerkCount = 0;
                    
                    InitObstacleAvoidanceSubHSM(); //reset OA subHSM ^^^ does the same as above
                    
                    //dont counter corner if hit
                    
                    ES_Timer_InitTimer(SETUP_COUNTER_IGNORE_TIMER, 2000); //reset corner counter ignore timer from OA to localize of Tape following
                    
                    
                    ThisEvent.EventType = HSM_ON_TAPE;
                    PostTopHSM(ThisEvent);
                    break;
                    
                case LEFT_BUMPER_PRESSED:
                case RIGHT_BUMPER_PRESSED:
                    nextState = JerkObstacle;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;
                    
                    
                case ES_NO_EVENT:
                case ES_EXIT:
                default: // all unhandled events pass the event back up to the next level
                    break;    
                
            }
            break;
        
    case IgnoreCenterTape:
        switch(ThisEvent.EventType)
        {
            case ES_ENTRY:
                printf("OA: Ignoring center tape temporarily\r\n");
                Motors_SetSpeed(300, 300);
                
                if (obstacleLevel >= 1)
                {
                    ES_Timer_InitTimer(OA_IGNORE_TAPE_TIMER, 1500); // 3 seconds
                }
                else
                {
                    ES_Timer_InitTimer(OA_IGNORE_TAPE_TIMER, 500); // 1 second
                }

                
                
                break;
                
            case ES_TIMEOUT:
                if(ThisEvent.EventParam == OA_IGNORE_TAPE_TIMER)
                {
                    ES_Timer_StopTimer(OA_IGNORE_TAPE_TIMER);
                    printf("OA: Done ignoring center tape\r\n");

                    nextState = GetToTape;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                }
                break;
        
            case LEFT_BUMPER_PRESSED:
            case RIGHT_BUMPER_PRESSED:
                    printf("OA: Bumper Pressed on ignoring Center\r\n");
                    nextState = JerkObstacle;
                    makeTransition = TRUE;
                    ThisEvent.EventType = ES_NO_EVENT;
                    break;  
                
            default: // all unhandled states fall into here
                break;
                
    
        }
        
    } // end switch on Current State


    
    
    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunObstacleAvoidanceSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunObstacleAvoidanceSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    //ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

