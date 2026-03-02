	  #include<LPC21XX.H>
	  #define LED 0xFF
	  void delay(){
	  int i,ms;
	  for(ms=500;ms>0;ms--){
	  for(i=12000;i>0;i--);
	  }
	  }
	  int main(){
	  int led;
	  PINSEL0=0;
	  IODIR0=LED;
	  while(1){
	  for(led=7;led>=0;led--){
	  IOCLR0=LED;
	  IOSET0=(1<<led);
	  delay();
	  }
	  }
	  }
