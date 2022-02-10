CC=g++
CFLAGS=-I.
DEPS = header.h
OBJ = main.o functions.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

assignment1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)