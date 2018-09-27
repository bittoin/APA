CC = g++
CFLAGS = -c -Wall -std=c++11

all: counting

counting: Counting_Sort_Neg.o
	$(CC) Counting_Sort_Neg.o -o counting

Counting_Sort_Neg.o: Counting_Sort_Neg.cpp
	$(CC) $(CFLAGS) Counting_Sort_Neg.cpp

clean:
	rm -rf *o counting
