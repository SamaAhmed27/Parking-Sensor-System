/*
 * lcd.h
 *
 *  Created on: Oct 1, 2024
 *      Author: samaa
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LCD_DATA_BITS_MODE 		4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* Definitions of the LCD HW pins */
#define LCD_RS_PORT_ID			PORTA_ID
#define LCD_RS_PIN_ID			PIN1_ID

#define LCD_E_PORT_ID			PORTA_ID
#define LCD_E_PIN_ID			PIN2_ID

#define LCD_DB_PORT_ID			PORTA_ID

/* Condition in case the LCD is operating in 4-bits mode */
#if (LCD_DATA_BITS_MODE == 4)
#define LCD_DB4_PIN_ID			PIN3_ID
#define LCD_DB5_PIN_ID			PIN4_ID
#define LCD_DB6_PIN_ID			PIN5_ID
#define LCD_DB7_PIN_ID			PIN6_ID
#endif

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Function to send the command to the LCD, here we define the RS with 0, then follow the timing diagram
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Function to send display a character on the LCD, here we define the RS with 1, then follow the timing diagram
 */
void LCD_displayCharacter(uint8 character);

/*
 * Description :
 * Function to initialize the LCD
 */
void LCD_init(void);

/*
 * Description :
 * Function to display a string
 */
void LCD_displayString(const char *string);

/*
 * Description :
 * Function to move the cursor of the LCD to a certain position
 */
void LCD_moveCursor(uint8 row, uint8 col);

/*
 * Description :
 * Function to display a string at a certain row and column
 */
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *str);

/*
 * Description :
 * Function to clear the screen
 */
void LCD_clearDisplay(void);

/*
 * Description :
 * Function to convert an integer to a string to be able to display it on screen
 */
void LCD_integerToString(uint32 num);

#endif /* LCD_H_ */
