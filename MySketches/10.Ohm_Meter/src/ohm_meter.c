#include "adc.h"
#include "digio.h"
#include "delay.h"
#include "uart.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>

int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float knownRes = 1000; // change this if another resistor is used
float unknownRes = 0;
float buffer = 0;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

int main(void){
	
	uart=UART_init("uart_0", 115200);
	adc_init();
	char msg[32];
	
	while(1){
		raw = adc_read(analogPin);
		buffer = raw * Vin;
		Vout = (buffer) / 1024.0;
		buffer = (Vin / Vout) - 1;
		unknownRes = knownRes * buffer;

		sprintf(msg, "Tensione in uscita: %.2f V\n", Vout);
		printString(msg);
		sprintf(msg, "Valore resistenza: %.2f Ohm\n", unknownRes);
		printString(msg);
		
		delayMs(2000);
	}
	
	return 0;
}
