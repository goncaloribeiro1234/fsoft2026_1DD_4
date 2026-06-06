#include "../../headers/views/MainView.h"
#include "../../headers/views/AdminView.h"
#include <iostream>

using namespace std;

void MainView::show() {
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
                AdminView adminView;
                adminView.showMenu();
                break;
            }
            case 2:
                cout << "\nMenu Instrutor em desenvolvimento" << endl;
                break;
            case 3:
                cout << "\nMenu Atleta em desenvolvimento" << endl;
                break;
            case 0: cout << "A fechar sistema..." << endl; break;
            default: cout << "Opcao invalida" << endl;
        }
    }
}