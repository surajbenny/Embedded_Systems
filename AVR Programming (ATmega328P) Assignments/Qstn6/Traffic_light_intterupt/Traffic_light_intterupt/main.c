/*
 * Traffic_light_intterupt.c
 *
 * Created: 16-05-2026 23:12:41
 * Author : My PC
 6. Objective: Write a program to manage a traffic light sequence that includes a high priority 
    interrupt designed to trigger a state change only after the current light cycle
    completes its minimum safe duration.
 
 Requirements: The system must control three LEDs (Green, Orange, and Red)
 connected to PORTB. Under normal operation, the program should cycle through the
 Green (10s), Orange (3s), and Red (10s) states in a continuous loop. An emergency
 push-button must be interfaced with the External Interrupt 0 (INT0) pin. When the
 button is pressed, the program should set a flag within the Interrupt Service Routine
 (ISR) rather than jumping states immediately. The main program logic must check
 this flag at the end of the current light's duration. If the flag is set, the system must
 then prioritize the Green light for a set duration before clearing the flag and resuming
 the normal cycle.
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 16000000UL

volatile int emergency_flag =0;

void delay_1sec()
{
	unsigned int i;
	unsigned int count = 977;
	for(i=0;i<count;i++)
	{
		TCNT0 = 0;
		TIFR0 = (1<<TOV0);
		TCCR0B = (1<<CS00) | (1<<CS01);
		
		
		while(!(TIFR0 & (1<<TOV0)));
	}
}

void delay_seconds(unsigned int sec)
{
	int j;
	for (j=0;j<sec;j++)
	{
		delay_1sec();
	}
}


ISR(INT0_vect)
{
	emergency_flag =1;	
}


int main(void)
{   
	
	DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2);
	
	
	 // PD2 (INT0) as input
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PORTD2);	 // Enable pull-up resistor
	
	// interrupt happens when switch is pressed , by default due to pull up resistor the value in pd2 is high
	// Enable INT0
	EIMSK = (1<<INT0);
	
	// Falling edge trigger
	EICRA = (1<<ISC01);
	EICRA &= ~(1<<ISC00);
	sei();
	
	
    /* Replace with your application code */
    while (1) 
    {
		//Green
		PORTB = (1<<PORTB0);
		delay_seconds(10);
		
		// Check emergency request
		if (emergency_flag)
		{
			PORTB = (1<<PORTB0);
			delay_seconds(10);
			emergency_flag=0;	
		}
		
		//orange
		PORTB = (1<<PORTB1);
		delay_seconds(3);
		
		// Check emergency request
		if (emergency_flag)
		{
			PORTB = (1<<PORTB0);
			delay_seconds(10);
			emergency_flag=0;
		}
		
		//red
		PORTB =(1<<PORTB2);
		delay_seconds(10);
		if (emergency_flag)
		{
			PORTB = (1<<PORTB0);
			delay_seconds(10);
			emergency_flag=0;
		}
    }
}

