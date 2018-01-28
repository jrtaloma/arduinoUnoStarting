# Semaforo per non udenti

![GitHub Logo](semaphore.jpg)

**Compilazione, flashing su Arduino ed esecuzione**

`$ make semaphore.hex`

Ogni 4 secondi un timer interrupt permette al semaforo di passare dal rosso, al verde e al giallo. Quando il semaforo è verde l'active buzzer emette un beep ogni 500 ms; quando è giallo un beep ogni 250 ms.
