/*
 * SPI_Temperature_read.c
 *
 * Created: 15-11-2025 14:55:54
 * Author : My PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main ()
{
	uint32_t dummy, MSB,LSB,XLSB, temp;
	
	                                                             
	DDRB |= (1 << DDB3) | (1 << DDB5) | (1 << DDB2) |(1 << DDB0);   // Set MOSI, SCK, and SS as output
	
	DDRB &= ~ (1 << DDB4);  // Set MISO as input
	
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI and Master mode. Set clock rate fosc / 16
	//Select SPI mode to MODE 0.
	SPCR &= ~ ((1 << CPOL) | (1 << CPHA));
	
	
	// ====== READ TEMPERATURE REGISTERS (0xFA,0xFB,0xFC) =====
	
	
	
	PORTB &= ~ (1 << PB2); // Pull SS low to select slave
	
	SPDR = 0XFA | 0X80;  // For read operation, MSB=1, hence OR register address with 0XFA
	// Wait until transmission is complete
	while (! (SPSR & (1 << SPIF)));
	//To reset SPIF bit, read the SPDR data (copy data to a variable)
	dummy = SPDR; //Here we get random value stored in slave [ Equivalent expression without using dummy : (void)SPDR
	//For reading the Value in OxFA, send 0X00 so that data from slave comes to master.
	SPDR = 0X00;
	// Wait until transmission is complete
	while (! (SPSR & (1 << SPIF)));
	// Read value in address 0xfa which is now in SPDR
	MSB = SPDR; // Here the original data (MSB Value in 0xFA) is obtained
	
	//(here microcontroller know it is 20 bit )
	
	//---READ LSB---
	
	//SPDR = 0XFB|0X80;
	//while(!(SPSR & (1<<SPIF)));
	//dummy=SPDR;
	SPDR= 0x00;
	while(!(SPSR &(1<<SPIF)));
	LSB=SPDR;
	
	
	//----READ XLSB-----
	
	//SPDR=0xFC|0X80;
	//while (!(SPSR & (1<<SPIF)));
	//dummy=SPDR;
	SPDR=0X00;
	while(!(SPSR & (1<<SPIF)));
	XLSB=SPDR;
	
	PORTB |=(1 << PB2);   //CSB high
	
	temp = ((uint32_t)MSB<< 12) | ((uint32_t)LSB << 4) | ((uint32_t)XLSB >> 4); // you have to use uint32 separate because it is 20 bit data and may throw an error if not given uint32 sepearte for each
	
	
	UART_TxString("Raw Temp: ");
	UART_TxNumber(temp);       // print raw temperature
	UART_TxChar('\n');

	

}