#include <iostream>
#include <locale.h>
#include "cliente.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int menu;

    cout << "Digite:" << endl;
    cout << "1 - Sessão do cliente" << endl;
    cout << "2 - Sessão do funcionário" << endl;
    cout << "3 - Cadastrar quarto" << endl;
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
        cadastroQuarto();
        break;
    case 4:
        sessaoEstadia();
        break;
    case 5:
        exit(1);
    default:
        cout << "Valor inválido";
        break;
    }

    return 0;
}
