#include "adc.h"
#include "delay.h"
#include "lcd_lib.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int ThermistorPin = 0;
int Vo;
float R1 = 13000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

int main(void){
	
	// initialize adc
	adc_init();
	
	// initialize LCD screen
	LCDinit();
	LCDclr();
	LCDcursorOFF();
	
	while(1){
		Vo = adc_read(ThermistorPin);
		R2 = R1 * (1023.0 / (float)Vo - 1.0);
		logR2 = log(R2);
		T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
		Tc = T - 273.15;
		
		char msg[16];
		sprintf(msg, "Temp: %.1f C", Tc);
		LCDclr();
		LCDstring((uint8_t*)msg, strlen(msg));
		
		delayMs(1500);
	}
	
	return 0;
}
