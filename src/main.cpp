#include <iostream>
#include <string>
#include <cmath>
#include "../include/imagem.h"
#include "../include/paleta.h"
#include "../include/terreno.h"

using namespace std;

int main()
{  
    int gerador, tamanho;
    cin >> gerador;
    tamanho = pow(2, gerador) + 1;


    Terreno teste(gerador, 0.9);


    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            cout << teste.consulta_altitude(i, j) << " ";
        }
        cout << endl;
    }
}