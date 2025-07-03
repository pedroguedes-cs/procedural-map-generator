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

        void ler_arquivo()
        {

        }

        Cor consulta_cor(double valor)
        {
            // Varificação
            if (valores[0] > valor)
            {
                return cores[0];
            }

            for (int i = 0; i < quantidade; i++)
            {
                if (valores[i] > valor)
                {
                    return cores[i-1];
                }
            }
            return cores[quantidade];
        }

};