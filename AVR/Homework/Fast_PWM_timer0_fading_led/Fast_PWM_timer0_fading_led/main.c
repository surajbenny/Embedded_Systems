/*
 * Fast_PWM_timer0_fading_led.c
 *
 * Created: 25-09-2025 16:03:08
 * Author : My PC
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
    DDRD|=(1<<DDD6);
	TCCR0B|=(1<<CS00);
	TCCR0B|=(1<<CS01);
	TCCR0A|=(1<<WGM01);
	TCCR0A|=(1<<WGM00);
	TCCR0A|=(1<<COM0A1);
	for(int i=0;i<256;i++)
	{
		OCR0A=i;
		_delay_ms(50);
	}
		
	if (OCR0A==255)
	{
		for(int j=255;j>=0;j--)
			{
				OCR0A=j;
				_delay_ms(20);
				
			}
	}
		
	
			
    while (1) 
    {
    }
}

