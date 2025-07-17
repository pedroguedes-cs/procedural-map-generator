#include "../include/paleta.h"
#include <fstream>

using namespace std;

/** Construtor padrão:
    Inicializa os elementos da paleta da seguinte:
        quantidade = 0;
        todas as cores do vector cores = 0;
        todos os valores do vector valores = 0.

*/
Paleta::Paleta()
{
    quantidade = 0;
    cores = {};
    valores = {};
}

/** Construtor parametrizado. 
    Recebe: 
        @quantidade1 - Quantidade de cores na paleta;  
        @cores1 - vector de cores;
        @valores1 - vector de valores.
*/
Paleta::Paleta(int quantidade1, vector<Cor> cores1, vector<double> valores1)
{
    quantidade = quantidade1;
    cores = cores1;
    valores = valores1;
}

/** Consultar quanidade 
    Retorna:
        @quantidade - quantidade de cores na paleta;
*/
int Paleta::consulta_quantidade() 
{ 
    return quantidade; 
}

/** Ler arquivo
    Recebe:
        @nome_arquivo - Nome do arquivo que será lido;
    Explicação:
        Lê o conteúdo do arquivo e armazena o valores na Paleta;
        Lê a primeira linha e armazena em @quantidade;
        Lê linha a linha até o final do arquivo e armazena em @valores[l] e @cores[l].
*/
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

/** Consulta cor
    Recebe:
        @valor - Valor que será consultado na paleta;
    Retorna:
        @cor - Cor correspondente ao inicio de intervalo;
    Explicação
        Verefica em que intervalo o @valor se encontra e retorna a @cor correspondente ao incio do intervalor;
*/
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