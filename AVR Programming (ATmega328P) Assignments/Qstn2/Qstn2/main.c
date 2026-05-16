/*
 * Qstn2.c
 *
 * Created: 16-05-2026 00:02:31
 * Author : My PC
 
 2. Objective: Write a program to toggle between a Red LED and a Green LED using a
 momentary push-button switch.
 
 Requirements: The system must interface with a Red LED, a Green LED, and a
 push-button switch. When the switch is pressed, the program must toggle the current
 active LED state. If the Red LED is currently ON, it must be turned OFF while the
 Green LED is turned ON. Conversely, if the Green LED is currently ON, it must be
 turned OFF while the Red LED is turned ON. Each individual press of the switch
 should trigger exactly one transition between the two LEDs
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRD &= ~(1<<DDD5);
	DDRD |= (1<<DDD6);
	DDRD |= (1<<DDD7);	
	
	PORTD |= (1<<DDD5);   // pull up resistor
	PORTD |= (1<<DDD6);
	PORTD &= ~(1<<DDD7);
	
	while(1)
	{
			if(!(PIND & (1<<PIND5)))
			{
				PORTD ^= (1<<PORTD7);
				PORTD ^= (1<<PORTD6);
				_delay_ms(200);
				
				while (!(PIND & (1<<PIND5)));
				
			}
	


	}
}

