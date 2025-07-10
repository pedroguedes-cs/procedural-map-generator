#include <iostream>
#include <string>
#include <cmath>
#include "../include/imagem.h"
#include "../include/paleta.h"
#include "../include/terreno.h"

using namespace std;

int main()
{  
    int gerador, tamanho_linha;
    cout << "Digite um número gerador: ";
    cin >> gerador;

    tamanho_linha = pow(2, gerador) + 1;

    Terreno teste(gerador, 0.9);

    for (int i = 0; i < (tamanho_linha * tamanho_linha); i++)
    {
        if (i % tamanho_linha == tamanho_linha - 1)
        {
            cout << teste.consulta_altitude(i / tamanho_linha, i % tamanho_linha) << endl;
        }
        else
        {
            cout << teste.consulta_altitude(i / tamanho_linha, i % tamanho_linha) << " ";
        }
    }
}