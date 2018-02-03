#include <stdint.h>

int pinLed = 6;
uint16_t adc_value;
float pwm_value;

void setup() {
	pinMode(pinLed, OUTPUT); // initialize the digital pin as an output
}	

void loop() {
	adc_value = analogRead(0); // read adc value at A0
	pwm_value = (float)(adc_value)/1023 * 255;
	analogWrite(pinLed, pwm_value);
	delay(30);
}

