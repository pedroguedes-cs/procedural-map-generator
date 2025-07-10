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

    altitudes = new int[linhas * colunas];
    for (int i = 0; i < (linhas * colunas); i++)
    {
        altitudes[i] = 0;
    }
}

//Destrutor
Terreno::~Terreno()
{

}

//Gerar mapa
void Terreno::gerar_mapa(double rugosidade)
{
    int lado = linhas;

    // Pontas
    altitudes[0 * lado + 0] = 
    altitudes[0 * lado + lado] = 
    altitudes[lado * lado + 0] = 
    altitudes[lado * lado + lado] = 
    

    // Loop (Diamond-Square)
    while (lado > 1)
    {

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

