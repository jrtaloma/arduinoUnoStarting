#include "spi.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

void spi_init_master(void){
	DDRB = (1<<5)|(1<<3); // set SCK, MOSI as Output
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); // enable SPI, set as Master, prescaler: Fosc/16
}

void spi_init_slave(void){
	DDRB = (1<<4); // MISO as Output
	SPCR = (1<<SPE); // enable SPI
}

unsigned char spi_tranceiver(unsigned char data){
	SPDR = data; // load data into the buffer
	while (!(SPSR & (1<<SPIF))); // wait until transmission complete
	return (SPDR); // return received data
}

void printStringSPI(char* s){
	for (int i=0; i<strlen(s); i++){
		spi_tranceiver(s[i]);
	}
}
