#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> par;

int main()
{
    ifstream arq_matriz("instancias_teste/dij10.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij20.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij40.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij50.txt", ios::in);

    int tam_matriz;
    arq_matriz >> tam_matriz; //Lê a primeira linha da matriz que diz respeito ao tamanho

    int dij[tam_matriz][tam_matriz] = {0}; //Cria matriz adjacência do tamanho certo 
    int n, m;                      // número de vértices e arestas
    int distancia[tam_matriz];           // o array de distâncias à fonte
    int processado[tam_matriz];          // o array que guarda se um vértice foi processado
    vector<par> vizinhos[tam_matriz];    // nossas listas de adjacência. O primeiro elemento do par representa a distância e o segundo representa o vértice
    
    for (int i = 0; i < tam_matriz; i++){
        for (int j = i; j < tam_matriz; j++){
            if (i == j) //Distância entre um vértice em relação a ele mesmo é 0
                continue;
            
            arq_matriz >> dij[i][j];
        }
    }

    int estimativa[tam_matriz] = {-1};
    int pai[tam_matriz] = {-1};
    bool verificado[tam_matriz] = {false};

    //INICIA ALGORITMO DE PRIM
    estimativa[0] = 0;
    int indexTemp = 0;

    while(1){
        for (unsigned int i = 0; i < aresta.size(); i++){
            if (aresta[i].v1 == indexTemp)
                solucaoTemp.push_back(aresta[i]);
        }

        insertionSort(solucaoTemp);
        MST.push_back(solucaoTemp[0]);
    }
    

    //IMPRIME A MATRIZ DE ARESTAS COMPLETA
    exibeVector(solucaoTemp); 

    int soma = 0;
    //IMPRIME NA TELA O VECTOR DE ARESTAS MST
    cout << endl << endl << "SOLUÇÃO DO CAMINHO MÍNIMO: " << endl;
    for (unsigned int i = 0; i < MST.size(); i++){
        cout << i << " >> " << "[" << MST[i].v1 << "]" << "[" << MST[i].v2 << "]" << " = " << MST[i].peso << endl;
        soma += MST[i].peso;
    }
    cout << "SOMA: " << soma << endl;

    return 0;
}