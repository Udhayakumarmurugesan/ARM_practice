#include<LPC21XX.h>
#include"lcd_n.h"
#define TRIG (1<<10)
#define ECHO (1<<11)

void US_init(void){
	IODIR0|=TRIG;
	

}
void sendTrigger(void){
	
	IOSET0= TRIG;
	delay_us(10);
	IOCLR0=TRIG;
}

unsigned int measurePulse(void){
    unsigned int width = 0, cm = 0, timeout = 0;
    while (!(IOPIN0 & ECHO)) {
        if (++timeout > 60000){ 
	return 0;
	}
    }
    T1PR  = 60 - 1;
    T1TCR = 0x03; 
    T1TCR = 0x01;

    timeout = 0;
    while (IOPIN0 & ECHO) {
        if (++timeout > 600000) 
		break;
    }
    width = T1TC;
    T1TCR = 0x00;
    cm = width / 58;
    return cm;
}

