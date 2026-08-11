/******************************************************************************
 *
 * Module: UltraSonic Sensor
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the UltraSonic Sensor driver
 *
 * Author: Abdelrahman Hamada
 *
 *******************************************************************************/
#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include <util\delay.h>

static uint16 timerValue = 0;
static uint8 counter = 0;
/*
 * Description:
 * Initialize the ultrasonic:
 * 1. Initialize ICU driver
 * 2. Set ICU callback function
 * 3. Configure trigger pin as output
 */
void Ultrasonic_init(void)
{
	/*
	 * The ICU should be configured with a frequency of F_CPU/8 and set to
	 * detect the rising edge as the first edge.
	 */
	ICU_ConfigType config1 = {F_CPU_8, RISING};
	ICU_init(&config1);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);
}
/*
 * Send the trigger pulse to the ultrasonic sensor.
 */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}
/*
 * Send the trigger pulse by using the Ultrasonic_Trigger
 * function.
 * Start the measurement process via the ICU driver.
 * The measured distance are in Centimeters
 */
uint16 Ultrasonic_readDistance(void)
{
	/*Sends trigger*/
	Ultrasonic_Trigger();

	_delay_ms(30);

	/*
	 * Calculate distance
	 * Rounding the distance value to the nearest integer
	 * Example: if distance = 11.2 -> 11.2 + 0.5 = 11.7 = 11
	 * 			if distance = 11.6 -> 11.6 + 0.5 = 12.1 = 12
	 */
	return (uint16)((float32)(timerValue/117.6) + 0.5);

}
/*
 * Description:
 * Callback function for ICU – calculates the high time of Echo pulse
 */
void Ultrasonic_edgeProcessing(void)
{
	counter++;
	if(counter == 1)
	{
		/*
		 * Clearing Timer to Starts Counting until the next falling edge.
		 */
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(counter == 2)
	{
		/*
		 * Falling Edge Detected:
		 * 1- Registering the value of the ICU into a static global variable
		 * 2- Reseting The Timer
		 * 3- Reseting the Counter
		 * 4- Setting the edge back to rising edge
		 */
		timerValue = ICU_getInputCaptureValue();
		ICU_clearTimerValue();

		counter = 0;
		ICU_setEdgeDetectionType(RISING);
	}
}
