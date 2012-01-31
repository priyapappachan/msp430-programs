#include <msp430.h>

__attribute__((interrupt(WDT_VECTOR)))
void isr()
{
	P1OUT ^= 1;
}

void watchdog_init()
{
	WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL;
	IE1 = IE1 | WDTIE;
}		



main()
{
	P1DIR = 1;
	__enable_interrupt();
	watchdog_init();
	while(1);
}
