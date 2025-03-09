/*
 * main.c
 *
 *  Created on: Oct 16, 2024
 *      Author: samaa
 */

/* Include needed drivers */
#include "lcd.h"
#include "ultrasonic.h"
#include "led.h"
#include "buzzer.h"

#include <avr/io.h> /* to init the I-bit */
#include <util/delay.h>
#include "common_macros.h"

int main(void){
	/* initialize the drivers */
	Ultrasonic_init();
	Buzzer_init();
	LEDS_init();
	LCD_init();

	/* Set the I-bit */
	SET_BIT(SREG,7);

	/* Variables initialization */
	uint16 distance;

	while(1){
		/* Read distance */
		distance = Ultrasonic_readDistance();

		LCD_displayStringRowColumn(1,2,"Distance=");
		LCD_moveCursor(1,11);
		if(distance<10){
			LCD_integerToString(distance); /* Moving from 10s to 1s */
			LCD_displayString("cm");
			LCD_displayCharacter(' ');
		}
		else{
			LCD_integerToString(distance);
			LCD_displayString("cm");
		}



		if(distance <= 5){
			Buzzer_on();

			/* Read distance */
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			_delay_ms(500);

			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			_delay_ms(500);

			LCD_displayStringRowColumn(2,7,"Stop");
		}
		else if(distance>=6 && distance <= 10){
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(2,7,"    "); /* To delete the stop */
		}
		else if(distance>=11 && distance <= 15){
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(2,7,"    ");
		}
		else if(distance>=16 && distance <= 20){
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(2,7,"    ");
		}
		else{
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
			Buzzer_off();
			LCD_displayStringRowColumn(2,7,"    ");
		}
	}
	return 0;
}


