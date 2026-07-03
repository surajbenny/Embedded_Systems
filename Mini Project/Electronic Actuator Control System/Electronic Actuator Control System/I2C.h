/*
 * I2C.h
 *
 * Created: 04-07-2026 01:13:33
 *  Author: My PC
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>

void I2C_Init(void);

void I2C_Start(void);

void I2C_Stop(void);

void I2C_Write(uint8_t data);



#endif /* I2C_H_ */