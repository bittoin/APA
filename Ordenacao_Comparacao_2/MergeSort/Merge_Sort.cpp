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
    int esqIndex, dirIndex, tamanhoMax;
    vector<int> itemTemp(item.size());
    bool limiteEsq = false, limiteDir = false;
    tamanhoMax = fimIndex - inicioIndex + 1;
    esqIndex = inicioIndex;
    dirIndex = indexCentro + 1;

    for (int i = 0; i < tamanhoMax; i++){
        if (!limiteDir && !limiteEsq){
            //Condição para ordenar os dois quando estão fragmentados
            if(item[esqIndex] < item[dirIndex]){
                itemTemp[i] = item[esqIndex];
                esqIndex++;
            }else{
                itemTemp[i] = item[dirIndex];
                dirIndex++;
            }

            //Condição p/ não continuar a ordenação dos dois ao mesmo tempo
            if (esqIndex > indexCentro)
                limiteEsq = true;
            if (dirIndex > fimIndex)
                limiteDir = true;
        }else{
            if(!limiteEsq){
                itemTemp[i] = item[esqIndex];
                esqIndex++;
            }else{
                itemTemp[i] = item[dirIndex];
                dirIndex++;
            }
        }
    }

    //Faz a ordenação dos elementos no array principal por pedaços
    for (int i = 0, parte = inicioIndex; i < tamanhoMax; i++, parte++){
        item[parte] = itemTemp[i];
    }
    
    itemTemp.clear(); //Vector temporário não é mais necessário
}

void mergeSort(vector<int> &item, int inicioIndex, int fimIndex){
    int indexCentro;
    cout << "TESTE" << endl;
    if (inicioIndex < fimIndex){
        indexCentro = floor((inicioIndex + fimIndex) / 2);
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
    mergeSort(item, 0, item.size());
    exibeItens(item);

    return 0;
}
