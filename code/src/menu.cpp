#include <iostream>
#include "../include/menu.hpp"
#include "../include/style.hpp"

void print_menu()
{
    subtitle("MENU:");
    std::cout << "[1] Set map\n";
    std::cout << "[2] Set palette\n";
    std::cout << "[3] Map overview\n";
    std::cout << "[4] Generate map\n";
    std::cout << "[5] Exit\n";
}