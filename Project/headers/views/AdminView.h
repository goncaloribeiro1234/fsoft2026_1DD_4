#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include "../controllers/AthleteController.h"
#include "../controllers/InstructorController.h"
#include "../controllers/RoomController.h"
#include "../controllers/ModalityController.h"
#include "../controllers/ClassSessionController.h"
#include "../controllers/ClassEnrollmentController.h"
#include "../controllers/PaymentController.h"

class AdminView {
private:
    AthleteController athleteController;
    InstructorController instructorController;
    ModalityController modalityController;
    RoomController roomController;
    ClassSessionController classSessionController;
    ClassEnrollmentController classEnrollmentController;
    PaymentController paymentController;

public:
    void showMenu();
};

#endif