#include "../../headers/views/AdminView.h"
#include <iostream>

using namespace std;

void AdminView::showMenu() {
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
            
            cout << "\nSelecione o Nivel Tecnico:" << endl;
            cout << "1. Iniciante\n2. Intermedio\n3. Avancado\nOpcao: ";
            int levelOption; cin >> levelOption;

            if(levelOption == 1) level = "Iniciante";
            else if(levelOption == 2) level = "Intermedio";
            else if(levelOption == 3) level = "Avancado";

            try {
                // A View não toca no Model nem no Service, apenas fala com o Controller!
                athleteController.addAthlete(name, email, pass, level);
                cout << "SUCESSO: Atleta registado!" << endl;
            } catch (exception& e) {
                cout << "ERRO: " << e.what() << endl;
            }
        }
        else if (opt == 2) {
            auto lista = athleteController.findAllAthletes();
            cout << "\n--- LISTAGEM DE ATLETAS ---" << endl;
            for (auto a : lista) {
                cout << "Nome: " << a->getName() << " | Email: " << a->getEmail() << endl;
            }
        }
    }
}