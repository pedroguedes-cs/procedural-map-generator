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
    
    // Matriz de altitudes (3x3)
    altitudes = new double*[padrao];
    
    for(int i = 0; i < padrao; i++)
    {
        altitudes[i] = new double[padrao];
    }

    // Inicializando valores
    for (int i = 0; i < padrao; i++)
    {
        for (int j = 0; j < padrao; j++)
        {
            altitudes[i][j] = -1;
        }
    }

}


// Construtor parametrizado
Terreno::Terreno(int gerador, double rugosidade)
{
    int tamanho = pow(2, gerador) + 1;
    linhas = tamanho;
    colunas = tamanho;

    // Matriz de altitudes
    altitudes = new double*[tamanho];
    
    for(int i = 0; i < tamanho; i++)
    {
        altitudes[i] = new double[tamanho];
    }

    // Inicializando valores
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            altitudes[i][j] = -1;
        }
    }

    gerar_mapa(rugosidade);
}


//Destrutor
Terreno::~Terreno()
{
    delete[] altitudes;
}

// Diamond
void Terreno::diamond(int lado, int deslocamento, int limite)
{
    int linhas_de_quadrados = (linhas - 1) / lado;
    int colunas_de_quadrados = linhas_de_quadrados;

    // Passando por cada quadrado + executando o Diamond
    for (int i = 0; i < linhas_de_quadrados; i++)
    {
        for (int j = 0; j < colunas_de_quadrados; j++)
        {
            // Coordenadas
            Ponto ponta1 = {i * lado, j * lado};
            Ponto ponta2 = {i * lado, j * lado + lado};
            Ponto ponta3 = {i * lado + lado, j * lado};
            Ponto ponta4 = {i * lado + lado, j * lado + lado};
            Ponto centro = {i * lado + (lado / 2), j * lado + (lado / 2)};
            
            int deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
            double soma = altitudes[ponta1.linha][ponta1.coluna] + altitudes[ponta2.linha][ponta2.coluna] + altitudes[ponta3.linha][ponta3.coluna] + altitudes[ponta4.linha][ponta4.coluna];

            // Centro
            altitudes[centro.linha][centro.coluna] = abs((soma / 4) + deslocamento_aleatorio);
        }
    }
}


