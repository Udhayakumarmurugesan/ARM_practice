#include<LPC21XX.h>
#include"i2c_driver.h"
void I2C_EEPROM_WRITE(unsigned char slaveAddr,unsigned char wBuffAddr,unsigned char dat)
{
  I2C_START();	
  I2C_WRITE(slaveAddr<<1); //slaveAddr + w
  I2C_WRITE(wBuffAddr);    //wBuffAddr
  I2C_WRITE(dat);          //data
  I2C_STOP();
  delay(10);
}


unsigned char I2C_EEPROM_READ(unsigned char slaveAddr,unsigned char rBuffAddr)
{
	unsigned char dat;
	I2C_START();	
  	I2C_WRITE(slaveAddr<<1); //slaveAddr + w
	I2C_WRITE(rBuffAddr);    //wBuffAddr
	I2C_RESTART();	
	I2C_WRITE(slaveAddr<<1|1); //slaveAddr + r  
  	dat=I2C_NACK();	
	I2C_STOP();
	return dat;

}

void EEPROM_PAGE_WRITE(unsigned char slaveAddr,unsigned char wBuffStartAddr,unsigned char *p,unsigned char nBytes)
{
  unsigned char i;
  I2C_START();	
  I2C_WRITE(slaveAddr<<1);    //slaveAddr + w
	I2C_WRITE(wBuffStartAddr);  //wBuffStartAddr
	for(i=0;i<nBytes;i++)
	{
	   I2C_WRITE(p[i]);             //wBuffAddr
	}
	I2C_STOP();
	delay(10);
}			 


void EEPROM_SEQ_READ(unsigned char slaveAddr,unsigned char rBuffStartAddr,unsigned char *p,unsigned char nBytes)
{
	unsigned char i;
	I2C_START();	
  I2C_WRITE(slaveAddr<<1); //slaveAddr + w
	I2C_WRITE(rBuffStartAddr);    //rBuffAddr
	I2C_RESTART();	
	I2C_WRITE(slaveAddr<<1|1); //slaveAddr + r
	for(i=0;i<nBytes-1;i++)
	{
    p[i]=I2C_MASTERACK();	
	}
	p[i]=I2C_NACK();
	I2C_STOP();
}

