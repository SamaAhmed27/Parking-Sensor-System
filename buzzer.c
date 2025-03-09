/*
 * buzzer.c
 *
 *  Created on: Oct 8, 2024
 *      Author: samaa
 */
/*******************************************************************************/
#include "buzzer.h"
#include "gpio.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Definition: This function initializes the buzzer, setting the pin direction
 */
void Buzzer_init(void){
	/* Set pin as output */
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	/* Initialize it to be turned off */
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}

/*
 * Definition: This function activates the buzzer by setting the pin to High
 */
void Buzzer_on(void){
	/* Turn ON the buzzer */
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);
}

/*
 * Definition: This function stops the buzzer after the alarm is over by
 * setting the pin to low
 */
void Buzzer_off(void){
	/* Turn OFF the buzzer */
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}

