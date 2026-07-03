/*
 * ADC.c
 *
 * Created: 03-07-2026 13:59:19
 *  Author: My PC
 */ 
#include "ADC.h"

void ADC_Init(void)
{
	ADMUX = (1<<REFS0);    //AVCC Reference
	
	// Enable ADC Prescaler 128

    ADCSRA =(1<<ADEN) |(1<<ADPS2) |(1<<ADPS1) |(1<<ADPS0);
}

	
uint16_t ADC_Read(uint8_t channel)
{
	channel &= 0x07;		    //channel selected limited to 7
	ADMUX &= 0xF8;
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC);	    // ADC coversion start
	while(ADCSRA & (1<<ADSC));   // waiting to set the flag 0

	return (ADCL | (ADCH << 8));         // Combine result
}

//average several samples to get steady value due to noise.
uint16_t ADC_ReadAverage(uint8_t channel)
{
	uint32_t sum = 0;

	for(uint8_t i=0;i<10;i++)
	{
		sum += ADC_Read(channel);
	}

	return sum/10;
}