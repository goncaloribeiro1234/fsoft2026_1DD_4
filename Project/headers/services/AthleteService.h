#ifndef ATHLETESERVICE_H
#define ATHLETESERVICE_H

#include <list>

#include "../containers/AthleteContainer.h"

using namespace std;

class AthleteService {
public:
    void add(const Athlete& athlete);

    list<Athlete*> getAll();

    Athlete* authenticate(const string& email, const string& password);
};

#endif