#include<msp430.h>

void delay(void);

main()
{
	P1DIR = 0x40;
	P1OUT = 0x40;
	while(1)
	{
		delay();	
		P1OUT^= 0x40;
	}
}

void delay()
{
	int i;
	for (i=0;i<10000;i++);
}
