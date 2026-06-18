/*
 * LED_Button.c
 *
 *  Created on: May 29, 2026
 *      Author: My PC
 */


#include "stm32f446xx_gpio_driver.h"

int main()
{

	GPIO_Handle_t Button;

	Button.pGPIOx = GPIOB;

	Button.GPIO_PinConfig.GPIO_PinMode   = GPIO_MODE_IN;
	Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOC,ENABLE);
	GPIO_Init(&Button);

	GPIO_Handle_t LED;

	LED.pGPIOx = GPIOA;

	LED.GPIO_PinConfig.GPIO_PinMode          = GPIO_MODE_OUT;
	LED.GPIO_PinConfig.GPIO_PinNumber        = GPIO_PIN_NO_5;
	LED.GPIO_PinConfig.GPIO_PinOPType        = GPIO_OP_TYPE_PP;
	LED.GPIO_PinConfig.GPIO_PinPuPdControl   = GPIO_NO_PUPD;
	LED.GPIO_PinConfig.GPIO_PinSpeed         = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOA,ENABLE);
	GPIO_Init(&LED);


	while(1)
	{

		if(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_5) == 0)
		{
			GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
			for(uint32_t i=0;i<300000;i++);
		}
	}
}
