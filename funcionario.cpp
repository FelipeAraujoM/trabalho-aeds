#include <iostream>
#include <fstream>
#include <sstream>
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

    cout << "Digite os 3 últimos números do CPF: ";
    cin >> funcionario.id;

    if(idExistente(funcionario.id)) {
        cout << "Já existe um funcionário com esse ID" << endl;
        return;
    }

    cout << "Digite o nome do funcionário: ";
    cin.ignore();
    cin.getline(funcionario.nome, sizeof(funcionario.nome));

    cout << "Digite o telefone: ";
    cin >> funcionario.telefone;

    cout << "Digite o cargo ocupado: ";
    cin >> funcionario.cargo;

    cout << "Digite o valor do salário: R$";
    cin >> funcionario.salario;

    ofstream arqFuncionario("funcionario.txt", ios::app);

    if(arqFuncionario.is_open()) {
        arqFuncionario << "ID: " << funcionario.id << endl;
        arqFuncionario << "Nome: " << funcionario.nome << endl;
        arqFuncionario << "Telefone: " << funcionario.telefone << endl;
        arqFuncionario << "Cargo: " << funcionario.cargo << endl;
        arqFuncionario << "Salário: " << funcionario.salario << endl;
        arqFuncionario << endl;

        arqFuncionario.close();

        cout << "Funcionário cadastrado com sucesso" << endl;
    } else {
        cout << "Erro ao abrir arquivo para escrita" << endl;
    }
}

void buscarFuncionario() {
    int id;
    cout << "Digite o ID do funcionário: ";
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
        cout << "Funcionário não encontrado" << endl;
    }

    arqFuncionario.close();
}
