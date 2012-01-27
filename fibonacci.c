#include <stdint.h>
#include <msp430.h>

void delay();

main()
{
	P1DIR = 0x41;
	P1OUT = 0x40;
 	unsigned lfsr = 0xace1;
	unsigned bit;
	do  {
	    bit  = ((lfsr >> 15) ^ (lfsr >> 13) ^ (lfsr >> 12) ^ (lfsr >> 10) ) & 1;
	    lfsr =  (lfsr << 1) | (bit);
	    if ((lfsr>>6) & 1) {
			P1OUT ^= 0x40;
			delay();
	    }		
	    if ((lfsr>>1) & 1) {
			P1OUT ^= 0x41;
			delay();
	    }			
	    P1OUT ^= 0x41;	
	} while(lfsr != 0xace1);
}
	
void delay(void)
{
	int i;
	for(i=0;i<30000;i++);
}	
