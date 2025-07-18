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
    
    cout << "Informe o nome do arquivo que contem a paleta de cores: ";
    cin >> nome_arquivo_paleta;
    
    cout << "Informe o valor para gerar a imagem: ";
    cin >> gerador;
    
    cout << "Informe o nome do arquivo onde a imagem será salva: ";
    cin >> nome_arquivo_imagem;

    Terreno teste(gerador, 0.9);
    Paleta paleta;

    paleta.ler_arquivo(nome_arquivo_paleta);

    teste.cria_imagem(paleta).salvar_imagem(nome_arquivo_imagem);

}