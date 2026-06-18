/*
 * Temp_Read_I2C.c
 *
 *  Created on: Jun 10, 2026
 *      Author: My PC
 */

#include <stdio.h>
#include <string.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_i2c_driver.h"
#include "stm32f446xx_usart_driver.h"


I2C_Handle_t   I2C1_handle;
USART_Handle_t Uart_handle;

void GPIO_Config_LED()
{
	GPIO_Handle_t led;
	led.pGPIOx = GPIOA;
	led.GPIO_PinConfig.GPIO_PinMode=1;
	led.GPIO_PinConfig.GPIO_PinNumber=5;
	led.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	led.GPIO_PinConfig.GPIO_PinPuPdControl=0;
			led.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;
			GPIO_Init(&led);


}
void Gpio_I2C()
{
	GPIO_Handle_t GPIO_I2C;

	GPIO_I2C.pGPIOx = GPIOB;
	GPIO_I2C.GPIO_PinConfig.GPIO_PinAltFunMode= 4;             // I2C selected
	GPIO_I2C.GPIO_PinConfig.GPIO_PinMode= GPIO_MODE_ALTFN;

	GPIO_I2C.GPIO_PinConfig.GPIO_PinOPType=GPIO_OP_TYPE_OD;
	GPIO_I2C.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_PIN_PU;
	GPIO_I2C.GPIO_PinConfig.GPIO_PinSpeed=GPIO_SPEED_FAST;

	GPIO_I2C.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_6;
	GPIO_Init(&GPIO_I2C);

	GPIO_I2C.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_9;
	GPIO_Init(&GPIO_I2C);
}

void GPIO_UART()
{
	GPIO_Handle_t Uart_handle;

	Uart_handle.pGPIOx = GPIOA;
	Uart_handle.GPIO_PinConfig.GPIO_PinAltFunMode  = 7;
	Uart_handle.GPIO_PinConfig.GPIO_PinMode        = GPIO_MODE_ALTFN ;
	Uart_handle.GPIO_PinConfig.GPIO_PinNumber      = GPIO_PIN_NO_2;          // USB Tx is connected TO PA2
	Uart_handle.GPIO_PinConfig.GPIO_PinOPType      = GPIO_OP_TYPE_PP;
	Uart_handle.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Uart_handle.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_FAST;

	GPIO_Init(&Uart_handle);


}

void I2C_Config_init()
{


	I2C1_handle.pI2Cx = I2C1;
	I2C1_handle.I2C_Config.I2C_AckControl=I2C_ACK_ENABLE;
	I2C1_handle.I2C_Config.I2C_DeviceAddress=0x61;
	I2C1_handle.I2C_Config.I2C_FMDutyCycle =I2C_FM_DUTY_2;
	I2C1_handle.I2C_Config.I2C_SCLSpeed =I2C_SCL_SPEED_SM;

	I2C_Init(&I2C1_handle);
}

void UART_I2C_config()
{


	Uart_handle.pUSARTx = USART2;
	Uart_handle.USART_Config.USART_Baud =USART_STD_BAUD_115200;
	Uart_handle.USART_Config.USART_HWFlowControl= USART_HW_FLOW_CTRL_NONE;
	Uart_handle.USART_Config.USART_Mode= USART_MODE_ONLY_TX;
    Uart_handle.USART_Config.USART_NoOfStopBits=USART_STOPBITS_1;
	Uart_handle.USART_Config.USART_ParityControl=USART_PARITY_DISABLE;
	Uart_handle.USART_Config.USART_WordLength=USART_WORDLEN_8BITS;

	USART_Init(&Uart_handle);

}

int main()
{
    uint8_t reg_add = 0xFA;   //BMP temp reg starting address
    uint8_t Temp_value[3];
    int32_t adc_T;
    GPIO_Config_LED();
    Gpio_I2C();
    GPIO_UART();
    I2C_Config_init();
    UART_I2C_config();

    I2C_PeripheralControl(I2C1, ENABLE);
    USART_PeripheralControl(USART2,ENABLE);



    while(1)
    {
        uint8_t reg_add = 0xD0;
        uint8_t data[3];

        I2C_MasterSendData(&I2C1_handle,
                           &reg_add,
                           1,
                           0x76,
                           I2C_ENABLE_SR);

        I2C_MasterReceiveData(&I2C1_handle,
                              data,
                              2,
                              0x76,
                              I2C_DISABLE_SR);

        USART_SendData(&Uart_handle,
                       (uint8_t*)"DONE\r\n",
                       6);

        for(uint32_t i=0;i<1000000;i++);
    }
}
