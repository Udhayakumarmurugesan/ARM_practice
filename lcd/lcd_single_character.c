#include <LPC21xx.H>
#include "delay.h"

void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);

#define LCD_D 0xF<<20       
#define RS    1<<17
#define RW    1<<18          
#define E     1<<19          

int main() {
    LCD_INIT();
    while (1) {
        LCD_COMMAND(0x80);      
        LCD_DATA('A');          
    }
}


void LCD_INIT() {
    IODIR1 |= RS | E | LCD_D |RW;            
	IOCLR1=RW;
    LCD_COMMAND(0x02);                    
    LCD_COMMAND(0x28);                    
    LCD_COMMAND(0x0C);                    
    LCD_COMMAND(0x80);                    
    LCD_COMMAND(0x01);                   
    delay_ms(2);
}
void LCD_COMMAND(unsigned char cmd)
 {
    IOCLR1 = LCD_D;
	IOSET1= ((cmd&0xf0)<<16);
	IOCLR1=RS;
	IOSET1=E;                          
    delay_ms(2);
	IOCLR1=E;

	IOCLR1 = LCD_D;
	IOSET1= ((cmd&0x0f)<<20);
	IOCLR1=RS;
	IOSET1=E;                          
    delay_ms(2);
	IOCLR1=E;
}

void LCD_DATA(unsigned char data)
{
    IOCLR1 = LCD_D;
	IOSET1= ((data&0xf0)<<16);
	IOSET1=RS;
	IOSET1=E;                          
    delay_ms(2);
	IOCLR1=E;

	IOCLR1 = LCD_D;
	IOSET1= ((data&0x0f)<<20);
	IOSET1=RS;
	IOSET1=E;                          
    delay_ms(2);
	IOCLR1=E;
}

