#ifndef CLASSENROLLMENTCONTROLLER_H
#define CLASSENROLLMENTCONTROLLER_H

#include "../services/ClassEnrollmentService.h"

class ClassEnrollmentController {
private:
    ClassEnrollmentService classEnrollmentService;

public:

    void enrollAthlete(
            const string& athleteName,
            const string& modality,
            const string& classDate,
            const string& startTime,
            const string& endTime,
            const string& room
    );

    list<ClassEnrollment*> findAllEnrollments();
};

#endif