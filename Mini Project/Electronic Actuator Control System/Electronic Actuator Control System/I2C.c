/*
 * I2C.c
 *
 * Created: 04-07-2026 01:13:21
 *  Author: My PC
 */ 

#include <stdint.h>
#include "I2C.h"

void I2C_Init(void)
{
	//SCL Frequency = 100 kHz 

	TWSR = 0x00;      // Prescaler = 1

	TWBR = 72;        // 100 kHz for F_CPU = 16 MHz

	TWCR = (1 << TWEN);   // Enable TWI
}

void I2C_Start(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));
}

void I2C_Stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void I2C_Write(uint8_t data)
{
	TWDR = data;

	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));
}