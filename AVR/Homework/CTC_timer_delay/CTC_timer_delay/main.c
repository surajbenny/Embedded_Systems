/*
 * CTC_timer_delay.c
 *
 * Created: 20-09-2025 14:58:26
 * Author : My PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
   DDRB|=(1<<DDB5);
   TCCR0A|=(1<<WGM01);
   TCCR0B|=(1<<CS00);
   TCCR0B|=(1<<CS01);
   TCNT0=0;
   OCR0A=220;
   TIFR0|=(1<<OCF0A);
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		for(int i=0;i<5682;i++)
		{
			while(!(TIFR0 & (1<<OCF0A)));
			TIFR0|=(1<<OCF0A);
		}
		
    }
}

