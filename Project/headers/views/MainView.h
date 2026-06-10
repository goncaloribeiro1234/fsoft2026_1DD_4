#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "../controllers/AthleteController.h"
#include "../controllers/InstructorController.h"

class MainView {
private:
    AthleteController athleteController;
    InstructorController instructorController;

public:
    void show();
};

#endif