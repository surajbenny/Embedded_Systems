/*
 * Push_button1_led_on.c
 *
 *  Created on: Feb 8, 2026
 *      Author: My PC
 */


#include "stm32_f446xx.h"
#include "stm32_f446xx_gpio_driver.h"

int main()
{

		GPIO_Handle_t GPIO_LED;
		GPIO_LED.pGPIOx = GPIOA;
		GPIO_LED.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_5;
		GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
		GPIO_LED.GPIO_PinConfig.GPIO_PinOPType= 0;
		GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;

		GPIO_Init(&GPIO_LED);


		GPIO_Handle_t GPIO_Btn1;
		GPIO_Btn1.pGPIOx = GPIOC;
		GPIO_Btn1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GPIO_Btn1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
		GPIO_Btn1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GPIO_Btn1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_SPEED_FAST;
		GPIO_Init(&GPIO_Btn1);

		while(1)
		{
			uint8_t Butn1_state = GPIO_ReadFromInputPin(GPIOC,GPIO_PIN_NO_13);

			if (Butn1_state==0)
				{
				GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,1);

				}
			else
			{
				GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_5,0);
			}
		}
}
