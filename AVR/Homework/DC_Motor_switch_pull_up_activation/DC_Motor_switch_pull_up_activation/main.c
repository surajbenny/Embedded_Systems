/*
 * DC_Motor_switch_pull_up_activation.c
 *
 * Created: 17-09-2025 17:19:32
 * Author : My PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB|=(1<<DDB5);
	DDRB|=(1<<DDB4);
	DDRD&=~(1<<DDD2);
	PORTD|=(1<<PORTD2);
	while (1)
	{
		if(!(PIND &(1<<PIND2)))
		{
			
			
			PORTB|=(1<<PORTB5);
			PORTB&=~(1<<PORTB4);
			_delay_ms(5000);
			PORTB&=~(1<<PORTB4);
			PORTB&=~(1<<PORTB5);
			_delay_ms(1000);
			PORTB|=(1<<PORTB4);
			PORTB&=~(1<<PORTB5);
			_delay_ms(5000);
			PORTB&=~(1<<PORTB4);
			PORTB&=~(1<<PORTB5);
			_delay_ms(1000);
		}
		else
		{
			PORTB&=~(1<<PORTB4);
			PORTB&=~(1<<PORTB5);
			
			
		}
		
	}
}

