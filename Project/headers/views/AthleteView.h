#ifndef ATHLETEVIEW_H
#define ATHLETEVIEW_H

#include "../controllers/AthleteController.h"
#include "../controllers/ClassSessionController.h"
#include "../controllers/ClassEnrollmentController.h"

class AthleteView {
private:
    AthleteController athleteController;
    ClassSessionController classSessionController;
    ClassEnrollmentController classEnrollmentController;

public:
    void showMenu();
};

#endif