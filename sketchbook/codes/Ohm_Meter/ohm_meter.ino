#include "adc.h"
#include <avr/io.h>
#include <avr/pgmspace.h>

int analogPin = 0;
int raw = 0;
int Vin = 5;
float Vout = 0;
float knownRes = 1000; // change this if another resistor is used
float unknownRes = 0;
float buffer = 0;

void setup() {
	Serial.begin(115200);
	adc_init();
}

void loop() {
	raw = adc_read(analogPin);
	buffer = raw * Vin;
	Vout = (buffer) / 1024.0;
	buffer = (Vin / Vout) - 1;
	unknownRes = knownRes * buffer;
	
	Serial.print("Tensione in uscita: ");
	Serial.println(Vout);
	Serial.print("Valore resistenza: ");
	Serial.println(unknownRes);
	
	delay(2000);
}
	
