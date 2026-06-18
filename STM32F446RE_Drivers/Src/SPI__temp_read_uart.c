/*
 * SPI__temp_read_uart.c
 *
 *  Created on: Jun 12, 2026
 *      Author: My PC
 */


#include <stdio.h>
#include <string.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_i2c_driver.h"
#include "stm32f446xx_usart_driver.h"
#include "stm32f446xx_spi_driver.h"


USART_Handle_t UART_handle;
SPI_Handle_t  SPI_handle;


void GPIO_SPI_INIT_CONFIG()
{
	GPIO_Handle_t GPIO_SPI_Handle;

	GPIO_SPI_Handle.pGPIOx = GPIOA;
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;

	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;


	//SCLK
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_5;
	GPIO_Init(&GPIO_SPI_Handle);
	//MISO
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_6;
	GPIO_Init(&GPIO_SPI_Handle);
	//MOSI
	GPIO_SPI_Handle.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_7;
	GPIO_Init(&GPIO_SPI_Handle);


}

void GPIO_CS_INIT()
{
	GPIO_Handle_t GPIO_CS_handle;

	GPIO_CS_handle.pGPIOx = GPIOA;

	GPIO_CS_handle.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_OUT;

	GPIO_CS_handle.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_CS_handle.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_CS_handle.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;



	//NSS
	GPIO_CS_handle.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_4;
	GPIO_Init(&GPIO_CS_handle);
}

void GPIO_UART_INIT_CONFIG()
{
	GPIO_Handle_t GPIO_UART_Handle;

	GPIO_UART_Handle.pGPIOx = GPIOA;
	GPIO_UART_Handle.GPIO_PinConfig.GPIO_PinAltFunMode= 7;
	GPIO_UART_Handle.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_ALTFN;
	GPIO_UART_Handle.GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_NO_2;
	GPIO_UART_Handle.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	GPIO_UART_Handle.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PUPD;
	GPIO_UART_Handle.GPIO_PinConfig.GPIO_PinSpeed= GPIO_SPEED_FAST;

	GPIO_Init(&GPIO_UART_Handle);
}

void UART_INIT_CONFIG()
{
	UART_handle.pUSARTx= USART2;
	UART_handle.USART_Config.USART_Baud             = USART_STD_BAUD_115200;
	UART_handle.USART_Config.USART_HWFlowControl    = USART_HW_FLOW_CTRL_NONE;
	UART_handle.USART_Config.USART_Mode             = USART_MODE_ONLY_TX;
	UART_handle.USART_Config.USART_NoOfStopBits     = USART_STOPBITS_1;
	UART_handle.USART_Config.USART_ParityControl    = USART_PARITY_DISABLE;
	UART_handle.USART_Config.USART_WordLength       = USART_WORDLEN_8BITS;

	USART_Init(&UART_handle);
}

void SPI_INIT_CONFIG()
{
	SPI_handle.pSPIx                    = SPI1 ;

	SPI_handle.SPIConfig.SPI_BusConfig  = SPI_BUS_CONFIG_FD;
	SPI_handle.SPIConfig.SPI_CPHA       =SPI_CPHA_LOW;
	SPI_handle.SPIConfig.SPI_CPOL       = SPI_CPOL_LOW;
	SPI_handle.SPIConfig.SPI_DFF        = SPI_DFF_8BITS;
	SPI_handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI_handle.SPIConfig.SPI_SSM        = SPI_SSM_EN;
	SPI_handle.SPIConfig.SPI_SclkSpeed  = SPI_SCLK_SPEED_DIV8;

	SPI_Init(&SPI_handle);

}



char arr[30];

int main()
{
	uint8_t reg_add = 0xD0 | 0x80;   // Read bit set
	uint8_t dummy_tx = 0xFF;
	uint8_t dummy_rx;
	uint8_t chip_id;


	GPIO_SPI_INIT_CONFIG();
	GPIO_CS_INIT();
	GPIO_UART_INIT_CONFIG();

	UART_INIT_CONFIG();
	SPI_INIT_CONFIG();

	//PERIPHERAL enable
	SPI_PeripheralControl(SPI1,ENABLE);
	USART_PeripheralControl(USART2, ENABLE);




while(1)
		{




	    SPI_SSIConfig(SPI1, ENABLE);     // Keep NSS(CSB) high internally since we are not using the NSS pin

		//CSB low  Select BMP280
		GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_4, GPIO_PIN_RESET);

		SPI_SendData(SPI1,&reg_add,1);           // Send register address



		SPI_ReceiveData(SPI1, &chip_id,1);		// actual chip ID


		// Deselect BMP280
		GPIO_WriteToOutputPin(GPIOA,GPIO_PIN_NO_4, GPIO_PIN_SET);


		char arr[10];
		sprintf(arr,"Chip ID: %X\r\n",chip_id);


		USART_SendData(&UART_handle,(uint8_t*)arr,strlen(arr));
		for(uint32_t i=0;i<500000;i++);







	}

}
