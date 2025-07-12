#include <iostream>
#include <string>
#include <cmath>
#include "../include/imagem.h"
#include "../include/paleta.h"
#include "../include/terreno.h"

using namespace std;

int main()
{  
    string nome_arquivo_paleta, nome_arquivo_imagem;
    int gerador;

    cin >> nome_arquivo_paleta >> nome_arquivo_imagem >> gerador;

    Terreno teste(gerador, 0.9);
    Paleta paleta;

    paleta.ler_arquivo(nome_arquivo_paleta);

    teste.cria_imagem(paleta).salvar_imagem(nome_arquivo_imagem);

}