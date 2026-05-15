#include <iostream>
#include <string>

#include "headers/services/AthleteService.h"
#include "headers/services/InstructorService.h"
#include "headers/services/ModalityService.h"
#include "headers/exceptions/InvalidDataException.h"

using namespace std;

void menuAdmin(AthleteService& athleteService,
               InstructorService& instructorService,
               ModalityService& modalityService);

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
                AthleteService athleteService;
                InstructorService instructorService;
                ModalityService modalityService;

                menuAdmin(athleteService, instructorService, modalityService);
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

void menuAdmin(AthleteService& athleteService,
               InstructorService& instructorService,
               ModalityService& modalityService) {
    int opt = -1;

    while (opt != 0) {
        cout << "\n--- MENU ADMINISTRADOR ---" << endl;
        cout << "1. Registar Atleta" << endl;
        cout << "2. Listar Todos os Atletas" << endl;
        cout << "3. Registar Instrutor" << endl;
        cout << "4. Listar Todos os Instrutores" << endl;
        cout << "5. Criar Modalidade" << endl;
        cout << "6. Listar Modalidades" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opt;

        if (opt == 1) {
            string name, email, pass, level;

            cout << "Nome: ";
            cin >> name;

            cout << "Email: ";
            cin >> email;

            cout << "Password: ";
            cin >> pass;

            cout << "\nSelecione o Nivel Tecnico:" << endl;
            cout << "1. Beginner" << endl;
            cout << "2. Intermediate" << endl;
            cout << "3. Advanced" << endl;
            cout << "Opcao: ";

            int levelOption;
            cin >> levelOption;

            switch(levelOption) {

            case 1:
                level = "Beginner";
                break;

            case 2:
                level = "Intermediate";
                break;

            case 3:
                level = "Advanced";
                break;

            default:
                throw InvalidDataException("Invalid technical level.");
            }

            try {
                Athlete a(name, "TEMP", email, pass, level);
                athleteService.add(a);

                cout << "SUCESSO: Atleta registado!" << endl;
            }
            catch (exception& e) {
                cout << "ERRO: " << e.what() << endl;
            }
        }
        else if (opt == 2) {
            auto lista = athleteService.getAll();

            cout << "\n--- LISTAGEM DE ATLETAS ---" << endl;

            for (Athlete* a : lista) {
                cout << "Nome: "
                     << a->getName()
                     << " | Email: "
                     << a->getEmail()
                     << endl;
            }
        }
        else if (opt == 3) {
            string name, email, pass, specialty;

            cout << "Nome: ";
            cin >> name;

            cout << "Email: ";
            cin >> email;

            cout << "Password: ";
            cin >> pass;

            cout << "Especialidade: ";
            cin >> specialty;

            try {
                Instructor i(name, "TEMP", email, pass, specialty);
                instructorService.add(i);

                cout << "SUCESSO: Instrutor registado!" << endl;
            }
            catch (exception& e) {
                cout << "ERRO: " << e.what() << endl;
            }
        }
        else if (opt == 4) {
            auto lista = instructorService.getAll();

            cout << "\n--- LISTAGEM DE INSTRUTORES ---" << endl;

            for (Instructor* i : lista) {
                cout << "Nome: "
                     << i->getName()
                     << " | Email: "
                     << i->getEmail()
                     << " | Especialidade: "
                     << i->getSpecialty()
                     << endl;
            }
        }
        else if (opt == 5) {
            string name, description, minimumLevel;

            cout << "Nome: ";
            cin >> name;

            cout << "Descricao: ";
            cin >> description;

            cout << "Nivel Minimo: ";
            cin >> minimumLevel;

            try {
                Modality m(name, description, minimumLevel);
                modalityService.add(m);

                cout << "SUCESSO: Modalidade criada!" << endl;
            }
            catch (exception& e) {
                cout << "ERRO: " << e.what() << endl;
            }
        }
        else if (opt == 6) {
            auto lista = modalityService.getAll();

            cout << "\n--- LISTAGEM DE MODALIDADES ---" << endl;

            for (Modality* m : lista) {
                cout << "Nome: "
                     << m->getName()
                     << " | Descricao: "
                     << m->getDescription()
                     << " | Nivel Minimo: "
                     << m->getMinimumLevel()
                     << endl;
            }
        }
    }
}

void menuInstructor() {
    cout << "\nem desenvolvimento" << endl;
}

void menuAthlete() {
    cout << "\nem desenvolvimento" << endl;
}