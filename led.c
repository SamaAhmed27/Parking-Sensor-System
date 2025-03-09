/*
 * led.c
 *
 *  Created on: Oct 6, 2024
 *      Author: samaa
 */

#include "led.h"
#include "gpio.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Definition: This function Initializes all Leds (red, green, blue) pins direction.
 * It initially turns off all LEDs
 */
void LEDS_init(void){
	/* Setting the direction of the LED pins */
	GPIO_setupPinDirection(LED_RED_PORT_ID,LED_RED_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,PIN_OUTPUT);

	/* Turn all LEDs off */
	GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LED_OFF);
	GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LED_OFF);
	GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LED_OFF);
}

/*
 * Definition: Turns on the specified LED.
 */
void LED_on(LED_ID id){
	/* Switch on the LED color to write each one to ON */
	switch(id){
	case RED:
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LED_ON);
		break;
	case GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LED_ON);
		break;
	case BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LED_ON);
		break;
	}
}

/*
 * Definition: Turns off the specified LED.
 */
void LED_off(LED_ID id){
	/* Switch on the LED color to write each one to OFF */
	switch(id){
	case RED:
		GPIO_writePin(LED_RED_PORT_ID,LED_RED_PIN_ID,LED_OFF);
		break;
	case GREEN:
		GPIO_writePin(LED_GREEN_PORT_ID,LED_GREEN_PIN_ID,LED_OFF);
		break;
	case BLUE:
		GPIO_writePin(LED_BLUE_PORT_ID,LED_BLUE_PIN_ID,LED_OFF);
		break;
	}
}
