#ifndef ATHLETECONTROLLER_H
#define ATHLETECONTROLLER_H

#include <string>
#include <list>
#include "../services/AthleteService.h"

using namespace std;

class AthleteController {
private:
    AthleteService athleteService;

public:
    void addAthlete(const string& name, const string& email, const string& password, const string& level);
    list<Athlete*> findAllAthletes();

    Athlete* login(const string& email, const string& password);
};

#endif