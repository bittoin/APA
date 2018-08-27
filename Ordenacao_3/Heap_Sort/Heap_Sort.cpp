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
void MaxHeapify(vector<int> &item, int index){
    int indexEsq = 2*index + 1;
    int indexDir = 2*index + 2;
    int tamanho_heap = item.size() - index;
    int maior = index;
    int noEsq = item[indexEsq];
    int noDir = item[indexDir];

    //if (noEsq <= tamanho_heap)
}

void BuildMaxHeap(vector<int> &item){
    int tamanho_heap = item.size();
    int lim = floor(item.size()/2) - 1;
    for(int i = lim; i >= 0; i--){
        MaxHeapify(item, i);
    }
}

void heapSort(vector<int> &item){

}

int main(){
    vector<int> item = {5, 4, 90, 70, 18, 0, 1, 900, 25, 43, 51, 13, 200, 151, 0, 45, 1045, 0}; /* Apenas valores positivos */
    //vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553}; /* Caso com negativos */
    //vector<int> item = {5, 1, 0, 10, 3, 0, 7, 2}; /* Apenas valores positivos */

    vector<int> vectorOrdenado(item.size()); //Armazena valores ordenados
    
    exibeItens(vectorOrdenado);

    return 0;
}