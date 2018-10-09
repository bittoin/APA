CC = g++
CFLAGS = -c -Wall -std=c++11

all: Dijkstra

Dijkstra: Dijkstra.o
	$(CC) Dijkstra.o -o dijkstra

Dijkstra.o: Dijkstra.cpp
	$(CC) $(CFLAGS) Dijkstra.cpp

clean:
	rm -rf *o dijkstra
