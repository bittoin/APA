CC = g++
CFLAGS = -c -Wall -std=c++11

all: merge

merge: Merge_Sort.o
	$(CC) Merge_Sort.o -o merge

Merge_Sort.o: Merge_Sort.cpp
	$(CC) $(CFLAGS) Merge_Sort.cpp

clean:
	rm -rf *o merge
