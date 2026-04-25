
#include <stdio.h>
#include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    adc_oneshot_unit_handle_t handle;               //created handle
    adc_oneshot_unit_init_cfg_t init_config;        // declaration of init config
    init_config.unit_id = ADC_UNIT_1;               //selected ADC unit 1 as our ADC
    init_config.ulp_mode = ADC_ULP_MODE_DISABLE;
    adc_oneshot_new_unit(&init_config, &handle);    // passing handle config to new unit 
    
    adc_oneshot_chan_cfg_t config;
    config.atten = ADC_ATTEN_DB_12;             // voltage range 0-3.3 v  can be counted as  0-4095
    config.bitwidth = ADC_BITWIDTH_DEFAULT;     //12 BIT ADC

    adc_oneshot_config_channel(handle, ADC_CHANNEL_6, &config);  // passing handle,channel value and configuration settings to  channel configuration struct

    while(1)
{
    int raw = 0;
    adc_oneshot_read(handle, ADC_CHANNEL_6, &raw);


    float voltage = (raw * 3.3) / 4095;
    float temp = ((voltage * 100.0)+10);

    printf("Temperature = %f C\n", temp);

    //printf("Raw ADC Vlaue = %d\n ",raw);
    vTaskDelay(pdMS_TO_TICKS(1000));


}
}
    