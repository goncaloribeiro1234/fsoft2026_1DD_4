#include "../../headers/views/AthleteView.h"
#include <iostream>
#include <vector>

using namespace std;

void AthleteView::showMenu() {
    int opt = -1;

    while (opt != 0) {
        cout << "\n--- MENU ATLETA ---" << endl;
        cout << "1. Inscrever em Aula" << endl;
        cout << "0. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opt;

        if (opt == 1) {
            auto athletes = athleteController.findAllAthletes();
            auto sessions = classSessionController.findAllSessions();

            if(athletes.empty()) {
                cout << "Nao existem atletas registados." << endl;
                continue;
            }
            if(sessions.empty()) {
                cout << "Nao existem aulas criadas." << endl;
                continue;
            }

            cout << "\n--- INSCRICAO EM AULA ---" << endl;
            cout << "\nSelecione o Atleta que esta a usar o sistema:" << endl;
            
            vector<string> athleteNames;
            int index = 1;
            for(auto a : athletes) {
                cout << index << ". " << a->getName() << endl;
                athleteNames.push_back(a->getName());
                index++;
            }

            int athleteChoice;
            cout << "Opcao: "; cin >> athleteChoice;
            string athleteName = athleteNames[athleteChoice - 1];

            vector<ClassSession*> sessionList;
            index = 1;
            cout << "\nSelecione a Aula:" << endl;
            for(auto s : sessions) {
                cout << index << ". " << s->getModality() << " - " 
                     << s->getDate() << " " << s->getStartTime() << " - " << s->getEndTime() << endl;
                sessionList.push_back(s);
                index++;
            }

            int sessionChoice;
            cout << "Opcao: "; cin >> sessionChoice;
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
    }
}