CC = g++
CFLAGS = -c -Wall -std=c++11

all: heap

heap: Heap_Sort.o Heap.o
	$(CC) Heap_Sort.o Heap.o -o heap

Heap_Sort.o: Heap_Sort.cpp 
	$(CC) $(CFLAGS) Heap_Sort.cpp

Heap.o: Heap.cpp Heap.h
	$(CC) $(CFLAGS) Heap.cpp Heap.h
clean:
	rm -rf *o heap