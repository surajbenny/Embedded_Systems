/*
 * oled.h
 *
 * Created: 04-07-2026 01:37:47
 *  Author: My PC
 */ 


#ifndef OLED_H_
#define OLED_H_

#include <stdint.h>
#include <avr/io.h>

void OLED_Init(void);
void OLED_Command(uint8_t cmd);
void OLED_Data(uint8_t data);
void OLED_Clear(void);




#endif /* OLED_H_ */