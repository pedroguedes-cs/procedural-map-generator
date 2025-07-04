#include <iostream>
#include <string>
#include "paleta.cpp"

using namespace std;

int main()
{   

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
    
    cout << saida.get_quant() << endl;
    cout << resposta.r << " " << resposta.g << " " << resposta.b << endl;


    return 0;
}