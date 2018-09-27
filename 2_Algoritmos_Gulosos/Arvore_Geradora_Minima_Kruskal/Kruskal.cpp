#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "aresta.h"

using namespace std;

int main()
{
    ifstream arq_matriz("instancias_teste/dij10.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij20.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij40.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij50.txt", ios::in);

    int tam_matriz;
    arq_matriz >> tam_matriz; //Lê a primeira linha da matriz que diz respeito ao tamanho

    int dij[tam_matriz][tam_matriz] = {0}; //Cria matriz adjacência do tamanho certo 
    
    for (int i = 0; i < tam_matriz; i++){
        for (int j = i; j < tam_matriz; j++){
            if (i == j) //Distância entre um vértice em relação a ele mesmo é 0
                continue;
            
            arq_matriz >> dij[i][j];
        }
    }

    vector<Aresta> aresta;

    for (int i = 0; i < tam_matriz; i++){
        for (int j = i+1; j < tam_matriz; j++){
            Aresta arestaTemp(i, j, dij[i][j]);
            aresta.push_back(arestaTemp);
        }
    }

    //INSERTION SORT PARA ORDENAR AS ARESTAS DE ACORDO COM SEU PESO (IMPLEMENTADO NA PRIMEIRA ENTREGA)
    int pivoIndex = 0;
    for(unsigned int i = 0; i < aresta.size()-1; i++){
        pivoIndex = i+1;
        while(pivoIndex > 0 && (aresta[pivoIndex].peso < aresta[pivoIndex-1].peso)){
            swap(aresta[pivoIndex], aresta[pivoIndex-1]);
            pivoIndex--;
        }
    }

    /*for (unsigned int i = 0; i < aresta.size(); i++){
        cout << i << " >> " << "[" << aresta[i].v1 << "]" << "[" << aresta[i].v2 << "]" << " = " << aresta[i].peso << endl;
    }*/

    //CRIA VECTOR COM IDENTIFICADORES PARA AS ÁRVORES
    vector<int> arvoreID(tam_matriz);
    for (int i = 0; i < tam_matriz; i++){
        arvoreID[i] = i;
    }

    //Cria vector de arestas onde serão armazenados os vértices da arvore geradora mínima
    vector<Aresta> MST;

    for (unsigned int i = 0; i < aresta.size(); i++){
        if (arvoreID[aresta[i].v1] != arvoreID[aresta[i].v2]){
            //arvoreID[aresta[i].v2] = arvoreID[aresta[i].v1];
            
            for (int j = 0; j < tam_matriz; j++){
                if (arvoreID[j] == aresta[i].v2)
                    arvoreID[j] = arvoreID[aresta[i].v1];
            }
            MST.push_back(aresta[i]);

            if (MST.size() >= tam_matriz -1)
                break;
        }
    }

    /*for (unsigned int i = 0; i < aresta.size(); i++){
        if (arvoreID[aresta[i].v2] == -1){
            MST.push_back(aresta[i]);
            arvoreID[aresta[i].v2] = aresta[i].v2;
        }
    }*/

    int soma = 0;
    //IMPRIME NA TELA O VECTOR DE ARESTAS MST
    for (unsigned int i = 0; i < MST.size(); i++){
        cout << i << " >> " << "[" << MST[i].v1 << "]" << "[" << MST[i].v2 << "]" << " = " << MST[i].peso << endl;
        soma += MST[i].peso;
    }
    cout << "SOMA: " << soma << endl;

    return 0;
}