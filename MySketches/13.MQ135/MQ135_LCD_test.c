#include "adc.h"
#include "delay.h"
#include "lcd_lib.h"
#include "pwm.h"
#include <stdio.h>
#include <string.h>

int sensorPin = 0;
int backlightPin = 3;

int main(void) {
	PWM_init();
	PWM_enable(backlightPin, 1);
	PWM_setDutyCycle(backlightPin, (255/5)*4.2);
	
	adc_init();
	
	LCDinit();
	LCDcursorOFF();
	
	char msg[8];

	while(1) {
		LCDclr();
		int sensorValue = adc_read(sensorPin);
		sprintf(msg, "%d", sensorValue);
		LCDstring((uint8_t*)msg, strlen(msg));
		delayMs(500);
	}
}
