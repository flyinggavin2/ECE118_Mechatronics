/* ************************************************************************** */
/** Descriptive File Name

  @Company
 Gavin Wang (gaywang@ucsc.edu)

  @File Name
 motors.h

  @Summary
 head for motors.c

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef MOTORS_H    /* Guard against multiple inclusion */
#define MOTORS_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include "motors.h"


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

#define PWM_MAX 600



    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */

//    typedef struct _example_struct_t {
//        /* Describe structure member. */
//        int some_number;
//
//        /* Describe structure member. */
//        bool some_flag;
//
//    } example_struct_t;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        inttialize motors

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
    int ExampleFunction(int param1, int param2);
    
    
    void Motors_Init(void);
    void Motors_SetLeftSpeed(int speed);
    void Motors_SetRightSpeed(int speed);
    void Motors_SetSpeed(int leftSpeed, int rightSpeed);
    void Motors_Stop(void);

    
    void Flywheel_SetSpeed(int speed);
    void Flywheel_Stop(void);
    
    void DispenseWheel_SetSpeed(int speed);
    void DispenseWheel_Stop(void);
    
    //wrapper functions
    void Flywheel_On(void);
    void DispenseWheel_On(void);
    
    
#endif /* MOTORS_H*/

/* *****************************************************************************
 End of File
 */
