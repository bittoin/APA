CC = g++
CFLAGS = -c -Wall -std=c++11

all: quick

quick: Quick_Sort.o
	$(CC) Quick_Sort.o -o quick

Quick_Sort.o: Quick_Sort.cpp
	$(CC) $(CFLAGS) Quick_Sort.cpp

clean:
	rm -rf *o quick
