/*
 * one-way traffic controller.c
 *
 * Created: 16-05-2026 16:00:05
 * Author : My PC
 
 5. Objective: Write a program to simulate a basic one-way traffic light controller using
 three LEDs to represent the Green, Orange, and Red signals without using inbuilt
 _delay() function.
 
 Requirements: The system must control three LEDs connected to any three
 available GPIO pins on PORTB. Upon system start, the Green LED must turn ON for
 a duration of 10 seconds. After this period, the Green LED must turn OFF and the
 Orange LED must turn ON for 3 seconds. Once the Orange duration ends, it must
 turn OFF and the Red LED must turn ON for 10 seconds. The program must be
 designed to continuously cycle through this Green-Orange-Red sequence indefinitely.
 */ 

#include <avr/io.h>

void delay_1sec()
{
	unsigned int i;
	unsigned int count=62500;

	for (i=0;i<count;i++)
	{
		
	TCNT0 = 0;	
	TIFR0 = (1<<TOV0);    //MAKING OVERFLOW FALG 0	in atmega only
	TCCR0A = 0;
	TCCR0B = (1<<CS00);	
	

	while(!(TIFR0 & (1<<TOV0)));
	}
	
}

void delay_seconds(unsigned int sec)
{
	for (int j=0;j<sec;j++)
	{
		delay_1sec();
	}
}


int main(void)
{
	DDRB = 0x07;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB |= (1<<PORTB0);  //green on
		PORTB &= ~(1<<PORTB1);
		PORTB &= ~(1<<PORTB2);
		delay_seconds(10);
		PORTB &= ~(1<<PORTB0);
		PORTB &= ~(1<<PORTB2);
		PORTB |= (1<<PORTB1);
		delay_seconds(3);
		PORTB &= ~(1<<PORTB0);
		PORTB &= ~(1<<PORTB1);
		PORTB |= (1<<PORTB2);
		delay_seconds(10);
		
    }
}

