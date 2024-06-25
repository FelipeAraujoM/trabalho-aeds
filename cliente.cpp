#include <iostream>
#include <fstream>
#include <sstream>
#include "cliente.hpp"

using namespace std;

void sessaoCliente() {
    int menuCliente;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar um cliente" << endl;
    cout << "2 - Procurar um cliente" << endl;
    cout << "3 - Calcular pontos de fidelidade" << endl;
    cin >> menuCliente;

    switch (menuCliente) {
    case 1:
        cadastroCliente();
        break;
    case 2:
        buscarCliente();
        break;
    case 3:
        calcularPontosFidelidade();
        break;
    default:
        cout << "Valor inválido" << endl;
        break;
    }
}

bool idExistenteCliente(int id) {
    ifstream arquivo("cliente.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return false;
    }

    string line;
    while (getline(arquivo, line)) {
        if (line.find("ID: " + to_string(id)) != string::npos) {
            arquivo.close();
            return true;
        }
    }

    arquivo.close();
    return false;
}

void cadastroCliente() {
    Cliente cliente;

    cout << "Digite os 3 últimos números do CPF: ";
    cin >> cliente.id;

    if (idExistenteCliente(cliente.id)) {
        cout << "Já existe um cliente com esse ID" << endl;
        return;
    }

    cout << "Digite o nome do cliente: ";
    cin.ignore();
    cin.getline(cliente.nome, sizeof(cliente.nome));

    cout << "Digite o endereço: ";
    cin.getline(cliente.endereco, sizeof(cliente.endereco));

    cout << "Digite o telefone: ";
    cin >> cliente.telefone;

    ofstream arquivo("cliente.txt", ios::app);

    if (arquivo.is_open()) {
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
    int idCliente;
    cout << "Digite o ID do cliente: ";
    cin >> idCliente;

    ifstream arqCliente("cliente.txt");
    if (!arqCliente.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return;
    }

    string line;
    bool encontrado = false;
    while (getline(arqCliente, line)) {
        if (line.find("ID: " + to_string(idCliente)) != string::npos) {
            encontrado = true;
            cout << line << endl;
            for (int i = 0; i < 3; ++i) {
                getline(arqCliente, line);
                cout << line << endl;
            }
            cout << endl;
            break;
        }
    }

    arqCliente.close();

    if (!encontrado) {
        cout << "Cliente não encontrado" << endl;
        return;
    }

    ifstream arqEstadia("estadia.txt");
    if (!arqEstadia.is_open()) {
        cout << "Erro ao abrir arquivo de estadias para leitura" << endl;
        return;
    }

    int qtdEstadias = 0;
    while (getline(arqEstadia, line)) {
        if (line.find("Código do Cliente: " + to_string(idCliente)) != string::npos) {
            ++qtdEstadias;

            for (int i = 0; i < 5; ++i) {
                getline(arqEstadia, line);
            }
        }
    }

    arqEstadia.close();

    cout << "Quantidade de estadias realizadas: " << qtdEstadias << endl;
}

void calcularPontosFidelidade() {
    int idCliente;
    cout << "Digite o ID do cliente: ";
    cin >> idCliente;

    ifstream arqEstadia("estadia.txt");
    if (!arqEstadia.is_open()) {
        cout << "Erro ao abrir arquivo de estadias para leitura" << endl;
        return;
    }

    string line;
    int totalPontos = 0;
    bool encontrouCliente = false;

    while (getline(arqEstadia, line)) {
        if (line.find("Código do Cliente: " + to_string(idCliente)) != string::npos) {
            encontrouCliente = true;
            int dias = 0;

            for (int i = 0; i < 5; ++i) {
                getline(arqEstadia, line);
                if (line.find("Quantidade de Diárias: ") != string::npos) {
                    istringstream iss(line);
                    string temp;
                    iss >> temp >> temp >> temp >> temp >> dias;
                    totalPontos += dias * 10;
                }
            }
        }
    }

    arqEstadia.close();

    if (!encontrouCliente) {
        cout << "Cliente não encontrado ou não possui estadias registradas." << endl;
        return;
    }

    cout << "Total de pontos para o cliente " << idCliente << ": " << totalPontos << endl;
}
