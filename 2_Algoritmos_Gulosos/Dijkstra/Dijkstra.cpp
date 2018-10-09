#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <cstdio>
#include <algorithm>

#define INFINITO 99999999

using namespace std;

typedef pair<int, int> par;

/*
void Dijkstra(int S){
	
	for(int i = 1;i <= tam_matriz;i++) distancia[i] = INFINITO; // definimos todas as distâncias como infinito, exceto a de S.
	distancia[S] = 0;                                  // Assim, garantimos que o primeiro vértice selecionado será o próprio S.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[S], S) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distância do
	// vértice a S e o segundo como sendo o próprio vértice
	
	while(true){ // rodar "infinitamente"
		
		int davez = -1;
		int menor = INFINITO;
		
		// selecionamos o vértice mais próximo
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ // podemos usar esse vértice porque ele ainda não foi processado
				davez = atual;
				break;
			}
			
			// se não, continuamos procurando
		}
		
		if(davez == -1) break; // se não achou ninguém, é o fim do algoritmo
		
		processado[davez] = true; // marcamos para não voltar para este vértice
		
		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possível distância é distancia[davez] + dist.
			// Comparamos isso com distancia[atual]
			
			if( distancia[atual] > distancia[davez] + dist ){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = distancia[davez] + dist;    // atualizamos a distância
				fila.push( pii(distancia[atual], atual) );     // inserimos na fila de prioridade
			}
		}
	}
	
}*/

int main()
{
    ifstream arq_matriz("instancias_teste/dij10.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij20.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij40.txt", ios::in);
    //ifstream arq_matriz("instancias_teste/dij50.txt", ios::in);
    

    int tam_matriz; // Quantidade de vertices
    int num_arestas = 0; // Quantidade de arestas

    arq_matriz >> tam_matriz; //Lê a primeira linha da matriz que diz respeito ao tamanho

    int dij[tam_matriz][tam_matriz] = {0}; //Cria matriz adjacência do tamanho certo 
    int distancia[tam_matriz];           // o array de distâncias à fonte
    int processado[tam_matriz];          // o array que guarda se um vértice foi processado
    vector<par> vizinhos[tam_matriz];

    for (int i = 0; i < tam_matriz; i++){
        for (int j = i; j < tam_matriz; j++){
            if (i == j) //Distância entre um vértice em relação a ele mesmo é 0
                continue;
            
            arq_matriz >> dij[i][j];
            dij[j][i] = dij[i][j];
            num_arestas++;
            vizinhos[i].push_back(par(dij[i][j], j));
            vizinhos[j].push_back(par(dij[i][j], i));
        }
    }

    /*
    for (int i = 0; i < tam_matriz; i++){
        for (int j = i + 1; j < tam_matriz; j++){
            cout << dij[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Numero de arestas do grafo: " << num_arestas << endl;
    */

    int S = 0;
    for(int i = 1;i <= tam_matriz;i++) distancia[i] = INFINITO; // definimos todas as distâncias como infinito, exceto a de S.
	distancia[S] = 0;                                  // Assim, garantimos que o primeiro vértice selecionado será o próprio S.
	
	priority_queue< par, vector<par>, greater<par> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( par(distancia[S], S) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distância do
	// vértice a S e o segundo como sendo o próprio vértice
	
	while(true){ // rodar "infinitamente"
		
		int davez = -1;
		unsigned long int menor = INFINITO;
		
		// selecionamos o vértice mais próximo
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ // podemos usar esse vértice porque ele ainda não foi processado
				davez = atual;
				break;
			}
			
			// se não, continuamos procurando
		}
		
		if(davez == -1) break; // se não achou ninguém, é o fim do algoritmo
		
		processado[davez] = true; // marcamos para não voltar para este vértice
		
		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possível distância é distancia[davez] + dist.
			// Comparamos isso com distancia[atual]
			
			if( distancia[atual] > distancia[davez] + dist ){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = distancia[davez] + dist;    // atualizamos a distância
				fila.push( par(distancia[atual], atual) );     // inserimos na fila de prioridade
			}
		}
	}

    cout << distancia[8] << endl;

    return 0;
}