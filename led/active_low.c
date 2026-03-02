	  #include<LPC21XX.H>
	  #define LED 0xFF
	  void delay(){
	  int i,ms;
	  for(ms=500;ms>0;ms--){
	  for(i=12000;i>0;i--);
	  }
	  }
	  int main(){
	  PINSEL0=0;
	  IODIR0=LED;
	  while(1){
	  IOCLR0=LED;
	  delay();
	  IOSET0=LED;
	  delay();
	  }
	  }
