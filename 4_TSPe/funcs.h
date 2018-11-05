#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <climits>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NUM_ALTO 999999

using namespace std;

struct matriz{
    int numero_elementos;
    int** elementos;
};

struct lista{
    int custo;
    int numV;
};

void imprimir_matriz(struct matriz x);
void imprimir_percurso(int n, int* percurso);
void vizinho(struct matriz x, int* percurso, int vInit);
int custo(struct matriz x, int* percurso);
void inverteArray(matriz x, int *solucao, int limInferior, int limSuperior);
int* opt_2(struct matriz x, int* solucao);
void copia_percurso(struct matriz x, int* origem, int* destino);
int* swap(struct matriz x, int* solucao);
int melhorVInicial(struct matriz x, int* solucao);
int* VND(struct matriz x, int* solucao);
bool acha_candidato(vector<int> vertices, int valor);
int custo_maximo(vector<lista> vertices);
int custo_minimo(vector<lista> vertices);
struct lista inicializa_vertice(struct matriz x, int j, int i);
vector<int> GRC(struct matriz x, int alfa);
void GRASP(struct matriz x, int max);

#endif