#include "../../headers/services/AthleteService.h"
#include "../../headers/repo/GymRepositoryMemory.h"
#include <stdexcept>

using namespace std;

void AthleteService::add(const Athlete& athlete) {
    Gym* model = GymRepositoryMemory::getModel();
    model->getAthleteContainer().add(athlete);
}

list<Athlete*> AthleteService::getAll() {
    Gym* model = GymRepositoryMemory::getModel();
    return model->getAthleteContainer().getAll();
}

Athlete* AthleteService::authenticate(const string& email, const string& password) {
    Gym* model = GymRepositoryMemory::getModel();

    for (auto a : model->getAthleteContainer().getAll()) {
        if (a->getEmail() == email && a->getPassword() == password) {
            return a;
        }
    }
    throw invalid_argument("Credenciais invalidas. Email ou password incorretos.");
}