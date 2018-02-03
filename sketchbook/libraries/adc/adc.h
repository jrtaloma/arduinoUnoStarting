#pragma once
#include <stdint.h>

/* initialize adc */
void adc_init(void);

/* enable ADC_vect Interrupt */
void adc_enableInterrupt(void);

/* read adc value from channel ch */
uint16_t adc_read(uint8_t ch);
