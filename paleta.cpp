#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Cor
{
    int r;
    int g;
    int b;
};

class Paleta
{
    //Atributos
    int quantidade;
    vector<Cor> cores;
    vector<double> valores;

    //Operações
    public:
        Paleta (int quantidade1, vector<Cor> cores1, vector<double> valores1)
        {
            quantidade = quantidade1;
            cores = cores1;
            valores = valores1;
        }

        ler_arquivo()

};