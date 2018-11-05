#include "funcs.h"

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



int* opt_2(struct matriz x, int* solucao){
	int mCustoEntrada = custo(x, solucao); 
	int mCusto_atual = mCustoEntrada;
	int *solucaoTemporaria = new int[x.numero_elementos + 1];
	int *solucaoSaida = new int[x.numero_elementos + 1];
	
	for (int i = 0; i < x.numero_elementos+1; i++){
		solucaoTemporaria[i] = solucao[i];
		solucaoSaida[i] = solucao[i];
	}

	//cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << mCusto_atual << ">>>>>>>>>>>>>>>>" << custo(x, solucaoSaida) << endl;
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

    return solucaoSaida;

    //copia_percurso(x, solucaoSaida, solucao);
	//imprimir_percurso(x.numero_elementos+1, solucaoSaida);
	//cout << "CUSTO DE ENTRADA NO 2-OPT: " << mCustoEntrada << "      CUSTO DE SAIDA NO 2-OPT: "<< mCusto_atual <<endl;
}

void copia_percurso(struct matriz x, int* origem, int* destino){
	int i;

	for(i = 0; i <= x.numero_elementos; i++){
		destino[i] = origem[i];
	}
}

int* swap(struct matriz x, int* solucao){
	int* solucao_temporaria = new int[x.numero_elementos + 1];
    int* melhorConjunto = new int[x.numero_elementos + 1];
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
    //copia_percurso(x, melhorConjunto, solucao);

    return melhorConjunto;
}

int melhorVInicial(struct matriz x, int* solucao){
    int melhorVInicial;
    //Exibe as soluções com variação no vértice inicial
	int ref = NUM_ALTO;
	
	for (int i = 0; i < x.numero_elementos; i++){
		vizinho(x, solucao, i);

		int custo_solucao = custo(x, solucao);
		//cout << "Custo da solucao: " << custo_solucao << endl;
		if (ref > custo_solucao){
			melhorVInicial = i;
			ref = custo_solucao;
		}
	}

    return melhorVInicial;
}

int* VND(struct matriz x, int* solucao){
	//PARA NUMDESCIDAS = 1, MÉTODO DA PRIMEIRA MELHORA
    int estruturas = 2;
    int i = 0;
	int custoAtual, custoAnterior;
	int *solucaoTemp = new int[x.numero_elementos + 1];
	int *solucaoInicial = new int[x.numero_elementos + 1];
    copia_percurso(x, solucao, solucaoInicial);
    copia_percurso(x, solucao, solucaoTemp);
    //cout << "CUSTO DE ENTRADA: " << custo(x, solucao) << endl;

    while(i < estruturas){
        if(i == 0){
            solucaoTemp = swap(x, solucao);
            custoAtual = custo(x, solucaoTemp);
        }else if(i == 1){
            solucaoTemp = opt_2(x, solucao);
            custoAtual = custo(x, solucaoTemp);
        }

        custoAnterior = custo(x, solucao);
        if(custoAtual < custoAnterior){
            copia_percurso(x, solucaoTemp, solucao);
            i = 0;
        }else{
            i++;
        }
    }

    printf("Custo VND %d\n", custo(x, solucao));
    //copia_percurso(x, solucaoTemp, solucao);
    return solucao;
    
}

bool acha_candidato(vector<int> vertices, int valor){
    for(int i; i < vertices.size(); i++){
        if(valor == vertices[i]){
            return true;
        }
    }

    return false;
}

int custo_maximo(vector<lista> vertices){
    int valorMaximo = 0;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].custo > valorMaximo){
            valorMaximo = vertices[i].custo;
        }
    }

    return valorMaximo;
}

int custo_minimo(vector<lista> vertices){
    int valorMinimo = NUM_ALTO;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].custo < valorMinimo){
            valorMinimo = vertices[i].custo;
        }
    }

    return valorMinimo;
}

struct lista inicializa_vertice(struct matriz x, int j, int i){
    struct lista lista1;

    lista1.numV = j;
    lista1.custo = x.elementos[i][j];

    return lista1;
}

vector<int> GRC(struct matriz x, int alfa){
    vector<int> solucao;
    solucao.push_back((int)(rand()%x.numero_elementos));

    while(solucao.size() != x.numero_elementos){
        vector<lista> custoFeature;
        for(int i = 0; i < x.numero_elementos; i++){
            if(acha_candidato(solucao, i) == false){
                custoFeature.push_back(inicializa_vertice(x, i, solucao[solucao.size()-1]));
            }
        }

        vector<lista> LCR;
        int custoMinimo = custo_minimo(custoFeature);
        int custoMaximo = custo_maximo(custoFeature);

        int limite = custoMinimo + alfa * (custoMaximo - custoMinimo);
        
        for(int i = 0; i < custoFeature.size(); i++){
            if(custoFeature[i].custo <= limite){
                LCR.push_back(custoFeature[i]);
            }
        }
        srand(clock());
        int vertice_aleatorio = rand() % (LCR.size());

        solucao.push_back(LCR[vertice_aleatorio].numV);
    }
    solucao.push_back(solucao[0]);
    return solucao;
}

int* vector_para_array(vector<int> lista){
    int *array = new int[lista.size()];

    for(int i = 0; i < lista.size(); i++){
        array[i] = lista[i];
    }

    return array;
}

void GRASP(struct matriz x, int max){
    int custo_ref = NUM_ALTO;
    int custo_final, total;

    vector<int> solucao;
    vector<int> solucaoFinal;
     int *solucaoArray = new int[x.numero_elementos + 1];

    for(int i = 0; i < max; i++){
        solucao = GRC(x, 1);
        solucaoArray = vector_para_array(solucao);
        solucaoArray = VND(x, solucaoArray);
        total = custo(x, solucaoArray);

        if(total <= custo_ref){
            custo_final = total;
            solucaoFinal = solucao;
        }   
    }

    printf("Custo GRASP: %d\n", custo_final);
}