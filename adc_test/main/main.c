#include <stdio.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

static esp_adc_cal_characteristics_t adc1_chars;

void app_main(void)
{
    esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);

    adc1_config_width(ADC_WIDTH_BIT_DEFAULT);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
    int voltage;

    while (1) 
    {
        int adc_value = adc1_get_raw(ADC1_CHANNEL_4);
        voltage = esp_adc_cal_raw_to_voltage(adc_value, &adc1_chars);
        printf("Voltage: %d mV", voltage);
        printf("\n");
        vTaskDelay(10/ portTICK_PERIOD_MS);
    }
}
