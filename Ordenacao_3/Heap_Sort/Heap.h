#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include <iostream>
#include <math.h>
#include <utility>

using namespace std;

class Heap{
private:    
    int tamanho_heap;

public:
    Heap();
    Heap(vector<int> &item);
    ~Heap();
    void exibeItens(vector<int> &item);
    void MaxHeapify(vector<int> &item, int tamanho, int index);
    void BuildMaxHeap(vector<int> &item);
    void heapSort(vector<int> &item, int tam);
};

#endif