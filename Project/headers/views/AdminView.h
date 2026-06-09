#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include "../controllers/AthleteController.h"
#include "../controllers/InstructorController.h"
#include "../controllers/RoomController.h"
#include "../controllers/ModalityController.h"
#include "../controllers/ClassSessionController.h"
#include "../controllers/ClassEnrollmentController.h"

class AdminView {
private:
    AthleteController athleteController;
    InstructorController instructorController;
    ModalityController modalityController;
    RoomController roomController;
    ClassSessionController classSessionController;
    ClassEnrollmentController classEnrollmentController;

public:
    void showMenu();
};

#endif