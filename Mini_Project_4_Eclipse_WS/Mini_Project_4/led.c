 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.c
 *
 * Description: Source file for the LED driver
 *
 * Author: Abdelrahman Hamada
 *
 *******************************************************************************/
#include "led.h"
/* Description
 * Initializes all LEDs (red, green, blue) pins direction.
 * Turn off all the LEDs.
 * */
void LED_init(void){
	GPIO_setupPinDirection(LED_PORT, LED_RED, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT, LED_GREEN, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT, LED_BLUE, PIN_OUTPUT);

	GPIO_writePin(LED_PORT, LED_RED, LOGIC_LOW);
	GPIO_writePin(LED_PORT, LED_GREEN, LOGIC_LOW);
	GPIO_writePin(LED_PORT, LED_BLUE, LOGIC_LOW);
}
/* Description
 * Turns on the specified LED
 * */
void LED_on(LED_ID id){
	GPIO_writePin(LED_PORT, id, LED_ON);
}
/* Description
 * Turns off the specified LED
 * */
void LED_off(LED_ID id){
	GPIO_writePin(LED_PORT, id, LED_OFF);
}
