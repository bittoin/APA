/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Selection Sort
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
    for(unsigned int i = 0; i < item.size(); i++){
        int minimoIndex = i;
        for (int j = i+1; j < item.size(); j++){
            if (item[j] < item[minimoIndex])
                minimoIndex = j;
        }
        swap(item[i], item[minimoIndex]);
    }

    //Visualização dos dados ordenados
    cout << endl << "Elementos ordenados: " << endl;
    for(unsigned int i = 0;i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }

    return 0;
}