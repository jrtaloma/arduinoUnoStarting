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
const int buttonPin = 3; // PD3 is the port related to INT1

volatile int buttonStatus = 0;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

ISR(INT1_vect) { /* external interrupt service routine */
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
	
	DigIO_setDirection(buttonPin, Input); // PD3 as an input
	DigIO_setValue(buttonPin, HIGH); // pull up resistor on PD3
	EIMSK = (1<<INT1); // Turns On INT1
	EICRA = (1<<ISC11)|(1<<ISC10); // The rising edge of INT1 generates an interrupt request | The falling edge of INT1 generates an interrupt request
	
	sei(); // enable interrupts globally
	
	// this loop does nothing
	while(1){}
	
	return 0;
}
