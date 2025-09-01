#include <iostream>
#include "../include/style.hpp"

void title(std::string title)
{
    std::cout << "\n\n---------------------------------------------------------------------------\n";
    std::cout << title << std::endl;
    std::cout << "---------------------------------------------------------------------------\n\n\n";
}

void subtitle(std::string subtitle)
{
    std::cout << subtitle << "\n\n";
}

void print_line()
{
    std::cout << "\n\n---------------------------------------------------------------------------\n\n\n";
}