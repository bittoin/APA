#include <iostream>
#include <climits>
#include <fstream>
#include <string>
#define TRUE 1
#define FALSE 0
#define NUM_ALTO 999999

using namespace std;

struct matriz{
    int numero_elementos;
    int** elementos;
};

int melhor;

void imprimir_matriz(struct matriz x){
    cout << "Matriz de adjacencia: " << endl;

    for(int i = 0; i < x.numero_elementos; i++){
        for(int j = 0; j < x.numero_elementos; j++){
            cout << x.elementos[i][j] << " ";
        }

        cout << endl;
    }
}

void imprimir_percurso(int n, int* percurso) {
    int i;

    for(i = 0; i < n; i++){
        cout << percurso[i] << " ";
    }
    cout << endl;
}

/*void vizinho(struct matriz x, int* percurso, int vInit){
	int elem_adicionados[x.numero_elementos];

	for(int i = 0; i < x.numero_elementos; i++){
		elem_adicionados[i] = FALSE;
	}

	elem_adicionados[vInit] = TRUE;
	percurso[0] = vInit;

	for(int i = 0; i < x.numero_elementos; i++){
		int ref = NUM_ALTO;
		int vizinho_escolhido = 0;

		for(int j = 0; j < x.numero_elementos; j++){
			if(!elem_adicionados[j] && ref > x.elementos[i][j]){
				ref = x.elementos[i][j];
				vizinho_escolhido = j;
			}
		}
		percurso[i + 1] = vizinho_escolhido;
		cout << vizinho_escolhido << endl;
		elem_adicionados[vizinho_escolhido] = TRUE;
	}

	percurso[x.numero_elementos] = vInit;

}*/

void vizinho(struct matriz x, int* percurso, int vInit){
	int elem_adicionados[x.numero_elementos];

	for(int i = 0; i < x.numero_elementos; i++){
		elem_adicionados[i] = FALSE;
	}

	elem_adicionados[vInit] = TRUE;
	percurso[0] = vInit;

	for(int i = 0; i < x.numero_elementos; i++){
		int ref = NUM_ALTO;
		int vizinho_escolhido = 0;

		for(int j = 0; j < x.numero_elementos; j++){
			if(!elem_adicionados[j] && ref > x.elementos[i][j]){
				ref = x.elementos[i][j];
				vizinho_escolhido = j;
			}
		}
		percurso[i + 1] = vizinho_escolhido;
		elem_adicionados[vizinho_escolhido] = TRUE;
	}

	percurso[x.numero_elementos] = vInit;
}

int custo(struct matriz x, int* percurso){
	int custo = 0;

	for(int i = 0; i < x.numero_elementos; i++){
		custo = custo + x.elementos[percurso[i]][percurso[i + 1]];
	}

	return custo;
}

void inverteArray(matriz x, int *solucao, int limInferior, int limSuperior){
	int arrayTemp[x.numero_elementos+1] = {0};

	for (int i = limInferior, j = limSuperior; i <= limSuperior; i++, j--){
		arrayTemp[i] = solucao[i];
	}

	for (int i = limInferior, j = limSuperior; i <= limSuperior; i++, j--){
		solucao[i] = arrayTemp[j];
	}
	
}

void opt_2(struct matriz x, int* solucao){
	int mCustoEntrada = custo(x, solucao); 
	int mCusto_atual = custo(x, solucao);
	int *solucaoTemporaria = new int[x.numero_elementos + 1];
	int *solucaoSaida = new int[x.numero_elementos + 1];
	
	for (int i = 0; i < x.numero_elementos+1; i++){
		solucaoTemporaria[i] = solucao[i];
		solucaoSaida[i] = solucao[i];
	}

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << mCusto_atual << ">>>>>>>>>>>>>>>>" << custo(x, solucaoSaida) << endl;
	for (int i = 1; i < x.numero_elementos - 2; i++){
		for (int j = 2; j < x.numero_elementos; j++){
			for (int k = 0; k < x.numero_elementos+1; k++){
				solucaoTemporaria[k] = solucao[k];
			}
			inverteArray(x, solucaoTemporaria, i, j);			
			//cout << "Custo das iterações: " << custo(x, solucaoTemporaria) << endl;
			if (mCusto_atual > custo(x, solucaoTemporaria)){
				//cout << "entrei " << mCusto_atual << " comparado a " << custo(x, solucaoTemporaria) << endl;
				mCusto_atual = custo(x, solucaoTemporaria);
				for (int k = 0; k < x.numero_elementos+1; k++){
					solucaoSaida[k] = solucaoTemporaria[k];
				}
			}
				
		}
	}

	//imprimir_percurso(x.numero_elementos+1, solucaoSaida);
	cout << "CUSTO DE ENTRADA NO 2-OPT: " << mCustoEntrada << "      CUSTO DE SAIDA NO 2-OPT: "<< mCusto_atual <<endl;

}

