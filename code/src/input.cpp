#include <iostream>
#include <limits>

#include "../include/input.hpp"

int read_choice()
{
    int choice;

    while (true)
    {
        std::cout << "\nEnter your choice (1-6): ";

        if (std::cin >> choice && choice >= 1 && choice <= 6)
        {
            return choice;
        }
    
        std::cin.clear(); // Clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "[Invalid input] Please enter a number between 1 and 6.\n";
    }
}

int read_width()
{
    int width;

    while (true)
    {
        std::cout << "Width: ";

        if (std::cin >> width && width >= 1)
        {
            return width;
        }
    
        std::cin.clear(); // Clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "[Invalid input] Please enter a positive integer value.\n";
    }
}

int read_height()
{
    int height;

    while (true)
    {
        std::cout << "Height: ";

        if (std::cin >> height && height >= 1)
        {
            return height;
        }
    
        std::cin.clear(); // Clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "[Invalid input] Please enter a positive integer value.\n";
    }
}

float read_shade()
{
    float shade;

    while (true)
    {
        std::cout << "Shade factor: ";

        if (std::cin >> shade && shade >= 0 && shade <= 1)
        {
            return shade;
        }
    
        std::cin.clear(); // Clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "[Invalid input] Please enter a decimal floating-point number between 0 and 1.\n";
    }
}

float read_roughness()
{
    float roughness;

    while (true)
    {
        std::cout << "Roughness factor: ";

        if (std::cin >> roughness && roughness >= 0 && roughness <= 1)
        {
            return roughness;
        }
    
        std::cin.clear(); // Clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "[Invalid input] Please enter a decimal floating-point number between 0 and 1.\n";
    }
}

Map read_map()
{
    read_width();
    read_height();
    read_roughness();
    read_shade();
}

int read_palette_choice()
{
    int choice;

    while (true)
    {
        std::cout << "\nEnter your choice (1-6): ";

        if (std::cin >> choice && choice >= 1 && choice <= 6)
        {
            return choice;
        }
    
        std::cin.clear(); // Clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "[Invalid input] Please enter a number between 1 and 6.\n";
    }
}