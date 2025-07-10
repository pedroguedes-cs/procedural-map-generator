#include <iostream>
#include <string>
#include "imagem.h"
#include "paleta.h"
#include "terreno.h"

using namespace std;

int main()
{   
    Terreno teste(3, 0.5);

    teste.consulta_altitude(0, 1);

}