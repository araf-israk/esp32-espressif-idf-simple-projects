#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LED_PIN 2

void app_main(void)
{
    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    int ON = 0;

    char character = 0;
    char str[100];
    memset(str,0,sizeof(str));

    while (character != '\n')
    {
        character = getchar();
        if(character != 0xff){
            str[strlen(str)] = character;
            printf("%c", character);
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    printf("User Entered: %s\n", str);
}
