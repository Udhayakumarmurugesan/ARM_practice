#include<LPC21XX.H>
#define LED 1<<17
#define SW 14
int main(){
IODIR0=LED;
while(1){
    if(((IOPIN0>>SW)&1)==0)
      {
        IOCLR0=LED;
      }
    else{
      IOSET0=LED;
      }
    }
}

/* IOPIN0 >> 14
➤ This shifts the value of IOPIN0 right by 14 bits.
➤ So the bit that was at position P14 (14th pin) now moves to bit 0 (LSB).

& 1
➤ This isolates only the lowest bit (LSB), which is now the original value of pin 14.
➤ Result:

    0 → pin is LOW (pressed if pull-up logic)

    1 → pin is HIGH (not pressed)

*/

