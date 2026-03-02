#include <LPC21xx.h>
#define SW 1<<14
void delay(unsigned int time){
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<6000;j++);
}

int main(){
    unsigned int x = 15000; 
	PINSEL1=0x400;
    PWMMR0 = 300000;
    PWMMR5 = 0;
    PWMMCR = 0x3;
    PWMPCR = 0x2000;
    PWMTCR = 0x09;
    PWMLER = 0x20; 

     while(1){
        if((IOPIN0 & SW) == 0){ 
            PWMMR5 = x;
            delay(500);
            if(x > 37500){
                x = 0;
            } else {
                x += 7500;
            }
            PWMLER = 0x20; 
        }
	}
}

