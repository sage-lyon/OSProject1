CC=g++
CFLAGS=-I.
OBJ = main.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)
all: project1 test1 test2 test3 test4 test5

project1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test1: test1.o
	$(CC) -o $@ $^ $(CFLAGS)

test2: test2.o

test3: test3.o

test4: test4.o

test5: test5.o