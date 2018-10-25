#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//Cria classe Objeto para analisar com mais facilidade as possibilidades de itens na mochila
class Objeto{
public:
    int peso;
    int valor;

    Objeto();
    Objeto(int, int);
};

Objeto::Objeto(){
    this->peso = 0;
    this->valor = 0;
}

Objeto::Objeto(int peso, int valor){
    this->peso = peso;
    this->valor = valor;
}

int Mochila(int linhas, int colunas, vector<Objeto> &obj){

    int matrizPesos[linhas][colunas];

    for (int i = 0; i < linhas; i ++){
        for (int j = 0; j < colunas; j++){
            matrizPesos[i][j] = 0;
        }
    }


    // ALGORITMO ALTERNATIVO TESTADO E DÁ UM PEQUENO ERRO, SOLUÇÃO ÓTIMA É ENCONTRADA EM ALGUNS CASOS, OUTROS CHEGA PERTO
    // for (int i = 1; i < linhas; i++){
    //     for (int j = 1; j < colunas; j++){
    //         if (obj[i-1].peso < j){

    //             if ((obj[i-1].valor + matrizPesos[i-1][j-obj[i-1].peso]) > matrizPesos[i-1][j]){
    //                 matrizPesos[i][j] = obj[i-1].valor + matrizPesos[i-1][j-obj[i-1].peso];
    //             }else{
    //                 matrizPesos[i][j] = matrizPesos[i-1][j];
    //             }

    //         }else{
    //             matrizPesos[i][j] = matrizPesos[i-1][j];
    //         }
    //     }

    // }

    // return matrizPesos[linhas-1][colunas-1];

    //ALGORITMO BASEADO NO SLIDE
    for (int i = 1; i < linhas; i++){
        for (int j = 1; j < colunas; j++){
            if (obj[i-1].peso <= j){
                matrizPesos[i][j] = max(matrizPesos[i-1][j], obj[i-1].valor + matrizPesos[i-1][j-obj[i-1].peso]);
            }else{
                matrizPesos[i][j] = matrizPesos[i-1][j];
            }
        }

    }

    return matrizPesos[linhas-1][colunas-1];
}

int main(int argc, char const *argv[])
{
    // ifstream mochila("instancias/mochila01.txt.txt", ios::in);
    // ifstream mochila("instancias/mochila02.txt.txt", ios::in);
    // ifstream mochila("instancias/mochila1000.txt.txt", ios::in);
    // ifstream mochila("instancias/mochila2500.txt.txt", ios::in);
    ifstream mochila("instancias/mochila5000.txt.txt", ios::in);

    //Lê as duas primeiras linhas do arquivo que dizem respeito a quantidade de objetos e capacidade da mochila
    int qnt_obj, capacidade;
    mochila >> qnt_obj >> capacidade;
    
    //Lê do arquivo e armazena informações no vector de Objetos
    vector<Objeto> obj;
    for (int i = 0; i < qnt_obj; i++){
        Objeto objTemp;
        mochila >> objTemp.peso;
        mochila >> objTemp.valor;
        obj.push_back(objTemp);
    }

    
    //INSERTION SORT PARA ORDENAR OS OBJETOS DE ACORDO COM SEU PESO
    int pivoIndex = 0;
    for(unsigned int i = 0; i < obj.size()-1; i++){
        pivoIndex = i+1;
        while(pivoIndex > 0 && (obj[pivoIndex].peso < obj[pivoIndex-1].peso)){
            swap(obj[pivoIndex], obj[pivoIndex-1]);
            pivoIndex--;
        }
    }

    //Cria matriz para armazenar valores relacionados ao custo benefício dos objetos de acordo com o peso
    unsigned int linhas = obj.size() + 1;
    unsigned int colunas = capacidade + 1;
    //int matrizPesos[linhas][colunas] = {0};

    cout << "Valor maximo da mochila: " << Mochila(linhas, colunas, obj) << endl;
    return 0;
}
