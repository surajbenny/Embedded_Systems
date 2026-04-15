/*
 * project_traffic.c
 *
 * Created: 02-11-2025 11:26:25
 * Author : My PC
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR1(INT0_vect)
{
			PORTB|=(1<<PORTB5);    // RED1 ON
			PORTB&=~(1<<PORTB2);   // GREEN1 OFF
			PORTC&=~(1<<PORTC5);   // RED2 OFF
			PORTC|=(1<<PORTC2);    // GREEN2 ON
	        _delay_ms(5000); 
	
}

ISR2(INT1_vect)
{
	PORTB&=~(1<<PORTB5);    // RED1 OFF
	PORTB|=(1<<PORTB2);   // GREEN1 ON
	PORTC|=(1<<PORTC5);   // RED2 ON
	PORTC&=~(1<<PORTC2);    // GREEN2 OFF
	_delay_ms(5000);
	
}






int main(void)
{
   

   DDRB |= (1 << DDB5);     // PB5 as output (LED)
   DDRD &= ~(1 << DDD2);    // PD2 as input (button)
   DDRD &= ~(1 << DDD3);	// PD3 as input (button)
   PORTD |= (1 << PORTD2);  // Enable internal pull-up resistor on PD2 (active LOW)
   EICRA |= (1 << ISC01);   // Trigger INT0 on falling edge (button press)
   EICRA &= ~(1 << ISC00);  // (ISC01=1, ISC00=0 ? falling edge)
   
   PORTD |= (1 << PORTD3);  // Enable internal pull-up resistor on PD2 (active LOW)
   EICRA |= (1 << ISC11);   // Trigger INT0 on falling edge (button press)
   EICRA &= ~(1 << ISC10);  // (ISC11=1, ISC10=0 ? falling edge)
   
   EIMSK |= (1 << INT0);    // Enable INT0 interrupt
   EIMSK |= (1 << INT1);    // Enable INT1 interrupt
   sei();                   // Enable global interrupts

	
		
	DDRB |= (1 << DDB5);
	DDRB |=(1<<DDB2);
	DDRC |=(1<<DDC5);
	DDRC |=(1<<DDC2);
	
	
	

    while (1) 
    {
		PORTB|=(1<<PORTB5);  // RED1 ON   
		PORTB&=~(1<<PORTB2);   // GREEN1 OFF
		PORTC&=~(1<<PORTC5);   // RED2 OFF
		PORTC|=(1<<PORTC2);  // GREEN2 ON
		
		
		_delay_ms(2000);
		
		
		
		PORTB&=~(1<<PORTB5);  // RED1 OFF
		PORTB|=(1<<PORTB2);   // GREEN1 ON
		PORTC|=(1<<PORTC5);   // RED2 ON
		PORTC&=~(1<<PORTC2);  // GREEN2 OFF

		_delay_ms(2000);
	
	 
	}
	

	
	
}


