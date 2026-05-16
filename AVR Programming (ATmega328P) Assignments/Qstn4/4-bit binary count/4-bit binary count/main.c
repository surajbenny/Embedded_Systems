/*
 * 4-bit binary count.c
 *
 * Created: 16-05-2026 14:15:18
 * Author : My PC
 
 4. Objective: Write a program that uses four LEDs to display a 4-bit binary count
 triggered by a switch.
 
 Requirements: Four LEDs must be connected to PORTB (Pins 0 through 3) and a
 push-button must be connected to PORTD Pin 2. Every time the switch is pressed,
 the value displayed by the LEDs must increment by one in binary format (from 0000
 to 1111). When the count reaches 15 (all LEDs ON), the next press must reset the
 counter back to 0. The program should use a dedicated function to update the LED
 states based on the current counter variable.
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


void updateLEDs(unsigned char count)
{
	PORTB = count;
}


int main(void)
{
	
	unsigned char count = 0;
	
	DDRB = 0x0F;								// Pin B0 to B3 as output
	DDRD &= ~(1<<DDD2);							// Pin D2 as input
	
	// Enable pull-up resistor for switch
	PORTD |= (1<<PORTD2);
	
    // Initial LED display
    updateLEDs(count);	
	
	while(1)
	{
		if (!(PIND &(1<<PIND2)))
		{
			count++;
			updateLEDs(count);
			
			if(count > 15)
			{
				count = 0;
			}
			
			_delay_ms(200);
			
			while(!(PIND &(1<<PIND2)));
			
		}
	
	
	}
}

