#include <stdint.h>

int trig_pin = 13;
int echo_pin = 12;

void setup(){
	Serial.begin(115200);
	pinMode(trig_pin, OUTPUT);
	pinMode(echo_pin, INPUT);
}

void loop(){
	digitalWrite(trig_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(trig_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig_pin, LOW);
	
	uint64_t duration = pulseIn(echo_pin, HIGH);
	int distance = duration/29/2;
	if(!duration){
		Serial.println("Warning: no pulse from sensor");
	}
	else{
		Serial.print(distance);
		Serial.println(" cm");
	}
	delay(500);
}
