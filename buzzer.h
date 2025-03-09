/*
 * buzzer.h
 *
 *  Created on: Oct 8, 2024
 *      Author: samaa
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT_ID			PORTC_ID
#define BUZZER_PIN_ID			PIN5_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Definition: This function initializes the buzzer, setting the pin direction
 */
void Buzzer_init(void);

/*
 * Definition: This function activates the buzzer by setting the pin to High
 */
void Buzzer_on(void);

/*
 * Definition: This function stops the buzzer after the alarm is over by
 * setting the pin to low
 */
void Buzzer_off(void);


#endif /* BUZZER_H_ */
