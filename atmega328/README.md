# C - Arduino Uno

**IMPORTANTE: i file qui presenti sono stati riadattati per la versione ATmega328**

I file originali presentati a lezione per ATmega2560 si trovano su [https://gitlab.com/grisetti/sistemi_operativi_2016_17/tree/master/source/14_microcontrollers/atmega2560](https://gitlab.com/grisetti/sistemi_operativi_2016_17/tree/master/source/14_microcontrollers/atmega2560) 

**Installazione Arduino e Minicom**

`$ sudo apt-get install arduino`

`$ sudo apt-get install minicom`

**Compilazione**

`$ make`

**Flashing su Arduino ed esecuzione**

`$ make <nome programma>.hex`

**Monitorare i messaggi di output di Arduino**

`$ minicom -D /dev/ttyACM0 -b 115200`

**Bonus**

L'Hello World di Arduino nella cartella `Blink_Test`
