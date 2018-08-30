#include "Heap.h"

Heap::Heap(){

}

Heap::~Heap(){
    
}

Heap::Heap(vector<int> &item){
    if (item.empty() == true){
        cout << "VECTOR VAZIO" << endl;
        exit(1);
    }
        
    heapSort(item, item.size());
}

//Função necessária para garantir a propriedade do Heap Máximo (Valor do nó pai > Valor do nó filho)
void Heap::MaxHeapify(vector<int> &item, int tamanho, int index){
    int indexEsq = 2*index + 1;
    int indexDir = 2*index + 2;
    int maiorIndex = index;

    if (indexEsq < tamanho && item[indexEsq] > item[maiorIndex])
        maiorIndex = indexEsq;

    if (indexDir < tamanho && item[indexDir] > item[maiorIndex])
        maiorIndex = indexDir;

    if (maiorIndex != index){
        swap(item[index], item[maiorIndex]);
        MaxHeapify(item, tamanho, maiorIndex);
    }
    
}

void Heap::BuildMaxHeap(vector<int> &item){
    int lim = floor(item.size()/2) - 1;
    for(int i = lim; i >= 0; i--){
        MaxHeapify(item, item.size(), i);
    }
}

void Heap::heapSort(vector<int> &item, int tam){
    BuildMaxHeap(item);
    //Depois que faz a troca, diminui o tamanho do array
    for (int i = item.size() - 1; i >= 0; i--)
	{
		swap(item[0], item[i]);
		MaxHeapify(item, i, 0);
	}
}

//Exibe todos os valores do vector
void Heap::exibeItens(vector<int> &item){
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
}