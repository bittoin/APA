/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Heap Sort
 */

#include <iostream>
#include <vector>
#include <utility> // Contém função swap
#include <math.h>

using namespace std;

//Exibe todos os valores do vector
void exibeItens(vector<int> &item){
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
}

//Função necessária para garantir a propriedade do Heap Máximo (Valor do nó pai > Valor do nó filho)
//ATUALMENTE REALIZA O MAXHEAP NO ARRAY INTEIRO
void MaxHeapify(vector<int> &item, int tamanho, int index){
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

void BuildMaxHeap(vector<int> &item){
    int lim = floor(item.size()/2) - 1;
    for(int i = lim; i >= 0; i--){
        MaxHeapify(item, item.size(), i);
    }
}


void heapSort(vector<int> &item, int tam){
    BuildMaxHeap(item);
    //Depois que faz a troca, diminui o tamanho do array
    for (int i = item.size() - 1; i >= 0; i--)
	{
		swap(item[0], item[i]);
		MaxHeapify(item, i, 0);
	}


}

int main(){
    //vector<int> item = {5, 4, 90, 70, 18, 0, 1, 900, 25, 43, 51, 13, 200, 151, 0, 45, 1045, 0}; /* Apenas valores positivos */
    vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553}; /* Caso com negativos */
    //vector<int> item = {5, 1, 0, 10, 3, 0, 7, 2}; /* Apenas valores positivos */

    heapSort(item, item.size());
    exibeItens(item);

    return 0;
}