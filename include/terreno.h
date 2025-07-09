#pragma once
#include <string>

using namespace std;

class Terreno
{
    int linhas;
    int colunas;
    int *altitudes;

    //Falta definir Diamond e Square
    
    public:
        Terreno(int gerador); // Construtor default, Matriz tem tamanho (2^gerador) + 1
        ~Terreno(); // Destrutor

        void gerar_mapa(int gerador, double rugosidade); //Gerar mapa de altitudes

        int consulta_linhas(); // Consultar numero de linhas
        int consulta_colunas(); // consultar numero de colunas
        int consulta_altitude(int linha1, int coluna1); //Consultar altitude

        void salvar_terreno(string nome_arquivo); //Salvar dimensões e altitudes em um arquivo
        Terreno ler_terreno(string nome_arquivo); //Se houver matriz alocada, desalocar a matriz e alocar outra com as informações do arquivo    

};