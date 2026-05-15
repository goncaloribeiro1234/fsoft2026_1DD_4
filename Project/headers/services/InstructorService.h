#ifndef INSTRUCTORSERVICE_H
#define INSTRUCTORSERVICE_H

#include <list>
#include "../model/Instructor.h"

using namespace std;

class InstructorService {
public:
    void add(const Instructor& instructor);

    list<Instructor*> getAll();
};

#endif