/*
 * Qstn3.c
 *
 * Created: 16-05-2026 13:10:04
 * Author : My PC
 
 3. Objective: Write a program to create a "train" animation where a single active LED
 appears to move across a series of connected GPIO pins.
 
 Requirements: The system must control a sequence of at least eight LEDs
 connected to PORTB. When the program starts, only the first LED should turn ON.
 After a short delay, the first LED must turn OFF and the second LED must turn ON.
 This sequential shifting must continue until the last LED in the row is reached. Once
 the "train" reaches the end of the line, the pattern should immediately reset to the
 first LED and repeat the sequence indefinitely to create a continuous moving light
 effect.
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
	int i ;
    DDRB |=(1<<DDB0)| (1<<DDB1) | (1<<DDB2) | (1<<DDB3) | (1<<DDB4) | (1<<DDB5) | (1<<DDB6) | (1<<DDB7);
	
    while (1) 
    {
		for(i=0;i<8;i++)
		{
			PORTB = (1<<i);
			_delay_ms(200);
		}

    }
}

