#pragma once

#include <vector>
#include <string>

#include "color.hpp"


class Palette
{
    //Atributos
    private:
        std::string name;
        int quantity;
        std::vector<Color> colors;
        std::vector<double> values;

    //Operações
    public:
        Palette(); /** Construtor padrão */
        Palette(int quantity, std::vector<Color> colors, std::vector<double> values); /** Construtor parametrizado */

        int get_quantity(); /** Consulta a quantidade de Colores na pelata */
        Color get_color(double value); /** Recebe um valor e retorna a Color Colorespondente ao intevalo do valor */

        void load_from_file(std::string file_name); /** Ler um arquivo de nome @nome_arquivo */
};