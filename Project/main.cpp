#include <iostream>
#include <string>
#include "headers/services/AthleteService.h"

using namespace std;

void menuAdmin(AthleteService& service);
void menuInstructor();
void menuAthlete();

int main() {
    int role = -1;

    while (role != 0) {
        cout << "\n-- GROSSOS E FIBRADOS: ARTES MARCIAIS --" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Instrutor" << endl;
        cout << "3. Atleta" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha o seu perfil: ";
        cin >> role;

        switch (role) {
            case 1: {
                AthleteService service;
                menuAdmin(service);
                break;
            }
            case 2: menuInstructor(); break;
            case 3: menuAthlete(); break;
            case 0: cout << "A fechar sistema..." << endl; break;
            default: cout << "Opcao invalida" << endl;
        }
    }
    return 0;
}

void menuAdmin(AthleteService& service) {
    int opt = -1;
    while (opt != 0) {
        cout << "\n--- MENU ADMINISTRADOR ---" << endl;
        cout << "1. Registar Atleta" << endl;
        cout << "2. Listar Todos os Atletas" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opt;

        if (opt == 1) {
            string name, email, pass, level;
            cout << "Nome: "; cin >> name;
            cout << "Email: "; cin >> email;
            cout << "Password: "; cin >> pass;
            cout << "Nivel Tecnico: "; cin >> level;

            try {
                Athlete a(name, "TEMP", email, pass, level);
                service.add(a);
                cout << "SUCESSO: Atleta registado!" << endl;
            } catch (exception& e) {
                cout << "ERRO: " << e.what() << endl;
            }
        } else if (opt == 2) {
            auto lista = service.getAll();
            cout << "\n--- LISTAGEM DE ATLETAS ---" << endl;
            for (Athlete* a : lista) {
                cout << "Nome: " << a->getName() << " | Email: " << a->getEmail() << endl;
            }
        }
    }
}

void menuInstructor() { cout << "\nem desenvolvimento" << endl; }
void menuAthlete() { cout << "\nem desenvolvimento" << endl; }