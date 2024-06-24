#include <iostream>
#include "cliente.hpp"

using namespace std;

void sessaoQuarto() {
    int menuQuarto;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar um quarto" << endl;
    cout << "2 - Ver o status dos quartos" << endl;
    cin >> menuQuarto;

    switch (menuQuarto) {
    case 1:
        cadastroQuarto();
        break;
    case 2:
        buscarQuarto();
        break;
    default:
        cout << "Valor inválido";
        break;
    }
}

void cadastroQuarto() {
    cout << "1";
}

void buscarQuarto() {
    cout << "2";
}
