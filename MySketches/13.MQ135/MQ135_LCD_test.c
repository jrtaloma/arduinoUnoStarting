#include "adc.h"
#include "delay.h"
#include "lcd.h"
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
	
	lcd_init(LCD_DISP_ON);
	
	char msg[8];

	while(1) {
		lcd_clrscr();
		int sensorValue = adc_read(sensorPin);
		sprintf(msg, "%d", sensorValue);
		lcd_puts(msg);
		delayMs(500);
	}
}
