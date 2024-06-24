#include <iostream>
#include "cliente.hpp"

using namespace std;

void sessaoFuncionario() {
    int menuFuncionario;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar um funcionário" << endl;
    cout << "2 - Procurar um funcionário" << endl;
    cin >> menuFuncionario;

    switch (menuFuncionario) {
    case 1:
        cadastroFuncionario();
        break;
    case 2:
        buscarFuncionario();
        break;
    default:
        cout << "Valor inválido";
        break;
    }
}

void cadastroFuncionario() {
    cout << "1";
}

void buscarFuncionario() {
    cout << "2";
}
