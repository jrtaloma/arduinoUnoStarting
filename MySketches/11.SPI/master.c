#include "delay.h"
#include "spi.h"
 
int main(void) {
	spi_init_master();                                   
 
	while(1) {
		printStringSPI("Hello World\n");
		delayMs(1500);
	}
}
