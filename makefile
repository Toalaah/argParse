CFLAGS=-std=c99 -Wall
CC=gcc
.DEFAULT_GOAL=build

main.o: examples/main.c parser.o 
	$(CC) $(CFLAGS) -c examples/main.c -o main.o


parser.o: parser.c parser.h 
	$(CC) $(CFLAGS) -c parser.c -o parser.o


example: main.o parser.o
	$(CC) $(CFLAGS) main.o parser.o -o main;
	./main -i 7 -f 1.618 -s 'Goodbye world!'

build: parser.c parser.h 
	$(CC) $(CFLAGS) -c parser.c -o parser.o


clean:
	rm -f *.o main
