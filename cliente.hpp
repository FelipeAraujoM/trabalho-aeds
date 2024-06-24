#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>

using namespace std;

void sessaoCliente();
void cadastroCliente();
void buscarCliente();

void sessaoFuncionario();
void cadastroFuncionario();
void buscarFuncionario();

void sessaoQuarto();
void cadastroQuarto();
void buscarQuarto();

void sessaoEstadia();
void cadastroEstadia();
void verificarPreco();

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
    char cargo;
    float salario;
};

class Estadia {
    int id;
    int diaEntrada;
    int mesEntrada;
    int anoEntrada;
    int diaSaida;
    int mesSaida;
    int anoSaida;
    int idCliente;
    int numQuarto;
};

class Quarto {
    int numQuarto;
    int qtdHospedes;
    int valDiaria;
    bool status;
};

#endif
