#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "spi.h"
 
struct UART* uart; 

unsigned char data;
char tx_buffer[300];
char rx_buffer[300];
int size = 0;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

void setup() {	
	uart=UART_init("uart_0", 115200);
	SPI_SlaveInit();
	rx_buffer[0] = 0;
}	

void loop() {
	data = SPI_SlaveReceive();
	rx_buffer[size] = data;
	++size;
	rx_buffer[size] = 0;
	if (data == '\n') {
		sprintf(tx_buffer, "%s", rx_buffer);
		printString(tx_buffer);
		size = 0;
	}
}
