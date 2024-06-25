#include <iostream>
#include "cliente.hpp"
#include <fstream>

using namespace std;

bool numCadastrado(int id) {
    ifstream arqQuarto("quarto.txt");
    if (!arqQuarto.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return false;
    }

    string line;
    while (getline(arqQuarto, line)) {
        if (line.find("N�mero: " + to_string(id)) != string::npos) {
            arqQuarto.close();
            return true;
        }
    }

    arqQuarto.close();
    return false;
}

void cadastroQuarto() {
    Quarto quarto;

    cout << "Digite o n�mero do quarto: ";
    cin >> quarto.numQuarto;

    if(numCadastrado(quarto.numQuarto)) {
        cout << "Quarto j� cadastrado" << endl;
        return;
    }

    cout << "Digite a lota��o m�xima do quarto: ";
    cin >> quarto.qtdHospedes;

    cout << "Digite o valor da di�ria: ";
    cin >> quarto.valDiaria;

    quarto.status = "Desocupado";

    ofstream arqQuarto("quarto.txt", ios::app);

    if(arqQuarto.is_open()) {
        arqQuarto << "N�mero: " << quarto.numQuarto << endl;
        arqQuarto << "N�mero de Hospedes: " << quarto.qtdHospedes << endl;
        arqQuarto << "Di�ria: " << quarto.valDiaria << endl;
        arqQuarto << "Status: " << quarto.status << endl;
        arqQuarto << endl;

        arqQuarto.close();

        cout << "Quarto cadastrado com sucesso" << endl;
    } else {
        cout << "Erro ao abrir arquivo para escrita";
    }
}
