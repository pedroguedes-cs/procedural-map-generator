#include "terreno.h"
#include <string>
#include <fstream>
#include <cmath>
using namespace std;


//Construtor padrão
Terreno::Terreno(int gerador)
{   
    int tamanho = pow(2, gerador) + 1;
    linhas = tamanho;
    colunas = tamanho;
    altitudes = new int[tamanho * tamanho];

    for(int i=0; i < tamanho; i++){
        altitudes[i] = 0;
    }

}

//Destrutor
Terreno::~Terreno()
{
    delete[] altitudes;
}

//Gerar mapa
void Terreno::gerar_mapa(int gerador, double rugosidade)
{

}

//Consultar linhas
int Terreno::consulta_linhas()
{
    return linhas;
}

//Consultar colunas
int Terreno::consulta_colunas()
{
    return colunas;
}

//Consultar altitude
int Terreno::consulta_altitude(int linha1, int coluna1)
{
    return altitudes[linhas * colunas + coluna1];
}

//Salvar terreno em um arquivo
void Terreno::salvar_terreno(string nome_arquivo)
{
    ofstream arquivo(nome_arquivo, ios::out | ios::trunc);

    if(arquivo.is_open() == false)
    {
        return;
    }
    else
    {
        arquivo << linhas << " " << colunas << endl;
    }

    for(int i=0; i < linhas; i++)
    {
        for(int j=0; j < colunas; j++)
        {
            arquivo << altitudes[i * colunas + j] << " ";
        }
        arquivo << endl;
    }
}

//Ler um arquivo e retornar um terreno
Terreno Terreno::ler_terreno(string nome_arquivo)
{

}

