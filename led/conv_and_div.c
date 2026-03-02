	  #include<LPC21XX.H>
	  #define LED 0xFF
	  void delay(){
	  int i,ms;
	  for(ms=1000;ms>0;ms--){
	  for(i=12000;i>0;i--);
	  }
	  }
	  int main(){
	  int led;
	  PINSEL0=0;
	  IODIR0=LED;
	  while(1){
		  //Divergence
	  for(led=0; led<4;led++){
            IOCLR0=LED;
            IOSET0=(1<<(3-led))|(1<<(4+led));
            delay();
        	}
		  //Convergence
	  for(led=7;led>=0;led--){
	  IOCLR0=LED;
	  IOSET0=(1<<led)|(1<<(7-led));
	  delay();
	  }
	  }
	  }
