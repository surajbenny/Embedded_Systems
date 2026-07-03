/*
 * gpio.c
 *
 * Created: 03-07-2026 13:58:19
 *  Author: My PC
 */ 

#include "gpio.h"

void GPIO_Init()
{
	
	//DDRB |= (1<<PB1);      //Servo Output 

	// UART
	DDRD |= (1<<PD1);
	DDRD &= ~(1<<PD0);

	DDRC &= ~(1<<PC0);     // ADC

	// OLED I2c

	DDRC |= (1<<PC4);
	DDRC |= (1<<PC5);
	}
	