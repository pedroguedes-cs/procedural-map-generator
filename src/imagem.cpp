#include "imagem.h"
#include <string>
#include <fstream>

using namespace std;

//altura = linha
//largura = coluna

Imagem::Imagem(int largura1, int altura1)
{
    altura = altura1;
    largura = largura1;
    matriz = new Cor[altura1 * largura1];

    for(int i=0; i < altura1; i++){
        for(int j=0; j < largura1; j++){
            matriz[i * largura1 + j] = {0, 0, 0};
        }
    }
}

Cor Imagem::consulta_pixel(int largura1, int altura1)
{
    Cor resposta = matriz[altura1 * largura + largura1];
    return resposta;   
}

void Imagem::definir_cor(int largura1, int altura1, Cor cor_pixel)
{
    matriz[altura1 * largura + largura1].r = cor_pixel.r; 
    matriz[altura1 * largura + largura1].g = cor_pixel.g; 
    matriz[altura1 * largura + largura1].b = cor_pixel.b; 
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
                arquivo << matriz[i * largura + j].r << " " << matriz[i * largura + j].g << " " << matriz[i * largura + j].b << endl;
            }
        }
    }
}

void Imagem::liberar_matriz(Imagem imagem){
    delete[] imagem.matriz;
};