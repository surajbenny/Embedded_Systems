/*
 * uart.h
 *
 * Created: 03-07-2026 22:01:12
 *  Author: My PC
 */ 


#ifndef UART_H_
#define UART_H_



#include <avr/io.h>

void UART_Init(void);

void UART_SendChar(char data);

void UART_SendString(const char *str);


#endif /* UART_H_ */