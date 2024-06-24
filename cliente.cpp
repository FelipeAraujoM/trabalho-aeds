#include <iostream>
#include <fstream>
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
    Cliente cliente;

    cout << "Digite os 3 últimos números do CPF: ";
    cin >> cliente.id;

    cout << "Digite o nome do cliente: ";
    cin.ignore();
    cin.getline(cliente.nome, sizeof(cliente.nome));

    cout << "Digite o endereço: ";
    cin.getline(cliente.endereco, sizeof(cliente.endereco));

    cout << "Digite o telefone: ";
    cin >> cliente.telefone;

    ofstream arquivo("cliente.txt", ios::app);

    if(arquivo.is_open()) {
        arquivo << "ID: " << cliente.id << endl;
        arquivo << "Nome: " << cliente.nome << endl;
        arquivo << "Endereço: " << cliente.endereco << endl;
        arquivo << "Telefone: " << cliente.telefone << endl;
        arquivo << endl;

        arquivo.close();

        cout << "Cliente cadastrado com sucesso" << endl;
    } else {
        cout << "Erro ao abrir arquivo para escrita" << endl;
    }
}

void buscarCliente() {
    cout << "2";
}
