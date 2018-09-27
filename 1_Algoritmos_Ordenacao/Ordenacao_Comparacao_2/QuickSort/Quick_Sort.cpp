/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Quick Sort
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int particao(vector<int> &item, int inicioIndex, int fimIndex){
    int pivo, esquerdaIndex, direitaIndex;
    esquerdaIndex = inicioIndex;
    direitaIndex = fimIndex;
    pivo = item[inicioIndex]; // Verificar se der bug

    while (esquerdaIndex < direitaIndex){
        while(item[esquerdaIndex] <= pivo)
            esquerdaIndex++;

        while(item[direitaIndex] > pivo)
            direitaIndex--;

        if (esquerdaIndex < direitaIndex)
            swap(item[esquerdaIndex], item[direitaIndex]);
    }

    item[inicioIndex] = item[direitaIndex];
    item[direitaIndex] = pivo;
    return direitaIndex;
}

void quickSort(vector<int> &item, int inicioIndex, int fimIndex){
    int pivo;
    if (fimIndex > inicioIndex){
        pivo = particao(item, inicioIndex, fimIndex); // Pivo é a posição onde todo mundo paraa esquerda é menor e todo mundo para a direita é maior
        quickSort(item, inicioIndex, pivo - 1);
        quickSort(item, pivo + 1, fimIndex);
    }
}

void exibeItens(vector<int> &item){
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
}

int main(){

    //Casos teste
    vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553};
    quickSort(item, 0, item.size());
    exibeItens(item);

    return 0;
}