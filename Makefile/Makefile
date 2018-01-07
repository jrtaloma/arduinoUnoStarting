CC = gcc -g

CFLAGS = -I ./include

CC_OPTS = -Wall --std=gnu99 -Wstrict-prototypes

OBJECTS = hellomake.c hellofunc.c

HEADERS = hellomake.h\

PROGRAM_NAME = hellomake

LIBS =

BINS = hellomake\

$(PROGRAM_NAME):$(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) $(LIBS)

.PHONY: clean

clean:
	rm -rf *.o *~ $(LIBS) $(BINS)
