#include<LPC21XX.H>
#define LED1 1<<2


void Non_vectored_isr(void)__irq
{
if((VICIRQStatus>>14)&1){
	EXTINT=0x01;//To clear EINT0 flag
	IOSET0=LED1;
	IOCLR0=LED1;
	}
	VICVectAddr=0;
}
int main(){
unsigned int count =0;
PINSEL1= 0x1;//P0.16 is enabled because at P0.1 we have one of the UART0 pin
IODIR0=LED1;//P0.2 as digital output pin

VICIntSelect=0;
VICDefVectAddr=(int)Non_vectored_isr;

EXTMODE=0x01;
EXTPOLAR=0x00;

VICIntEnable=1<<14;

/*Main line code*/
while(1){
count++;
	}
}


