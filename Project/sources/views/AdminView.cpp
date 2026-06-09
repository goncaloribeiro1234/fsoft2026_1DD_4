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
        cout << "8. Criar Aula" << endl;
        cout << "9. Listar Aulas" << endl;
        cout << "10. Inscrever Atleta em Aula" << endl;
        cout << "11. Listar Inscricoes" << endl;
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
        } else if (opt == 8) {
            auto modalidades =
                    modalityController.findAllModalities();

            auto instrutores =
                    instructorController.findAllInstructors();

            auto salas =
                    roomController.findAllRooms();

            string modality;
            string instructor;
            string room;

            string date;
            string startTime;
            string endTime;

            cout << "\n--- CRIAR AULA ---" << endl;

            // MODALIDADES

            cout << "\nSelecione a Modalidade:" << endl;

            vector<string> modalityNames;

            int index = 1;

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

            int modChoice;

            cout << "Opcao: ";
            cin >> modChoice;

            if(modChoice < 1 || modChoice > modalityNames.size()) {
                cout << "Opcao invalida." << endl;
                continue;
            }

            modality =
                    modalityNames[modChoice - 1];

            // INSTRUTORES

            cout << "\nSelecione o Instrutor:" << endl;

            vector<string> instructorNames;

            index = 1;

            for (auto i: instrutores) {

                if(i->getSpecialty() == modality) {

                    cout << index << ". "
                         << i->getName()
                         << endl;

                    instructorNames.push_back(
                            i->getName()
                    );

                    index++;
                }
            }

            if(instructorNames.empty()) {

                cout << "\nNao existem instrutores para "
                     << modality
                     << endl;

                continue;
            }

            int instructorChoice;

            cout << "Opcao: ";
            cin >> instructorChoice;

            instructor =
                    instructorNames[
                        instructorChoice - 1
                    ];

            // SALAS

            cout << "\nSelecione a Sala:" << endl;

            vector<string> roomNames;

            index = 1;

            for (auto r: salas) {
                cout
                        << index
                        << ". "
                        << r->getName()

                        << " ("
                        << r->getCapacity()
                        << " pessoas)"

                        << endl;

                roomNames.push_back(
                    r->getName()
                );

                index++;
            }

            int roomChoice;

            cout << "Opcao: ";
            cin >> roomChoice;

            room =
                    roomNames[roomChoice - 1];

            // HORARIO

            cout << "\nData (DD/MM/AAAA): ";
            cin >> date;

            cout << "Hora Inicio (HH:MM): ";
            cin >> startTime;

            cout << "Hora Fim (HH:MM): ";
            cin >> endTime;

            try {

                classSessionController.createClassSession(
                        modality,
                        instructor,
                        room,
                        date,
                        startTime,
                        endTime
                );

                cout << "\nSUCESSO: Aula criada!" << endl;
            }
            catch(exception& e) {

                cout
                        << "\nERRO: "
                        << e.what()
                        << endl;
            }
        }
        else if (opt == 9) {

            auto sessions =
                    classSessionController.findAllSessions();

            cout
                    << "\n--- LISTAGEM DE AULAS ---"
                    << endl;

            if(sessions.empty()) {

                cout
                        << "Ainda nao ha aulas criadas."
                        << endl;
            }

            for(auto s : sessions) {

                cout
                        << "\nModalidade: "
                        << s->getModality()

                        << "\nInstrutor: "
                        << s->getInstructor()

                        << "\nSala: "
                        << s->getRoom()

                        << "\nData: "
                        << s->getDate()

                        << "\nHora Inicio: "
                        << s->getStartTime()

                        << "\nHora Fim: "
                        << s->getEndTime()

                        << "\nDuracao: "
                        << s->getduration()
                        << " minutos"

                        << endl;
            }
        }

        else if (opt == 10) {

            auto athletes =
                    athleteController.findAllAthletes();

            auto sessions =
                    classSessionController.findAllSessions();

            if(athletes.empty()) {

                cout << "Nao existem atletas registados."
                     << endl;

                continue;
            }

            if(sessions.empty()) {

                cout << "Nao existem aulas criadas."
                     << endl;

                continue;
            }

            cout << "\n--- INSCRICAO EM AULA ---"
                 << endl;

            vector<string> athleteNames;

            int index = 1;

            cout << "\nSelecione o Atleta:"
                 << endl;

            for(auto a : athletes) {

                cout << index
                     << ". "
                     << a->getName()
                     << endl;

                athleteNames.push_back(
                        a->getName()
                );

                index++;
            }

            int athleteChoice;

            cout << "Opcao: ";
            cin >> athleteChoice;

            string athleteName =
                    athleteNames[
                            athleteChoice - 1
                    ];

            vector<ClassSession*> sessionList;

            index = 1;

            cout << "\nSelecione a Aula:"
                 << endl;

            for(auto s : sessions) {

                cout
                        << index
                        << ". "
                        << s->getModality()

                        << " - "
                        << s->getDate()

                        << " "
                        << s->getStartTime()

                        << " - "
                        << s->getEndTime()

                        << endl;

                sessionList.push_back(s);

                index++;
            }

            int sessionChoice;

            cout << "Opcao: ";
            cin >> sessionChoice;

            ClassSession* selectedSession =
                    sessionList[
                            sessionChoice - 1
                    ];

            try {

                classEnrollmentController.enrollAthlete(
                        athleteName,
                        selectedSession->getModality(),
                        selectedSession->getDate(),
                        selectedSession->getStartTime(),
                        selectedSession->getEndTime(),
                        selectedSession->getRoom()
                );

                cout << "\nSUCESSO: Inscricao criada!"
                     << endl;
            }
            catch(exception& e) {

                cout << "\nERRO: "
                     << e.what()
                     << endl;
            }
        }

        else if (opt == 11) {

            auto enrollments =
                    classEnrollmentController
                            .findAllEnrollments();

            cout
                    << "\n--- LISTAGEM DE INSCRICOES ---"
                    << endl;

            if(enrollments.empty()) {

                cout
                        << "Nao existem inscricoes."
                        << endl;
            }

            for(auto e : enrollments) {

                cout
                        << "\nAtleta: "
                        << e->getAthleteName()

                        << "\nModalidade: "
                        << e->getModality()

                        << "\nData: "
                        << e->getClassDate()

                        << "\nHora Inicio: "
                        << e->getStartTime()

                        << "\nHora Fim: "
                        << e->getEndTime()

                        << endl;
            }
        }
    }
}
