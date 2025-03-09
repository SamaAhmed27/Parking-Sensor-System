/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: samaa
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LED_ON					LOGIC_HIGH
#define LED_OFF					LOGIC_LOW

#define LED_RED_PORT_ID			PORTC_ID
#define LED_RED_PIN_ID			PIN0_ID

#define LED_GREEN_PORT_ID		PORTC_ID
#define LED_GREEN_PIN_ID		PIN1_ID

#define LED_BLUE_PORT_ID		PORTC_ID
#define LED_BLUE_PIN_ID			PIN2_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	RED,GREEN,BLUE
}LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Definition: This function Initializes all Leds (red, green, blue) pins direction.
 * It initially turns off all LEDs
 */
void LEDS_init(void);

/*
 * Definition: Turns on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Definition: Turns off the specified LED.
 */
void LED_off(LED_ID id);



#endif /* LED_H_ */
