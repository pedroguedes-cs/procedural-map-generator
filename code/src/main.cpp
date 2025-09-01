#include <iostream>
#include <string>

#include "../include/color.hpp"
#include "../include/image.hpp"
#include "../include/input.hpp"
#include "../include/map.hpp"
#include "../include/menu.hpp"
#include "../include/message.hpp"
#include "../include/overview.hpp"
#include "../include/palette.hpp"
#include "../include/point.hpp"
#include "../include/style.hpp"

struct Filename
{
    std::string folder;
    int number;
    std::string type;
};


int main()
{  
    // Classes
    Map map;
    Palette palette;
    palette.load_from_file("palettes/earthy.txt");
    Filename filename = {"images/image", 1, ".ppm"};
    
    // Variables
    bool exit = false;
    int choice;
    int palette_choice;


    title("PROCEDURAL MAP GENERATOR");

    while (true)
    {
        print_menu();
        choice = read_choice();

        print_line();

        switch(choice)
        {
            case 1:
                subtitle("MAP:");
                map.free_map();
                map = read_map();
                map.set_valid_size();
                map.alocate_map();
                map.set_active(true);
                map.set_terrain_generated(false);
                saved();
                break;

            case 2:
                print_palette_menu();
                palette_choice = read_palette_choice();
                
                switch(palette_choice)
                {
                    case 1: 
                        palette.load_from_file("palettes/earthy.txt");
                        break;
                    case 2: 
                        palette.load_from_file("palettes/hot.txt");
                        break;
                    case 3:
                        palette.load_from_file("palettes/cold.txt");
                        break;
                    case 4:
                        palette.load_from_file("palettes/grey.txt");
                        break;
                    case 5:
                        palette.load_from_file("palettes/neon.txt");
                        break;
                    case 6:
                        palette.load_from_file("palettes/pastel.txt");
                        break;
                }
                saved();
                break;

            case 3:
                print_overview(map, palette);
                break;

            case 4:
                if (map.get_active())
                {
                    map.generate_map_terrain();
                    map.set_terrain_generated(true);
                    saved();
                }
                else
                {
                    set_first();
                }
                break;

            case 5:
                if (map.get_active() && map.get_terrain_generated())
                {
                    (map.generate_image(palette)).save_image(filename.folder + std::to_string(filename.number) + filename.type);
                    filename.number++;
                    image_generated();
                }
                else
                {
                    generate_first();
                }
                break;

            case 6:
                exit = true;
                exiting();
                break;
        }

        print_line();

        if (exit)
        {
            break;
        }
    }


    bye();


    return 0;
}