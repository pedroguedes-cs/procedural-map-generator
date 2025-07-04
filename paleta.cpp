#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
        Paleta()
        {
            quantidade = 0;
            cores = {};
            valores = {};
        }

        Paleta (int quantidade1, vector<Cor> cores1, vector<double> valores1)
        {
            quantidade = quantidade1;
            cores = cores1;
            valores = valores1;
        }

        Paleta ler_arquivo(string nome_arquivo)
        {
            ifstream arquivo(nome_arquivo);

             Paleta paleta;

            if (arquivo.is_open() == false)
            {
                return paleta;
            }
            else
            {
                arquivo >> paleta.quantidade;

                double valor_cor;
                int r1, g1, b1;

                while (arquivo >> valor_cor >> r1 >> g1 >> b1)
                {
                    paleta.valores.push_back(valor_cor);
                    paleta.cores.push_back({r1, g1, b1});
                }

                return paleta;
            }
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