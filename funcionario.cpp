#include <iostream>
#include "cliente.hpp"

using namespace std;

void sessaoFuncionario() {
    int menuFuncionario;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar um funcion�rio" << endl;
    cout << "2 - Procurar um funcion�rio" << endl;
    cin >> menuFuncionario;

    switch (menuFuncionario) {
    case 1:
        cadastroFuncionario();
        break;
    case 2:
        buscarFuncionario();
        break;
    default:
        cout << "Valor inv�lido";
        break;
    }
}

void cadastroFuncionario() {
    cout << "1";
}

void buscarFuncionario() {
    cout << "2";
}
