/*
 * oled.c
 *
 * Created: 04-07-2026 01:38:25
 *  Author: My PC
 */ 
#include "oled.h"
#include "I2C.h"

#define OLED_ADDR 0x78      // 0x3C << 1

void OLED_Init(void)
{
	OLED_Command(0xAE);   // Display OFF

	OLED_Command(0x20);   // Memory Addressing Mode
	OLED_Command(0x00);   // Horizontal Addressing

	OLED_Command(0xB0);   // Page 0

	OLED_Command(0xC8);   // COM Scan Direction

	OLED_Command(0x00);   // Low Column
	OLED_Command(0x10);   // High Column

	OLED_Command(0x40);   // Start Line

	OLED_Command(0x81);   // Contrast
	OLED_Command(0x7F);

	OLED_Command(0xA1);   // Segment Remap

	OLED_Command(0xA6);   // Normal Display

	OLED_Command(0xA8);   // Multiplex Ratio
	OLED_Command(0x3F);

	OLED_Command(0xD3);   // Display Offset
	OLED_Command(0x00);

	OLED_Command(0xD5);   // Clock Divide
	OLED_Command(0x80);

	OLED_Command(0xD9);   // Precharge
	OLED_Command(0xF1);

	OLED_Command(0xDA);   // COM Pins
	OLED_Command(0x12);

	OLED_Command(0xDB);   // VCOMH
	OLED_Command(0x40);

	OLED_Command(0x8D);   // Charge Pump
	OLED_Command(0x14);

	OLED_Command(0xAF);   // Display ON
}
void OLED_Command(uint8_t cmd)
{
	I2C_Start();

	I2C_Write(OLED_ADDR);   // Slave Address + Write

	I2C_Write(0x00);        // Command mode

	I2C_Write(cmd);

	I2C_Stop();
}

void OLED_Data(uint8_t data)
{
	I2C_Start();

	I2C_Write(OLED_ADDR);

	I2C_Write(0x40);        // Data mode

	I2C_Write(data);

	I2C_Stop();
}

void OLED_Clear(void)
{
	uint8_t page;
	uint8_t column;

	for(page = 0; page < 8; page++)
	{
		OLED_Command(0xB0 + page);

		OLED_Command(0x00);

		OLED_Command(0x10);

		for(column = 0; column < 128; column++)
		{
			OLED_Data(0x00);
		}
	}
}