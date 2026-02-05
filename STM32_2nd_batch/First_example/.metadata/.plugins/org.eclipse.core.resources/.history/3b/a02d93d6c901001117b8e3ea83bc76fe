/*
 * stm32_f446xx_gpio_driver.c
 *
 *  Created on: Feb 2, 2026
 *      Author: My PC
 */


#include "stm32_f446xx_gpio_driver.h"

/**
 * @fn        GPIO_PerClockControl
 * @brief     Enables or disables the peripheral clock for the specified GPIO port.
 *
 * @param[in] pGPIOx  Base address of the GPIO peripheral (e.g., GPIOA, GPIOB)
 * @param[in] EnorDi  Macro to enable or disable the clock (ENABLE or DISABLE)
 *
 * @return    None
 *
 * @note      This must be called before using any GPIO functions on the port.
 */


void GPIO_PericClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}		if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}

	}
	else
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}		if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
}

	/**
	 * @fn           	GPIO_Init
	 * @brief    	 	This function initialise the GPIO port pin.
	 *
	 * @param[in] 		pGPIO_Handle_t pointer to GPIO handle structure
	 *
	 *
	 * @return    		None
	 *
	 * @note		    refer macros for gpio configuration
	 */


void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)

/**
 * @fn        		GPIO_ReadFromInputPin
 *
 * @brief    		This function is used to read the value in a gpio pin .
 *
 * @param[in] 		GPIO_RegDef_t pointer to GPIO GPIO_RegDef_t structure
 *
 * @param[in]		PinNumber
 *
 * @return    		uint8_t value (value inside that pin)
 *
 * @note      		refer macros for gpio configuration
 */
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = uint8_t ((pGPIOx->IDR)>>(PinNumber) & 0x00000001);
	return value;
}

/**
 * @fn        		GPIO_ReadFromInputPort
 *
 * @brief    		This function is used to read the value in a gpio port .
 *
 * @param[in] 		GPIO_RegDef_t pointer to GPIO GPIO_RegDef_t structure
 *
 * @param[in]		PinNumber
 *
 * @return    		uint8_t value (value inside that pin)
 *
 * @note      		refer macros for gpio configuration
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value =(uint16_t)(pGPIOx->IDR);
	return value;
}

/**
 * @fn        		GPIO_WriteToOutputPin
 *
 * @brief    		This function is used to read the value in a gpio port .
 *
 * @param[in] 		GPIO_RegDef_t pointer to GPIO GPIO_RegDef_t structure
 *
 * @param[in]		PinNumber
 *
 * @return    		uint8_t value (value inside that pin)
 *
 * @note      		refer macros for gpio configuration
 */

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value ==1)
	{
		(pGPIOx->ODR) |= (1<< PinNumber);
	}
	else
	{
		(pGPIOx->ODR) &= ~(1<< PinNumber);
	}
}

}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber)
{
	(pGPIOx->ODR) ^= (1<<PinNumber);

}
