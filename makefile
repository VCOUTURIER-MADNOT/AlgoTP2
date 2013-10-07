CC = gcc -Wall -O3 -ansi -pedantic

all: main

main: main.o pile.o outilsPile.o hanoi.o
	$(CC) -o main main.o pile.o outilsPile.o

main.o: main.c
	$(CC) -o main.o -c main.c

pile.o: pile.c pile.h
	$(CC) -o pile.o -c pile.c

outilsPile.o: outilsPile.c outilsPile.h
	$(CC) -o outilsPile.o -c outilsPile.c

hanoi.o: hanoi.c hanoi.h
	$(CC) -o hanoi.o -c hanoi.c

clean:
	rm -rf *.o
			
