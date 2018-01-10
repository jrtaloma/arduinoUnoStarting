/*
  Blink
  Turns on a LED for one second, then off for one second, repeatedly.
*/

#include "digio.h"
#include "delay.h"
#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0

const int pinLed = 13;
const int buttonPin = 2;

volatile int buttonStatus = 0;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
	// UART_putChar(uart, (uint8_t) '\0'); // 'IMPORTANT: '\0' serves to mark the end of the string
}

ISR(PCINT2_vect) { /* pin change interrupt service routine */
	buttonStatus = DigIO_getValue(buttonPin);
	if (buttonStatus == HIGH) {
		// turn the LED on (HIGH is the voltage level)
		DigIO_setValue(pinLed, HIGH);
		printString("On\n");
		delayMs(1000);
		
		// turn the LED off by making the voltage LOW
		DigIO_setValue(pinLed, LOW);
		printString("Off\n");
		delayMs(1000);
	}	
}

int main(void){
	cli(); // disable interrupts globally
	
	// 1. this is the setup routine
	DigIO_setDirection(pinLed, Output); // pinLed as an output
	
	DigIO_setDirection(buttonPin, Input); // buttonPin as an input
	DigIO_setValue(buttonPin, HIGH); // pull up resistor on buttonPin
	PCICR = (1<<PCIE2); // enable Pin Change 2 interrupt
	PCMSK2 = (1<<PCINT18);
	
	uart=UART_init("uart_0", 115200);
	
	sei(); // enable interrupts globally
	
	// 2. this loop does nothing
	while(1){}
	
	return 0;
}
