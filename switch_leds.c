#include<msp430.h>

void delay(void);

main()
{
	P1DIR = 0x41;
	P1OUT = 1;	
	while(1) {
		while (P1IN >> 3 & 1) {
		}
		while (!(P1IN >> 3 & 1)) {
		}		
		P1OUT^= 0x41;
		delay();
	}
}

void delay()
{
	int i;	
	for(i=0;i<20000;i++) {
	}
}
