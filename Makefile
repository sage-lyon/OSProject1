CC=gcc
CFLAGS=-I.

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: project1 test1 test2 test3 test4 test5

project1: main.o
	$(CC) -o $@ $^ $(CFLAGS)

test1: test1.o
	$(CC) -o $@ $^ $(CFLAGS)

test2: test2.o
	$(CC) -o $@ $^ $(CFLAGS) -lm

test3: test3.o
	$(CC) -o $@ $^ $(CFLAGS)

test4: test4.o
	$(CC) -o $@ $^ $(CFLAGS)

test5: test5.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-rm -f *.o project1 test1 test2 test3 test4 test5
