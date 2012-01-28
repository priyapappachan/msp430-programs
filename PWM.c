#include<msp430.h>
#define MAX 1000

int on_time = 0;
void delay(int n)
{
	while (n--);
}

void one_cycle()
{
	P1OUT = 1;
	delay(on_time);
	P1OUT = 0;
	delay(MAX-on_time);
}


main()
{
	P1DIR = 1;
	on_time = 0;
	while(1) {
		while (on_time < 1000) {
			one_cycle();
			on_time += 10;
		}		
		while (on_time > 0) {
			on_time -= 10;
			one_cycle();
		}
	}		
}	

