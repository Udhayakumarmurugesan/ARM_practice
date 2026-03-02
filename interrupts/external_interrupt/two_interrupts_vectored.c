#include<LPC21XX.H>
#define IRQ_SLOT_EN 1<<5
#define EINT0_num 14
#define EINT1_num 15
#define LED1 1<<2
#define LED2 1<<3


void eint0_isr(void)__irq{
	EXTINT=0x01;//To clear EINT0 flag
	IOSET0=LED1;
	IOCLR0=LED1;
	VICVectAddr=0;//To indicate the end of ISR(dummy wrte-not to reset)
}
void eint1_isr(void)__irq{
	EXTINT=0x03;//To clear EINT1 flag
	IOSET0=LED2;
	IOCLR0=LED2;
	VICVectAddr=0;//To indicate the end of ISR(dummy wrte-not to reset)
}


int main(){
unsigned int count =0;
PINSEL1= 0x1;//P0.16 is enabled because at P0.1 we have one of the UART0 pin
PINSEL0=(1<<29);//P0.14 is enabled
IODIR0=LED1|LED2;//P0.2 as digital output pin


/*Configure the interrupt*/
VICIntSelect=0;//Configured as IRQs FIQ-(1<<Interrupt number in VIC Block)

	
/*Allocate slot 0 to EINT0 and slot 1 to EINT1*/
VICVectCntl0=IRQ_SLOT_EN|EINT0_num;
VICVectAddr0=(int)eint0_isr;
VICVectCntl1=IRQ_SLOT_EN|EINT1_num;
VICVectAddr1=(int)eint1_isr;

	
/*Select the triggering mode of external interrupt*/
EXTMODE=0x03;
EXTPOLAR=0x00;
VICIntEnable=1<<14;
VICIntEnable=1<<15;

	
/*Main line code*/
while(1){
count++;
	}
}


