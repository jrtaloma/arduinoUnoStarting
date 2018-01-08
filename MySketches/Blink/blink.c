#include <avr/io.h>
#include <util/delay.h>

int main() {
	/* set DDRB.5 for output*/
	DDRB = (1<<DDB5);
	
	while(1) {
		/* set PORTB.5 high */
		PORTB = (1<<PB5);
		
		_delay_ms(1000);
		
		/* set PORTB.5 low */
		PORTB = (1<<0);
		
		_delay_ms(1000);
	}
	
	return 0;

}
