CC = gcc
CFLAGS = -g -Wall
CENDING = -lpthread

all: mt-collatz.o

mt-collatz.o: mt-collatz.c mt-collatz.h
	$(CC) $(CFLAGS) mt-collatz.c mt-collatz.h -o mt-collatz $(CENDING)

.PHONY: clean run	 
clean:
	rm mt-collatz.o
	
run:
	./mt-collatz
