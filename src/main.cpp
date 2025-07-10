#include <iostream>
#include <string>
#include "../include/imagem.h"
#include "../include/paleta.h"
#include "../include/terreno.h"

using namespace std;

int main()
{   
    Terreno teste(3, 0.5);

    cout << teste.consulta_altitude(0, 1);

}