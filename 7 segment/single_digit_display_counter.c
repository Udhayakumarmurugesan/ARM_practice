//for 1 segment only(1 digit number)
#include<LPC21XX.h>
#define SEG_D 0XFF
#define SEG1 1<<8
void delay_ms(int ms)
{
T0PR=15000-1	 ;
T0TCR=0X01;
while(T0TC<ms);
T0TCR=0X03;	 
T0TCR=0X00;
}
unsigned char seg_lut[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X98};// 0-9 hex values (active high 7 segment display)
int main(){
unsigned char digit=0;
IODIR0=SEG_D;
while(digit<10){
	IOCLR0=SEG_D;
	IOSET0=seg_lut[digit++];
	if(digit>=10){
		digit=0;
		}
	delay_ms(1000);
	
	}
}
