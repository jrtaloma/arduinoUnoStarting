# LCD

Seguire le istruzioni al link seguente per configurare il PinMapping.

**AVR-GCC 4 bit and 8 bit LCD library**: [http://winavr.scienceprog.com/example-avr-projects/avr-gcc-4-bit-and-8-bit-lcd-library.html](http://winavr.scienceprog.com/example-avr-projects/avr-gcc-4-bit-and-8-bit-lcd-library.html)

Personalmente ho scelto di configurare i registri dello schermo LCD per ricreare lo stesso circuito in [Appunti su Arduino: pilotare un display LCD](http://www.maffucci.it/2012/02/17/appunti-su-arduino-pilotare-un-display-lcd/).

![GitHub Logo](http://www.maffucci.it/wp-content/uploads/2012/02/collegamenti-lcd.jpg)

**Compilazione, flashing su Arduino ed esecuzione**

`$ make main.hex` // questo è l'esempio ufficiale della libreria

`$ make blink_test.hex`

**Monitorare i messaggi di output di Arduino con il mio programma**: `$ ./myScreen`

In alternativa installare il tool più usato:

`$ sudo apt-get install screen`

`$ screen /dev/ttyACM0 115200`
