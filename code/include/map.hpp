#pragma once

#include <string>

#include "image.hpp"
#include "palette.hpp"


class Map
{
    private:
        int lines;
        int columns;
        double roughness_factor;
        double shade_factor;
        int valid_size;
        double **heights;
        bool active = false;
        bool terrain_generated = false;

        void diamond(int square_side_length, int displacement); 
        void square(int square_side_length, int displacement); 
        
    public:
        Map(); 
        Map(int lines, int columns, double roughness, double shade); 
        ~Map();

        void free_map();
        void alocate_map();
        void clear();

        int get_lines();
        int get_columns(); 
        double get_roughness_factor();
        double get_shade_factor();
        bool get_active();
        bool get_terrain_generated();
        double get_pixel_height(int line, int column); 

        void set_lines(int lines);
        void set_columns(int columns);
        void set_roughness_factor(double roughness);
        void set_shade_factor(double shade);
        void set_active(bool status);
        void set_terrain_generated(bool status);
        void set_valid_size(int lines, int columns);

        void generate_map_terrain(); 
        void save_map(std::string file_name); 
        void read_map(std::string file_name);
        
        Image generate_image(Palette palette);
};

