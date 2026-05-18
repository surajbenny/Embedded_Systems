/*
 * PWM_Timer0.c
 *
 * Created: 17-05-2026 21:48:53
 * Author : My PC
 
 8. Objective: Write a program to control the brightness of an LED or the speed of a
 small DC motor using the hardware PWM capability of Timer0.
 
 Requirements: The program must initialize Timer0 in Fast PWM mode with the
 output directed to the OC0A pin (PORTD Pin 6). The system should start with a 25%
 duty cycle. A push-button connected to an input pin should be used to cycle the duty
 cycle through four levels: 25%, 50%, 75%, and 100% OFF. Each time the button is
 pressed, the program should update the Output Compare Register (OCR0A) to the
 next level. The transition between speeds must be handled by a dedicated function
 that updates the timer registers.

 
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000UL
#include <util/delay.h>


void set_pwm_duty(uint8_t level);


int main(void)
{
	uint8_t level =0	;
	
	DDRD |= (1<<DDD6);      // Configure PD6 (OC0A) as OUTPUT
	
	//switch config
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PORTD2);
	 
	TCCR0A |= (1<<WGM00) | (1<<WGM01);      //fast mode pwm
    TCCR0A |= (1<<COM0A1);     // NON INVERTING MODE
	
	TCCR0B |= (1 << CS01) | (1 << CS00);

	set_pwm_duty(0); //start with 25%
	
    while (1) 
    { 
		 // Button pressed
	if (!(PIND & (1 << PIND2)))
	{
		// Debounce delay
		_delay_ms(100);

		// Confirm button press
		if (!(PIND & (1 << PIND2)))
			 {          
				level++;
			
				if (level >3)
				{
					level = 0;
				}
			
			set_pwm_duty(level);
			
			while (!(PIND & (1<<PIND2)));
		}
    }
}

void set_pwm_duty(uint8_t level)
{
	switch(level)
	{
		case 0:
			OCR0A = 64;     //25%
			break;
		
		case 1:
			OCR0A=128;		//50%
			break;
		
		case 2:
			OCR0A=192;		//75%
			break;
			
		case 3:
			OCR0A=255;		//100%
			break;
			
	}
	
}