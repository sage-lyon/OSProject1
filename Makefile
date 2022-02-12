CC=gcc
CFLAGS=-I.

all: project1 test1 test2 test3 test4 test5

project1: main.c
	$(CC) -o $@ $^ $(CFLAGS)

test1: test1.c
	$(CC) -o $@ $^ $(CFLAGS)

test2: test2.c
	$(CC) -o $@ $^ $(CFLAGS) -lm

test3: test3.c
	$(CC) -o $@ $^ $(CFLAGS)

test4: test4.c
	$(CC) -o $@ $^ $(CFLAGS)

test5: test5.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-rm -f project1 test1 test2 test3 test4 test5
