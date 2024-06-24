#include <iostream>
#include "cliente.hpp"

using namespace std;

void sessaoEstadia() {
    int menuEstadia;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar um quarto" << endl;
    cout << "2 - Ver o status dos quartos" << endl;
    cin >> menuEstadia;

    switch (menuEstadia) {
    case 1:
        cadastroEstadia();
        break;
    case 2:
        verificarPreco();
        break;
    default:
        cout << "Valor inválido";
        break;
    }
}

void cadastroEstadia() {
    cout << "1";
}

void verificarPreco() {
    cout << "2";
}

