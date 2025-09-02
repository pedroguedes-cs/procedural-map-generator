#include <iostream>

#include "../include/message.hpp"

void saved()
{
    std::cout << "\nYour changes were saved!\n";
}

void terrain_generated()
{
    std::cout << "\nMap terrain successfully generated!\n";
}

void image_generated()
{
    std::cout << "Your image has been created!\n";
}

void set_first()
{
    std::cout << "\nPlease set your map before generating the map terrain.\n";
}

void generate_first()
{
     std::cout << "\nPlease set the map and generate a terrain before creating an image.\n";
}

void exiting()
{
      std::cout << "Exiting program...\n";
}

void bye()
{
    std::cout << "Bye! See you next time.\n\n\n\n";
}