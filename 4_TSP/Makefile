CC = g++
CFLAGS = -c -Wall -std=c++11

all: tsp

tsp: tsp.o
	$(CC) tsp.o -o tsp

tsp.o: tsp.cpp
	$(CC) $(CFLAGS) tsp.cpp

clean:
	rm -rf *o tsp
