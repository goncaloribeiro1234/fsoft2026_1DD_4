#ifndef INSTRUCTORVIEW_H
#define INSTRUCTORVIEW_H

#include "../controllers/ModalityController.h"
#include "../controllers/InstructorController.h"
#include "../controllers/RoomController.h"
#include "../controllers/ClassSessionController.h"
#include "../controllers/ClassEnrollmentController.h"
#include "../model/Instructor.h"
#include "../controllers/AthleteController.h"


class InstructorView {
private:
    ModalityController modalityController;
    InstructorController instructorController;
    RoomController roomController;
    ClassSessionController classSessionController;
    ClassEnrollmentController classEnrollmentController;
    AthleteController athleteController;

public:
    void showMenu(Instructor* loggedInInstructor);
};

#endif