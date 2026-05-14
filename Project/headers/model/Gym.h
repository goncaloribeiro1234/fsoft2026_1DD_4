#ifndef GYM_H
#define GYM_H

#include <string>
#include "../containers/AthleteContainer.h"

class Gym {
private:
    string name;
    AthleteContainer athleteContainer;

public:
    Gym(const string& name) : name(name) {}
    AthleteContainer& getAthleteContainer() { return athleteContainer; }
};

#endif