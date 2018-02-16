#include "adc.h"
#include "delay.h"
#include "lcd_lib.h"
#include <stdio.h>
#include <string.h>

int sensorPin = 0;

int main(void) {
	adc_init();
	LCDinit();
	LCDcursorOFF();
	char msg[8];

	while(1) {
		LCDclr();
		int sensorValue = adc_read(sensorPin);
		sprintf(msg, "%d", sensorValue);
		LCDstring((uint8_t*)msg, strlen(msg));
		delayMs(300);
	}
}
