/*
 * LED_Toggle.c
 *
 * Created: 15-05-2026 20:57:30
 * Author : My PC
 
 1. Objective: Write a program to toggle an LED connected to PORTD Pin 5 with
 specific timing intervals for the ON and OFF states.
 
 Requirements: The LED must be interfaced with PORTD Pin 5. Upon system start
 or reset, the LED must immediately turn ON and remain in that state for exactly 3
 seconds. After the ON period, the LED must turn OFF for a duration of exactly 5
 seconds. The program must be designed to continuously loop this 3-second ON and
 5-second OFF sequence.
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	DDRD |= (1<<DDD5);
	
	
    /* Replace with your application code */
    while (1) 
    {
		PORTD |= (1<<PORTD5);
		_delay_ms(3000);
		PORTD &= ~(1<<PORTD5);
		_delay_ms(5000);
	}
}

