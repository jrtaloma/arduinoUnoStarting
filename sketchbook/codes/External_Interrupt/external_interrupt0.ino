#include <avr/io.h>
#include <avr/interrupt.h>

const int pinLed = 13;
const int buttonPin = 2;

volatile int buttonStatus = 0;

ISR(INT0_vect) { /* external interrupt service routine */
	buttonStatus = digitalRead(buttonPin);
	if (buttonStatus == HIGH) {
		digitalWrite(pinLed, HIGH);
		delay(500);
		digitalWrite(pinLed, LOW);
		delay(500);
	}	
}

void setup() {
	pinMode(pinLed, OUTPUT);
	pinMode(buttonPin, INPUT);
	digitalWrite(buttonPin, HIGH); // pull up resistor on buttonPin
	
	EIMSK = (1<<INT0); // Turns On INT0
	EICRA = (1<<ISC01)|(1<<ISC00); // The low level of INT0 generates an interrupt request | Any logical change on INT0 generates an interrupt request
	
	sei(); // enable interrupts globally
}

void loop() {}
