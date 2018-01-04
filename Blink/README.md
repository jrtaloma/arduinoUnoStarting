# C - Arduino Uno

N.B.
Il codice sorgente è lo stesso che si trova al link [https://github.com/dataplayer/Blinking-LED-on-Arduino](https://github.com/dataplayer/Blinking-LED-on-Arduino)

**Installazione Arduino**

`$ sudo apt-get install arduino`

**Compilazione**

`$ avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328 -c -o blink.o blink.c`

`$ avr-gcc -mmcu=atmega328p blink.o -o blink`

`$ avr-objcopy -O ihex -R .eeprom blink blink.hex`

**Flashing su Arduino ed esecuzione**

`$ avrdude -V -F -C /etc/avrdude.conf -p m328 -P /dev/ttyACM0 -b 115200 -c arduino -U flash:w:blink.hex`