void copia_percurso(struct matriz x, int* origem, int* destino){
	int i;

	for(i = 0; i <= x.numero_elementos; i++){
		destino[i] = origem[i];
	}
}

void swap(struct matriz x, int* solucao, int* melhorConjunto){
	int* solucao_temporaria = new int[x.numero_elementos + 1];
	int custo_ref = custo(x, solucao);
	int aux = 0;
	int custo_solucao = 0;

	copia_percurso(x, solucao, melhorConjunto);

	for(int i = 1; i < x.numero_elementos; i++){
		copia_percurso(x, solucao, solucao_temporaria);

		for(int j = i + 1; j < x.numero_elementos; j++){
			aux = solucao_temporaria[i];
			solucao_temporaria[i] = solucao_temporaria[j];
			solucao_temporaria[j] = aux;

			custo_solucao = custo(x, solucao_temporaria);

			if(custo_solucao < custo_ref){
				custo_ref = custo_solucao;
				copia_percurso(x, solucao_temporaria, melhorConjunto);
			}

		}
	}	

}

int main(void){
	struct matriz x;
 	//Leitura do arquivo
	//ifstream arquivo("instancias/pcv10.txt", ios::in);
	//ifstream arquivo("instancias/brazil58.tsp", ios::in);
	//ifstream arquivo("instancias/si175.tsp", ios::in);
	//ifstream arquivo("instancias/si535.tsp", ios::in);
	ifstream arquivo("instancias/gr21.tsp", ios::in);
	string temp;

	while (temp.compare("DIMENSION") != 0 && temp.compare("DIMENSION:") != 0){
		arquivo >> temp;
	}
	arquivo >> x.numero_elementos;

	while (temp.compare("EDGE_WEIGHT_SECTION") != 0 && temp.compare("EDGE_WEIGHT_SECTION:") != 0){
		arquivo >> temp;
	}

	//INICIALIZA MATRIZ ADJACÊNCIA
	x.elementos = new int*[x.numero_elementos];
	for(int i = 0; i < x.numero_elementos; i++){
		x.elementos[i] = new int[x.numero_elementos];
	}

	cout << "Valor do número de elementos: " << x.numero_elementos << endl;

	for(int i = 0; i < x.numero_elementos; i++){
		for(int j = 0; j < x.numero_elementos; j++){
			arquivo >> temp;
			x.elementos[i][j] = atoi(temp.c_str());
			//x.elementos[j][i] = x.elementos[i][j];
			//cout << x.elementos[i][j] << endl;
		}
	}
	
	int *solucao = new int[x.numero_elementos + 1];

	//Exibe as soluções com variação no vértice inicial
	int ref = NUM_ALTO;
	for (int i = 0; i < x.numero_elementos; i++){
		vizinho(x, solucao, i);

		int custo_solucao = custo(x, solucao);
		//cout << "Custo da solucao: " << custo_solucao << endl;
		if (ref > custo_solucao){
			melhor = i;
			ref = custo_solucao;
		}
	}


	int *melhorConjunto = new int[x.numero_elementos + 1];
	vizinho(x, solucao, melhor);

	imprimir_percurso(x.numero_elementos+1, solucao);
	//cout << "CUSTO DE ENTRADA NO SWAP: " << custo(x, solucao) << endl;
	imprimir_percurso(x.numero_elementos+1, solucao);
	swap(x, solucao, melhorConjunto);
	imprimir_percurso(x.numero_elementos+1, melhorConjunto);
	cout << "      CUSTO DE SAIDA NO SWAP: "<< custo(x, melhorConjunto) << endl;
	opt_2(x, melhorConjunto);
	imprimir_percurso(x.numero_elementos+1, melhorConjunto);
	imprimir_matriz(x);
}