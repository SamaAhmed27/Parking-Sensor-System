/*
 * ultrasonic.c
 *
 *  Created on: Oct 16, 2024
 *      Author: samaa
 */

#include "ultrasonic.h"
#include "gpio.h"
#include "icu.h"
#include <util/delay.h>

uint16 g_time_high = 0;
/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*
 * Definition: This function will initialize the sensor's ports and call the init
 * of the ICU as well
 */
void Ultrasonic_init(void){
	/* Set the trigger pin as output */
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);

	/* Structure of the ICU config. that sets a prescaler of 8
	 * It also activates the ICU at the rising edge
	 */
	ICU_ConfigType us_icu = {F_CPU_8,RISING};
	ICU_init(&us_icu); /* Call the ICU init function */

	ICU_setCallBack(Ultrasonic_edgeProcessing);

}

/*
 * Definition: This function will send the trigger pulse to the sensor
 */
void Ultrasonic_Trigger(void){
	/* send a pulse for 10ms */
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_LOW);

}

/*
 * Definition: This function will read the output distance of the sensor using
 * the echo
 * It will first call the Ultrasonic_trigger and then measure
 */
uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	/* Get the ICR1 value */
	/* Calculate the distance */
	return g_time_high / 117.6;

}

/*
 * Definition: This function will calculate the pulse time of the sensor
 */
void Ultrasonic_edgeProcessing(void){

	static uint8 count_edge = 0; /* Variable to store/set the count of edges (0 or 1) */

	if(count_edge == 0){
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
		count_edge = 1;
	}
	else if(count_edge == 1){
		g_time_high = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RISING);
		count_edge = 0;
	}

}

