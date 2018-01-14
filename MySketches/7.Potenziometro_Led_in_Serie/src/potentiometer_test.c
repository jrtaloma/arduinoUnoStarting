#include "digio.h"
#include "delay.h"
#include "uart.h"
#include "pwm.h"
#include "adc.h"
#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0

int pinLed = 6;

struct UART* uart;

void printString(char* s){
	int l=strlen(s);
	for(int i=0; i<l; ++i, ++s)
		UART_putChar(uart, (uint8_t) *s);
	// UART_putChar(uart, (uint8_t) '\0'); // 'IMPORTANT: '\0' serves to mark the end of the string
}

int main(void){
	
	DigIO_setDirection(pinLed, Output); // initialize the digital pin as an output

	uart=UART_init("uart_0", 115200);
	
	adc_init(); // initialize adc
	
	// all pins as inputs with pull up resistors
	PWM_init();
	
	// enable pin 6 as pwm output
	PWM_enable(pinLed, 1);
	
	uint16_t adc_value;
	float pwm_value;
	char buffer[32];
	
	while(1){
		adc_value = adc_read(0); // read adc value at A0
		sprintf(buffer, "%d\n", adc_value);
		printString(buffer);
		pwm_value = (float)(adc_value)/1023 * 255;
		PWM_setDutyCycle(pinLed, pwm_value);
		delayMs(30);
	}
	
	return 0;
}
