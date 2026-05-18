/*
 * Servo_motor_angle_potentio.c
 *
 * Created: 18-05-2026 16:50:19
 * Author : My PC
 
 11. Write a program to control the angular position of a servo motor based on the analog
 input received from a potentiometer.
 
 Requirements: The system must interface a potentiometer with ADC Channel 0
 and a servo motor with the OC1A pin (PORTB Pin 1). The program must configure
 Timer1 in 16-bit Phase Correct PWM mode to generate the 50Hz signal required for
 servo operation. A dedicated function should read the 10-bit analog value from the
 potentiometer and map it to the corresponding pulse width required to move the
 servo from 0 to 180 degrees. The motor position must update in real-time as the
 potentiometer is turned.
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

uint16_t ADC_Init()
{
	ADMUX |= (1<<REFS0);		//Avcc selected as Aref
	ADMUX |= (0x0F<< MUX3);     //channel 0
	ADCSRA |= (1<<ADEN);		//ADC enable
}

uint16_t ADC_read()
{
	ADCSRA |= (1<<ADPS1);    //prescaler 128
	ADCSRA |= (1<< ADSC);    //start conversion
	
	while(ADCSRA & (1<< ADSC));
	
	return (ADCL | ADCH <<8);
	
}

uint8_t servo_pwm()
{
	DDRB |= (1<<DDB1);
	TCCR1A |= (1<<COM1A1);  // non Inverting
	
	
}


int main(void)
{
    DDRB |= (1<<DDB1);
	
	//PWM Config
	
	
	
	
    while (1) 
    {
    }
}

