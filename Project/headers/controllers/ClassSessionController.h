#ifndef CLASSSESSIONCONTROLLER_H
#define CLASSSESSIONCONTROLLER_H

#include "../services/ClassSessionService.h"

class ClassSessionController {
private:
    ClassSessionService classSessionService;

public:

    void createClassSession(
            const string& modality,
            const string& instructor,
            const string& room,
            const string& date,
            const string& startTime,
            const string& endTime,
            int duration
    );

    list<ClassSession*> findAllSessions();
};

#endif