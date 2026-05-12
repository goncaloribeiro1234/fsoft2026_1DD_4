#include "../../headers/services/AthleteService.h"

void AthleteService::add(const Athlete& athlete) {

    container.add(athlete);
}

list<Athlete*> AthleteService::getAll() {

    return container.getAll();
}