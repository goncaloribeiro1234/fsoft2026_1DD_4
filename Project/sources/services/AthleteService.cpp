#include "../../headers/services/AthleteService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void AthleteService::add(const Athlete& athlete) {
    Gym* model = GymRepositoryMemory::getModel();
    model->getAthleteContainer().add(athlete);
}

list<Athlete*> AthleteService::getAll() {
    Gym* model = GymRepositoryMemory::getModel();
    return model->getAthleteContainer().getAll();
}