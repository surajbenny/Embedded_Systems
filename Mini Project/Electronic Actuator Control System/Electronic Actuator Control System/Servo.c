/*
 * Servo.c
 *
 * Created: 03-07-2026 21:59:38
 *  Author: My PC
 */ 
#include "servo.h"
#include "TIMER_1_PWM.h"

void Servo_Init(void)
{
	PWM_Init();
}

void Servo_SetAngle(uint8_t angle)
{
	uint16_t pulse;

	pulse = 2000 + ((uint32_t)angle * 2000) / 180;

	OCR1A = pulse;
}