#pragma once

//Initialize SPI Master Device
void spi_init_master(void);

//Initialize SPI Slave Device
void spi_init_slave(void);

//Function to send and receive a single data
unsigned char spi_tranceiver(unsigned char data);

//Function to send a string
void printStringSPI(char* s);
