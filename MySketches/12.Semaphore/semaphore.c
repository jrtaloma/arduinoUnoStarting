#include "digio.h"
#include "delay.h"
#include "timer.h"
#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0

int buzzerPin = 13;
int redLED = 11;
int yellowLED = 10;
int greenLED = 9;

volatile int redON = 0;
volatile int yellowON = 0;
volatile int greenON = 0;

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

int main(void){
	
	DigIO_setDirection(buzzerPin, Output);
	DigIO_setDirection(redLED, Output);
	DigIO_setDirection(yellowLED, Output);
	DigIO_setDirection(greenLED, Output);
	
	redON = 1;
	
	struct Timer* timer=Timer_create("timer_0", 4000, timerFn, NULL);
	Timer_start(timer);
	
	while(1) {
		if (redON) {
			DigIO_setValue(buzzerPin, LOW);
			DigIO_setValue(yellowLED, LOW);
			DigIO_setValue(redLED, HIGH);
			while (redON) {}
		}
		
		if (greenON) {
			DigIO_setValue(redLED, LOW);
			DigIO_setValue(greenLED, HIGH); 	
			while (greenON) {
				DigIO_setValue(buzzerPin, HIGH);
				delayMs(500);
				DigIO_setValue(buzzerPin, LOW);
				delayMs(500);
			}
		}
		
		if (yellowON) {
			DigIO_setValue(greenLED, LOW);
			DigIO_setValue(yellowLED, HIGH);
			while (yellowON) {
				DigIO_setValue(buzzerPin, HIGH);
				delayMs(250);
				DigIO_setValue(buzzerPin, LOW);
				delayMs(250);
			}
		}
	}
	
	return 0;
}
