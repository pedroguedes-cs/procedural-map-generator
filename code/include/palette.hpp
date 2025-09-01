#pragma once
#include <vector>
#include <string>
#include "color.hpp"

using namespace std;

class Palette
{
    //Atributos
    private:
        int quantity;
        vector<Color> colors;
        vector<double> values;

    //Operações
    public:
        Palette(); /** Construtor padrão */
        Palette(int quantity, vector<Color> colors, vector<double> values); /** Construtor parametrizado */

        int get_colors_quantity(); /** Consulta a quantidade de Colores na pelata */
        Color get_color(double value); /** Recebe um valor e retorna a Color Colorespondente ao intevalo do valor */

        void read_file(string file_name); /** Ler um arquivo de nome @nome_arquivo */
};