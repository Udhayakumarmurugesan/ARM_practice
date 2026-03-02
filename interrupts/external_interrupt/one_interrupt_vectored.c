
#include<LPC21XX.H>
#define IRQ_SLOT_EN 1<<5//or we can also use 0x20
#define EINT0_num 14
#define LED 1<<2

void eint0_isr(void)__irq{
	EXTINT=0x01;//To clear EINT0 flag
	IOSET0=LED;
	IOCLR0=LED;
	VICVectAddr=0;//To indicate the end of ISR(dummy write-not to reset)
}


int main(){
unsigned int count =0;
PINSEL1= 0x1;//P0.16 is enabled because at P0.1 we have one of the UART0 pin
IODIR0=LED;//P0.2 as digital output pin
  
/*Configure the interrupt*/
VICIntSelect=0;//Configured as IRQs. For FIQ-(1<<Interrupt number in VIC Block)
	
/*Allocate slot 0 to EINT0*/
VICVectCntl0=IRQ_SLOT_EN|EINT0_num;
VICVectAddr0=(int)eint0_isr;//by default it will be in unsigned char data type so we will typecast it to integer data type

  
/*Select the triggering mode of external interrupt*/
EXTMODE=0x00;//selecting level or edge
EXTPOLAR=0x00;
VICIntEnable=1<<14;

  
/*Main line code*/
while(1){
count++;
	}
}
/*Registers in LPC2148 ARM7

    EXTMODE:

        0: Level-sensitive
        1: Edge-sensitive

    EXTPOLAR:

        If level-sensitive:
            0: LOW-level
            1: HIGH-level
        If edge-sensitive:
            0: Falling edge
            1: Rising edge
	    */


