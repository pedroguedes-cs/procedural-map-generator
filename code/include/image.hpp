#pragma once

#include <string>

#include "color.hpp"



class Image
{
    int width;
    int height;
    Color** bitmap;

    public:
        Image(int width, int height); // Construtor
        ~Image(); //Destrutor

        Color get_pixel_color(int line, int column); //Consulta de pixel da Image

        void set_color(int line, int column, Color color); // Definir pixel na Image

        void save_image(std::string file_name); //Salvar Image em PPM
};

