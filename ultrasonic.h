/*
 * ultrasonic.h
 *
 *  Created on: Oct 16, 2024
 *      Author: samaa
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ULTRASONIC_TRIGGER_PORT_ID		PORTD_ID
#define ULTRASONIC_TRIGGER_PIN_ID		PIN7_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Definition: This function will initialize the sensor's ports and call the init
 * of the ICU as well
 */
void Ultrasonic_init(void);

/*
 * Definition: This function will send the trigger pulse to the sensor
 */
void Ultrasonic_Trigger(void);

/*
 * Definition: This function will read the output distance of the sensor using
 * the echo
 * It will first call the Ultrasonic_trigger and then measure
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Definition: This function will calculate the pulse time of the sensor
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
