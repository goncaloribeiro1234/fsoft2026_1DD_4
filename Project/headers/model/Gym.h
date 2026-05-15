#ifndef GYM_H
#define GYM_H

#include <string>

#include "../containers/AthleteContainer.h"
#include "../containers/InstructorContainer.h"
#include "../containers/ModalityContainer.h"
#include "../containers/RoomContainer.h"
#include "../containers/ClassSessionContainer.h"
#include "../containers/ClassEnrollmentContainer.h"

using namespace std;

class Gym {
private:
    string name;
    string location;

    AthleteContainer athleteContainer;
    InstructorContainer instructorContainer;
    ModalityContainer modalityContainer;

public:
    Gym(const string& name, const string& location);

    AthleteContainer& getAthleteContainer();
    InstructorContainer& getInstructorContainer();
    ModalityContainer& getModalityContainer();
};

#endif