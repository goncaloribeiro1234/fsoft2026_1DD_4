#include "../../headers/controllers/InstructorController.h"

void InstructorController::addInstructor(const string& name, const string& email, const string& password, const string& specialty) {
    Instructor i(name, "TEMP", email, password, specialty);
    instructorService.add(i);
}

list<Instructor*> InstructorController::findAllInstructors() {
    return instructorService.getAll();
}

Instructor* InstructorController::login(const string& email, const string& password) {
    return instructorService.authenticate(email, password);
}