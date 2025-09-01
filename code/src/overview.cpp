#include <iostream>

#include "../include/overview.hpp"

void print_overview(Map& map, Palette& palette)
{
    std::cout << "Lines = " << map.get_lines() << std::endl;
    std::cout << "Columns = " << map.get_columns() << std::endl;
    std::cout << "Roughness factor = " << map.get_roughness_factor() << std::endl;
    std::cout << "Shade factor = " << map.get_shade_factor() << std::endl;
    std::cout << "\nPalette = " << map.get_columns() << std::endl;
}