#include"dht11.h"
int main(){
	int H_int,H_dec,T_int,T_dec,checksum;
	LCD_INIT();
	while(1)
	{
	DHT11_INIT();
	DHT11_CheckResponse();
	H_int=DHT11_Readbyte();
	H_dec=DHT11_Readbyte();
	T_int=DHT11_Readbyte();
	T_dec=DHT11_Readbyte();
	checksum=DHT11_Readbyte();
        if ((H_int+H_dec+T_int+T_dec) != checksum)
	 {
            LCD_STR("Checksum Error   ");
        } 
	else 
	{
            LCD_STR("H:");
            LCD_DECIMAL(H_int+H_dec*0.01);
            LCD_DATA('%');
            LCD_COMMAND(0xC0);
            LCD_STR("T:");
            LCD_DECIMAL(T_int+T_dec*0.01);
            LCD_DATA('C');
        }
        delay_ms(2000);

        LCD_COMMAND(0x01);

    }

}


