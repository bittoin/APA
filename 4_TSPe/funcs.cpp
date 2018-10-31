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



void opt_2(struct matriz x, int* solucao){
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

    copia_percurso(x, solucaoSaida, solucao);
	//imprimir_percurso(x.numero_elementos+1, solucaoSaida);
	//cout << "CUSTO DE ENTRADA NO 2-OPT: " << mCustoEntrada << "      CUSTO DE SAIDA NO 2-OPT: "<< mCusto_atual <<endl;
}

void copia_percurso(struct matriz x, int* origem, int* destino){
	int i;

	for(i = 0; i <= x.numero_elementos; i++){
		destino[i] = origem[i];
	}
}

void swap(struct matriz x, int* solucao){
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
    copia_percurso(x, melhorConjunto, solucao);
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

void VND(struct matriz x, int* solucao){
    /*cout << "CUSTO DE ENTRADA NO SWAP: " << custo(x, solucao) << endl;
	swap(x, solucao);
	cout << "CUSTO DE SAIDA NO SWAP: "<< custo(x, solucao) << endl;
	opt_2(x, solucao);
	cout << "CUSTO DE SAIDA NO 2-OPT: "<< custo(x, solucao) << endl;*/

	//PARA NUMDESCIDAS = 1, MÉTODO DA PRIMEIRA MELHORA
    int numDescidas = 1, i =0;
	int iteraSwap = 0, iteraOpt = 0;
	int menorCusto = custo(x, solucao);
	int custoAnterior;
	int *solucaoTemp = new int[x.numero_elementos + 1];
	copia_percurso(x, solucao, solucaoTemp);
    cout << "CUSTO DE ENTRADA: " << custo(x, solucao) << endl;

    while(iteraSwap < numDescidas){
        swap(x, solucaoTemp);
        custoAnterior = custo(x, solucaoTemp);
        if(menorCusto > custoAnterior){
            menorCusto =  custo(x,solucaoTemp);
            iteraSwap++;
        }else{
            iteraSwap = 0;
        }
        //cout << "teste swap" << endl;
    }
    
    menorCusto = custo(x, solucaoTemp);
    while(iteraOpt < numDescidas){
        opt_2(x, solucaoTemp);
        custoAnterior = custo(x, solucaoTemp);
        if(menorCusto > custoAnterior){
            menorCusto = custo(x, solucaoTemp);
            iteraOpt++;
        }else{
            iteraOpt = 0;
        }
        //cout << "teste opt" << endl;
    }

    cout << "CUSTO DE SAIDA: " << custo(x, solucaoTemp) << endl;
	imprimir_percurso(x.numero_elementos+1, solucaoTemp);
}

int remove_elemento(int numero, int* caminho, int local){
    int valor = caminho[local];

    if(local == numero-1){
        return valor;
    }

    for(int i = local; i < numero-1; i++){
        caminho[i] = caminho[i+1];
    }

    return valor;
}


void ordena_solucao(struct matriz x, int* solucaoInicial){
    int aux = 0, menor;
    struct lista lista[x.numero_elementos];

    for(int i = 0; i < x.numero_elementos; i++){ 
        for(int j = 0; j < x.numero_elementos; j++){
            aux = aux + x.elementos[i][j];
        }
        lista[i].numV = i;
        lista[i].custo = aux;
        aux = 0;
    }
    for(int i = 0; i < x.numero_elementos ; i++){
        solucaoInicial[i] = lista[i].numV;
    }
    printf("\nLista de melhores vertices: ");
    imprimir_percurso(x.numero_elementos+1, solucaoInicial);

    for(int i = 0; i < x.numero_elementos; i++){
        for(int j=i+1; j < x.numero_elementos; j++){
            if(lista[j].custo < lista[i].custo){
                aux = lista[j].numV;
                menor = lista[j].custo;
                lista[j].numV = lista[i].numV;
                lista[j].custo = lista[i].custo;
                lista[i].custo = menor;
                lista[i].numV = aux;
            }
        }
    }

    for(int i = 0; i < x.numero_elementos; i++){
        solucaoInicial[i] = lista[i].numV;
    }
    printf("\nLista dos melhores vertices ordenada: ");
    imprimir_percurso(x.numero_elementos+1, solucaoInicial);

}

void construcaoLCR(struct matriz x, int* solucao, float alfa){
    int* solucaoTemp = new int[x.numero_elementos + 1];
    int* solucaoFinal = new int[x.numero_elementos + 1];
    int numero = x.numero_elementos;
    int vertice;
    int j, aux;

    ordena_solucao(x, solucao); 
    copia_percurso(x, solucao, solucaoTemp);
    printf("\nSolucao inicial: ");
    imprimir_percurso(x.numero_elementos+1, solucaoTemp);
    int custoSolucaoTemp = custo(x, solucaoTemp);
    printf("Custo: %d\n\n", custoSolucaoTemp);
   
    for(int i = 0; i < x.numero_elementos; i++){
        if(numero > 1){
            aux = (int)(alfa*numero);
        }else{
            aux = 0;
        }

        printf("\naux = %d\n",aux);
        if(aux > 1){
            j = rand() % (aux-1);
        }else{
            j = 0;
        }
        printf("\n j = %d",j);

        printf("\nnumero = %d",numero);

        vertice = remove_elemento(numero, solucaoTemp, j);
        if(numero > 0){
            numero--;
        }

        solucaoFinal[i] = vertice;
    }

    copia_percurso(x, solucaoFinal, solucao);
}

void GRASP(struct matriz x, int* solucaoInicial, int max, int* solucaoFinal){
    int valor_ref = NUM_ALTO;
    int custo_ref;

    ordena_solucao(x, solucaoInicial);
    srand(time(NULL));

    for(int i = 0; i < max; i++){
        construcaoLCR(x, solucaoInicial, 0.5);
        printf("\nSolucao Grasp = ");
        imprimir_percurso(x.numero_elementos+1, solucaoInicial);
        custo_ref = custo(x, solucaoInicial);
        printf("\n Custo = %d\n", custo_ref);
        /*ImplementarVND(m,solucao_inicial,solucao_final);
        custo_referencia = custo(m,solucao_final);
        if(custo_referencia < valor_referencia){
            valor_referencia = custo_referencia;
            solucao_final = solucao_final;
        }*/
    }
}