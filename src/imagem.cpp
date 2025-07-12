#include "../include/imagem.h"
#include <string>
#include <fstream>

using namespace std;

//altura = linha
//largura = coluna

Imagem::Imagem(int altura1, int largura1)
{
    altura = altura1;
    largura = largura1;
    matriz = new Cor*[altura1];

    for (int i = 0; i < altura1; i++)
    {
        matriz[i] = new Cor[largura1];
    }

    for (int i = 0; i < altura1; i++)
    {
        for (int j = 0; j < largura1; j++)
        {
            matriz[i][j] = {0, 0, 0};
        }
    }
}

Cor Imagem::consulta_pixel(int linha, int coluna)
{
    Cor resposta = matriz[linha][coluna];
    return resposta;   
}

void Imagem::definir_cor(int linha, int coluna, Cor cor_pixel)
{
    matriz[linha][coluna].r = cor_pixel.r; 
    matriz[linha][coluna].g = cor_pixel.g; 
    matriz[linha][coluna].b = cor_pixel.b; 
}

void Imagem::salvar_imagem(string nome_arquivo)
{
    ofstream arquivo(nome_arquivo, ios::out | ios::trunc);

    if (arquivo.is_open() == false)
    {
        return;
    }
    else
    {
        // Metadados
        arquivo << "P3" << endl;
        arquivo << largura << " " << altura << endl;
        arquivo << "255" << endl;

        // Matriz
        for (int i = 0; i < altura; i++)
        {
            for (int j = 0; j < largura; j++)
            {
                arquivo << matriz[i][j].r << " " << matriz[i][j].g << " " << matriz[i][j].b << endl;
            }
        }
    }
}

Imagem::~Imagem()
{
    for (int i = 0; i < largura; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}