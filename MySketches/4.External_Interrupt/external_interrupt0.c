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
const int buttonPin = 2; // PD2 is the port related to INT0

volatile int buttonStatus = 0;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

ISR(INT0_vect) { /* external interrupt service routine */
	buttonStatus = DigIO_getValue(buttonPin);
	if (buttonStatus == HIGH) {
		DigIO_setValue(pinLed, HIGH);
		printString("On\n");
		delayMs(500);
		
		DigIO_setValue(pinLed, LOW);
		printString("Off\n");
		delayMs(500);
	}	
}

int main(void){
	uart=UART_init("uart_0", 115200);
	
	DigIO_setDirection(pinLed, Output); // pinLed as an output
	
	DigIO_setDirection(buttonPin, Input); // PD2 as an input
	DigIO_setValue(buttonPin, HIGH); // pull up resistor on PD2
	EIMSK = (1<<INT0); // Turns On INT0
	EICRA = (1<<ISC01)|(1<<ISC00); // The low level of INT0 generates an interrupt request | Any logical change on INT0 generates an interrupt request
	
	sei(); // enable interrupts globally
	
	// this loop does nothing
	while(1){}
	
	return 0;
}
