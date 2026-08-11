 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: header file for the LED driver
 *
 * Author: Abdelrahman Hamada
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "gpio.h"

/*------------------------- Configurations ----------------------------*/

typedef enum {
    LED_RED = PIN0_ID,
    LED_GREEN = PIN1_ID,
    LED_BLUE = PIN2_ID
}LED_ID;

#define LED_PIN PIN0_ID
#define LED_PORT PORTC_ID

#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW

/*------------------------ Functions Prototype ------------------------*/

void LED_init(void);

void LED_on(LED_ID id);

void LED_off(LED_ID id);
#endif /* LED_H_ */
