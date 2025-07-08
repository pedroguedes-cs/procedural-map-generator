#include "imagem.h"

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

/*void Imagem::definir_cor(int largura1, int altura1, Cor cor_pixel)
{
    *(matriz + (altura1 * largura) + largura1)
}*/

void salvar_imagem();

void Imagem::liberar_matriz(Imagem imagem){
    delete[] imagem.matriz;
};