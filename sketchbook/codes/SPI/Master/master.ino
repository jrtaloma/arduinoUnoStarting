#include "spi.h"
 
void setup(void){
	SPI_MasterInit();                                   
}

void loop(){
	SPI_sendString("Hello World\n");
	delay(1500);
}
