#include <iostream>
#include <string>
#include "imagem.h"
#include "paleta.h"
#include "terreno.h"

using namespace std;

int main()
{   
    Terreno teste(1);

    cout << teste.consulta_linhas() << endl;
    cout << teste.consulta_colunas() << endl;

    teste.salvar_terreno("pato.txt");

}