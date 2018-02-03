#include "timer.h"

int buzzerPin = 13;
int redLED = 11;
int yellowLED = 10;
int greenLED = 9;

volatile int redON = 0;
volatile int yellowON = 0;
volatile int greenON = 0;

struct Timer* timer;

void timerFn(void* args){
	if (yellowON) {
		yellowON = 0;
		redON = 1;
	}	
		
	else if (redON) {
		redON = 0;
		greenON = 1; 	
	}
	
	else if (greenON) {
		greenON = 0;
		yellowON = 1;
	}
}

void setup(){
	pinMode(buzzerPin, OUTPUT);
	pinMode(redLED, OUTPUT);
	pinMode(yellowLED, OUTPUT);
	pinMode(greenLED, OUTPUT);
	
	redON = 1;
	
	timer=Timer_create("timer_0", 4195, timerFn, NULL); // 4195 ms is the maximum delay supported by TIMER1 (16 bit): a greater value causes overflow 
	Timer_start(timer);
}

void loop() {
	if (redON) {
		digitalWrite(buzzerPin, LOW);
		digitalWrite(yellowLED, LOW);
		digitalWrite(redLED, HIGH);
		while (redON) {}
	}
	if (greenON) {
		digitalWrite(redLED, LOW);
		digitalWrite(greenLED, HIGH); 	
		while (greenON) {
			digitalWrite(buzzerPin, HIGH);
			delay(500);
			digitalWrite(buzzerPin, LOW);
			delay(500);
		}
	}
	if (yellowON) {
		digitalWrite(greenLED, LOW);
		digitalWrite(yellowLED, HIGH);
		while (yellowON) {
			digitalWrite(buzzerPin, HIGH);
			delay(250);
			digitalWrite(buzzerPin, LOW);
			delay(250);
		}
	}
}
