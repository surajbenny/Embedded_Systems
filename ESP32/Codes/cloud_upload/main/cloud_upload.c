
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_adc/adc_oneshot.h"

#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "nvs_flash.h"


#include "esp_http_client.h"

#define SSID "Suraj"
#define PASSWORD "123456789"   


void send_to_cloud(int temp)
{
    char url[200];

    sprintf(url,
    "http://api.thingspeak.com/update?api_key=MQ4O6NDDUWQTP93Z&field1=%d",
    temp);

    esp_http_client_config_t cloud_config = {
        .url = url
    };

    esp_http_client_handle_t client = esp_http_client_init(&cloud_config);
    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}


static void wifi_event_handler(void* arg,esp_event_base_t event_base,int32_t event_id,void* event_data)
{
    if(event_base ==  WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        printf("WIFI Started \n");
        esp_wifi_connect();
    }

    else if (event_base ==  IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        printf("Connection succesful \n");
        
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        printf("Got IP :" IPSTR "\n",IP2STR(&event -> ip_info.ip));
    }

    else if (event_base ==  WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        printf("Wifi Disconnected \n");
        wifi_event_sta_disconnected_t* event = (wifi_event_sta_disconnected_t*)event_data;
        printf("Reason : %d \n",event->reason);
        esp_wifi_connect();
    
    }
}



void app_main(void)
{

// wifi configuration

    nvs_flash_init();
    esp_netif_init();

    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
    esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);

    wifi_config_t config = {
    .sta = {
    .ssid = SSID,
    .password = PASSWORD,
    },
    };

    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(WIFI_IF_STA, &config);
    esp_wifi_start();


    //ADC configuration

    adc_oneshot_unit_handle_t handle;               //created handle
    adc_oneshot_unit_init_cfg_t init_config;        // declaration of init config
    init_config.unit_id = ADC_UNIT_1;               //selected ADC unit 1 as our ADC
    init_config.ulp_mode = ADC_ULP_MODE_DISABLE;
    adc_oneshot_new_unit(&init_config, &handle);    // passing handle config to new unit 
    
    adc_oneshot_chan_cfg_t adc_config;
    adc_config.atten = ADC_ATTEN_DB_12;             // voltage range 0-3.3 v  can be counted as  0-4095
    adc_config.bitwidth = ADC_BITWIDTH_DEFAULT;     //12 BIT ADC

    adc_oneshot_config_channel(handle, ADC_CHANNEL_6, &adc_config);  // passing handle,channel value and configuration settings to  channel configuration struct


    while(1)
    {
    int raw = 0;
    adc_oneshot_read(handle, ADC_CHANNEL_6, &raw);


    float voltage = (raw * 3.3) / 4095;
    float temp = ((voltage * 100.0)+10);

    printf("Temperature = %f C\n", temp);
    send_to_cloud(temp);

    //printf("Raw ADC Vlaue = %d\n ",raw);
    vTaskDelay(pdMS_TO_TICKS(15000));  //(15000 because of cloud limitation)

    }
}
