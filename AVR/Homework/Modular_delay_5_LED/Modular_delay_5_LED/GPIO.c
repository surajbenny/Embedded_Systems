/*
 * GPIO.c
 *
 * Created: 29-09-2025 17:44:51
 *  Author: My PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>


void timer_0_init(void)
{
	DDRB|=(1<<DDB5);
	DDRB|=(1<<DDB4);
	DDRB|=(1<<DDB3);
	DDRB|=(1<<DDB2);
	DDRB|=(1<<DDB1);
	TCCR0B|=(1<<CS00);
	TCCR0B|=(1<<CS01);
	TCCR0A|=(1<<WGM01);
	TCNT0=0;
	TIFR0|=(1<<OCF0A);
	OCR0A=249;
	
}

void delay(uint16_t ms)
{
	timer_0_init();
	
	while(ms--)
	{
		while(!(TIFR0&(1<<OCF0A)))
		{
			
		}
		TIFR0|=(1<<OCF0A);
	}
	
	
}