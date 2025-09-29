/*
 * Modular_delay.c
 *
 * Created: 26-09-2025 20:21:49
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "sreejith.h"
#include <stdint.h>



int main(void)
{
    DDRB|=(1<<DDB5);
	
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		suraj(5000);
    }
}

