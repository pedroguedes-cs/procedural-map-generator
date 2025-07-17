#pragma once
#include "cor.h"
#include <string>

using namespace std;

class Imagem
{
    int largura;
    int altura;
    Cor **matriz;

    public:
        Imagem(int largura1, int altura1); // Construtor
        ~Imagem(); //Destrutor

        Cor consulta_pixel(int linha, int coluna); //Consulta de pixel da imagem
        void definir_cor(int linha, int coluna, Cor cor_pixel); // Definir pixel na imagem
        void salvar_imagem(string nome_arquivo); //Salvar imagem em PPM
};

