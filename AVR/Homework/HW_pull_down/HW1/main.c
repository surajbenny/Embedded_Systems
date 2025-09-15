# define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)

{
	DDRC=0b00000000;	
	DDRD=0b00001000;
    while (1) 
    {
		if (PINC==0b00000001)
		{
			PORTD=0b00001000;
		}
		else
		{
			PORTD=0b00000000;
		}
	}
}
