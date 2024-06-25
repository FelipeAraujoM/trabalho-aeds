#include <iostream>
#include <fstream>
#include <sstream>
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

bool idExistente(int id) {
    ifstream arqFuncionario("funcionario.txt");
    if (!arqFuncionario.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return false;
    }

    string line;
    while (getline(arqFuncionario, line)) {
        if (line.find("ID: " + to_string(id)) != string::npos) {
            arqFuncionario.close();
            return true;
        }
    }

    arqFuncionario.close();
    return false;
}

void cadastroFuncionario() {
    Funcionario funcionario;

    cout << "Digite os 3 �ltimos n�meros do CPF: ";
    cin >> funcionario.id;

    if(idExistente(funcionario.id)) {
        cout << "J� existe um funcion�rio com esse ID" << endl;
        return;
    }

    cout << "Digite o nome do funcion�rio: ";
    cin.ignore();
    cin.getline(funcionario.nome, sizeof(funcionario.nome));

    cout << "Digite o telefone: ";
    cin >> funcionario.telefone;

    cout << "Digite o cargo ocupado: ";
    cin >> funcionario.cargo;

    cout << "Digite o valor do sal�rio: R$";
    cin >> funcionario.salario;

    ofstream arqFuncionario("funcionario.txt", ios::app);

    if(arqFuncionario.is_open()) {
        arqFuncionario << "ID: " << funcionario.id << endl;
        arqFuncionario << "Nome: " << funcionario.nome << endl;
        arqFuncionario << "Telefone: " << funcionario.telefone << endl;
        arqFuncionario << "Cargo: " << funcionario.cargo << endl;
        arqFuncionario << "Sal�rio: " << funcionario.salario << endl;
        arqFuncionario << endl;

        arqFuncionario.close();

        cout << "Funcion�rio cadastrado com sucesso" << endl;
    } else {
        cout << "Erro ao abrir arquivo para escrita" << endl;
    }
}

void buscarFuncionario() {
    int id;
    cout << "Digite o ID do funcion�rio: ";
    cin >> id;

    ifstream arqFuncionario("funcionario.txt");
    if (!arqFuncionario.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return;
    }

    string line;
    bool encontrado = false;
    while (getline(arqFuncionario, line)) {
        if (line.find("ID: " + to_string(id)) != string::npos) {
            encontrado = true;
            cout << line << endl;
            for (int i = 0; i < 4; ++i) {
                getline(arqFuncionario, line);
                cout << line << endl;
            }
            cout << endl;
        }
    }

    if (!encontrado) {
        cout << "Funcion�rio n�o encontrado" << endl;
    }

    arqFuncionario.close();
}
