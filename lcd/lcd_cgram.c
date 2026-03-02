//Add the lcd_8.h file from this repository and try this program
// in cgram_lut array add the hexadecimal number according to 5x8 pixels on the lcd display
#include<LPC21XX.h>
#include"lcd_8.h"
unsigned char cgram_lut[]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
void CGRAM_WRITE(unsigned char nBytes){
	unsigned char i;
	LCD_COMMAND(0x40);
	for(i=0;i<nBytes;i++){
		LCD_DATA(cgram_lut[i]);
	}
}
int main(){
LCD_INIT();
while(1){
LCD_COMMAND(0x80);
CGRAM_WRITE(8);
}
}


