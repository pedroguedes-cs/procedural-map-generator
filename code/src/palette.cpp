#include "../include/palette.hpp"
#include <fstream>

using namespace std;

/** Construtor padrão:
    Inicializa os elementos da Palette da seguinte:
        quantidade = 0;
        todas as cores do vector cores = 0;
        todos os valores do vector valores = 0.

*/
Palette::Palette()
{
    quantity = 0;
    colors = {};
    values = {};
}

/** Construtor parametrizado. 
    Recebe: 
        @quantidade1 - Quantidade de cores na Palette;  
        @cores1 - vector de cores;
        @valores1 - vector de valores.
*/
Palette::Palette(int quantity, vector<Color> colors, vector<double> values)
{
    this->quantity = quantity;
    this->colors = colors;
    this->values = values;
}

/** Consultar quanidade 
    Retorna:
        @quantidade - quantidade de cores na Palette;
*/
int Palette::get_colors_quantity() 
{ 
    return quantity; 
}

/** Ler arquivo
    Recebe:
        @nome_arquivo - Nome do arquivo que será lido;
    Explicação:
        Lê o conteúdo do arquivo e armazena o valores na Palette;
        Lê a primeira linha e armazena em @quantidade;
        Lê linha a linha até o final do arquivo e armazena em @valores[l] e @cores[l].
*/
void Palette::read_file(string file_name)
{
    ifstream file(file_name);

    // Limpar valores anteriores
    quantity = 0;
    colors.clear();
    values.clear();


    if (file.is_open() == false)
    {
        return;
    }
    else
    {
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

/** Consulta cor
    Recebe:
        @valor - Valor que será consultado na Palette;
    Retorna:
        @cor - Cor correspondente ao inicio de intervalo;
    Explicação
        Verefica em que intervalo o @valor se encontra e retorna a @cor correspondente ao incio do intervalor;
*/
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