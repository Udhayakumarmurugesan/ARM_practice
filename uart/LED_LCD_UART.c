//Make sure that you should have LCD Driver from the LCD folder on my github repository to make this function

#include <LPC21XX.h>
#include "lcd_n.h"

#define LED1 (1 << 17)
#define LED2 (1 << 18)
#define LED3 (1 << 19)

void UART0_CONFIG(void) {
    PINSEL0 = 0x5; 
    U0LCR = 0x83; 
    U0DLL = 97;  
    U0DLM = 0;
    U0LCR = 0x03; 
}

void UART0_TX(unsigned char txByte) {
    while (((U0LSR >> 5) & 1) == 0);
    U0THR = txByte;
}

unsigned char UART0_RX() {
    while ((U0LSR & 1) == 0);
    return U0RBR;
}

int main() {
    unsigned char rxByte;

    LCD_INIT();               
    UART0_CONFIG();         
    IODIR0 = LED1|LED2|LED3;   
	IOSET0=LED1|LED2|LED3;
    LCD_COMMAND(0x01);      
    LCD_COMMAND(0x80);
	LCD_STR("Type cmd");      

    while (1) {
        rxByte = UART0_RX(); 

        if (rxByte == '1') {
            IOCLR0 = LED1;       
            LCD_COMMAND(0x01);
            LCD_COMMAND(0x80);
            LCD_STR("LED 1 ON");
        }
        else if (rxByte == '2') {
            IOCLR0 = LED2;      
            LCD_COMMAND(0x01);
            LCD_COMMAND(0x80);
            LCD_STR("LED 2 ON");
        }
		else if (rxByte == '3') {
            IOCLR0 = LED3;      
            LCD_COMMAND(0x01);
            LCD_COMMAND(0x80);
            LCD_STR("LED 3 ON");
        }


		else if (rxByte == '4') {
            IOSET0 = LED1;      
            LCD_COMMAND(0x01);
            LCD_COMMAND(0x80);
            LCD_STR("LED 1 OFF");
        }
		else if (rxByte == '5') {
            IOSET0 = LED2;      
            LCD_COMMAND(0x01);
            LCD_COMMAND(0x80);
            LCD_STR("LED 2 OFF");
        }
		else if (rxByte == '6') {
            IOSET0 = LED3;      
            LCD_COMMAND(0x01);
            LCD_COMMAND(0x80);
            LCD_STR("LED 3 OFF");
        }
		
    }
}
