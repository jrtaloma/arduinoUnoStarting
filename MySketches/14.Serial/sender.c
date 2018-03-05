#include "delay.h"
#include "uart.h"
#include <stdio.h>
#include <string.h>

struct UART* uart;

void printString(char* s){
	int l = strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
}

int main(void){
	uart = UART_init("uart_0", 115200);
	char* msg = "Goodnight moon";
	char buffer[32];
	buffer[0] = 0;
	
	while(1){
		sprintf(buffer, "%s\n", msg);
		printString(buffer);
		delayMs(1000);
	}
	
	return 0;
}
