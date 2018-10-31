CC = g++
CFLAGS = -c -Wall -std=c++11

all: tsp
	./tsp

tsp: tsp.o funcs.o
	$(CC) tsp.o funcs.o -o tsp

tsp.o: tsp.cpp
	$(CC) $(CFLAGS) tsp.cpp

funcs.o: funcs.cpp
	$(CC) $(CFLAGS) funcs.cpp

clean:
	rm -rf *o tsp