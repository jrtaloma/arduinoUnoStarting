/*
  Blink
  Turns on a LED for one second, then off for one second, repeatedly.
*/

#include "digio.h"
#include "delay.h"
#include <stdio.h>
#include <string.h>

#define HIGH 1
#define LOW 0

// pin 13 has an LED connected on most Arduino boards
int led = 13;

int main(void){
	
	// 1. this is the setup routine: initialize the digital pin as an output
	DigIO_setDirection(led, Output);
	
	// 2. this is the loop routine running over and over again forever
	while(1) {
		// turn the LED on (HIGH is the voltage level)
		DigIO_setValue(led , HIGH);
		delayMs(1000);
		
		// turn the LED off by making the voltage LOW
		DigIO_setValue(led, LOW);
		delayMs(1000);
	}
	
	return 0;
}
