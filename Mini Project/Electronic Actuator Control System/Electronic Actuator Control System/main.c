/*
 * Electronic Actuator Control System.c
 *
 * Created: 03-07-2026 13:54:31
 * Author : My PC
 */

 #include "gpio.h"
 #include "adc.h"
 #include "servo.h"
 #include "uart.h"
 #include "actuator.h"
 #include <avr/io.h>
 #define F_CPU 16000000UL
 #include <util/delay.h>
 
 int main(void)
 {
	 GPIO_Init();
	 ADC_Init();
	 Servo_Init();
	 UART_Init();
	 I2C_Init();
	 OLED_Init();
	 OLED_Clear();


	while(1)
	{
		Actuator_Update();
	}
	

 }