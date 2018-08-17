CC = g++
CFLAGS = -c -Wall -std=c++11

all: selection

selection: Selection_Sort.o
	$(CC) Selection_Sort.o -o selection

Selection_Sort.o: Selection_Sort.cpp
	$(CC) $(CFLAGS) Selection_Sort.cpp

clean:
	rm -rf *o selection
