#include<LPC21XX.H>
#define LED1 1<<2
#define LED2 1<<3


void Non_vectored_isr(void)__irq
{
if((VICIRQStatus>>14)&1){
	EXTINT=0x01;//To clear EINT0 flag
	IOSET0=LED1;
	IOCLR0=LED1;
	}
if((VICIRQStatus>>15)&1){
	EXTINT=0x01;//To clear EINT1 flag
	IOSET0=LED2;
	IOCLR0=LED2;
	}
	VICVectAddr=0;
}
int main(){
unsigned int count =0;
PINSEL1= 0x1;

IODIR0=LED1|LED2;

VICIntSelect=0;
VICDefVectAddr=(int)Non_vectored_isr;
EXTMODE=0x03;
EXTPOLAR=0x00;
VICIntEnable=1<<14;
VICIntEnable=1<<15;

while(1){
count++;
	}
}


