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
const int buttonPin = 12;

volatile int buttonStatus = 0;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

ISR(PCINT0_vect) { /* pin change interrupt service routine */
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
	
	DigIO_setDirection(buttonPin, Input); // buttonPin as an input
	DigIO_setValue(buttonPin, HIGH); // pull up resistor on buttonPin
	PCICR = (1<<PCIE0); // enable Pin Change 0 interrupt
	PCMSK0 = (1<<PCINT4);
	
	sei(); // enable interrupts globally
	
	while(1){}
	
	return 0;
}
