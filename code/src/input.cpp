#include <iostream>
#include <limits>

#include "../include/input.hpp"

std::string normalize_float(std::string number)
{
    // Exchange ',' -> '.'
    for (char &c : number)
    {
        if (c == ',')
        {
            c = '.';
        }
    }

    return number;
}

bool is_integer(std::string number)
{
    if (number.empty())
    {
        return false;
    }

    if (number == "+" || number == "-")
    {
        return false;
    }

    for (auto i = number.begin(); i < number.end(); i++)
    {
        if ((*i == '+' || *i == '-') && i != number.begin())
        {
            return false;
        }

        if (*i != '-' && *i != '+' && (*i < '0' || *i > '9'))
        {
            return false;
        }
    }

    return true;
}

bool is_float(std::string number)
{
    if (number.empty())
    {
        return false;
    }

    if (number == "+" || number == "-" || number == ".")
    {
        return false;
    }

    int counter_dots = 0;

    for (auto i = number.begin(); i < number.end(); i++)
    {
        if ((*i == '+' || *i == '-') && i != number.begin())
        {
            return false;
        }

        else if (*i == '.')
        {
            if (counter_dots >= 1)
            {
                return false;
            }

            counter_dots++;
        }

        else if (*i != '-' && *i != '+' && (*i < '0' || *i > '9'))
        {
            return false;
        }
    }

    return true;
}

int read_choice()
{
    std::string choice;

    while (true)
    {
        std::cout << "\nEnter your choice (1-6): ";

        if (getline(std::cin,choice) && is_integer(choice) && stoi(choice) >= 1 && stoi(choice) <= 6)
        {
            return stoi(choice);
        }

        std::cout << "[Invalid input] Please enter a integer number between 1 and 6.\n";
    }
}

int read_lines()
{
    std::string lines;

    while (true)
    {
        std::cout << "\nLines: ";

        if (getline(std::cin, lines) && is_integer(lines) && stoi(lines) >= 1)
        {
            return stoi(lines);
        }

        std::cout << "[Invalid input] Please enter a positive integer value.\n";
    }
}

int read_columns()
{
    std::string columns;

    while (true)
    {
        std::cout << "\nColumns: ";

        if (getline(std::cin, columns) && is_integer(columns) && stoi(columns) >= 1)
        {
            return stoi(columns);
        }

        std::cout << "[Invalid input] Please enter a positive integer value.\n";
    }
}

float read_shade()
{
    std::string shade;

    while (true)
    {
        std::cout << "\nShade factor: ";

        if (getline(std::cin, shade) && is_float(normalize_float(shade)) && stof(normalize_float(shade)) >= 0 && stof(normalize_float(shade)) <= 1)
        {
            return stof(normalize_float(shade));
        }

        std::cout << "[Invalid input] Please enter a decimal floating-point number between 0 and 1. (ex: 0.75)\n";
    }
}

float read_roughness()
{
    std::string roughness;

    while (true)
    {
        std::cout << "\nRoughness factor: ";

        if (getline(std::cin, roughness) && is_float(normalize_float(roughness)) && stof(normalize_float(roughness)) >= 0 && stof(normalize_float(roughness)) <= 1)
        {
            return stof(normalize_float(roughness));
        }

        std::cout << "[Invalid input] Please enter a decimal floating-point number between 0 and 1. (ex: 0.75)\n";
    }
}

Map read_map()
{
    int lines = read_lines();
    int columns = read_columns();
    double roughness = read_roughness();
    double shade = read_shade();

    return {lines, columns, roughness, shade};
}

int read_palette_choice()
{
    std::string choice;

    while (true)
    {
        std::cout << "\nChoose a palette (1-6): ";

        if (getline(std::cin,choice) && is_integer(choice) && stoi(choice) >= 1 && stoi(choice) <= 6)
        {
            return stoi(choice);
        }

        std::cout << "[Invalid input] Please enter a integer number between 1 and 6.\n";
    }
}