#include "../include/terreno.h"
#include <string>
#include <fstream>
#include <cmath>
#include <random>
using namespace std;


//Construtor padrão
Terreno::Terreno()
{
    int padrao = 3;

    linhas = padrao;
    colunas = padrao;
    altitudes = new double[padrao * padrao];

    for(int i = 0; i < (padrao * padrao); i++)
    {
        altitudes[i] = -1;
    }

}


// Construtor parametrizado
Terreno::Terreno(int gerador, double rugosidade){
    int tamanho = pow(2, gerador) + 1;
    linhas = tamanho;
    colunas = tamanho;
    altitudes = new double[tamanho * tamanho];

    for(int i=0; i < tamanho; i++)
    {
        altitudes[i] = -1;
    }

    gerar_mapa(rugosidade);
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
    altitudes[(linhas - 1) * colunas + (colunas - 1)] = random(0, limite);
    

    // Loop (Diamond-Square)
    int lado = (linhas - 1);
    double deslocamento = 10;

    while (lado > 1)
    {
        int quadrados_por_linha = (linhas - 1) / lado;
        int quadrados_por_coluna = quadrados_por_linha;

        // Loop (Diamond)
        for (int i = 0; i < quadrados_por_coluna; i++)
        {
            for (int j = 0; j < quadrados_por_linha; j++)
            {
                // Pontas
                int p1 = (i * lado) + (j * lado);
                int p2 = (i * lado) + (j * lado) + lado;
                int p3 = (i * lado) + (j * lado) + (lado * colunas);
                int p4 = (i * lado) + (j * lado) + lado + (lado * colunas);
                int centro = (i * lado) + (j * lado) + (lado / 2 * colunas) + (lado / 2);


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
                
                double media = (altitudes[p1] + altitudes[p2] + altitudes[p3] + altitudes[p4]) / 4;
                double deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
                altitudes[centro] = media + deslocamento_aleatorio;
            }
        }

        // Loop (Square)
        for (int i = 0; i < quadrados_por_coluna; i++)
        {
            for (int j = 0; j < quadrados_por_linha; j++)
            {
                // Pontas
                int p1 = (i * lado) + (j * lado);
                int p2 = (i * lado) + (j * lado) + lado;
                int p3 = (i * lado) + (j * lado) + (lado * colunas);
                int p4 = (i * lado) + (j * lado) + lado + (lado * colunas);
                int centro = (i * lado) + (j * lado) + (lado / 2 * colunas) + (lado / 2);

                // Pontos intermediários
                int p_cima = centro - (lado / 2 * colunas);
                int p_baixo = centro + (lado / 2 * colunas);
                int p_direita = centro + (lado / 2);
                int p_esquerda = centro - (lado / 2);

                // Cima
                double deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
                if (p_cima < colunas)
                {
                    altitudes[p_cima] = ((altitudes[p1] + altitudes[p2] + altitudes[centro]) / 3) + deslocamento_aleatorio;
                }
                else
                {
                    altitudes[p_cima] = ((altitudes[p1] + altitudes[p2] + altitudes[centro] + altitudes[centro - (lado * colunas)]) / 4) + deslocamento_aleatorio;
                }

                // Baixo
                deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
                if (p_baixo > (linhas - 1) * colunas)
                {
                    altitudes[p_baixo] = ((altitudes[p3] + altitudes[p4] + altitudes[centro]) / 3) + deslocamento_aleatorio;
                }
                else
                {
                    altitudes[p_baixo] = ((altitudes[p3] + altitudes[p4] + altitudes[centro] + altitudes[centro + (lado * colunas)]) / 4) + deslocamento_aleatorio;
                }

                // Direita
                deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
                if (p_direita % colunas == colunas - 1)
                {
                    altitudes[p_direita] = ((altitudes[p2] + altitudes[p4] + altitudes[centro]) / 3) + deslocamento_aleatorio;
                }
                else
                {
                     altitudes[p_direita] = ((altitudes[p2] + altitudes[p4] + altitudes[centro] + altitudes[centro + lado]) / 4) + deslocamento_aleatorio;
                }

                // Esquerda
                deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
                if (p_esquerda % colunas == 0)
                {
                    altitudes[p_esquerda] = ((altitudes[p1] + altitudes[p3] + altitudes[centro]) / 3) + deslocamento_aleatorio;
                }
                else
                {
                    altitudes[p_esquerda] = ((altitudes[p1] + altitudes[p3] + altitudes[centro] + altitudes[centro - lado]) / 4) + deslocamento_aleatorio;
                }

            }
        }

        // Atualização 
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
double Terreno::consulta_altitude(int linha1, int coluna1)
{
    return altitudes[linha1 * colunas + coluna1];
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
// Terreno Terreno::ler_terreno(string nome_arquivo)
// {

// }

