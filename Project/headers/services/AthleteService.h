#ifndef ATHLETESERVICE_H
#define ATHLETESERVICE_H

#include <list>

#include "../containers/AthleteContainer.h"

using namespace std;

class AthleteService {
private:
    AthleteContainer container;

public:
    void add(const Athlete& athlete);

    list<Athlete*> getAll();
};

#endif