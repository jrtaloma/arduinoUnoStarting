#include "digio.h"
#include "pwm.h"
#include "delay.h"
#include <stdio.h>

int pinLed = 6;

int main(void){
  // all pins as inputs with pull up resistors
  PWM_init();
  
  // enable pin 6 as pwm output
  PWM_enable(pinLed, 1);

  uint8_t start_pin=0;
  while(1) {
    
    for (int i=0; i<256; i++){
      PWM_setDutyCycle(pinLed, i);
	  delayMs(10);
    } 
    
    delayMs(500);
    
	for (int i=255; i>=0; i--) {
	  PWM_setDutyCycle(pinLed, i);
	  delayMs(10);
	}
	
	delayMs(500);
	
  }
}
