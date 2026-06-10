#include "../../headers/views/AdminView.h"
#include <iostream>
#include <vector>

using namespace std;

void AdminView::showMenu() {
    int opt = -1;

    while (opt != 0) {
        cout << "\n--- MENU ADMINISTRADOR ---" << endl;
        cout << "1. Registar Atleta" << endl;
        cout << "2. Registar Instrutor" << endl;
        cout << "3. Criar Sala" << endl;
        cout << "4. Listar Todos os Atletas" << endl;
        cout << "5. Listar Todos os Instrutores" << endl;
        cout << "6. Listar Todas as Salas" << endl;
        cout << "7. Listar Modalidades" << endl;
        cout << "0. Voltar" << endl;

        cout << "Opcao: ";
        cin >> opt;

        if (opt == 1) {

            string name;
            string email;
            string pass;

            cout << "Nome: ";
            cin >> name;

            cout << "Email: ";
            cin >> email;

            cout << "Password: ";
            cin >> pass;

            try {

                athleteController.addAthlete(
                        name,
                        email,
                        pass,
                        "Sem Nivel"
                );

                cout << "SUCESSO: Atleta registado!" << endl;
            }
            catch(exception &e) {

                cout << "ERRO: "
                     << e.what()
                     << endl;
            }
        } else if (opt == 2) {
            string name;
            string email;
            string pass;
            string specialty;

            cout << "Nome do Instrutor: ";

            cin >> ws;
            getline(cin, name);

            cout << "Email: ";
            cin >> email;

            cout << "Password: ";
            cin >> pass;

            auto modalidades =
                    modalityController.findAllModalities();

            cout << "\nSelecione a Especialidade do Instrutor:" << endl;

            int index = 1;

            vector<string> modalityNames;

            for (auto m: modalidades) {
                cout
                        << index
                        << ". "
                        << m->getName()
                        << endl;

                modalityNames.push_back(
                    m->getName()
                );

                index++;
            }

            cout << "Opcao: ";

            int modChoice;
            cin >> modChoice;

            if (modChoice > 0 &&
                modChoice <= modalityNames.size()) {
                specialty =
                        modalityNames[
                            modChoice - 1
                        ];
            } else {
                cout << "Opcao invalida." << endl;
                specialty = "Indefinida";
            }

            try {
                instructorController.addInstructor(
                    name,
                    email,
                    pass,
                    specialty
                );

                cout
                        << "SUCESSO: Instrutor de "
                        << specialty
                        << " registado!"
                        << endl;
            } catch (exception &e) {
                cout
                        << "ERRO: "
                        << e.what()
                        << endl;
            }
        } else if (opt == 3)
        {
            string name;
            int capacity;

            cout << "Nome/Identificador da Sala: ";

            cin >> ws;
            getline(cin, name);

            cout << "Capacidade maxima de alunos: ";
            cin >> capacity;

            try {
                roomController.addRoom(
                    name,
                    capacity
                );

                cout << "SUCESSO: Sala criada!" << endl;
            } catch (exception &e) {
                cout
                        << "ERRO: "
                        << e.what()
                        << endl;
            }
        } else if (opt == 4) {
            auto atletas =
                    athleteController.findAllAthletes();

            cout
                    << "\n--- LISTAGEM DE ATLETAS ---"
                    << endl;

            if (atletas.empty()) {
                cout
                        << "Ainda nao ha atletas registados."
                        << endl;
            }

            for (auto a: atletas) {
                cout
                        << "Nome: "
                        << a->getName()

                        << " | Email: "
                        << a->getEmail()

                        << endl;
            }
        } else if (opt == 5) {
            auto instrutores =
                    instructorController.findAllInstructors();

            cout
                    << "\n--- LISTAGEM DE INSTRUTORES ---"
                    << endl;

            if (instrutores.empty()) {
                cout
                        << "Ainda nao ha instrutores registados."
                        << endl;
            }

            for (auto i: instrutores) {
                cout
                        << "Nome: "
                        << i->getName()

                        << " | Especialidade: "
                        << i->getSpecialty()

                        << endl;
            }
        } else if (opt == 6) {
            auto salas =
                    roomController.findAllRooms();

            cout
                    << "\n--- LISTAGEM DE SALAS ---"
                    << endl;

            if (salas.empty()) {
                cout
                        << "Ainda nao ha salas registadas."
                        << endl;
            }

            for (auto r: salas) {
                cout
                        << "Sala: "
                        << r->getName()

                        << " | Lotacao: "
                        << r->getCapacity()

                        << " pessoas"
                        << endl;
            }
        } else if (opt == 7) {
            auto modalidades =
                    modalityController.findAllModalities();

            cout
                    << "\n--- LISTAGEM DE MODALIDADES ---"
                    << endl;

            if (modalidades.empty()) {
                cout
                        << "Ainda nao ha modalidades registadas."
                        << endl;
            }

            for (auto m: modalidades) {
                cout
                        << "Nome: "
                        << m->getName()

                        << " | Descricao: "
                        << m->getDescription()

                        << endl;
            }
        }
    }
}
