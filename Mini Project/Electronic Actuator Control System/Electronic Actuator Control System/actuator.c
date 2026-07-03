/*
 * actuator.c
 *
 * Created: 03-07-2026 22:00:38
 *  Author: My PC
 */ 

#include "actuator.h"
#include "adc.h"
#include "servo.h"

uint16_t pedal;
uint8_t angle;

void Actuator_Update(void)
{
	pedal = ADC_ReadAverage(0);

	angle = (pedal * 180) / 1023;

	Servo_SetAngle(angle);
}