// Square
void Terreno::square(int lado, int deslocamento)
{
    int linhas_de_quadrados = (linhas - 1) / lado;
    int colunas_de_quadrados = linhas_de_quadrados;

    // Passando por cada quadrado + executando o Square
    for (int i = 0; i < linhas_de_quadrados; i++)
    {
        for (int j = 0; j < colunas_de_quadrados; j++)
        {
            // Coordenadas
            Ponto ponta1 = {i * lado, j * lado};
            Ponto ponta2 = {i * lado, j * lado + lado};
            Ponto ponta3 = {i * lado + lado, j * lado};
            Ponto ponta4 = {i * lado + lado, j * lado + lado};

            Ponto centro = {i * lado + (lado / 2), j * lado + (lado / 2)};
            
            Ponto norte = {i * lado, j * lado + (lado / 2)};
            Ponto sul = {i * lado + lado, j * lado + (lado / 2)};
            Ponto leste = {i * lado + (lado / 2), j * lado + lado};
            Ponto oeste = {i * lado + (lado / 2), j * lado};

            Ponto centro_norte = {centro.linha - lado, centro.coluna};
            Ponto centro_sul = {centro.linha + lado, centro.coluna};
            Ponto centro_leste = {centro.linha, centro.coluna + lado};
            Ponto centro_oeste = {centro.linha, centro.coluna - lado};


            // Norte

            int deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);
            int soma;

            if (altitudes[norte.linha][norte.coluna] < 0)
            {
                if (norte.linha == 0)
                {
                    soma = altitudes[ponta1.linha][ponta1.coluna] + altitudes[ponta2.linha][ponta2.coluna] + altitudes[centro.linha][centro.coluna];
                    altitudes[norte.linha][norte.coluna] = (soma / 3) + deslocamento_aleatorio;
                }
                else
                {
                    soma = altitudes[ponta1.linha][ponta1.coluna] + altitudes[ponta2.linha][ponta2.coluna] + altitudes[centro.linha][centro.coluna] + altitudes[centro_norte.linha][centro_norte.coluna];
                    altitudes[norte.linha][norte.coluna] = (soma / 4) + deslocamento_aleatorio;
                }
                if (altitudes[norte.linha][norte.coluna] < 0)
                {
                    altitudes[norte.linha][norte.coluna] = abs(altitudes[norte.linha][norte.coluna]);
                }
            }


            // Sul

            deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);

            if (altitudes[sul.linha][sul.coluna] < 0)
            {
                if (sul.linha == (linhas - 1))
                {
                    soma = altitudes[ponta3.linha][ponta3.coluna] + altitudes[ponta4.linha][ponta4.coluna] + altitudes[centro.linha][centro.coluna];
                    altitudes[sul.linha][sul.coluna] = (soma / 3) + deslocamento_aleatorio;
                }
                else
                {
                    soma = altitudes[ponta3.linha][ponta3.coluna] + altitudes[ponta4.linha][ponta4.coluna] + altitudes[centro.linha][centro.coluna] + altitudes[centro_sul.linha][centro_sul.coluna];
                    altitudes[sul.linha][sul.coluna] = (soma / 4) + deslocamento_aleatorio;
                }
                if (altitudes[sul.linha][sul.coluna] < 0)
                {
                    altitudes[sul.linha][sul.coluna] = abs(altitudes[sul.linha][sul.coluna]);
                }
            }
            

            // Leste

            deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);

            if (altitudes[leste.linha][leste.coluna] < 0)
            {
                if (leste.coluna == (colunas - 1))
                {
                    soma = altitudes[ponta2.linha][ponta2.coluna] + altitudes[ponta4.linha][ponta4.coluna] + altitudes[centro.linha][centro.coluna];
                    altitudes[leste.linha][leste.coluna] = (soma / 3) + deslocamento_aleatorio;
                }
                else
                {
                    soma = altitudes[ponta2.linha][ponta2.coluna] + altitudes[ponta4.linha][ponta4.coluna] + altitudes[centro.linha][centro.coluna] + altitudes[centro_leste.linha][centro_leste.coluna];
                    altitudes[leste.linha][leste.coluna] = (soma / 4) + deslocamento_aleatorio;
                }
                if (altitudes[leste.linha][leste.coluna] < 0)
                {
                    altitudes[leste.linha][leste.coluna] = abs(altitudes[leste.linha][leste.coluna]);
                }
            }


            // Oeste

            deslocamento_aleatorio = random((-1 * deslocamento), deslocamento);

            if (altitudes[oeste.linha][oeste.coluna] < 0)
            {
                if (oeste.coluna == 0)
                {
                    soma = altitudes[ponta1.linha][ponta1.coluna] + altitudes[ponta3.linha][ponta3.coluna] + altitudes[centro.linha][centro.coluna];
                    altitudes[oeste.linha][oeste.coluna] = (soma / 3) + deslocamento_aleatorio;
                }
                else
                {
                    soma = altitudes[ponta1.linha][ponta1.coluna] + altitudes[ponta3.linha][ponta3.coluna] + altitudes[centro.linha][centro.coluna] + altitudes[centro_oeste.linha][centro_oeste.coluna];
                    altitudes[oeste.linha][oeste.coluna] = (soma / 4) + deslocamento_aleatorio;
                }
                if (altitudes[oeste.linha][oeste.coluna] < 0)
                {
                    altitudes[oeste.linha][oeste.coluna] = abs(altitudes[oeste.linha][oeste.coluna]);
                }
            }


        }
    }


}

// Diamond-Square
void Terreno::gerar_mapa(double rugosidade)
{
    int deslocamento = 10;
    int lado = linhas - 1;

    // Pontas iniciais
    int limite = 21;
    altitudes[0][0] = random(0, limite);
    altitudes[0][lado] = random(0, limite);
    altitudes[lado][0] = random(0, limite);
    altitudes[lado][lado] = random(0, limite);



    while(lado > 1)
    {
        diamond(lado, deslocamento, limite);
        square(lado, deslocamento);

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
    return altitudes[linha1][coluna1];
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

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            arquivo << altitudes[i][j] << " ";
        }
        arquivo << endl;
    }
}

//Ler um arquivo e retornar um terreno
void Terreno::ler_terreno(string nome_arquivo)
{
    ifstream arquivo(nome_arquivo);

    if (arquivo.is_open() == false)
    {
        return;
    }
    else
    {
        // Liberando memória
        for (int i = 0; i < linhas; i++)
        {
            delete[] altitudes[i];
        }
        delete[] altitudes;

        // Leitura medidas
        arquivo >> linhas >> colunas;
        altitudes = new double*[linhas];

        // Alocando matriz
        for (int i = 0; i < linhas; i++)
        {
            altitudes[i] = new double[colunas];
        }

        // Leitura altitudes
        double valor;
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                arquivo >> valor;
                altitudes[i][j] = valor;
            }
        }
    }
}


// Função que gera números aleatórios
int random(int inicio_intervalo, int fim_intervalo)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(inicio_intervalo, fim_intervalo);
    return distrib(gen);
    return distrib(gen);
}
