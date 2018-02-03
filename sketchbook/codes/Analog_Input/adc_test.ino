#include "adc.h"
#include <avr/interrupt.h>

int led = 13;

volatile uint16_t adc_value;

// the ISR will be called when an A2D conversion completes
ISR(ADC_vect) {
	if (adc_value < 128) {
		digitalWrite(led, HIGH);
		delay(1000);
	}
	else {
		digitalWrite(led, LOW);
	}
}

void setup(){
	pinMode(led, OUTPUT); // initialize the digital pin as an output
	adc_init();	
	adc_enableInterrupt(); // enable ADC interrupt
	sei(); // enable global interrupts
}

void loop() {
	adc_value = adc_read(5); // read adc value at A5
}
