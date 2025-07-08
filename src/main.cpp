#include <iostream>
#include <string>
#include "paleta.h"
#include "imagem.h"

using namespace std;

int main()
{   
    // ETAPA 1;
    Cor resposta;
    double consulta;
    Paleta teste;
    string nome_arquivo;

    cout << "Digite o nome do arquivo: ";
    cin >> nome_arquivo;
    cout << "Digite o valor a ser consultado: ";
    cin >> consulta;

    Paleta saida = teste.ler_arquivo(nome_arquivo);
    resposta = saida.consulta_cor(consulta);
    
    cout << resposta.r << " " << resposta.g << " " << resposta.b << endl;
    // FIM ETAPA 1


    //ETAPA 2;
    Imagem testando(2, 2);
    for(int i = 0; i < 4; i++){
        
    }

    return 0;
}