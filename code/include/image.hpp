#pragma once

#include <string>

#include "color.hpp"



class Image
{
    private:
        int width;
        int height;
        Color** bitmap;

    public:
        Image(int width, int height); 
        ~Image();

        Color get_pixel_color(int line, int column); 

        void set_color(int line, int column, Color color); 

        void save_image(std::string file_name); 
};

