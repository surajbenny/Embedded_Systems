/*
 * Modular_delay_5_LED.c
 *
 * Created: 29-09-2025 17:00:24
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "GPIO.h"


int main(void)
{
	timer_0_init();
    
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		PORTB^=(1<<PORTB4);
		PORTB^=(1<<PORTB3);
		PORTB^=(1<<PORTB2);
		PORTB^=(1<<PORTB1);
		delay(2000);
		
		
    }
}

