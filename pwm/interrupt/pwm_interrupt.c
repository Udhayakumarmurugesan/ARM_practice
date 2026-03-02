//Varying PWM signal
#include<LPC21XX.h>
int main(){
unsigned int x=0;
PINSEL1=0x400;
PWMMR0=100;//Period register
PWMMR5=0;
PWMMCR=0x3;
PWMPCR=0x2000;
PWMTCR=0x9;
PWMLER=0x20;
while(1){
	while((PWMIR&1)==0);
	PWMIR=0x1;
	PWMMR5=x;
	if(x>PWMMR0){
		x=0;
		}
		x++;
	PWMLER=0x20;
}
}

