#include <string>
#include <fstream>
#include <cmath>

#include "../include/map.hpp"
#include "../include/palette.hpp"
#include "../include/point.hpp"
#include "../include/utilities.hpp"


// Constructors and destructor
Map::Map()
{
    int default_size = 3;

    lines = default_size;
    columns = default_size;
    roughness_factor = 0;
    shade_factor = 0;
    active = false;
    terrain_generated = false;

    
    // Matriz de heights (3x3)
    heights = new double*[default_size];
    
    for(int i = 0; i < default_size; i++)
    {
        heights[i] = new double[default_size];
    }

    // Inicializando valores
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            heights[i][j] = -1;
        }
    }

}

Map::Map(int lines, int columns, double roughness, double shade)
{
    this->lines = lines;
    this->columns = columns;
    this->roughness_factor = roughness;
    this->shade_factor = shade;

    active = true;
    terrain_generated = false;

    valid_size = next_valid_size(std::max(lines, columns));

    // Matriz de heights
    heights = new double*[valid_size];
    
    for(int i = 0; i < valid_size; i++)
    {
        heights[i] = new double[valid_size];
    }

    // Inicializando valores
    for (int i = 0; i < valid_size; i++)
    {
        for (int j = 0; j < valid_size; j++)
        {
            heights[i][j] = -1;
        }
    }
}

Map::~Map()
{
    // Liberando memória
    for (int i = 0; i < lines; i++)
    {
        delete[] heights[i];
    }
    delete[] heights;
}

// Functions to reuse
void Map::alocate_map()
{
    heights = new double*[valid_size];

    for (int i = 0; i < valid_size; i++)
    {
        heights[i] = new double[valid_size];
    }

    // Inicializando valores
    for (int i = 0; i < valid_size; i++)
    {
        for (int j = 0; j < valid_size; j++)
        {
            heights[i][j] = -1;
        }
    }
}

void Map::free_map()
{
    // Liberando memória
    for (int i = 0; i < lines; i++)
    {
        delete[] heights[i];
    }
    delete[] heights;
}

void Map::clear()
{
    lines = 0;
    columns = 0;
    roughness_factor = 0;
    shade_factor = 0;
    active = false;
    terrain_generated = false;
    free_map();
}

// Getters
int Map::get_lines()
{
    return lines;
}

int Map::get_columns()
{
    return columns;
}

double Map::get_roughness_factor()
{
    return roughness_factor;
}

double Map::get_shade_factor()
{
    return shade_factor;
}

bool Map::get_active()
{
    return active;
}

bool Map::get_terrain_generated()
{
    return terrain_generated;
}

double Map::get_pixel_height(int line, int column)
{
    return heights[line][column];
}

// Setters
void Map::set_lines(int lines)
{
    this->lines = lines;
}

void Map::set_columns(int columns)
{
    this->columns = columns;
}

void Map::set_roughness_factor(double roughness)
{
    roughness_factor = roughness;
}

void Map::set_shade_factor(double shade)
{
    shade_factor = shade;
}

void Map::set_terrain_generated(bool status)
{
    terrain_generated = status;
}

void Map::set_active(bool status)
{
    active = status;
}

void Map::set_valid_size(int lines, int columns)
{
    valid_size = next_valid_size(std::max(lines, columns));
}


// Map Operations
void Map::diamond(int side_length, int displacement)
{
    int squares_per_height = (valid_size - 1) / side_length;
    int squares_per_width = squares_per_height;

    // Passando por cada quadrado + executando o Diamond
    for (int i = 0; i < squares_per_height; i++)
    {
        for (int j = 0; j < squares_per_width; j++)
        {
            // Coordenadas
            Point corner1 = {i * side_length, j * side_length};
            Point corner2 = {i * side_length, j * side_length + side_length};
            Point corner3 = {i * side_length + side_length, j * side_length};
            Point corner4 = {i * side_length + side_length, j * side_length + side_length};
            Point mid = {i * side_length + (side_length / 2), j * side_length + (side_length / 2)};
            
            int random_displacement = random((-1 * displacement), displacement);
            double sum = heights[corner1.line][corner1.column] + heights[corner2.line][corner2.column] + heights[corner3.line][corner3.column] + heights[corner4.line][corner4.column];

            // mid
            heights[mid.line][mid.column] = abs((sum / 4) + random_displacement);
        }
    }
}

