/*
 * DC_motor_with_function.c
 *
 * Created: 12-09-2025 15:58:30
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void cw()
{
	PORTB|=(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
}

void stp()
{
	PORTB&=~(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
}

void ccw()
{
	PORTB|=(1<<PORTB4);
	PORTB&=~(1<<PORTB5);
}

int main(void)
{
	DDRB|=(1<<DDB5);
	DDRB|=(1<<DDB4);
    /* Replace with your application code */
    while (1) 
    {
		cw();
		_delay_ms(3000);
		stp();
		_delay_ms(1000);
		ccw();
		_delay_ms(3000);
		stp();
		_delay_ms(1000);
    }
}

