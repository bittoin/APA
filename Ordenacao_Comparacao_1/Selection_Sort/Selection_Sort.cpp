/*
 * Aluno: Mateus Antonio da Silva
 * Disciplina: Análise e Projeto de Algoritmos
 * Período: 2018.1
 * Algoritmo de Ordenação: Selection Sort
 */

#include <iostream>
#include <vector>
#include <utility> //Contém função swap
#include <chrono>

using namespace std;

int main(){
    //vector<int> item = {5, 4, 90, -3, 70, 18, 0, 1, -400, 900, 25, 43, 51, 13, -6, -14, 200, 151, -9, 0, 45, 1045, 0, -553}; /* Caso médio */
    //vector<int> item = {1045, 900, 200, 151, 90, 70, 51, 45, 43, 25, 18, 13, 5, 4, 1, 0, 0, 0, -3, -6, -9, 14, -400, -553}; /* Pior caso */
    vector<int> item = {-553, -400, -14, -9, -6, -3, 0, 0, 0, 1, 4, 5, 13, 18, 25, 43, 45, 51, 70, 90, 151, 200, 900, 1045}; /* Melhor caso */
    
    // Começa a contagem do tempo
    auto start = chrono::high_resolution_clock::now();
    
    //Ordenação dos dados
    for(unsigned int i = 0; i < item.size(); i++){
        int minimoIndex = i;
        for (unsigned int j = i+1; j < item.size(); j++){
            if (item[j] < item[minimoIndex])
                minimoIndex = j;
        }
        swap(item[i], item[minimoIndex]);
    }
    
    // Armazena o fim do tempo
    auto finish = chrono::high_resolution_clock::now();
    // Realiza a diferença do tempo entre o final e o início do algoritmo
    chrono::duration<double> elapsed = finish - start;

    //Visualização dos dados ordenados
    cout << endl << "Elementos ordenados: " << endl;
    for(unsigned int i = 0;i < item.size(); i++){
        cout << "Item[" << i << "]: " << item[i] << endl;
    }
    
    cout << "Tempo de execução do algoritmo: " << elapsed.count() << " s\n";

    return 0;
}
