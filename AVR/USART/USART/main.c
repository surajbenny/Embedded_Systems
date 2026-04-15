/*
 * USART.c
 *
 * Created: 25-10-2025 15:10:56
 * Author : My PC
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void Init(void)
{
	 UBRR0L=103; // set baud rate as 9600
	 UBRR0H=0;
	 UCSR0B |= (1<<TXEN0);  // Enable transmission
	 UCSR0C |=(1<<UCSZ00)|(1<<UCSZ01); // 8-bit data mode
}

int main(void)
{
	int i;
	char a[]="hello\n"; // this is data

Init();

    while (1) 
    {
		for(i = 0; a[i] != '\0'; i++)
		{
			while (!(UCSR0A &= (1<<UDRE0))); // wait until UDR0 is ready
			UDR0=a[i];		
		}
    }
}

