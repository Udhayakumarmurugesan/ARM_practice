#include<LPC21XX.h>
#define SEG_D 0XFF
#define SEG1 1<<8
#define SEG2 1<<9
void delay_ms(int ms)
{
T0PR=15000-1	 ;
T0TCR=0X01;
while(T0TC<ms);
T0TCR=0X03;	 
T0TCR=0X00;
}
unsigned char seg_lut[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X98};
void twodigitdisplay(int n){
IOCLR0=SEG_D;
IOSET0=seg_lut[n/10];
IOCLR0=SEG1;
delay_ms(5);
IOSET0=SEG1;

IOCLR0=SEG_D;
IOSET0=seg_lut[n%10];
IOCLR0=SEG2;
delay_ms(5);
IOSET0=SEG2;
}
int main(){
while(1){
IODIR0=SEG_D|SEG1|SEG2;
	twodigitdisplay(64);
	}
}

