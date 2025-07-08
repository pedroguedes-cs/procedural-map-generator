#pragma once
#include "cor.h"

using namespace std;

class Imagem
{
    int largura;
    int altura;
    Cor *matriz = new Cor[altura * largura];

    public:
        Imagem(int largura1, int altura1); // Construtor

        Cor consulta_pixel(int largura1, int altura1); //Consulta de pixel da imagem
        void definir_cor(int largura1, int altura1, Cor cor_pixel); // Definir pixel na imagem
        void salvar_imagem(string nome_arquivo); //Salvar imagem em PPM

        void liberar_matriz(); // Liberar matriz na alocação dinamica

};

