#pragma once
#include <string>

using namespace std;

class Terreno
{
    int linhas;
    int colunas;
    double **altitudes;

    //Falta definir Diamond e Square
    
    public:
        Terreno(); // Construtor default, Matriz tem tamanho (2^gerador) + 1
        Terreno(int gerador, double rugosidade); //Construtor parametrizado
        ~Terreno(); // Destrutor

        void gerar_mapa(double rugosidade); //Gerar mapa de altitudes
        void diamond(int lado, int deslocamento, int limite); // Etapa Diamond
        void square(int lado, int deslocamento); // Etapa Square

        int consulta_linhas(); // Consultar numero de linhas
        int consulta_colunas(); // consultar numero de colunas
        double consulta_altitude(int linha1, int coluna1); //Consultar altitude

        void salvar_terreno(string nome_arquivo); //Salvar dimensões e altitudes em um arquivo
        void ler_terreno(string nome_arquivo); //Se houver matriz alocada, desalocar a matriz e alocar outra com as informações do arquivo    

};

int random(int inicio_intervalo, int fim_intervalo);

struct Ponto
{
    int linha;
    int coluna;
};