/*
 * File:   main.c
 * Author: gavinwang
 *
 * Created on May 13, 2026, 5:31 PM
 */


#include "xc.h"
#include <BOARD.h>
#include "AD.h"
#include "pwm.h"
#include "LED.h"
#include "serial.h"
#include "IO_Ports.h"
#include "Stepper.h"
#include "motors.h"

#define MAIN
#ifdef MAIN
int main(void) {
    
    BOARD_Init();
    Motors_Init();
    
     //Initialize ADC 
    AD_Init();
    AD_AddPins(AD_PORTV3);  //Continuously sample the potentiometer pin.?

//    PWM_Init();
//    PWM_AddPins(PWM_PORTZ06);
//    PWM_SetFrequency(MIN_PWM_FREQ);
    
    //Initialize LEDs
    LED_Init();
    LED_AddBanks(LED_BANK1 | LED_BANK2 | LED_BANK3); //all 3 LEDbanks (12 LEDs)
  
    
    // READ the pot   
    unsigned int potValue;
    unsigned int ledCount;
    unsigned char ledPattern;
    int i = 0;
    int Duty = 0;
    
    int leftSpeed = 1000;
    int rightSpeed = 1000;
    
    
    while(1){
        
            Motors_SetSpeed(leftSpeed, rightSpeed);

            if(i == 500){
                printf("Running Motor\n");
                i = 0;
         
            }
            i++;
            
            // LED bar display
            ledCount = (leftSpeed * 12) / 1000;
            ledPattern = (1 << ledCount) - 1; //ex: ledCount=3 ? 000000000111
            
            LED_SetBank(LED_BANK1, ledPattern & 0x0F);
            LED_SetBank(LED_BANK2, (ledPattern >> 4) & 0x0F);
            LED_SetBank(LED_BANK3, (ledPattern >> 8) & 0x0F);
    }

    return 0;
}
#endif