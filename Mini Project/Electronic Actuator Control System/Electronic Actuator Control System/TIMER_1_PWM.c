/*
 * TIMER_1_PWM.c
 *
 * Created: 03-07-2026 13:59:59
 *  Author: My PC
 */ 
#include "TIMER_1_PWM.h"
#include <stdint.h>

void PWM_Init(void)
{
	DDRB |= (1<<PB1);

	ICR1 = 39999;  // reset to 0 after 39999 

	OCR1A = 3000;   // start in the middle 90 degree =3000 as per calculation

	TCCR1A =(1<<COM1A1) |(1<<WGM11);  //COM1A1: Enable PWM output on OC1A (PB1)

	TCCR1B =(1<<WGM13) |(1<<WGM12) |(1<<CS11);  // CS11 PRESCALAR 8
}