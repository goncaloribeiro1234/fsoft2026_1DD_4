#ifndef CLASSSESSIONSERVICE_H
#define CLASSSESSIONSERVICE_H

#include <list>

#include "../model/ClassSession.h"

using namespace std;

class ClassSessionService {
public:

    void add(const ClassSession& session);

    list<ClassSession*> getAll();

    bool hasRoomConflict(
            const string& room,
            const string& date,
            const string& startTime,
            const string& endTime
    );

    bool hasInstructorConflict(
            const string& instructor,
            const string& date,
            const string& startTime,
            const string& endTime
    );
};

#endif