#include<LPC21XX.h>
#include"lcd_8.h"
#define SW1 (1<<14)
#define SW2 (1<<15)
#define SW3 (1<<16)
int main(){
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_INIT();
	while(1){
	if((IOPIN0&SW1)==0){
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("Switch 1 pressed");
	}
	else if((IOPIN0&SW2)==0){
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("Switch 2 pressed");
	}
	else if((IOPIN0&SW3)==0){
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("Switch 3 pressed");
	}
	else{
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("Press the switch");
		delay_ms(1000);
		}

	}
}




