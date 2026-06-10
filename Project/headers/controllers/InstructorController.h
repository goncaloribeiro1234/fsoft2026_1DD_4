#ifndef INSTRUCTORCONTROLLER_H
#define INSTRUCTORCONTROLLER_H

#include <string>
#include "../services/InstructorService.h"

using namespace std;

class InstructorController {
private:
    InstructorService instructorService;

public:
    void addInstructor(const string& name, const string& email, const string& password, const string& specialty);

    list<Instructor *> findAllInstructors();

    list<Instructor*> findAllAthletes();

    Instructor* login(const string& email, const string& password);
};

#endif