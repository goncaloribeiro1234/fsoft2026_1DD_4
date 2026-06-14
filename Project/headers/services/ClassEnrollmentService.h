#ifndef CLASSENROLLMENTSERVICE_H
#define CLASSENROLLMENTSERVICE_H

#include <list>
#include <string>
#include "../model/ClassEnrollment.h"

using namespace std;

class ClassEnrollmentService {
public:
        void add(const ClassEnrollment& enrollment);

        list<ClassEnrollment*> getAll();

        bool isAlreadyEnrolled(
                const string& athleteName,
                const string& modality,
                const string& classDate
        );

        void cancelEnrollment(
                const string& athleteName,
                const string& modality,
                const string& date,
                const string& startTime
        );
};

#endif