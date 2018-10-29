#include "funcs.h"

int main(void){
	struct matriz x;

	int melhor; //Armazena melhor índice em relação ao vértice inicial

 	//---------------LEITURA DAS INSTÂNCIAS---------------

		//--Instâncias com o triangulo superior--
	//ifstream arquivo("instancias/brazil58.tsp", ios::in);
	//ifstream arquivo("instancias/si175.tsp", ios::in);
	ifstream arquivo("instancias/si535.tsp", ios::in);
	//ifstream arquivo("instancias/si1032.tsp", ios::in);

		//--Instâncias com o triangulo inferior--
	//ifstream arquivo("instancias/swiss42.tsp", ios::in);
	//ifstream arquivo("instancias/brg180.tsp", ios::in);
	//ifstream arquivo("instancias/dantzig42.tsp", ios::in);
	//ifstream arquivo("instancias/fri26.tsp", ios::in); //nao adicionada ainda
	//ifstream arquivo("instancias/gr17.tsp", ios::in); //nao adicionada ainda
	//ifstream arquivo("instancias/gr21.tsp", ios::in); //nao adicionada ainda
	//ifstream arquivo("instancias/gr24.tsp", ios::in); //nao adicionada ainda
	//ifstream arquivo("instancias/gr48.tsp", ios::in); //nao adicionada ainda
	//ifstream arquivo("instancias/gr96.tsp", ios::in); //nao adicionada ainda
	
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
		}
	}
	
	int *solucao = new int[x.numero_elementos + 1];

	melhor = melhorVInicial(x, solucao);

	vizinho(x, solucao, melhor);
	
	VND(x, solucao);

}