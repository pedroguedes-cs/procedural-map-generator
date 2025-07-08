#include "imagem.h"

using namespace std;

Imagem::Imagem(int largura1, int altura1)
{
    for(int i=0; i < altura1; ++i){
        for(int j=0; j < largura1; ++j){
            matriz[i * largura1 + j] = {0, 0, 0};
        }
    }
}

Cor Imagem::consulta_pixel(int largura1, int altura1)
{
    Cor resposta;
    
}

void Imagem::definir_cor(int largura1, int altura1, Cor cor_pixel)
{
    matriz[altura1 * largura + largura1].r = cor_pixel.r; 
    matriz[altura1 * largura + largura1].g = cor_pixel.g; 
    matriz[altura1 * largura + largura1].b = cor_pixel.b; 
}

void salvar_imagem();

void liberar_matriz();