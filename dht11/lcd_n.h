#include<LPC21XX.h>
#define LCD_D 0xF<<20       
#define RS    1<<17
#define RW    1<<18          
#define E     1<<19
void delay_ms(unsigned int ms){
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0x03;
T0TCR=0x00;
}

void delay_us(unsigned int us){
T0PR=15-1;
T0TCR=0x01;
while(T0TC<us);
T0TCR=0x03;
T0TCR=0x00;
}  
    
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char []);
void LCD_SCROLL(unsigned char []);
void LCD_DECIMAL(float);
void CGRAM_WRITE(unsigned char);
unsigned int len(char *);


void LCD_COMMAND(unsigned char cmd){
    IOCLR1 = LCD_D;
	IOSET1= ((cmd&0xF0)<<16);
	IOCLR1=RS;
	IOSET1=E;                          
    delay_ms(2);
	IOCLR1=E;

	IOCLR1 = LCD_D;
	IOSET1= ((cmd&0x0F)<<20);
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


void LCD_STR(unsigned char s[]){
	int i=0;
	while(s[i]!='\0'){
		LCD_DATA(s[i]);
		i++;
	}
}


unsigned int len(char s[]){
	int i,len=0;
	for(i=0;s[i]!='\0';i++){
		  len++;
	}
return len;
}


void LCD_SCROLL(unsigned char s[]){
     unsigned int length=len(s),i;
	LCD_COMMAND(0x01);       
    delay_ms(2);
    LCD_COMMAND(0x80);        
    LCD_STR(s);          
    delay_ms(1000);       

    for (i=0; i<length+16; i++) {  
        LCD_COMMAND(0x18);           
        delay_ms(300);              
    }
}
void LCD_DECIMAL(float n){
		int integer=(int)n;
		int fraction=(int)((n-integer)*100);
		if(n<0){
			LCD_DATA('-');
			integer=-integer;
			fraction=-fraction;
			}
			LCD_DATA((integer/10)+48);
			LCD_DATA((integer%10)+48);
			LCD_DATA('.');
			LCD_DATA((fraction/10)+48);
			LCD_DATA((fraction%10)+48);
}

void LCD_INIT() {
    IODIR1 |= RS | E | LCD_D |RW;            
	IOCLR1=RW;
    LCD_COMMAND(0x02);                    
    LCD_COMMAND(0x28);                    
    LCD_COMMAND(0x0C);                    
    LCD_COMMAND(0x80);                    
    LCD_COMMAND(0x01);                   
}


/*
void CGRAM_WRITE(unsigned char nBytes){
	unsigned char i;
	LCD_COMMAND(0x40);
	for(i=0;i<nBytes;i++){
		LCD_DATA(cgram_lut[i]);
	}
}
*/




