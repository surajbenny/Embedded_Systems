/*
 * delay_timer_0_normal.c
 *
 * Created: 17-09-2025 20:48:22
 * Author : My PC
 */ 
#define F_CPU16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	unsigned int i;
	unsigned int count=	62500;
	for (i=0;i<count;i++)
	{
	
	TCNT0=0;
	TCCR0A=0;
	TCCR0B|=(1<<CS00);
	TIFR0|=(1<<TOV0); // making timer overflow flag 0, in atmega to set 0
	while(!(TIFR0 & (1<< TOV0))); // waiting timer overflow flag to set so that we get a  delay 16 us
	}
}

int main(void)
{
	DDRB|=(1<<DDB5);
    /* Replace with your application code */
    while (1)
    {
		PORTB|=(1<<PORTB5);
		delay_1s();
		PORTB&=~(1<<PORTB5);
		delay_1s();
		
		
    }
}

