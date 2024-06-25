#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>
#include <string>

using namespace std;

void sessaoCliente();
void cadastroCliente();
void buscarCliente();
void calcularPontosFidelidade();

void sessaoFuncionario();
void cadastroFuncionario();
void buscarFuncionario();

void cadastroQuarto();
void baixaEstadia();

void sessaoEstadia();
void cadastroEstadia();

bool numCadastrado(int id);

class Cliente {
public:
    int id;
    char nome[50];
    char endereco[100];
    int telefone;
};

class Funcionario {
public:
    int id;
    char nome[50];
    int telefone;
    char cargo[50];
    float salario;
};

class Estadia {
public:
    int id;
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    int idCliente;
    int numQuarto;
    int qtdHospedes;
};

class Quarto {
public:
    int numQuarto;
    int qtdHospedes;
    float valDiaria;
    string status;
};

#endif
