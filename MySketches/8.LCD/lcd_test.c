#include <avr/io.h>
#include "delay.h"
#include "lcd.h"
 
int main(void){
	char* msgOn = "On";
	char* msgOff= "Off";
	
	lcd_init(LCD_DISP_ON); /* initialize lcd, display on, cursor off */
	
	while(1){
		lcd_clrscr();
		lcd_puts(msgOn);
		delayMs(1000);
		lcd_clrscr();
		lcd_puts(msgOff);
		delayMs(1000);
	}
}
