#include <stdio.h>
#include <driver/gpio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED GPIO_NUM_2
#define BTN GPIO_NUM_4


void app_main(void)
{
    gpio_reset_pin(LED); // reset pin
    gpio_set_direction(LED,GPIO_MODE_OUTPUT);
    gpio_set_direction(BTN,GPIO_MODE_INPUT); 
    gpio_set_pull_mode(BTN, GPIO_PULLUP_ONLY);

    while(1)
    {
        if(gpio_get_level(BTN) == 0)  //pressed
            gpio_set_level(LED, 1);

        else
            gpio_set_level(LED, 0);
    }
}
