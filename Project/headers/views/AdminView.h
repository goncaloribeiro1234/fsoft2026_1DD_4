#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include "../controllers/AthleteController.h"

class AdminView {
private:
    AthleteController athleteController;
    //InstructorController instructorController;
    //ModalityController modalityController;

public:
    void showMenu();
};

#endif