#include "../include/image.hpp"
#include <string>
#include <fstream>

using namespace std;


/** Construtor parametrizado
    Recebe:
        @altura1  - coordenada Y do pixel;
        @largura1 - coordenada X do pixel.
*/
Image::Image(int height, int width)
{
    this->height = height;
    this->width = width;
    bitmap = new Color*[height];

    for (int i = 0; i < height; i++)
    {
        bitmap[i] = new Color[width];
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bitmap[i][j] = {0, 0, 0};
        }
    }
}

/** Destrutor
    Explicação:
        Como adotamos o formato ponteiro de ponteiros, precisamos deletar  cada "ponteiro-elemento"
*/
Image::~Image()
{
    for (int i = 0; i < width; i++)
    {
        delete[] bitmap[i];
    }
    delete[] bitmap;
}

/** Retorna a cor de um pixel específico
    Recebe:
        @line  - coordenada Y do pixel;
        @column - coordenada X do pixel;
    Retorna:
        @cor - cor do pixel nas coordenadas.
*/
Color Image::get_pixel_color(int line, int column)
{
    Color color = bitmap[line][column];
    return color;   
}


/** Altera a cor de um pixel específico
    Recebe:
        @line  - coordenada Y do pixel
        @column - coordenada X do pixel
        @cor_pixel - cor a ser aplicada
*/
void Image::set_color(int line, int column, Color color)
{
    bitmap[line][column].r = color.r; 
    bitmap[line][column].g = color.g; 
    bitmap[line][column].b = color.b; 
}


/** Salva uma Image em um file 'ppm'
    Recebe:
        @nome_file - nome do file que receberá a Image
*/
void Image::save_image(string file_name)
{
    ofstream file(file_name, ios::out | ios::trunc);

    if (file.is_open() == false)
    {
        return;
    }
    else
    {
        // Metadados
        file << "P3" << endl;
        file << width << " " << height << endl;
        file << "255" << endl;

        // bitmap
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                file << bitmap[i][j].r << " " << bitmap[i][j].g << " " << bitmap[i][j].b << endl;
            }
        }
    }
}
