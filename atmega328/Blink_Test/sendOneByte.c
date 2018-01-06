// https://unix.stackexchange.com/questions/138342/how-to-read-write-to-tty-device

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>    
#include <string.h>
int main() {
    char byte;
    int fd = open("/dev/ttyACM0", O_RDWR);
    
    char* s = "It's beautiful";
	int l = strlen(s);	
	int i;
	for (i=0; i<l; i++, s++) {
		write(fd, s, 1);
	}
	write(fd, "\0", 1);
	
	while (1) {
		usleep(2500);
	
		while (1) {
			ssize_t n = read(fd, &byte, 1);
			printf("%c", byte);
			if (byte == '\0' || byte == '\n' || byte == '\r')  {
				break;
			}	
		}
	}	
	
    return 0;
}
