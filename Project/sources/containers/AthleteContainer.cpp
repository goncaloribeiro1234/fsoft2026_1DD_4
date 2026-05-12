#include "../../headers/containers/AthleteContainer.h"

void AthleteContainer::add(const Athlete& athlete) {

    athletes.push_back(new Athlete(athlete));
}

list<Athlete*> AthleteContainer::getAll() {
    return athletes;
}