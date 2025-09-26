/*
 * DC_motor_input_delay.c
 *
 * Created: 12-09-2025 16:18:13
 * Author : Suraj
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Custom delay function using 1 ms steps
void delay_user(int t) {
    for (int i = 0; i < t; i++) {
        _delay_ms(1);
    }
}


void cw(int t) {
    PORTB |= (1 << PORTB5);
    PORTB &= ~(1 << PORTB4);
    delay_user(t);
}


void stp(int t) {
    PORTB &= ~(1 << PORTB4);
    PORTB &= ~(1 << PORTB5);
    delay_user(t);
}


void ccw(int t) {
    PORTB |= (1 << PORTB4);
    PORTB &= ~(1 << PORTB5);
    delay_user(t);
}

int main(void) {
    DDRB |= (1 << DDB4) | (1 << DDB5);  

    while (1) {
        cw(3000);     
        stp(1000);    
        ccw(7000);    
        stp(1000);    
    }
}