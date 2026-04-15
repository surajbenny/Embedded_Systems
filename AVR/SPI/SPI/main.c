/*
 * SPI.c
 *
 * Created: 29-10-2025 20:46:55
 * Author : My PC
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	uint16_t dummy, chip_ID;
	DDRB |= (1<<DDB3) | (1<<DDB5) | (1<<DDB2);  // MOSI,SCK,SS as output
	DDRB |= (1 << DDD3); 
	DDRB &= ~(1<<DDB4); // MISO as input
	SPCR |= (1<< MSTR) | (1<<SPE) | (1<< SPR0);   // Enabling SPI as master , enable SPI, SPRO =1 clock speed set SCK Frequency as fosc / 16
	SPCR &= ~(1<<SPR1);    // SPR1 = 0 clock speed set SCK Frequency as fosc / 16
	SPCR &= ~((1<<CPOL) | (1<<CPHA)); // No Polarity
	
	PORTB |= (1 << PB2); 
	
	_delay_ms(100);

	PORTB &= ~(1<<PORTB2); // Before sending data SS should be low , to select slave
	SPDR = (0xD0|0x80);    // address 0f chip value is OR to keep the msb as 1 , so that slave knows it is in read mode
    while (!(SPSR & (1<<SPIF))); // waiting till SPIF becomes 1
    dummy=SPDR; // clear the bit SPIF
	//PORTB |= (1<<PORTB2);  // Deselect Slave
	
	//PORTB &=~(1<<PORTB2);
	SPDR=0x00; // 0x00 or 0xFF is sent to receive data from slave
	while (!(SPSR & (1<<SPIF)));
	chip_ID = SPDR;
	PORTB |= (1<<PORTB2);
	 _delay_ms(100);
	
	while (1)
	{
		if(chip_ID==0x58)
		{
			PORTD|=(1<<PD3);
		}
		else
		{
			PORTD &=~(1<<PD3);
		}
	}

	
	
}

