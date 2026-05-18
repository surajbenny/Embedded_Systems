/*
 * auto_cooling_LM35_DC_MOTOR.c
 *
 * Created: 18-05-2026 01:03:01
 * Author : My PC
 
 10. Objective: Write a program to create an automated cooling system using an LM35
 sensor and a DC motor with manual power control.
 
 Requirements: The system must interface with an LM35 temperature sensor and a
 DC motor. A push-button must be used to toggle the entire system ON and OFF.
 When the system is ON, it should read the temperature and adjust the motor speed
 accordingly. At lower temperatures, the motor should run at a reduced speed, and at
 higher temperatures, the motor should automatically switch to a higher speed. The
 program logic for sensor reading, speed calculation, and motor control must be
 implemented using separate functions.

 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void ADC_init(void);
uint16_t ADC_read(void);

uint16_t read_temperature(void);
uint8_t calculate_speed(uint16_t temp);
void motor_control(uint8_t speed);


int main(void)
{
	
	uint8_t system_on = 0;
	
    // PD6 -> OC0A output
    DDRD |= (1 << DDD6);
	
	//Push button config
	DDRD &= ~(1<<DDD2);
	PORTD |= (1<<PORTD2);
	
	//ADC initailised
	ADC_init();
	
	
	//PWM config
	TCCR0A |= (1<<COM0A1);					//non inverting
	TCCR0A |= (1<<WGM00) | (1<<WGM01);		//FAST PWM
	  
	TCCR0B |= (1 << CS01) | (1 << CS00);     // Prescaler = 64
	
	
	//ADC initialisation
	
	 
	
	
    /* Replace with your application code */
    while (1) 
    {
		if(!(PIND & (1<<PIND2)))
		{
			_delay_ms(100);
			
			if(!(PIND & (1<<PIND2)))
			{
				system_on = !system_on;
				
				while (!(PIND & (1<<PIND2)));
					
			}
			
		}
		
		
		if (system_on)
		{
			
			uint16_t temperature = read_temperature();
			uint8_t speed = calculate_speed(temperature);
			motor_control(speed);
			
		}
		
        else
        {
	        OCR0A = 0;
        }		
    }
}
	
	void ADC_init(void)
	{
		ADMUX |= (1<<REFS0);									 //ADC ref voltage selected as Avcc
		ADCSRA |=(1<<ADEN);										//ADC enable
		ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);	// Prescaler = 128	(125 kHz ADC clock)
		
	}
	
	uint16_t ADC_read(void)
	{
		
		ADMUX &= 0xF0;        // Select ADC0 CHANNEL
		ADCSRA |= (1<<ADSC);  // start adc conversion
		
		while (ADCSRA & (1<<ADSC));  //// Wait until conversion complete
		
		return ((ADCH<<8) | ADCL);     // ADC result
		
				
	}
	
	uint16_t read_temperature(void)
	{
		
		uint16_t adc = ADC_read();
		
	    uint16_t temp_degree = (adc*500)/1024;
		
		return temp_degree;
	}
	
	uint8_t calculate_speed(uint16_t temp)
	{
		if (temp < 30)
		{
			return 64;      // 25%
		}
		else if (temp < 40)
		{
			return 128;     // 50%
		}
		else if (temp < 50)
		{
			return 192;     // 75%
		}
		else
		{
			return 255;     // 100%
		}
	}
	
	
	void motor_control(uint8_t speed)
	{
		OCR0A = speed;
	}


