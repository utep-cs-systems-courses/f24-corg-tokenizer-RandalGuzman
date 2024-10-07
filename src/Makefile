CC = gcc
CFLAGS = -Wall -g

SRCS = main.c tokenizer.c history.c

OBJS = main.o tokenizer.o history.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c tokenizer.h history.h
	$(CC) $(CFLAGS) -c main.c

tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

history.o: history.c history.h
	$(CC) $(CFLAGS) -c history.c

clean:
	rm -f $(OBJS) $(TARGET)
