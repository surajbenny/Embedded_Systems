/*
 * DC_motor_input_delay.c
 *
 * Created: 12-09-2025 16:18:13
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void cw(int t)
{
	PORTB|=(1<<PORTB5);
	PORTB&=~(1<<PORTB4);
	_delay_ms(t);
	
}

void stp()
{
	PORTB&=~(1<<PORTB4);
	PORTB&=~(1<<PORTB5);
	_delay_ms(1000);
}

/*void ccw(int t)
{
	PORTB|=(1<<PORTB4);
	PORTB&=~(1<<PORTB5);
	_delay_ms(t);
}*/
int main(void)
{
    DDRB|=(1<<DDB4);
	DDRB|=(1<<DDB5);
    while (1) 
    {
		cw(3000);
		stp(1000);
		//ccw(7000);
		//stp(1000);
    }
}

