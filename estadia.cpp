#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cliente.hpp"

using namespace std;

void sessaoEstadia() {
    int menuEstadia;

    cout << "Digite:" << endl;
    cout << "1 - Cadastrar uma estadia" << endl;
    cout << "2 - Dar baixa em uma estadia" << endl;
    cin >> menuEstadia;

    switch (menuEstadia) {
    case 1:
        cadastroEstadia();
        break;
    case 2:
        baixaEstadia();
        break;
    default:
        cout << "Valor inválido";
        break;
    }
}

bool idExistenteEstadia(int id) {
    ifstream arqCliente("cliente.txt");
    if (!arqCliente.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return false;
    }

    string line;
    while (getline(arqCliente, line)) {
        if (line.find("ID: " + to_string(id)) != string::npos) {
            arqCliente.close();
            return true;
        }
    }

    arqCliente.close();
    return false;
}

int calcularDiasEntreDatas(int diaEntrada, int mesEntrada, int anoEntrada,
                           int diaSaida, int mesSaida, int anoSaida) {
    int totalDiasEntrada = diaEntrada + mesEntrada * 30 + anoEntrada * 360;
    int totalDiasSaida = diaSaida + mesSaida * 30 + anoSaida * 360;
    return totalDiasSaida - totalDiasEntrada;
}

void quartosDesocupados() {
    ifstream arqQuarto("quarto.txt");
    if (!arqQuarto.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return;
    }

    string line;
    string numeroQuarto;
    while (getline(arqQuarto, line)) {
        if (line.find("Número: ") != string::npos) {
            numeroQuarto = line;
        } else if (line.find("Status: Desocupado") != string::npos) {
            cout << numeroQuarto << endl;
        }
    }

    arqQuarto.close();
}

void atualizarStatusQuarto(int numQuarto, string novoStatus) {
    ifstream arqQuarto("quarto.txt");
    ofstream tempFile("temp.txt");

    if (!arqQuarto.is_open() || !tempFile.is_open()) {
        cout << "Erro ao abrir arquivos para leitura/escrita" << endl;
        return;
    }

    string line;
    while (getline(arqQuarto, line)) {
        tempFile << line << endl;
        if (line.find("Número: " + to_string(numQuarto)) != string::npos) {
            while (getline(arqQuarto, line) && !line.empty()) {
                if (line.find("Status: ") != string::npos) {
                    tempFile << "Status: " << novoStatus << endl;
                } else {
                    tempFile << line << endl;
                }
            }
            tempFile << endl;
        }
    }

    arqQuarto.close();
    tempFile.close();

    remove("quarto.txt");
    rename("temp.txt", "quarto.txt");
}

float obterValorDiaria(int numQuarto) {
    ifstream arqQuarto("quarto.txt");
    if (!arqQuarto.is_open()) {
        cout << "Erro ao abrir arquivo para leitura" << endl;
        return 0;
    }

    string line;
    while (getline(arqQuarto, line)) {
        if (line.find("Número: " + to_string(numQuarto)) != string::npos) {
            while (getline(arqQuarto, line) && !line.empty()) {
                if (line.find("Diária: ") != string::npos) {
                    arqQuarto.close();
                    return stof(line.substr(line.find(": ") + 2));
                }
            }
        }
    }

    arqQuarto.close();
    return 0;
}

