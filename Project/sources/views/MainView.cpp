#include "../../headers/views/MainView.h"
#include "../../headers/views/AdminView.h"
#include "../../headers/views/InstructorView.h"
#include "../../headers/views/AthleteView.h"
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
            case 2: {
                string email, pass;
                cout << "\n--- LOGIN INSTRUTOR ---" << endl;
                cout << "Email: "; cin >> email;
                cout << "Password: "; cin >> pass;

                try {
                    Instructor* loggedIn = instructorController.login(email, pass);
                    cout << "\nSUCESSO: Bem-vindo, Instrutor " << loggedIn->getName() << "!" << endl;

                    InstructorView instructorView;
                    instructorView.showMenu(loggedIn);
                } catch (exception& e) {
                    cout << "ACESSO NEGADO: " << e.what() << endl;
                }
                break;
            }
            case 3: {
                string email, pass;
                cout << "\n--- LOGIN ATLETA ---" << endl;
                cout << "Email: "; cin >> email;
                cout << "Password: "; cin >> pass;

                try {
                    Athlete* loggedIn = athleteController.login(email, pass);
                    cout << "\nSUCESSO: Bem-vindo, Atleta " << loggedIn->getName() << "!" << endl;

                    AthleteView athleteView;
                    athleteView.showMenu();
                } catch (exception& e) {
                    cout << "ACESSO NEGADO: " << e.what() << endl;
                }
                break;
            }
            case 0: cout << "A fechar sistema..." << endl; break;
            default: cout << "Opcao invalida" << endl;
        }
    }
}