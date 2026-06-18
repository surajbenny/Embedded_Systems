/*
 * UART_data_Send.c
 *
 *  Created on: Jun 6, 2026
 *      Author: My PC
 */


		#include <stdio.h>
		#include <string.h>
#include "stm32f446xx.h"
#include "stm32f446xx_usart_driver.h"
#include "stm32f446xx_gpio_driver.h"

char msg[] = "Button pressed..\r\n";

USART_Handle_t USART2_Handle;

void Button_gpio(void)
{
	GPIO_Handle_t GPIO_Button;

	GPIO_Button.pGPIOx = GPIOB;

	GPIO_Button.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_IN;
	GPIO_Button.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_5;

	GPIO_Button.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PIN_PU;
	GPIO_Button.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOB, ENABLE);
	GPIO_Init(&GPIO_Button);


}

void USRART2_Init(void)
{



	USART2_Handle.pUSARTx = USART2;
	USART2_Handle.USART_Config.USART_Baud = USART_STD_BAUD_115200;
	USART2_Handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	USART2_Handle.USART_Config.USART_Mode = USART_MODE_ONLY_TX;
	USART2_Handle.USART_Config.USART_NoOfStopBits =USART_STOPBITS_1;
	USART2_Handle.USART_Config.USART_ParityControl =USART_PARITY_DISABLE;
	USART2_Handle.USART_Config.USART_WordLength =USART_WORDLEN_8BITS;

	USART_Init(&USART2_Handle);
}

void USART2_GPIO(void)
{
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Handle_t USRT_gpio;

	USRT_gpio.pGPIOx = GPIOA;
	USRT_gpio.GPIO_PinConfig.GPIO_PinAltFunMode = 7;

	USRT_gpio.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	USRT_gpio.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PIN_PU;
	USRT_gpio.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	USRT_gpio.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;

	//for Tx
	USRT_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	GPIO_Init(&USRT_gpio);
	//for Rx
	USRT_gpio.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_3;
	GPIO_Init(&USRT_gpio);

}

int main(void)
{

	Button_gpio();
    USART2_GPIO();

    USRART2_Init();

    USART_PeripheralControl(USART2,ENABLE);

    while(1)
    {
    	    while(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_5)== 1);


    		 USART_SendData(&USART2_Handle,msg,strlen(msg));
    		 for(uint32_t i=0;i<500000;i++);

    		 while(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_5)==0);




     }
}