void Map::square(int side_length, int displacement)
{
    int squares_per_height = (valid_size - 1) / side_length;
    int squares_per_width = squares_per_height;

    // Passando por cada quadrado + executando o Square
    for (int i = 0; i < squares_per_height; i++)
    {
        for (int j = 0; j < squares_per_width; j++)
        {
            // Coordenadas
            Point corner1 = {i * side_length, j * side_length};
            Point corner2 = {i * side_length, j * side_length + side_length};
            Point corner3 = {i * side_length + side_length, j * side_length};
            Point corner4 = {i * side_length + side_length, j * side_length + side_length};

            Point mid = {i * side_length + (side_length / 2), j * side_length + (side_length / 2)};
            
            Point north = {i * side_length, j * side_length + (side_length / 2)};
            Point south = {i * side_length + side_length, j * side_length + (side_length / 2)};
            Point east = {i * side_length + (side_length / 2), j * side_length + side_length};
            Point west = {i * side_length + (side_length / 2), j * side_length};

            Point mid_north = {mid.line - side_length, mid.column};
            Point mid_south = {mid.line + side_length, mid.column};
            Point mid_east = {mid.line, mid.column + side_length};
            Point mid_west = {mid.line, mid.column - side_length};


            // north

            int random_displacement = random((-1 * displacement), displacement);
            int sum;

            if (heights[north.line][north.column] < 0)
            {
                if (north.line == 0)
                {
                    sum = heights[corner1.line][corner1.column] + heights[corner2.line][corner2.column] + heights[mid.line][mid.column];
                    heights[north.line][north.column] = (sum / 3) + random_displacement;
                }
                else
                {
                    sum = heights[corner1.line][corner1.column] + heights[corner2.line][corner2.column] + heights[mid.line][mid.column] + heights[mid_north.line][mid_north.column];
                    heights[north.line][north.column] = (sum / 4) + random_displacement;
                }
                if (heights[north.line][north.column] < 0)
                {
                    heights[north.line][north.column] = abs(heights[north.line][north.column]);
                }
            }


            // south

            random_displacement = random((-1 * displacement), displacement);

            if (heights[south.line][south.column] < 0)
            {
                if (south.line == (lines - 1))
                {
                    sum = heights[corner3.line][corner3.column] + heights[corner4.line][corner4.column] + heights[mid.line][mid.column];
                    heights[south.line][south.column] = (sum / 3) + random_displacement;
                }
                else
                {
                    sum = heights[corner3.line][corner3.column] + heights[corner4.line][corner4.column] + heights[mid.line][mid.column] + heights[mid_south.line][mid_south.column];
                    heights[south.line][south.column] = (sum / 4) + random_displacement;
                }
                if (heights[south.line][south.column] < 0)
                {
                    heights[south.line][south.column] = abs(heights[south.line][south.column]);
                }
            }
            

            // east

            random_displacement = random((-1 * displacement), displacement);

            if (heights[east.line][east.column] < 0)
            {
                if (east.column == (columns - 1))
                {
                    sum = heights[corner2.line][corner2.column] + heights[corner4.line][corner4.column] + heights[mid.line][mid.column];
                    heights[east.line][east.column] = (sum / 3) + random_displacement;
                }
                else
                {
                    sum = heights[corner2.line][corner2.column] + heights[corner4.line][corner4.column] + heights[mid.line][mid.column] + heights[mid_east.line][mid_east.column];
                    heights[east.line][east.column] = (sum / 4) + random_displacement;
                }
                if (heights[east.line][east.column] < 0)
                {
                    heights[east.line][east.column] = abs(heights[east.line][east.column]);
                }
            }


            // west

            random_displacement = random((-1 * displacement), displacement);

            if (heights[west.line][west.column] < 0)
            {
                if (west.column == 0)
                {
                    sum = heights[corner1.line][corner1.column] + heights[corner3.line][corner3.column] + heights[mid.line][mid.column];
                    heights[west.line][west.column] = (sum / 3) + random_displacement;
                }
                else
                {
                    sum = heights[corner1.line][corner1.column] + heights[corner3.line][corner3.column] + heights[mid.line][mid.column] + heights[mid_west.line][mid_west.column];
                    heights[west.line][west.column] = (sum / 4) + random_displacement;
                }
                if (heights[west.line][west.column] < 0)
                {
                    heights[west.line][west.column] = abs(heights[west.line][west.column]);
                }
            }


        }
    }


}

void Map::generate_map_terrain()
{
    int displacement = 10;
    int side = valid_size - 1;

    // corners iniciais
    int limit = 100;
    heights[0][0] = random(0, limit);
    heights[0][side] = random(0, limit);
    heights[side][0] = random(0, limit);
    heights[side][side] = random(0, limit);



    while(side > 1)
    {
        diamond(side, displacement);
        square(side, displacement);

        side = side / 2;
        displacement = displacement * roughness_factor;
    }

    terrain_generated = true;
}

void Map::save_map(std::string file_name)
{
    std::ofstream file(file_name, std::ios::out | std::ios::trunc);

    if(file.is_open() == false)
    {
        return;
    }
    else
    {
        file << lines << " " << columns << endl;
    }

    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            file << heights[i][j] << " ";
        }
        file << endl;
    }
}

void Map::read_map(std::string file_name)
{
    std::ifstream file(file_name);

    if (file.is_open() == false)
    {
        return;
    }
    else
    {
        // Liberando memória
        for (int i = 0; i < lines; i++)
        {
            delete[] heights[i];
        }
        delete[] heights;

        // Leitura medidas
        file >> lines >> columns;
        heights = new double*[lines];

        // Alocando matriz
        for (int i = 0; i < lines; i++)
        {
            heights[i] = new double[columns];
        }

        // Leitura heights
        double value;
        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                file >> value;
                heights[i][j] = value;
            }
        }
    }
}

// Image
Image Map::generate_image(Palette palette)
{
    Image image(lines, columns);

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Color color = palette.get_color(heights[i][j]);

            // Sombreamento
            bool is_sun_visible = true;
            int line = i;
            int column = j;

            while (line >= 0 && column >= 0)
            {
                if (heights[line][column] > heights[i][j])
                {
                    is_sun_visible = false;
                    break;
                }

                line--;
                column--;
            }

            if (is_sun_visible == false)
            {
                color.r = (int) color.r * effects.shade_factor;
                color.g = (int) color.g * effects.shade_factor;
                color.b = (int) color.b * effects.shade_factor;
        
            }


            image.set_color(i, j, color);
        }
    }

    return image;
}


