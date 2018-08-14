/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Merge Sort
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void mergeSort(vector<int> &item, int inicioIndex, int fimIndex){
    int indexCentro;
    if(inicioIndex < fimIndex){
        indexCentro = (inicioIndex + fimIndex) / 2;
        mergeSort(item, inicioIndex, indexCentro);
        mergeSort(item, indexCentro + 1, fimIndex);
        Merge(item, inicioIndex, indexCentro, fimIndex);
    }
}

void Merge(vector<int> &item, int inicioIndex, int indexCentro, int fimIndex){
    int esqIndex, dirIndex;
    esqIndex = indexCentro - inicioIndex + 1;
    dirIndex = fimIndex - indexCentro;
}

void exibeItens(vector<int> &item){
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
}

int main(){

    //Casos teste
    vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553};
    //vector<int> item = {1045, 900, 200, 151, 90, 70, 51, 45, 43, 25, 18, 13, 5, 4, 1, 0, 0, 0, -3, -6, -9, 14, -400, -553}; 
    //vector<int> item = {-553, -400, -14, -9, -6, -3, 0, 0, 0, 1, 4, 5, 13, 18, 25, 43, 45, 51, 70, 90, 151, 200, 900, 1045};
    mergeSort(item, 2, 3);

    return 0;
}
