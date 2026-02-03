/*
 * stm32_f446xx_gpio_driver.h
 *
 *  Created on: Feb 2, 2026
 *      Author: My PC
 */

#ifndef INC_STM32_F446XX_GPIO_DRIVER_H_
#define INC_STM32_F446XX_GPIO_DRIVER_H_

#include "Stm32_f446xx.h"


/*
 * GPIO Pin Configuration Structure
 * Describes how a specific GPIO pin should be configured.
 */
typedef struct {
    uint8_t GPIO_PinNumber;        // Pin number (0–15)
    uint8_t GPIO_PinMode;          // Mode: Input, Output, AltFn, Analog
    uint8_t GPIO_PinSpeed;         // Speed: Low, Medium, High, Very High
    uint8_t GPIO_PinPuPdControl;   // Pull-up / Pull-down configuration
    uint8_t GPIO_PinOPType;        // Output type: Push-pull / Open-drain
    uint8_t GPIO_PinAltFunMode;    // Alternate function (AF0–AF15)
} GPIO_PinConfig_t;

/*
 * GPIO Handle Structure
 * Combines the GPIO port base address and pin configuration.
 */
typedef struct {
    GPIO_RegDef_t *pGPIOx;         // Pointer to GPIO port (e.g., GPIOA, GPIOB)
    GPIO_PinConfig_t GPIO_PinConfig; // Pin configuration settings
} GPIO_Handle_t;


/*
 * GPIO Pin Number Definitions
 * Symbolic names for GPIO pin numbers (0–15)
 */
#define GPIO_PIN_NO_0     0
#define GPIO_PIN_NO_1     1
#define GPIO_PIN_NO_2     2
#define GPIO_PIN_NO_3     3
#define GPIO_PIN_NO_4     4
#define GPIO_PIN_NO_5     5
#define GPIO_PIN_NO_6     6
#define GPIO_PIN_NO_7     7
#define GPIO_PIN_NO_8     8
#define GPIO_PIN_NO_9     9
#define GPIO_PIN_NO_10    10
#define GPIO_PIN_NO_11    11
#define GPIO_PIN_NO_12    12
#define GPIO_PIN_NO_13    13
#define GPIO_PIN_NO_14    14
#define GPIO_PIN_NO_15    15


/*
 * GPIO Modes
 */

#define GPIO_MODE_INPUT        0  // 00: Input mode
#define GPIO_MODE_OUTPUT       1  // 01: Output mode
#define GPIO_MODE_ALTFN        2  // 10: Alternate function mode
#define GPIO_MODE_ANALOG       3  // 11: Analog mode



/*
 * GPIO SPEED
 */

#define GPIO_SPEED_LOW         0
#define GPIO_SPEED_MEDIUM      1
#define GPIO_SPEED_FAST        2
#define GPIO_SPEED_HIGH        3

/*
 * GPIO PINPUPD CONTROL
 */

#define GPIO_PUPD_NO         0
#define GPIO_PULL_UP      	 1
#define GPIO_PULL_DOWN       2



/*
 * Peripheral Clock Control
 * Enables or disables clock for the given GPIO port.
 */
void GPIO_PericClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * GPIO Initialization and Deinitialization
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * GPIO Read Operations
 */
uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

/*
 * GPIO Write Operations
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);






#endif /* INC_STM32_F446XX_GPIO_DRIVER_H_ */
