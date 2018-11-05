#include "funcs.h"

int main(void){
	struct matriz x;

	int melhor; //Armazena melhor índice em relação ao vértice inicial

 	//---------------LEITURA DAS INSTÂNCIAS---------------

		//--Instâncias da tsp matriz completa--
	//ifstream arquivo("instancias/pcv04.txt", ios::in);
	//ifstream arquivo("instancias/pcv10.txt", ios::in);
	//ifstream arquivo("instancias/pcv20.txt", ios::in);
	//ifstream arquivo("instancias/pcv50.txt", ios::in);

		//--Instâncias com o triangulo superior--
	//ifstream arquivo("instancias/si175.tsp", ios::in);
	//ifstream arquivo("instancias/si535.tsp", ios::in);
	//ifstream arquivo("instancias/si1032.tsp", ios::in);

	/*
	 * --Instâncias com a matriz completa--
	 * Encontrados em https://people.sc.fsu.edu/~jburkardt/datasets/tsp/tsp.html
	 */
	//ifstream arquivo("inst/att48_d.txt", ios::in);
	//ifstream arquivo("inst/dantzig42_d.txt", ios::in);
	//ifstream arquivo("inst/five_d.txt", ios::in);
	//ifstream arquivo("inst/fri26_d.txt", ios::in);
	//ifstream arquivo("inst/gr17_d.txt", ios::in);
	//ifstream arquivo("instancias/brazil58.txt", ios::in);
	ifstream arquivo("inst/p01_d.txt", ios::in);
	
	
	
	string temp;

	// while (temp.compare("DIMENSION") != 0 && temp.compare("DIMENSION:") != 0){
	// 	arquivo >> temp;
	// }
	arquivo >> x.numero_elementos;

	// while (temp.compare("EDGE_WEIGHT_SECTION") != 0 && temp.compare("EDGE_WEIGHT_SECTION:") != 0){
	// 	arquivo >> temp;
	// }

	//INICIALIZA MATRIZ ADJACÊNCIA
	x.elementos = new int*[x.numero_elementos];
	for(int i = 0; i < x.numero_elementos; i++){
		x.elementos[i] = new int[x.numero_elementos];
	}

	cout << "Valor do número de elementos: " << x.numero_elementos << endl;

	// LEITURA DOS ARQUIVOS PCV
	for(int i = 0; i < x.numero_elementos; i++){
		for(int j = 0; j < x.numero_elementos; j++){
			arquivo >> temp;
			x.elementos[i][j] = atoi(temp.c_str());
		}
	}

	// // LÊ MATRIZ DA TSP LIB
	// for(int i = 0; i < x.numero_elementos+2; i++){
	// 	for(int j = x.numero_elementos; j > i+1; j--){
	// 		arquivo >> temp;
	// 		x.elementos[i][j] = atoi(temp.c_str());
	// 		cout << x.elementos[i][j] << endl;
	// 	}
	// } // TERMINA LEITURA DOS ARQUIVOS

	int *solucao = new int[x.numero_elementos + 1];
	int *solucaoFinal = new int[x.numero_elementos + 1];

	melhor = melhorVInicial(x, solucao);

	vizinho(x, solucao, 0);
	
	VND(x, solucao);
	GRASP(x, x.numero_elementos);
	//imprimir_matriz(x);
}