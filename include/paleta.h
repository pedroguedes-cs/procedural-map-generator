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
        Paleta(); /** Construtor padrão */
        Paleta(int quantidade1, vector<Cor> cores1, vector<double> valores1); /** Construtor parametrizado */

        int consulta_quantidade(); /** Consulta a quantidade de cores na pelata */

        void ler_arquivo(string nome_arquivo); /** Ler um arquivo de nome @nome_arquivo */
        Cor consulta_cor(double valor); /** Recebe um valor e retorna a cor corespondente ao intevalo do valor */

};