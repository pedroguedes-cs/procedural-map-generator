#include "terreno.h"
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


//Construtor padrão
Terreno::Terreno(int gerador)
{
    int tamanho = (pow(2, gerador) + 1);
    linhas = tamanho;
    colunas = tamanho;

    altitudes = new double[linhas * colunas];
    for (int i = 0; i < (linhas * colunas); i++)
    {
        altitudes[i] = -1;
    }
}

//Destrutor
Terreno::~Terreno()
{

}

//Gerar mapa
void Terreno::gerar_mapa(double rugosidade)
{
    // Pontas
    srand(time(0));
    int limite = 21;

    altitudes[0 * linhas + 0] = (rand() % limite);
    altitudes[0 * linhas + (colunas - 1)] = (rand() % limite);
    altitudes[(linhas - 1) * colunas + 0] = (rand() % limite);
    altitudes[linhas * (colunas - 1) + (colunas - 1)] = (rand() % limite);
    

    // Loop (Diamond-Square)
    int lado = (linhas - 1);
    float fator = rugosidade;

    while (lado > 1)
    {
        int quadrados_por_linha = sqrt(((linhas - 1) * (colunas - 1)) / (lado * lado));

        for (int i = 0; i < quadrados_por_linha; i++)
        {
            for (int j = 0; j < quadrados_por_linha; j++)
            {
                // (1) Pontas
                int p1 = (i * lado) + (j * lado);
                int p2 = (i * lado) + ((j + 1) * lado);
                int p3 = ((i + 1) * lado) + (j * lado);
                int p4 = ((i + 1) * lado) + ((j + 1) * lado);
                int centro = (i * lado) + (j * lado) + (colunas * lado / 2) + (lado / 2);


                if (altitudes[p1] < 0)
                {
                    altitudes[p1] = 
                }
                if (altitudes[p2] < 0)
                {
                    altitudes[p2] = 
                }
                if (altitudes[p3] < 0)
                {
                    altitudes[p3] = 
                }
                if (altitudes[p4] < 0)
                {
                    altitudes[p4] = 
                }
                

                // (2) Diamond
                double media = (altitudes[p1] + altitudes[p2] + altitudes[p3] + altitudes[p4]) / 4;
                double deslocamento = ;
                altitudes[centro] = media + deslocamento;


                // (3) Square
            }
        }

        // (4) Atualização
        lado = lado / 2;
        fator = fator * 0.5;
}
}

//Consultar linhas
int Terreno::consulta_linhas()
{

}

//Consultar colunas
int Terreno::consulta_colunas()
{

}

//Consultar altitude
int Terreno::consulta_altitude(int linha1, int coluna1)
{

}

//Salvar terreno em um arquivo
void Terreno::salvar_terreno(string nome_arquivo)
{

}

//Ler um arquivo e retornar um terreno
Terreno Terreno::ler_terreno(string nome_arquivo)
{

}

