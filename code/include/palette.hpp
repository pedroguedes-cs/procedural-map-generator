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
        Palette(); 
        Palette(int quantity, std::vector<Color> colors, std::vector<double> values); 

        std::string get_name();
        int get_quantity(); 
        Color get_color(double value); 

        void load_from_file(std::string file_name); 
};