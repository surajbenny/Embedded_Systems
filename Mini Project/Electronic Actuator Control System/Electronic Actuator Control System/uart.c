/*
 * uart.c
 *
 * Created: 03-07-2026 22:01:23
 *  Author: My PC
 */ 
#include "uart.h"

void UART_Init(void)
{

	UBRR0 = 103;								  // Baud Rate  
	UCSR0B = (1<<TXEN0) | (1<<RXEN0);			 //Enable TX and RX 
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);          //8-bit, No parity, 1 Stop
}

void UART_SendChar(char data)
{
	while(!(UCSR0A & (1<<UDRE0)));

	UDR0 = data;
}

void UART_SendString(const char *str)
{
	while(*str)
	{
		UART_SendChar(*str);

		str++;
	}
}