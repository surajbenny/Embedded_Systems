/*
 * GPIO_INPUT1_low.c
 *
 * Created: 11-09-2025 23:42:43
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD=0b00000000;
	DDRB=0b00100000;
    while (1) 
    {
		if (PIND==0b00000000)
		PORTB=0b00100000;
		else
		PORTB=0b00000000;
    }
}

