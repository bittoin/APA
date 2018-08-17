CC = g++
CFLAGS = -c -Wall -std=c++11

all: counting

counting: Counting_Sort.o
	$(CC) Counting_Sort.o -o counting

Counting_Sort.o: Counting_Sort.cpp
	$(CC) $(CFLAGS) Counting_Sort.cpp

clean:
	rm -rf *o counting
