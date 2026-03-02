#include"lcd_n.h"
#define DHT_PIN (1<<4)

void DHT11_INIT(void){
	IODIR0|=DHT_PIN;
	IOCLR0=DHT_PIN;
	delay_ms(20);
	IOSET0=DHT_PIN;
	IODIR0&=~DHT_PIN;
	delay_us(30);
}
void DHT11_CheckResponse(){
    while (IOPIN0&DHT_PIN);
    while (!(IOPIN0 &DHT_PIN));
    while (IO0PIN&DHT_PIN);
}
int DHT11_Readbyte(void) {
   unsigned int i,data = 0;
    for (i=0;i<8;i++)
     {
        while (!(IO0PIN&DHT_PIN));
        delay_us(30);
        if(IO0PIN&DHT_PIN)
            data=(data<< 1)| 1;
        else
            data=(data << 1);
        while(IOPIN0&DHT_PIN);
    }
    return data;
}

