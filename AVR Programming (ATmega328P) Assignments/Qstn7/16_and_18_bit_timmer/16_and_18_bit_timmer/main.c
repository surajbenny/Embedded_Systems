/*
 * 16_and_18_bit_timmer.c
 *
 * Created: 17-05-2026 13:55:40
 * Author : My PC
 
 7. Objective: Write a program that manages two independent timing tasks
 simultaneously using the 16-bit Timer1 and the 8-bit Timer2.
 
 Requirements: The system must control two different LEDs. Timer1 must be
 configured to toggle a "Status LED" on PORTB Pin 1 exactly every 2 seconds.
 Simultaneously, Timer2 must be configured to toggle a "Heartbeat LED" on PORTB
 Pin 2 every 500 milliseconds. The program must use the Compare Match interrupt
 for both timers to ensure high precision. Each LED's timing logic must reside in its
 respective Interrupt Service Routine, allowing both sequences to run independently
 without interfering with each other.
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

ISR(TIMER1_COMPA_vect)
{
	//Status LED
	PORTB ^= (1<<PORTB1);
}

ISR(TIMER2_COMPA_vect)
{
		
	static int count =0;   // static It preserves previous value between function calls.
	
	count++;
	
	if(count == 31)
	{
		 	//Heartbeat LED
		PORTB ^= (1<<PORTB2);	
		count =0;
		
	}
	
}


int main(void)
{
	DDRB |= (1<<DDB1) | (1<<DDB2);
	
	//TIMER1
	TIFR1 = (1<<OCF1A);                              // clear bit
	TCCR1B |= (1<<WGM12);                           //ctc mode
	OCR1A = 31250;                                  // calculated for 2 sec
	TCCR1B |= (1<<CS12) | (1<<CS10);		      // Prescaler 1024
	
	TIMSK1 |= (1<<OCIE1A);						// Enable Timer1 Compare Match Interrupt
	sei();
	
	//TIMER2
	TCCR2A |= (1<<WGM21);  //CTC mode
	OCR2A = 250;
	TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22);    //prescalar 1024
	TIMSK2 |= (1<<OCIE2A);   // interrupt enable match for a
	sei();

	
	
    
    while (1) 
    {
    }
}

