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
    private:
        int lines;
        int columns;
        double **heights;
        Effects effects;
        int valid_size;

        void diamond(int square_side_length, int displacement); 
        void square(int square_side_length, int displacement); 
        
    public:
        Map(); 
        Map(int lines, int columns, Effects effects); 
        ~Map();

        int get_lines();
        int get_columns(); 
        double get_pixel_height(int line, int column); 

        void generate_map_terrain(); 
        void save_map(std::string file_name); 
        void read_map(std::string file_name);
        
        Image generate_image(Palette palette);
};

