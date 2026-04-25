#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define led_pin GPIO_NUM_2

void app_main(void)
{
    gpio_reset_pin(led_pin); // reset pin
    gpio_set_direction(led_pin,GPIO_MODE_OUTPUT); 
while(1)
{
gpio_set_level(led_pin,1); //pin2 high
vTaskDelay(pdMS_TO_TICKS(1000)); // Command to provide 1s delay  (freeRTOS)

gpio_set_level(led_pin,0); //pin2 low
vTaskDelay(pdMS_TO_TICKS(1000)); // Command to provide 1s delay 
}
}
