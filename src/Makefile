CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o tokenizer.o
	$(CC) -o main main.o tokenizer.o

main.o: main.c tokenizer.h
	$(CC) $(CFLAGS) -c main.c

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

clean:
	rm -f *.o main
