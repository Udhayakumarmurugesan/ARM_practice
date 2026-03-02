#include"uart_driver.h"
#define LEDs (0xFF)
void delay(unsigned int ms){
	T0PR=15000-1;
	T0TCR=0x01;
	while(T0TC<ms);
	T0TCR=0x03;
	T0TCR=0x00;
}

void LED_DIV(void){
	int led; 
	for(led=7;led>=0;led--){
	  IOCLR0=LED;
	  IOSET0=(1<<led)|(1<<(7-led));
	  delay(500);
	  }
}

void LED_CON(void){
	int led;
	for(led=0; led<4;led++){
            IOCLR0=LED;
            IOSET0=(1<<(3-led))|(1<<(4+led));
            delay(500);
        	}
}

int main(){
	UART0_CONFIG();
	IODIR0=(LEDs<<2);
	IOSET0=(LEDs<<2);

	while(1){
	unsigned char ch;
	 ch=UART0_RX();
	 if(ch=='1'){
	 LED_CON();
	 }

	 else if(ch=='2'){
	 LED_DIV();
	 }
	}
 }



