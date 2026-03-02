#include<LPC21XX.h>
#include"delay.h"
#define SCL_EN  0x00000010
#define SDA_EN  0x00000040

#define CCLK      60000000  //Hz
#define PCLK      CCLK/4    //Hz
#define I2C_SPEED 100000    //Hz
#define LOADVAL   ((PCLK/I2C_SPEED)/2)
#define   AA_BIT 2
#define   SI_BIT 3
#define  STO_BIT 4
#define  STA_BIT 5
#define I2EN_BIT 6

void I2C_INIT(void)
{
	PINSEL0|=SCL_EN|SDA_EN;
	 I2SCLL=LOADVAL;
	 I2SCLH=LOADVAL;
	 I2CONSET=1<<I2EN_BIT; 
}	
void I2C_START(void){
  	I2CONSET=1<<STA_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	I2CONCLR=1<<STA_BIT;
}

void I2C_RESTART(void)
{
	I2CONSET=1<<STA_BIT;
	I2CONCLR=1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	I2CONCLR=1<<STA_BIT;
}	


void I2C_WRITE(unsigned char dat)
{
	I2DAT=dat;	
	I2CONCLR = 1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
}	


void I2C_STOP(void)
{
	I2CONSET=1<<STO_BIT;
	I2CONCLR = 1<<SI_BIT;
}

unsigned char I2C_NACK(void)
{	
	//I2CONSET = 0x00; 
  I2CONCLR = 1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	return I2DAT;

}


unsigned char I2C_MASTERACK(void)
{	
	I2CONSET = 1<<AA_BIT;
  I2CONCLR = 1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	I2CONCLR = 0x04;
 	return I2DAT;
}



