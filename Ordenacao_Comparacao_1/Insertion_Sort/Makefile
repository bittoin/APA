CC = g++
CFLAGS = -c -Wall -std=c++11

all: inserction

inserction: Insertion_Sort.o
	$(CC) Insertion_Sort.o -o insertion

Insertion_Sort.o: Insertion_Sort.cpp
	$(CC) $(CFLAGS) Insertion_Sort.cpp

clean:
	rm -rf *o insertion
