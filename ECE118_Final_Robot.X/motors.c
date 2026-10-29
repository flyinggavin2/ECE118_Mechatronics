/* ************************************************************************** */
/** file: motor.c

  @Company
    Gavin Wang (gaywang@ucsc.edu) 

  @File Name
    Motor.c

  @Summary
    function calls to run motors of the robot

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/*
 NOTES:
 * pin 5 is cooked 
 */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include "motors.h"
#include <xc.h>
#include "IO_Ports.h"
#include "pwm.h"
#include "AD.h"
#include <stdio.h>
#include <stdlib.h>



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

//RIGHT MOTOR PINS
#define R_MOTOR_A PIN3 //Forward motion pin3 high and pin 4 low
#define R_MOTOR_B PIN4
#define R_MOTOR_PWM PWM_PORTY12

//LEFT MOTOR PINS
#define L_MOTOR_A PIN7 //Forward motion pin 7 high and pin 8 low
#define L_MOTOR_B PIN8
#define L_MOTOR_PWM PWM_PORTY10

#define MOTOR_PORT PORTY

#define FLYWHEEL_PWM PWM_PORTX11
#define DISPENSE_PWM PWM_PORTZ06

//FLYWHEEL PINS (port x)
#define FLYWHEEL_PORT PORTX
#define FLYWHEEL_A PIN12
#define FLYWHEEL_B PIN10

//DISPENSE WHEEL PINS (port z)
#define DISPENSE_PORT PORTZ
#define DISPENSE_A PIN5
#define DISPENSE_B PIN4


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

void Motors_Init(void)
{

    // Initialize PWM system
    PWM_Init();
    
    // Add two PWM channels
    PWM_AddPins(PWM_PORTY10);   // Left PWM
    PWM_AddPins(PWM_PORTY12);   // Right PWM
    PWM_SetFrequency(MIN_PWM_FREQ);
    
    IO_PortsSetPortOutputs(MOTOR_PORT, R_MOTOR_A);
    IO_PortsSetPortOutputs(MOTOR_PORT, R_MOTOR_B);
    IO_PortsSetPortOutputs(MOTOR_PORT, L_MOTOR_A);
    IO_PortsSetPortOutputs(MOTOR_PORT, L_MOTOR_B);

    Motors_Stop();
    
    
    // Flywheel
    PWM_AddPins(FLYWHEEL_PWM);
    IO_PortsSetPortOutputs(FLYWHEEL_PORT, FLYWHEEL_A | FLYWHEEL_B);

    
    // Dispense wheel
    PWM_AddPins(DISPENSE_PWM);
    IO_PortsSetPortOutputs(DISPENSE_PORT, DISPENSE_A | DISPENSE_B);

}

//========================= FLYWHEEL ==========================

void Flywheel_SetSpeed(int speed)
{
    // clamp
    if (speed > 1000) {
        speed = 1000;
    }

    if (speed < 0) {
        speed = 0;
    }

    // direction
    IO_PortsSetPortBits(FLYWHEEL_PORT, FLYWHEEL_A);
    IO_PortsClearPortBits(FLYWHEEL_PORT, FLYWHEEL_B);

    PWM_SetDutyCycle(FLYWHEEL_PWM, speed);
}


void Flywheel_Stop(void)
{
    PWM_SetDutyCycle(FLYWHEEL_PWM, 0);

    IO_PortsClearPortBits(FLYWHEEL_PORT,
            FLYWHEEL_A | FLYWHEEL_B);
}


//========================= DISPENSE WHEEL (60 = working speed) ==========================
void DispenseWheel_SetSpeed(int speed)
{
    // Set direction
    if (speed >= 0)
    {
        // Forward
        IO_PortsSetPortBits(DISPENSE_PORT, DISPENSE_A);
        IO_PortsClearPortBits(DISPENSE_PORT, DISPENSE_B);
    }
    else
    {
        // Reverse
        IO_PortsSetPortBits(DISPENSE_PORT, DISPENSE_B);
        IO_PortsClearPortBits(DISPENSE_PORT, DISPENSE_A);

        speed = -speed; // PWM must be positive
    }

    // Clamp PWM
    if (speed > 1000)
    {
        speed = 1000;
    }

    PWM_SetDutyCycle(DISPENSE_PWM, speed);
}

void DispenseWheel_Stop(void)
{
    PWM_SetDutyCycle(DISPENSE_PWM, 0);

    IO_PortsClearPortBits(DISPENSE_PORT,
            DISPENSE_A | DISPENSE_B);
}

// ============== WRAPPER FUNCTIONS ==============

void Flywheel_On(void)
{
    Flywheel_SetSpeed(800); //will varry
}

void DispenseWheel_On(void)
{
    DispenseWheel_SetSpeed(100); //working speed 
}


//========================= MOTORS ==========================

void Motors_SetLeftSpeed(int speed)
{
    // Set direction
    if (speed >= 0) {
        // Forward
        IO_PortsSetPortBits(PORTY, PIN7);
        IO_PortsClearPortBits(PORTY, PIN8);
    } else {
        // Backward
        IO_PortsSetPortBits(PORTY, PIN8); 
        IO_PortsClearPortBits(PORTY, PIN7);

        speed = -speed; // make PWM positive
    }

    // Clamp PWM
    if (speed > 1000) {
        speed = 1000;
    }

    PWM_SetDutyCycle(L_MOTOR_PWM, speed);
}

void Motors_SetRightSpeed(int speed)
{
    if (speed >= 0) {
        // Forward
        IO_PortsSetPortBits(PORTY, PIN3);
        IO_PortsClearPortBits(PORTY, PIN4);
    } else {
        // Backward
        IO_PortsSetPortBits(PORTY, PIN4);
        IO_PortsClearPortBits(PORTY, PIN3);

        speed = -speed;
    }

    if (speed > 1000) {
        speed = 1000;
    }

    PWM_SetDutyCycle(R_MOTOR_PWM, speed);
}

void Motors_SetSpeed(int leftSpeed, int rightSpeed)
{
    Motors_SetLeftSpeed(leftSpeed);
    Motors_SetRightSpeed(rightSpeed);
}

void Motors_Stop(void)
{
    PWM_SetDutyCycle(PWM_PORTY10, 0);
    PWM_SetDutyCycle(PWM_PORTY12, 0);
}



//#define MOTOR_TEST_HARNESS //checked and working (pins 5 is cooked)
#ifdef MOTOR_TEST_HARNESS

void main(void) 
{
    BOARD_Init();
    Motors_Init();

    printf("Running MOTOR.C TEST HARNESS");
    while(1) {
        //Motors_SetSpeed(-500, -500);
        Flywheel_SetSpeed(450);
        DispenseWheel_SetSpeed(100);
        }
}

#endif //MOTOR_TEST_HARNESS


/* *****************************************************************************
 End of File
 */
