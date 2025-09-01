#include <iostream>
#include "../include/menu.hpp"
#include "../include/style.hpp"

void print_menu()
{
    subtitle("MENU:");
    std::cout << "[1] Set map\n";
    std::cout << "[2] Set palette\n";
    std::cout << "[3] Map overview\n";
    std::cout << "[4] Generate map terrain\n";
    std::cout << "[5] Generate image\n";
    std::cout << "[6] Exit\n";
}

void print_palette_menu()
{
    subtitle("PALETTES:");
    std::cout << "[1] Earthy\n";
    std::cout << "[2] Hot\n";
    std::cout << "[3] Cold\n";
    std::cout << "[4] Grey\n";
    std::cout << "[5] Neon\n";
    std::cout << "[6] Pastel\n";
}