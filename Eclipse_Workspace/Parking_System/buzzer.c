 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the Buzzer driver
 *
 * Author: Abdelrahman Hamada
 *
 *******************************************************************************/
#include "buzzer.h"
/*
 * Description :
 * Initializes the buzzer pin direction and turn off the buzzer
 */
void Buzzer_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}
/*
 * Description :
 * Activates the buzzer
 */
void Buzzer_on(void)
{
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH);
}
/*
 * Description :
 * Deactivates the buzzer
 */
void Buzzer_off(void)
{
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}
