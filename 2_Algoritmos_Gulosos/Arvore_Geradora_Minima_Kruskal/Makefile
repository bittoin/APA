CC = g++
CFLAGS = -c -Wall -std=c++11

all: Kruskal

inserction: Kruskal.o
	$(CC) Insertion_Sort.o -o Kruskal

Kruskal.o: Kruskal.cpp
	$(CC) $(CFLAGS) Kruskal.cpp

clean:
	rm -rf *o Kruskal
