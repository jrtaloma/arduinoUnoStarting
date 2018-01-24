#include "spi.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

void spi_init_master(void){
	DDRB = (1<<5)|(1<<3); //Set SCK, MOSI as Output
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); //Enable SPI, Set as Master, Prescaler: Fosc/16
}

void spi_init_slave(void){
	DDRB = (1<<4); //MISO as Output
	SPCR = (1<<SPE); //Enable SPI
}

unsigned char spi_tranceiver(unsigned char data){
	SPDR = data; //Load data into the buffer
	while (!(SPSR & (1<<SPIF))); //Wait until transmission complete
	return (SPDR); //Return received data
}

void printStringSPI(char* s){
	for (int i=0; i<strlen(s); i++){
		spi_tranceiver(s[i]);
	}
}
