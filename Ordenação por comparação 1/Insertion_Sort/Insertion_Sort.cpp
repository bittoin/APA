/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Insertion Sort
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility> //Contém função swap

using namespace std;

int main(){
    vector<int> item;
    cout << "Insira os elementos da lista. (Para com a inserção do caractere 'n')" << endl;
    //Entrada de dados
    for (int i = 0;; i++){
        cout << "Item " << i << ": ";
        string tempItem;
        cin >> tempItem;
        if (!tempItem.compare("n")) break;
        item.push_back(stoi(tempItem));
    }
    
    //Ordenação dos dados
    for(unsigned int i = 0; i < item.size()-1; i++){
        int pivoIndex = i+1;
        while(pivoIndex > 0 && (item[pivoIndex] < item[pivoIndex-1])){
            swap(item[pivoIndex], item[pivoIndex-1]);
            pivoIndex--;
        }
    }

    //Visualização dos dados ordenados
    cout << endl << "Elementos ordenados: " << endl;
    for(unsigned int i = 0; i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }

    return 0;
}