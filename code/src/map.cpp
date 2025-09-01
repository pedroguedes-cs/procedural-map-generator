#include "../include/map.hpp"
#include "../include/palette.hpp"
#include "../include/point.hpp"
#include <string>
#include <fstream>
#include <cmath>
#include <random>
using namespace std;


/** Construtor padrão
    Observação:
        size padrão = (3 x 3)
*/
Map::Map()
{
    int default_size = 3;

    lines = default_size;
    columns = default_size;
    
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



/** Construtor parametrizado
    Recebe:
        @gerador - O n que gerará o size [2^n + 1]
        @roughness - O fator que reduz o displacement a cada iteração
*/
Map::Map(int generator, double roughness)
{
    int size = pow(2, generator) + 1;
    lines = size;
    columns = size;

    // Matriz de heights
    heights = new double*[size];
    
    for(int i = 0; i < size; i++)
    {
        heights[i] = new double[size];
    }

    // Inicializando valores
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            heights[i][j] = -1;
        }
    }

    generate_map(roughness);
}



/** Destrutor
    obs:
        Como adotamos o formato ponteiro de ponteiros, precisamos deletar  cada "ponteiro-elemento"
*/
Map::~Map()
{
    // Liberando memória
    for (int i = 0; i < lines; i++)
    {
        delete[] heights[i];
    }
    delete[] heights;
}


/** Aplica o a "Etapa Diamond" no Map
    recebe:
        @ side - size do side na iteração atual [permite definir a quantidade de sub-quadrados]
        @ displacement - displacement da iteração atual [necessário para definir o displacement-aleatório do Point central]
*/
void Map::diamond(int side_length, int displacement)
{
    int squares_per_height = (lines - 1) / side_length;
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


/** Aplica o a "Etapa Square" no Map
    recebe:
        @ side_length - size do side_length na iteração atual [permite definir a quantidade de sub-quadrados]
        @ displacement - displacement da iteração atual [necessário para definir o displacement-aleatório dos Points ortogonais]
*/
void Map::square(int side_length, int displacement)
{
    int squares_per_height = (lines - 1) / side_length;
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


/** União das etapas Diamond e Square
    Recebe:
        @roughness - O fator que reduz o displacement a cada iteração
*/
void Map::generate_map(double roughness)
{
    int displacement = 10;
    int side = lines - 1;

    // corners iniciais
    int limit = 21;
    heights[0][0] = random(0, limit);
    heights[0][side] = random(0, limit);
    heights[side][0] = random(0, limit);
    heights[side][side] = random(0, limit);



    while(side > 1)
    {
        diamond(side, displacement);
        square(side, displacement);

        side = side / 2;
        displacement = displacement * roughness;
    }
}


/** Consouthtar lines
    Retorna:
        @lines - Quantidade de lines/altura do Map.
 */
int Map::get_lines()
{
    return lines;
}


/** Consouthtar lines
    Retorna:
        @columns - Quantidade de columns/largura do Map.
 */
int Map::get_columns()
{
    return columns;
}


/** Consouthtar altitude
    Recebe:
        @line1 - coordenada Y do pixel;
        @column1 - coordenada X do pixel.
    Retorna:
        @altitude - altitude especifica no pixel de coordenadas recebidas.
*/
double Map::get_height(int line, int column)
{
    return heights[line][column];
}


/** Salva um Map em um arquivo '.txt'
    Recebe:
        @nome_arquivo - nome do arquivo que receberá o Map
*/
void Map::save_map(string file_name)
{
    ofstream file(file_name, ios::out | ios::trunc);

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


/** Ler um arquivo que possui um Map e armazena no Map que recebeu o método
    Recebe:
        @nome_arquivo - nome do arquivo que receberá o Map
*/
void Map::read_map(string file_name)
{
    ifstream file(file_name);

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


/** Transforma o Map em uma imagem
    Recebe:
        @paleta - determina a cor que cada pixel vai ter com base na sua altitude
*/
Image Map::create_image(Palette palette)
{
    Image image(lines, columns);

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Color color = palette.get_color(heights[i][j]);

            // Sombreamento
            double shade_factor = 0.7;
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
                color.r = (int) color.r * shade_factor;
                color.g = (int) color.g * shade_factor;
                color.b = (int) color.b * shade_factor;
        
            }


            image.set_color(i, j, color);
        }
    }

    return image;
}


/** Gera um número inteiro aleatório no intervalo definido
    Recebe:
        @inicio_intervalo - inicío do intervalo
        @fim_intervalo - fim do intervalo
*/
int random(int begin_range, int end_range)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(begin_range, end_range);
    return distrib(gen);
    return distrib(gen);
}


