#include "../include/paleta.h"
#include <fstream>

using namespace std;

int Paleta::get_quant() 
{ 
    return quantidade; 
}

Paleta::Paleta()
{
    quantidade = 0;
    cores = {};
    valores = {};
}

Paleta::Paleta(int quantidade1, vector<Cor> cores1, vector<double> valores1)
{
    quantidade = quantidade1;
    cores = cores1;
    valores = valores1;
}

void Paleta::ler_arquivo(string nome_arquivo)
{
    ifstream arquivo(nome_arquivo);

    // Limpar valores anteriores
    quantidade = 0;
    cores.clear();
    valores.clear();


    if (arquivo.is_open() == false)
    {
        return;
    }
    else
    {
        arquivo >> quantidade;

        double valor_cor;
        int r1, g1, b1;

        while (arquivo >> valor_cor >> r1 >> g1 >> b1)
        {
            valores.push_back(valor_cor);
            cores.push_back({r1, g1, b1});
        }
    }
}

// 
Cor Paleta::consulta_cor(double valor)
{
    // Verificação (valor mínimo)
    if (valores[0] > valor)
    {
        return cores[0];
    }

    // Caso normal
    for (int i = 0; i < quantidade; i++)
    {
        if (valores[i] > valor)
        {
            return cores[i - 1];
        }
    }

    // Valor máximo
    return cores[quantidade - 1];
}