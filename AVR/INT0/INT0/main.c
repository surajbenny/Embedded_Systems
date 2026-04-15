
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>


ISR(INT0_vect) //INTERRUPT SERVICE ROUTINE
{
	PORTB ^= (1 << PORTB5); //TOGGLE LED WHEN SWITCH IS PRESSED
	_delay_ms(1000);
}
int main(void)
{
	DDRB |= (1 << DDB5);  //PB5 AND PB4 IS SET AS OUTPUT
	DDRD &= ~(1 << DDD2); //PD2 IS SET AS INPUT
	PORTD |= (1 << PORTD2); // Enable internal pull-up on PD2
	
	EIMSK |= (1 << INT0); //ENABLING INTERRUPT 0.
	// FALLING EDGE TRIGGER FOR INT0
	EICRA |= (1 << ISC01);
	sei(); //ENABLING GLOBAL INTERRUPT
	
	
	while (1)
	{
		
	}
}
