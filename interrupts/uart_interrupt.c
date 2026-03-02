#include<LPC21XX.H>
unsigned int count=0;

void UART0_ISR(void)__irq
{
	U0THR='B';
	VICVectAddr=0;
}
void UART0_INT_CONFIG(void)
{
	VICIntSelect=0;
	VICVectCntl2=(0x20)|6;
	VICVectAddr2=(int)UART0_ISR;
	U0IER=1<<1;
	U0IER=1<<0;
}

void UART0_CONFIG(void)
{
	PINSEL0=0x05;
	U0LCR=0x83;
 	U0DLL=97;
	U0DLM=0;
	U0LCR=0x03;
}
int main()
{
	UART0_CONFIG();
	UART0_INT_CONFIG();
	VICIntEnable=1<<6;
	U0THR='A';


	while(1)
	{
		count++;
	}
}


