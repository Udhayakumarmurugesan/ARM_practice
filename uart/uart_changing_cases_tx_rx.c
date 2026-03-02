#include<LPC21XX.h>
void UART0_CONFIG(void){
PINSEL0=0X5;
U0LCR=0X83;
U0DLL=97;
U0DLM=0;
U0LCR=0X03;
}
void UART0_TX(unsigned char txByte){
while(((U0LSR>>5)&1)==0);
U0THR=txByte;
}
unsigned char UART0_RX(){
while((U0LSR&1)==0);
return U0RBR;
}
int main(){
unsigned char rxByte;
UART0_CONFIG();
while(1){
rxByte=UART0_RX();
rxByte=rxByte^32;
UART0_TX(rxByte);
}
}

