OBJECTS = hellomake.c hellofunc.c

HEADERS = hellomake.h

CC = gcc

CFLAGS = -g -Wall

PROGRAM_NAME = hellomake

# eventually LIBS = <libraries>

BINS = hellomake\

$(PROGRAM_NAME):$(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(OBJECTS) $(LIBS)

.PHONY: clean

clean:
	rm -rf *.o *~ $(BINS)

# eventually
# clean:
#	 rm -rf *.o *~ $(LIBS) $(BINS)
