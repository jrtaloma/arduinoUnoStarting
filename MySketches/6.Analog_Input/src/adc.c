#include <avr/io.h>

void adc_init(void) {
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	
	// ADC Enable and prescaler of 128 ----> 16 MHz/128 = 125 kHz
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t adc_read(uint8_t ch) {
	// analog input channels in Arduino Uno: A0 A1 A2 A3 A4 A5
	if (ch > 5) ch = 0;
	ADMUX |= ch;
	
	// starting single conversion
	ADCSRA |= (1<<ADSC);
	
	// ADSC becomes 0 at the end of conversion and breaks the loop
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}
