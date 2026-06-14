#include "../../headers/views/InstructorView.h"
#include <iostream>
#include <vector>

using namespace std;

void InstructorView::showMenu(Instructor* loggedInInstructor) {
    int opt = -1;

    while (opt != 0) {
        cout << "\n--- MENU INSTRUTOR ---" << endl;
        cout << "Sessao: " << loggedInInstructor->getName()
             << " (" << loggedInInstructor->getSpecialty() << ")" << endl;
        cout << "1. Criar Aula" << endl;
        cout << "2. Listar Aulas" << endl;
        cout << "3. Listar Inscricoes (Ver alunos)" << endl;
        cout << "4. Cancelar Aula" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opt;

        if (opt == 1) {
            string modality = loggedInInstructor->getSpecialty();
            string instructor = loggedInInstructor->getName();
            string room, date, startTime, endTime;

            cout << "\n--- AGENDAR NOVA AULA DE " << modality << " ---" << endl;
            cout << "Introduza a Data (DD/MM/AAAA): "; cin >> date;

            auto salas = roomController.findAllRooms();
            if(salas.empty()) {
                cout << "ERRO: Nao existem salas criadas no sistema. Contacte o Admin." << endl;
                continue;
            }

            cout << "\nSelecione a Sala Pretendida:" << endl;
            vector<string> roomNames;
            int index = 1;
            for (auto r: salas) {
                cout << index << ". " << r->getName() << " (" << r->getCapacity() << " pessoas)" << endl;
                roomNames.push_back(r->getName());
                index++;
            }
            int roomChoice;
            cout << "Opcao: "; cin >> roomChoice;
            if(roomChoice < 1 || roomChoice > roomNames.size()) {
                cout << "Opcao invalida." << endl;
                continue;
            }
            room = roomNames[roomChoice - 1];

            auto sessions = classSessionController.findAllSessions();
            cout << "\n==============================================" << endl;
            cout << "SITUACAO DA SALA [" << room << "] NO DIA " << date << ":" << endl;
            bool roomHasClasses = false;
            for(auto s : sessions) {
                if(s->getDate() == date && s->getRoom() == room) {
                    cout << "   -> OCUPADO: " << s->getStartTime() << " ate " << s->getEndTime()
                         << " (" << s->getModality() << " - Prof. " << s->getInstructor() << ")" << endl;
                    roomHasClasses = true;
                }
            }
            if(!roomHasClasses) cout << "   (Esta sala esta totalmente livre para este dia!)" << endl;

            cout << "\nO SEU HORARIO PESSOAL NO DIA " << date << ":" << endl;
            bool instHasClasses = false;
            for(auto s : sessions) {
                if(s->getDate() == date && s->getInstructor() == instructor) {
                    cout << "   -> INDISPONIVEL: " << s->getStartTime() << " ate " << s->getEndTime()
                         << " (Sala: " << s->getRoom() << ")" << endl;
                    instHasClasses = true;
                }
            }
            if(!instHasClasses) cout << "   (O seu horario esta totalmente livre para este dia!)" << endl;
            cout << "==============================================" << endl;

            cout << "\nIntroduza um horario livre:" << endl;
            cout << "Hora Inicio (HH:MM): "; cin >> startTime;
            cout << "Hora Fim (HH:MM): "; cin >> endTime;

            try {
                classSessionController.createClassSession(modality, instructor, room, date, startTime, endTime);
                cout << "\nSUCESSO: Aula agendada com toda a informacao consistente!" << endl;
            } catch(exception& e) {
                cout << "\nERRO: " << e.what() << endl;
            }
        }
        else if (opt == 2) {
            auto sessions = classSessionController.findAllSessions();
            cout << "\n--- LISTAGEM DE AULAS ---" << endl;
            if(sessions.empty()) cout << "Ainda nao ha aulas criadas." << endl;

            for(auto s : sessions) {
                cout << "\nModalidade: " << s->getModality()
                     << "\nInstrutor: " << s->getInstructor()
                     << "\nSala: " << s->getRoom()
                     << "\nData: " << s->getDate()
                     << "\nHora Inicio: " << s->getStartTime()
                     << "\nHora Fim: " << s->getEndTime()
                     << "\nDuracao: " << s->getduration() << " minutos\n";
            }
        }
        else if (opt == 3) {
            auto enrollments = classEnrollmentController.findAllEnrollments();
            cout << "\n--- LISTAGEM DE INSCRICOES ---" << endl;
            if(enrollments.empty()) cout << "Nao existem inscricoes." << endl;

            for(auto e : enrollments) {
                cout << "\nAtleta: " << e->getAthleteName()
                     << "\nModalidade: " << e->getModality()
                     << "\nData: " << e->getClassDate()
                     << "\nHora Inicio: " << e->getStartTime()
                     << "\nHora Fim: " << e->getEndTime() << endl;
            }
        }
        else if (opt == 4) {
            auto sessions = classSessionController.findAllSessions();
            if(sessions.empty()) {
                cout << "Nao existem aulas agendadas." << endl;
                continue;
            }

            cout << "\n--- CANCELAR AULA ---" << endl;
            vector<ClassSession*> sessionList;
            int index = 1;
            for(auto s : sessions) {
                if(s->getInstructor() == loggedInInstructor->getName()) {
                    cout << index << ". " << s->getModality() << " - " << s->getDate() << " as " << s->getStartTime() << " (Sala: " << s->getRoom() << ")" << endl;
                    sessionList.push_back(s);
                    index++;
                }
            }

            if(sessionList.empty()) {
                cout << "Nao tem nenhuma aula agendada em seu nome." << endl;
                continue;
            }

            cout << "Selecione a aula a cancelar (Numero): ";
            int choice; cin >> choice;

            if (choice > 0 && choice <= sessionList.size()) {
                ClassSession* s = sessionList[choice - 1];
                try {
                    classSessionController.cancelClassSession(s->getModality(), s->getDate(), s->getStartTime(), s->getRoom());
                    cout << "\nSUCESSO: Aula cancelada e atletas desvinculados!" << endl;
                } catch(exception& e) {
                    cout << "\nERRO: " << e.what() << endl;
                }
            }
        }
    }
}