#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int ThermistorPin = 0;

float senseTemp(void) {
	int Vo;
	float R1 = 10000;
	float logR2, R2, T, Tc;
	float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
	
	Vo = analogRead(ThermistorPin);
	R2 = R1 * (1023.0 / (float)Vo - 1.0);
	logR2 = log(R2);
	T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
	Tc = T - 273.15;
	return Tc;
}

void setup() {
	Serial.begin(115200);
}

void loop() {
	Serial.print("Temp: ");
	Serial.println(senseTemp());
	delay(1000);
}
	
