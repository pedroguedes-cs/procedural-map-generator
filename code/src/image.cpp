#include <string>
#include <fstream>

#include "../include/image.hpp"


// Constructor and destructor
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

Image::~Image()
{
    for (int i = 0; i < width; i++)
    {
        delete[] bitmap[i];
    }
    delete[] bitmap;
}

// Getter
Color Image::get_pixel_color(int line, int column)
{
    Color color = bitmap[line][column];
    return color;   
}

// Setter
void Image::set_color(int line, int column, Color color)
{
    bitmap[line][column].r = color.r; 
    bitmap[line][column].g = color.g; 
    bitmap[line][column].b = color.b; 
}

// Save
void Image::save_image(std::string file_name)
{
    std::ofstream file(file_name, std::ios::out | std::ios::trunc);

    if (file.is_open() == false)
    {
        return;
    }
    else
    {
        // Metadados
        file << "P3" << std::endl;
        file << width << " " << height << std::endl;
        file << "255" << std::endl;

        // bitmap
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                file << bitmap[i][j].r << " " << bitmap[i][j].g << " " << bitmap[i][j].b << std::endl;
            }
        }
    }
}
