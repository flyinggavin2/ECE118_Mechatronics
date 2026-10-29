#include <BOARD.h>
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"

//Motors and sensors 
#include "motors.h"
#include "Tape_Sensor.h"
#include "Bumper_Sensor.h"
#include "Trackwire_Sensor.h"
#include "Beacon_Detector.h"

#define MAIN
#ifdef MAIN

void main(void)
{
    ES_Return_t ErrorType;

    BOARD_Init();

    printf("Starting ES Framework Template\r\n");
    printf("using the 2nd Generation Events & Services Framework\r\n");


    // Your hardware initialization function calls go here
    Tape_Sensor_Init(TAPE_SENSOR_RIGHT);
    Tape_Sensor_Init(TAPE_SENSOR_CENTER);
    Tape_Sensor_Init(TAPE_SENSOR_LEFT);
    Bumper_Init();
    Trackwire_Init();
    Beacon_Init();
    Motors_Init();
    

    // now initialize the Events and Services Framework and start it running
    ErrorType = ES_Initialize();
    if (ErrorType == Success) {
        ErrorType = ES_Run();

    }
    //if we got to here, there was an error
    switch (ErrorType) {
    case FailedPointer:
        printf("Failed on NULL pointer");
        break;
    case FailedInit:
        printf("Failed Initialization");
        break;
    default:
        printf("Other Failure: %d", ErrorType);
        break;
    }
    for (;;)
        ;

};

#endif //MAIN

/*------------------------------- Footnotes -------------------------------*/
/*------------------------------ End of file ------------------------------*/
