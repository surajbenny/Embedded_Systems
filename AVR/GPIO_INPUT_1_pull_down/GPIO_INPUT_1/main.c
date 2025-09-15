/*
 * GPIO INPUT 1.c
 *
 * Created: 10-09-2025 17:35:08
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)

{
	DDRB=0b00100000;	
	DDRD=0b00000000;
    while (1) 
    {
		if (PIND==0b00000001)
		{
			PORTB=0b00100000;
		}
		else
		{
			PORTB=0b00000000;
		}
	}
}

