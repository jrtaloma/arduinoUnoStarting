/*
  Blink
  Turns on a LED for one second, then off for one second, repeatedly.
*/

#include "digio.h"
#include "delay.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0

// pin 13 has a LED connected on most Arduino boards
int led = 13;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
	// UART_putChar(uart, (uint8_t) '\0'); // 'IMPORTANT: '\0' serves to mark the end of the string
}

int main(void){
	
	// 1. this is the setup routine: initialize the digital pin as an output
	DigIO_setDirection(led, Output);
	uart=UART_init("uart_0", 115200);
	
	// 2. this is the loop routine running over and over again forever
	while(1){
		// turn the LED on (HIGH is the voltage level)
		DigIO_setValue(led, HIGH);
		printString("On\n");
		delayMs(1000);
		
		// turn the LED off by making the voltage LOW
		DigIO_setValue(led, LOW);
		printString("Off\n");
		delayMs(1000);
	}
	
	return 0;
}
