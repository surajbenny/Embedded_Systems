/*
 * Timer_0_CTM.c
 *
 * Created: 19-09-2025 20:37:58
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
	DDRB|=(1<<DDB5);
	TCCR0A|=(1<<WGM01); // CTC mode
	OCR0A=200; // set point equal to 200
	TCNT0=0;   // Initial value of timer set 0
	TCCR0B|=(1<<CS00); // No prescaling
	TIFR0 |= (1<<OCF0A); // Writing 1 to OCF0A bit to TIFR0 register to reset it (Exception for atmel avr)
	
	
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		for (long int i=0; i<160000;i++)  // long is used because int max val for 16 bit is 65535
		{
			while(!(TIFR0 & (1<<OCF0A)))
			{
				
			}
			TIFR0 |= (1<<OCF0A);// Writing 1 to OCF0A bit to TIFR0 register to reset it (Exception for atmel avr)
		}
    }
}

