CC = g++
CFLAGS = -c -Wall -std=c++11

all: heap

heap: Heap_Sort.o
	$(CC) Heap_Sort.o -o heap

Heap_Sort.o: Heap_Sort.cpp
	$(CC) $(CFLAGS) Heap_Sort.cpp

clean:
	rm -rf *o heap