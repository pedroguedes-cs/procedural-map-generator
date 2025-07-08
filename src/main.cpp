#include <iostream>
#include <string>
#include "imagem.h"
#include "paleta.h"
#include "imagem.h"

using namespace std;

int main()
{   
    Imagem teste(3, 3);

    
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 3; j++)
       {
            if (j == 0)
            {
                teste.definir_cor(i, j, {0, 0, 255});
            }
            if (j == 1)
            {
                teste.definir_cor(i, j, {255, 255, 255});
            }
            if (j == 2)
            {
                teste.definir_cor(i, j, {255, 0, 0});
            }
       } 
    }

    teste.salvar_imagem("França.ppm");
    return 0;
}