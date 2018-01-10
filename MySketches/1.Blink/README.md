# C - Arduino Uno

N.B.
* Per imparare le operazioni di I/O in AVR >>>>> [http://maxembedded.com/2011/06/port-operations-in-avr/](http://maxembedded.com/2011/06/port-operations-in-avr/)

* Pin Mapping ATmega328 >>>>> [https://www.arduino.cc/en/Hacking/PinMapping168](https://www.arduino.cc/en/Hacking/PinMapping168)

**Installazione Arduino**

`$ sudo apt-get install arduino`

**Compilazione**

`$ avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328 -c -o blink.o blink.c`

`$ avr-gcc -mmcu=atmega328p blink.o -o blink`

`$ avr-objcopy -O ihex -R .eeprom blink blink.hex`

**Flashing su Arduino ed esecuzione**

`$ avrdude -V -F -C /etc/avrdude.conf -p m328 -P /dev/ttyACM0 -b 115200 -c arduino -U flash:w:blink.hex`
