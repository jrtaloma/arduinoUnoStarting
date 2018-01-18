# uart_test.c

`uart_test.c` invia al PC la stringa stessa che è stata trasmessa via seriale (echo).
Il codice originale è stato modificato per evitare che sia inviata una stringa vuota all'avvio e che sia trasmesso un solo carattere alla volta, invece adesso l'intera stringa fino al terminatore '/0'.
Eseguire il programma `sendOneByte.c`.

**Compilazione, flashing su Arduino ed esecuzione**

`$ make uart_test.hex`

`$ gcc -o sendOneByte sendOneByte.c`

`$ ./sendOneByte`
