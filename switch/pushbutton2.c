#include<LPC21XX.H>
#define LED1 1<<17
#define LED2 1<<16
#define SW1 14
#define SW2 15
int main(){
IODIR0=LED1|LED2;
//IOSET0=LED2|LED1;
while(1)
{
if(((IOPIN0>>SW1)&1)==0)
{
IOCLR0=LED1;
//IOSET0=LED2;
}
if(((IOPIN0>>SW2)&1)==0)
{
IOCLR0=LED2;
//IOSET0=LED1;
}
else{
IOSET0=LED1|LED2;
}
}
}
