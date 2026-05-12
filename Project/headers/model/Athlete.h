#ifndef ATHLETE_H
#define ATHLETE_H

#include "User.h"

class Athlete : public User {
private:
    string technicalLevel;

public:
    Athlete(const string& name,
            const string& userId,
            const string& email,
            const string& password,
            const string& technicalLevel);

    string getTechnicalLevel() const;
};

#endif