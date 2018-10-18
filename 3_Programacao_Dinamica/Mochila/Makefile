CC = g++
CFLAGS = -c -Wall -std=c++11

all: mochila

mochila: mochila.o
	$(CC) mochila.o -o mochila

mochila.o: mochila.cpp
	$(CC) $(CFLAGS) mochila.cpp

clean:
	rm -rf *o mochila
