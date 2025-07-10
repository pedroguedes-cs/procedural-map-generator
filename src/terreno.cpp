#include "terreno.h"
#include <string>
#include <fstream>
#include <cmath>
#include <random>
using namespace std;


//Construtor padrão
Terreno::Terreno(int gerador)
{
    int tamanho = pow(2, gerador) + 1;
    linhas = tamanho;
    colunas = tamanho;
    altitudes = new double[linhas * colunas];
    for (int i = 0; i < (linhas * colunas); i++)
    {
        altitudes[i] = -1;
    }
}

Terreno::Terreno(int gerador, double rugosidade){
    int tamanho = pow(2, gerador) + 1;
    linhas = tamanho;
    colunas = tamanho;
    altitudes = new int[tamanho * tamanho];

    for(int i=0; i < tamanho; i++){
        altitudes[i] = 0;
    }

    gerar_mapa(gerador, rugosidade);

}


//Destrutor
Terreno::~Terreno()
{
    delete[] altitudes;
}

// Função que gera números aleatórios
double random(double inicio_intervalo, double fim_intervalo)
{
    static random_device rd;     
    static mt19937 gen(rd());      
    uniform_real_distribution<double> distrib(inicio_intervalo, fim_intervalo);
    return distrib(gen);
}

//Gerar mapa
void Terreno::gerar_mapa(double rugosidade)
{
    // Pontas
    int limite = 21;

    altitudes[0 * linhas + 0] = random(0, limite);
    altitudes[0 * linhas + (colunas - 1)] = random(0, limite);
    altitudes[(linhas - 1) * colunas + 0] = random(0, limite);
    altitudes[linhas * (colunas - 1) + (colunas - 1)] = random(0, limite);
    

    // Loop (Diamond-Square)
    int lado = (linhas - 1);
    double deslocamento = 10;

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
                    altitudes[p1] = random(0, limite);
                }
                if (altitudes[p2] < 0)
                {
                    altitudes[p2] = random(0, limite);
                }
                if (altitudes[p3] < 0)
                {
                    altitudes[p3] = random(0, limite);
                }
                if (altitudes[p4] < 0)
                {
                    altitudes[p4] = random(0, limite);
                }
                

                // (2) Diamond
                double media = (altitudes[p1] + altitudes[p2] + altitudes[p3] + altitudes[p4]) / 4;
                double deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
                altitudes[centro] = media + deslocamento_aleatorio;


                // (3) Square
            }
        }

        // (4) Atualização
        lado = lado / 2;
        deslocamento = deslocamento * rugosidade;
    }
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

