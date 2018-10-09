CC = g++
CFLAGS = -c -Wall -std=c++11

all: Prim

Prim: Prim.o aresta.o
	$(CC) Prim.o aresta.o -o Prim

Prim.o: Prim.cpp
	$(CC) $(CFLAGS) Prim.cpp

aresta.o:
	$(CC) $(CFLAGS) aresta.cpp

clean:
	rm -rf *o Prim
