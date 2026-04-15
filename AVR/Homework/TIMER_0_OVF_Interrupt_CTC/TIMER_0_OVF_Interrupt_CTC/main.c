/*
 * TIMER_0_OVF_Interrupt_CTC.c
 *
 * Created: 01-10-2025 17:26:38
 * Author : My PC
 */ 

#define F_CPU16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
volatile uint16_t count=0;

ISR(TIMER0_COMPA_vect)  //Interrupt service routine (Timer0_OVF_VECT =interrupt vector table "address" for timer overflow interrupt)
{
	count++;
	if (count>=1000)
	{
		PORTB^=(1<<PORTB5);
		count=0;
	}
	
	
	
}

int main(void)
{
	DDRB|=(1<<DDB5);
	TCCR0A=(1<<WGM01); // CTC mode
	TCCR0B|=(1<<CS00)|(1<<CS01);
	OCR0A=249;
	
	
	TIMSK0|=(1<<OCIE0A); // enabling timer overflow interrupt for timer0 in CTC mode
	sei(); // enable global interrupt
	while (1)
	{
	}
}

