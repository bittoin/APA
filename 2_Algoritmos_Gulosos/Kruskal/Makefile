CC = g++
CFLAGS = -c -Wall -std=c++11

all: Kruskal

Kruskal: Kruskal.o aresta.o
	$(CC) Kruskal.o aresta.o -o Kruskal

Kruskal.o: Kruskal.cpp
	$(CC) $(CFLAGS) Kruskal.cpp

aresta.o:
	$(CC) $(CFLAGS) aresta.cpp

clean:
	rm -rf *o Kruskal
