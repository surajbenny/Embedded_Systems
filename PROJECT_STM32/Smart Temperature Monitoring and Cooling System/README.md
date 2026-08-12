# Smart Temperature Monitoring and Cooling System

## Overview

The Smart Temperature Monitoring and Cooling System is an embedded systems project developed using the STM32F446RE (ARM Cortex-M4) microcontroller. The system continuously monitors temperature using the BMP280 sensor. The measured temperature is displayed on an SSD1306 OLED display and transmitted over UART for debugging. An LED brightness is controlled using PWM to visually indicate the temperature level. When the temperature exceeds **33°C**, the cooling fan is automatically switched ON through an L293D motor driver.

---
## Project Demonstration

**Demo Video:**  
https://drive.google.com/file/d/1XHzOymF6VWv5NTq-1nIkLiiVKt9mzlR7/view?usp=sharing

## Features

- Real-time temperature monitoring using BMP280
- OLED display for temperature visualization
- UART serial output for debugging
- PWM-based LED brightness control according to temperature
- Automatic cooling fan control
- Fan turns ON when temperature exceeds **33°C**

---

## Hardware Used

- STM32 NUCLEO-F446RE
- BMP280 Temperature Sensor
- SSD1306 OLED Display
- DC Motor (Cooling Fan)
- L293D Motor Driver
- LED
- Breadboard
- Jumper Wires

---

## Software Used

- STM32CubeIDE
- STM32CubeMX
- Embedded C
- STM32 HAL Library
- PuTTY

---

## Communication Protocols

- SPI – BMP280 Sensor
- I2C – SSD1306 OLED Display
- UART – Debug Output
- PWM – LED Brightness Control
- GPIO – Fan Control

---

## Working Principle

1. Initialize SPI, I2C, UART, GPIO, and Timer peripherals.
2. Read temperature from the BMP280 sensor using SPI.
3. Display the measured temperature on the OLED display.
4. Print the temperature over UART for debugging.
5. Adjust the LED brightness using PWM based on the measured temperature.
6. If the temperature exceeds **33°C**, switch ON the cooling fan.
7. If the temperature drops below **33°C**, switch OFF the cooling fan.

---

## Temperature Control Logic

| Temperature | LED Brightness | Fan |
|-------------|----------------|-----|
| Below 30°C | Low | OFF |
| 30°C – 33°C | Medium | OFF |
| Above 33°C | High | ON |

---

## Skills Demonstrated

- Embedded C
- STM32 HAL
- ARM Cortex-M4
- GPIO
- SPI
- I2C
- UART
- PWM
- Timer Configuration
- Sensor Interfacing
- Embedded Firmware Development

## Author

**Suraj Benny**
