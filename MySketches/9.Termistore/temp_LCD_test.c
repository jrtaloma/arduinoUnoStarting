#include "adc.h"
#include "delay.h"
#include "lcd.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int ThermistorPin = 0;
int Vo;
float R1 = 11000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

int main(void){
	
	// initialize adc
	adc_init();
	
	// initialize LCD screen
	lcd_init(LCD_DISP_ON);
	
	while(1){
		Vo = adc_read(ThermistorPin);
		R2 = R1 * (1023.0 / (float)Vo - 1.0);
		logR2 = log(R2);
		T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
		Tc = T - 273.15;
		
		char msg[16];
		sprintf(msg, "Temp: %.1f C", Tc);
		lcd_clrscr();
		lcd_puts(msg);
		
		delayMs(1500);
	}
	
	return 0;
}
