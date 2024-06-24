#include <iostream>
#include <locale.h>
#include "cliente.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int menu;

    cout << "Digite:" << endl;
    cout << "1 - Sess�o do cliente" << endl;
    cout << "2 - Sess�o do funcion�rio" << endl;
    cout << "3 - Sess�o dos quartos" << endl;
    cout << "4 - Cadastrar uma estadia" << endl;
    cout << "5 - Finalizar" << endl;
    cin >> menu;

    switch (menu) {
    case 1:
        sessaoCliente();
        break;
    case 2:
        sessaoFuncionario();
        break;
    case 3:
        sessaoQuarto();
        break;
    case 4:
        sessaoEstadia();
        break;
    default:
        cout << "Valor inv�lido";
        break;
    }

    return 0;
}
