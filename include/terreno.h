#pragma once
#include "../include/imagem.h"
#include "../include/paleta.h"
#include <string>

using namespace std;

class Terreno
{
    int linhas;
    int colunas;
    double **altitudes;

    void diamond(int lado, int deslocamento); /** Etapa Diamond */
    void square(int lado, int deslocamento); /** Etapa Square */
    int random(int inicio_intervalo, int fim_intervalo); /** Gera um numero aleatório */
    
    public:
        Terreno(); /** Construtor default, Matriz tem tamanho (2^gerador) + 1 */
        Terreno(int gerador, double rugosidade); /**Construtor parametrizado */
        ~Terreno(); /** Destrutor */


        void gerar_mapa(double rugosidade); /**Gerar mapa de altitudes */

        int consulta_linhas(); /** Consultar numero de linhas */
        int consulta_colunas(); /** Consultar numero de colunas */
        double consulta_altitude(int linha1, int coluna1); /** Consultar altitude */

        void salvar_terreno(string nome_arquivo); /** Salvar dimensões e altitudes em um arquivo */
        void ler_terreno(string nome_arquivo); /** Se houver matriz alocada, desalocar a matriz e alocar outra com as informações do arquivo */  
        
        Imagem cria_imagem(Paleta paleta) /** Gera uma imagem a partir de um terreno */;
};
