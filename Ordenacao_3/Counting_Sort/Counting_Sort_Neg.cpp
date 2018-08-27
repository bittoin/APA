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
    int menorNum = 0;
    
    for (unsigned int i = 0; i < item.size(); i++){
        if (item[i] > maiorNum)
            maiorNum = item[i];
        if (item[i] < menorNum)
            menorNum = item[i];
    }

    if (menorNum < 0)
        menorNum = menorNum * -1;

    cout << "Menor num: " << menorNum << endl;
    //Criando array "C" com a quantidade de indices referente ao maior número encontrado no vector
    vector<int> itemAux(maiorNum + menorNum + 1);
    cout << "Tamanho do vector: " << itemAux.size() << endl;
    //Usa os valores do vector principal para contar a quantidade de vezes aquele número foi encontrado no seu respectivo índice
    for (unsigned int i = 0; i < item.size(); i++){
        int index = item[i] + menorNum; // Desloca índice se necessário com menorNum
        itemAux[index]++;
    }
        //cout << "Vamos testar uma posição: " << itemAux[5] << endl;
    
    //Realiza soma da contagem em relação a todos os elementos anteriores ao atual
    for (unsigned int i = 1; i <= itemAux.size(); i++){
        itemAux[i] += itemAux[i-1];
    }
    cout << "Vamos testar uma posição: " << itemAux[50] << endl;
    //Atribui valores ordenados no vector "B" secundário
    int index = 0;
    for (int i = item.size()-1; i >= 0; i--){
        index = item[i] + menorNum; // Desloca índice se necessário com menorNum
        novoArray[itemAux[index] - 1] = item[i];
        itemAux[index]--;
    }

    itemAux.clear();
}

int main(){
    //vector<int> item = {5, 4, 90, 70, 18, 0, 1, 900, 25, 43, 51, 13, 200, 151, 0, 45, 1045, 0}; /* Apenas valores positivos */
    vector<int> item = {-2, 3, 5, 0, 1, -1, 0, 4}; /* Apenas valores positivos */
    //vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553}; /* Caso com negativos */
    //vector<int> item = {5, 1, 0, 10, 3, 0, 7, 2}; /* Apenas valores positivos */

    vector<int> vectorOrdenado(item.size()); //Armazena valores ordenados
    
    countingSort(item, vectorOrdenado);
    exibeItens(vectorOrdenado);

    return 0;
}