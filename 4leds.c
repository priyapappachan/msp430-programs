#include<msp430.h>

void delay()
{
	int i;
	for(i=0;i<30000;i++);
}

main()
{
	P1DIR = 0x0f;
	while(1) {
		P1OUT =	0x01;
		delay();
		P1OUT = 0x02;
		delay();
		P1OUT = 0x04;
		delay();
		P1OUT = 0x08;
		delay();
	}
}		 
		
