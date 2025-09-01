#pragma once

#include <string>

#include "image.hpp"
#include "palette.hpp"



struct Effects
{
    double shade_factor;
    double roughness_factor;
};


class Map
{
    int lines;
    int columns;
    double **heights;
    Effects effects;

    void diamond(int side_length, int displacement); /** Etapa Diamond */
    void square(int side_length, int displacement); /** Etapa Square */
    
    public:
        Map(); /** Construtor default, Matriz tem tamanho (2^gerador) + 1 */
        Map(int generator, double roughness); /**Construtor parametrizado */
        ~Map(); /** Destrutor */


        void generate_map(double roughness); /**Gerar mapa de altitudes */

        int get_lines(); /** Consultar numero de linhas */
        int get_columns(); /** Consultar numero de colunas */
        double get_height(int line, int column); /** Consultar altitude */

        void save_map(std::string file_name); /** Salvar dimensões e altitudes em um arquivo */
        void read_map(std::string file_name); /** Se houver matriz alocada, desalocar a matriz e alocar outra com as informações do arquivo */  
        
        Image create_image(Palette palette) /** Gera uma imagem a partir de um terreno */;
};

int random(int begin_range, int end_range); /** Gera um numero aleatório */
