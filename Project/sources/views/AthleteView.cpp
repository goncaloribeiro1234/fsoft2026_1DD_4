#include "../../headers/views/AthleteView.h"
#include <iostream>
#include <vector>

using namespace std;

void AthleteView::showMenu(Athlete* loggedInAthlete) {
    int opt = -1;

    while (opt != 0) {
        cout << "\n--- MENU ATLETA ---" << endl;
        cout << "Sessao: " << loggedInAthlete->getName() << endl;
        cout << "1. Inscrever em Aula" << endl;
        cout << "2. Cancelar Inscricao em Aula" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opt;

        if (opt == 1) {
            auto sessions = classSessionController.findAllSessions();
            if(sessions.empty()) {
                cout << "Nao existem aulas criadas." << endl;
                continue;
            }

            cout << "\n--- INSCRICAO EM AULA ---" << endl;
            string athleteName = loggedInAthlete->getName();

            vector<ClassSession*> sessionList;
            int index = 1;
            cout << "\nSelecione a Aula:" << endl;
            for(auto s : sessions) {
                cout << index << ". " << s->getModality() << " - "
                     << s->getDate() << " " << s->getStartTime() << " - " << s->getEndTime() << endl;
                sessionList.push_back(s);
                index++;
            }

            int sessionChoice;
            cout << "Opcao: "; cin >> sessionChoice;

            if (sessionChoice < 1 || sessionChoice > sessionList.size()) {
                cout << "Opcao invalida." << endl;
                continue;
            }
            ClassSession* selectedSession = sessionList[sessionChoice - 1];

            try {
                classEnrollmentController.enrollAthlete(
                        athleteName,
                        selectedSession->getModality(),
                        selectedSession->getDate(),
                        selectedSession->getStartTime(),
                        selectedSession->getEndTime(),
                        selectedSession->getRoom()
                );
                cout << "\nSUCESSO: Inscricao criada!" << endl;
            } catch(exception& e) {
                cout << "\nERRO: " << e.what() << endl;
            }
        }
        else if (opt == 2) {
            auto enrollments = classEnrollmentController.findAllEnrollments();
            cout << "\n--- CANCELAR INSCRIÇÃO ---" << endl;

            vector<ClassEnrollment*> myEnrollments;
            int index = 1;
            for(auto e : enrollments) {
                if(e->getAthleteName() == loggedInAthlete->getName()) {
                    cout << index << ". " << e->getModality() << " em " << e->getClassDate() << " as " << e->getStartTime() << endl;
                    myEnrollments.push_back(e);
                    index++;
                }
            }

            if(myEnrollments.empty()) {
                cout << "Nao se encontra inscrito em nenhuma aula por agora." << endl;
                continue;
            }

            cout << "Selecione o numero da inscricao a anular: ";
            int choice; cin >> choice;
            if(choice > 0 && choice <= myEnrollments.size()) {
                auto e = myEnrollments[choice - 1];
                try {
                    classEnrollmentController.cancelEnrollment(loggedInAthlete->getName(), e->getModality(), e->getClassDate(), e->getStartTime());
                    cout << "SUCESSO: Lugar libertado na aula com sucesso!" << endl;
                } catch(exception& ex) {
                    cout << "ERRO: " << ex.what() << endl;
                }
            }
        }
    }
}