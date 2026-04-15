/*
 * Timer)_overflow_interrupt.c
 *
 * Created: 29-09-2025 20:48:16
 * Author : My PC
 */ 
#define F_CPU16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
volatile uint16_t count=0;

ISR(TIMER0_OVF_vect)  //Interrupt service routine (Timer0_OVF_VECT =interrupt vector table "address" for timer overflow interrupt)
{
	count++;
	if (count>=977)
	{
		PORTB^=(1<<PORTB5);
		count=0;
	}
	
	
	
}

int main(void)
{
	DDRB|=(1<<DDB5);
	TCCR0A=0; // NORMAL mode
	TCCR0B|=(1<<CS00)|(1<<CS01);
	TIMSK0|=(1<<TOIE0); // enabling timer overflow interrupt for timer0 in normal mode
	sei(); // enable global interrupt
    while (1) 
    {
    }
}

