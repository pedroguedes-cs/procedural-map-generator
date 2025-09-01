#include "../include/palette.hpp"
#include <fstream>

using namespace std;


Palette::Palette()
{
    quantity = 0;
    colors = {};
    values = {};
}

Palette::Palette(int quantity, vector<Color> colors, vector<double> values)
{
    this->quantity = quantity;
    this->colors = colors;
    this->values = values;
}

int Palette::get_quantity() 
{ 
    return quantity; 
}

Color Palette::get_color(double value)
{
    // Verificação (valor mínimo)
    if (values[0] > value)
    {
        return colors[0];
    }

    // Caso normal
    for (int i = 0; i < quantity; i++)
    {
        if (values[i] > value)
        {
            return colors[i - 1];
        }
    }

    // Valor máximo
    return colors[quantity - 1];
}

void Palette::load_from_file(string file_name)
{
    ifstream file(file_name);

    // Limpar valores anteriores
    name = ".";
    quantity = 0;
    colors.clear();
    values.clear();


    if (file.is_open() == false)
    {
        return;
    }
    else
    {
        file >> name;
        file >> quantity;

        double color_value;
        int r, g, b;

        while (file >> color_value >> r >> g >> b)
        {
            values.push_back(color_value);
            colors.push_back({r, g, b});
        }
    }
}

