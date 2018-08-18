/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Counting Sort
 */

#include <iostream>
#include <vector>

using namespace std;

//Exibe todos os valores do vector
void exibeItens(vector<int> &item){
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
}

void countingSort(vector<int> &item, vector<int> &novoArray){
    int maiorNum = 0;
    for (unsigned int i = 0; i < item.size(); i++){
        if (item[i] > maiorNum)
            maiorNum = item[i];
    }

    //Criando array "C" com a quantidade de indices referente ao maior número encontrado no vector
    vector<int> itemAux(maiorNum + 1);

    //Usa os valores do vector principal para contar a quantidade de vezes aquele número foi encontrado no seu respectivo índice
    for (unsigned int i = 0; i < item.size(); i++){
        itemAux[item[i]]++;
    }
        //cout << "Vamos testar uma posição: " << itemAux[5] << endl;
    
    //Realiza soma da contagem em relação a todos os elementos anteriores ao atual
    for (unsigned int i = 1; i <= itemAux.size(); i++){
        itemAux[i] += itemAux[i-1];
    }
 
    //Criado para representar o vector "B" que armazena os valores ordenados
    //vector<int> novoArray(item.size()); 

    //Atribui valores ordenados no vector "B" secundário
    for (int i = item.size(); i >= 0; --i){
        novoArray[itemAux[item[i]] - 1] = item[i];
        itemAux[item[i]]--;
    }

    itemAux.clear();
}

int main(){
    vector<int> item = {5, 4, 90, 70, 18, 0, 1, 900, 25, 43, 51, 13, 200, 151, 0, 45, 1045, 0}; /* Apenas valores positivos */
    //vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553}; /* Caso com negativos */
    //vector<int> item = {5, 1, 0, 10, 3, 0, 7, 2}; /* Apenas valores positivos */

    vector<int> novoArray(item.size()); //Armazena valores ordenados
    
    countingSort(item, novoArray);
    exibeItens(novoArray);

    return 0;
}