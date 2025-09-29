/*
 * sreejith.c
 *
 * Created: 26-09-2025 20:28:41
 *  Author: My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


void timer0_init(void) // define timer0_init()
{
	
	TCCR0A|=(1<<WGM01); //CTC Mode
	OCR0A=249; //For count 250 setpoint , to get 1 ms delay
	TCNT0=0;// making counter 0
	TCCR0B|=(1<<CS00);
	TCCR0B|=(1<<CS01); // prescalar 64
	TIFR0|=(1<<OCF0A); // setting flag to 0
}

void suraj(uint16_t ms)
{
	timer0_init();
	
	while (ms--) // creates delay for ms
	{
		while (!(TIFR0&(1<<OCF0A))) // 1 ms loop
		{
			
		}
		TIFR0|=(1<<OCF0A);
	}
}