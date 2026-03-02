#include<LPC21XX.H>
#define LED1 1<<2
#define LED2 1<<3


void FIQ_Handler(void)__irq {
	EXTINT=0x01;//To clear EINT0 flag
	IOSET0=LED1;
	IOCLR0=LED1;	
}
int main(){
unsigned int count =0;
PINSEL1= 0x1;

IODIR0=LED1;

VICIntSelect=1<<14;

EXTMODE=0x01;
EXTPOLAR=0x00;
VICIntEnable=1<<14;

while(1){
count++;
	}
}


