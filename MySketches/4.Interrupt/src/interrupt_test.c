/*
  Blink on interrupt
  Turns on a LED for 500 ms, then off.
*/

#include "digio.h"
#include "uart.h"
#include <stdio.h>

// pin 13 has a LED connected on most Arduino boards
int led = 13;

struct UART* uart;

int main(void){
	
	// this is the setup routine: initialize the digital pin as an output
	DigIO_setDirection(led, Output);
	uart=UART_init("uart_0", 115200);
	
	// this loop does nothing
	while(1){}
	
	return 0;
}