void cadastroEstadia() {
    Estadia estadia;

    cout << "Insira o código do cliente: ";
    cin >> estadia.idCliente;

    if (!idExistenteEstadia(estadia.idCliente)) {
        cout << "Cliente não encontrado";
        return;
    }

    cout << "Quantidade de hospedes: ";
    cin >> estadia.qtdHospedes;

    cout << "Data de entrada (DD MM AAAA): ";
    cin >> estadia.diaEntrada >> estadia.mesEntrada >> estadia.anoEntrada;

    cout << "Data de saída (DD MM AAAA): ";
    cin >> estadia.diaSaida >> estadia.mesSaida >> estadia.anoSaida;

    if (estadia.anoSaida < estadia.anoEntrada ||
        (estadia.anoSaida == estadia.anoEntrada && estadia.mesSaida < estadia.mesEntrada) ||
        (estadia.anoSaida == estadia.anoEntrada && estadia.mesSaida == estadia.mesEntrada && estadia.diaSaida < estadia.diaEntrada)) {
        cout << "Erro: A data de saída não pode ser menor que a data de entrada" << endl;
        return;
    }

    int dias = calcularDiasEntreDatas(estadia.diaEntrada, estadia.mesEntrada, estadia.anoEntrada, estadia.diaSaida, estadia.mesSaida, estadia.anoSaida);

    cout << "Quartos Desocupados:" << endl;
    quartosDesocupados();

    cout << "Insira o número do quarto que deseja: ";
    cin >> estadia.numQuarto;

    atualizarStatusQuarto(estadia.numQuarto, "Ocupado");

    ofstream arqEstadia("estadia.txt", ios::app);

    if (arqEstadia.is_open()) {
        arqEstadia << "Código do Cliente: " << estadia.idCliente << endl;
        arqEstadia << "Número do Quarto: " << estadia.numQuarto << endl;
        arqEstadia << "Quantidade de Hospedes: " << estadia.qtdHospedes << endl;
        arqEstadia << "Data de Entrada: " << estadia.diaEntrada << "/" << estadia.mesEntrada << "/" << estadia.anoEntrada << endl;
        arqEstadia << "Data de Saída: " << estadia.diaSaida << "/" << estadia.mesSaida << "/" << estadia.anoSaida << endl;
        arqEstadia << "Quantidade de Diárias: " << dias << endl;
        arqEstadia << endl;

        arqEstadia.close();

        cout << "Estadia cadastrada com sucesso" << endl;

        // Chama a função para registrar a quantidade de dias multiplicada por 10
        registrarDiasCliente(estadia.idCliente, dias);
    } else {
        cout << "Erro ao abrir arquivo para escrita" << endl;
    }
}

void baixaEstadia() {
    int idCliente;
    cout << "Insira o código do cliente para dar baixa na estadia: ";
    cin >> idCliente;

    ifstream arqEstadia("estadia.txt");
    ofstream tempFile("tempEstadia.txt");

    if (!arqEstadia.is_open() || !tempFile.is_open()) {
        cout << "Erro ao abrir arquivos para leitura/escrita" << endl;
        return;
    }

    string line;
    bool estadiaEncontrada = false;
    int numQuarto = 0;
    int qtdDiarias = 0;
    float valorDiaria = 0.0;

    while (getline(arqEstadia, line)) {
        if (line.find("Código do Cliente: " + to_string(idCliente)) != string::npos) {
            estadiaEncontrada = true;
            tempFile << line << endl;

            while (getline(arqEstadia, line) && !line.empty()) {
                tempFile << line << endl;
                if (line.find("Número do Quarto: ") != string::npos) {
                    numQuarto = stoi(line.substr(line.find(": ") + 2));
                } else if (line.find("Quantidade de Diárias: ") != string::npos) {
                    qtdDiarias = stoi(line.substr(line.find(": ") + 2));
                }
            }
            tempFile << endl;
        } else {
            tempFile << line << endl;
        }
    }

    arqEstadia.close();
    tempFile.close();

    if (estadiaEncontrada) {
        valorDiaria = obterValorDiaria(numQuarto);
        float valorTotal = valorDiaria * qtdDiarias;

        cout << "Valor total a ser pago pelo cliente " << idCliente << " é: R$ " << valorTotal << endl;

        atualizarStatusQuarto(numQuarto, "Desocupado");

        remove("estadia.txt");
        rename("tempEstadia.txt", "estadia.txt");
    } else {
        cout << "Estadia não encontrada para o cliente " << idCliente << endl;
        remove("tempEstadia.txt");
    }
}

void registrarDiasCliente(int idCliente, int dias) {
    ofstream arqCliente("cliente.txt", ios::app);

    if (!arqCliente.is_open()) {
        cout << "Erro ao abrir arquivo para escrita" << endl;
        return;
    }

    int diasMultiplicados = dias * 10;

    arqCliente << "ID: " << idCliente << " - Pontos Fidelidade: " << diasMultiplicados << endl;

    arqCliente.close();
}
