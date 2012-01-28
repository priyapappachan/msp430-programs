#include<msp430.h>

void delay(void)
{
	int i;
	for(i=0;i<30000;i++);
}	

main()
{
	P1DIR = 0x41;
	P1OUT = 0x41;
	int lfsr = 0xACE1;
	do {
		unsigned lsb = lfsr & 1;  
		lfsr >>= 1;               
		if (lsb == 1)             
			lfsr ^= 0xB400u;        
                if ((lfsr>>6) & 1) {
			P1OUT ^= 0x40;
			delay();
	    	}		
	    	if ((lfsr>>1) & 1) {
			P1OUT ^= 0x01;
			delay();
	 	}			
	        P1OUT ^= 0x41;	             
	} while(lfsr != 0xACE1);
}
