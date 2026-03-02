#include<LPC21XX.h>
int main(){
PINSEL1=0x400;
PWMMR0=100;//Period register
PWMMR5=50;//Duty Cycle
PWMMCR=0x2;
PWMPCR=0x2000;
PWMTCR=0x9;
while(1){
}
}

