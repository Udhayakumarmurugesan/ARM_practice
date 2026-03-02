#include<stdio.h>
#include"ultrasonic_sensor.h"
int main(void) {
    float distance = 0;

    VPBDIV = 0x01;    // PCLK = CCLK = 60MHz
    LCD_INIT();
    US_init();

    LCD_COMMAND(0x80);
    LCD_STR("Ultrasonic Sensor");
    delay_ms(1000);
    LCD_COMMAND(0x01);

    while (1) {
        sendTrigger();
        distance = measurePulse();

        LCD_COMMAND(0x80);
        LCD_STR("Distance:");

        LCD_COMMAND(0xC0);
        if (distance == 0) {
            LCD_STR("No object     ");
        } else {
            LCD_DECIMAL(distance);
            LCD_STR(" cm   ");
        }

        delay_ms(500);
    }
}

