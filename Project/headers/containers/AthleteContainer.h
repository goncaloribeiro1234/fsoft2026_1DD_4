#ifndef ATHLETECONTAINER_H
#define ATHLETECONTAINER_H

#include <list>

#include "../model/Athlete.h"

using namespace std;

class AthleteContainer {
private:
    list<Athlete*> athletes;

public:
    void add(const Athlete& athlete);

    list<Athlete*> getAll();
};

#endif