#include<LPC21XX.h>
//#include<string.h>
#define LCD_D 0xFF      
#define RS    1<<8          
#define E     1<<9

void delay_ms(int ms)
{
T0PR=15000-1;
T0TCR=0X01;
while(T0TC<ms);
T0TCR=0X03;	 
T0TCR=0X00;
}

void LCD_COMMAND(unsigned char cmd)
 {
    IOCLR0 = LCD_D;
	IOSET0= (cmd&0xFF);// whatever commands we are giving will take place an and operation with 0xff as it is an 8 bit
	IOCLR0=RS;
	//IOCLR0=Rw;// If it is not grounded then this command should be given
	IOSET0=E;                          
    	delay_ms(2);// Enable will take place only for 2 ms
	IOCLR0=E;// If it is cleared then only we can write on LCD Display

}
void LCD_INIT() {
    IODIR0 = RS | E | LCD_D;
    LCD_COMMAND(0x02);// Function home                    
    LCD_COMMAND(0x38);//8 bit mode set                    
    LCD_COMMAND(0x0C);//Display ON cursor OFF                    
    LCD_COMMAND(0x80);//Starting address of line 1 for (16x2 and 20x4 display)
    //LCD_COMMAND(0xC0);//Starting address of line 2 for (16x2 and 20x4 display)
    //LCD_COMMAND(0x94);//Starting address of line 3 for (20x4 display only)
    //LCD_COMMAND(0xD4);//Starting address of line 4 for (20x4 display only)
    LCD_COMMAND(0x01);                   
}


void LCD_DATA(unsigned char data)
{
	IOCLR0 = LCD_D;
	IOSET0= (data&0xFF);
	IOSET0=RS;
	IOSET0=E;                          
    	delay_ms(2);
	IOCLR0=E;
}
void LCD_STR(unsigned char s[]){
	int i=0;
	while(s[i]!='\0'){
		LCD_DATA(s[i]);
		i++;
	}
}
int len(char s[]){
	int i,len=0;
	for(i=0;s[i]!='\0';i++){
		  len++;
	}
return len;
}


void LCD_SCROLL(unsigned char s[]){
	int length=len(s),i;
	//int length=strlen(s);
	LCD_COMMAND(0x01);       
    delay_ms(2);
    LCD_COMMAND(0x80);        
    LCD_STR(s);          
    delay_ms(1000);       

    for (i=0; i<length+16; i++) {  
        LCD_COMMAND(0x18);// Display shift left           
        delay_ms(300);//Controlling the speed of scrolling              
    }
}
unsigned char s[50]="Om Namaha Shivaya";
int main(){
  LCD_INIT();
  LCD_SCROLL(s);
  while(1);
}


