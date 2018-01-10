# interrupt_test.c

**Interrupt in AVR**: [http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html](http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html)

**Compilazione, flashing su Arduino ed esecuzione**

`$ make interrupt_test.hex`

Inviando tramite terminale un messaggio il led 13 si illuminerà per 500 ms: `$ echo "Turn ON" > /dev/ttyACM0`
