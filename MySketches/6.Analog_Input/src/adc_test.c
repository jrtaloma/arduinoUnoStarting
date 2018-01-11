#include "digio.h"
#include "delay.h"
#include "uart.h"
#include "adc.h"
#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0

// pin 13 has an LED connected on most Arduino boards
int led = 13;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
	// UART_putChar(uart, (uint8_t) '\0'); // 'IMPORTANT: '\0' serves to mark the end of the string
}

int main(void){
	uint16_t adc_value;
	
	DigIO_setDirection(led, Output); // initialize the digital pin as an output

	adc_init(); // initialize adc

	uart=UART_init("uart_0", 115200);
	
	while(1){
		adc_value = adc_read(5); // read adc value at A5
		if (adc_value < 128) {
			DigIO_setValue(led, HIGH);
			char buffer[32];
			sprintf(buffer, "adc_value: %d\n", adc_value);
			printString(buffer);
			delayMs(2000);
		}
		else {
			DigIO_setValue(led, LOW);
		}	
	}
	
	return 0;
}
