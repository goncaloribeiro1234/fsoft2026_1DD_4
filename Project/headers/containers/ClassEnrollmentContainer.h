#ifndef CLASSENROLLMENTCONTAINER_H
#define CLASSENROLLMENTCONTAINER_H

#include <list>

#include "../model/ClassEnrollment.h"

using namespace std;

class ClassEnrollmentContainer {
private:
    list<ClassEnrollment*> enrollments;

public:

    void add(const ClassEnrollment& enrollment);

    list<ClassEnrollment*> getAll();
};

#endif