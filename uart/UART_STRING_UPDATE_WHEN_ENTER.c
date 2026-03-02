#include <LPC21XX.h>
#include "lcd_n.h"

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
    unsigned char buffer[50];
	unsigned char ch;
	int i;
	UART0_CONFIG();
	LCD_INIT();
	i=0;
	while(1){
		ch=UART0_RX();
		UART0_TX(ch);
		if(ch=='\r'){
			LCD_COMMAND(0x01);
			LCD_COMMAND(0x80);
			LCD_STR(buffer);
			i=0;
		}
		else{
			buffer[i++]=ch;
		}
	}
}
