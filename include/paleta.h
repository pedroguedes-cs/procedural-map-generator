#pragma once
#include <vector>
#include <string>
#include "paleta.h"
#include "cor.h"

using namespace std;

class Paleta
{
    //Atributos
    int quantidade;
    vector<Cor> cores;
    vector<double> valores;

    //Operações
    public:
        int get_quant();
        
        Paleta();
        Paleta(int quantidade1, vector<Cor> cores1, vector<double> valores1);

        void ler_arquivo(string nome_arquivo);
        Cor consulta_cor(double valor);

};