/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Merge Sort
 */

#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

void merge(vector<int> &item, int inicioIndex, int indexCentro, int fimIndex){
    int esqIndex, dirIndex;
    esqIndex = indexCentro - inicioIndex + 1;
    dirIndex = fimIndex - indexCentro;
}

void mergeSort(vector<int> &item, int inicioIndex, int fimIndex){
    int indexCentro;
    if (inicioIndex < fimIndex){
        indexCentro = (inicioIndex + fimIndex) / 2;
        mergeSort(item, inicioIndex, indexCentro);
        mergeSort(item, indexCentro + 1, fimIndex);
        merge(item, inicioIndex, indexCentro, fimIndex);
    }
}

void exibeItens(vector<int> &item){
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
}

int main(){

    //Caso teste
    vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553};
    mergeSort(item, 2, 3);

    return 0;
}
