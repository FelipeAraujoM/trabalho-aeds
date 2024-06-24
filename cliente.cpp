#include <iostream>
#include "cliente.hpp"

using namespace std;

void sessaoCliente() {
    int menuCliente;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar um cliente" << endl;
    cout << "2 - Procurar um cliente" << endl;
    cin >> menuCliente;

    switch (menuCliente) {
    case 1:
        cadastroCliente();
        break;
    case 2:
        buscarCliente();
        break;
    default:
        cout << "Valor inválido";
        break;
    }
}

void cadastroCliente() {
    cout << "1";
}

void buscarCliente() {
    cout << "2";
}
