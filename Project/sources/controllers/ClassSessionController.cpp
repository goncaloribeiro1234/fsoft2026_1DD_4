#include "../../headers/controllers/ClassSessionController.h"

void ClassSessionController::createClassSession(
        const string& modality,
        const string& instructor,
        const string& room,
        const string& date,
        const string& startTime,
        const string& endTime,
        int duration) {

    ClassSession session(
            modality,
            instructor,
            room,
            date,
            startTime,
            endTime,
            duration
    );

    classSessionService.add(session);
}

list<ClassSession*> ClassSessionController::findAllSessions() {

    return classSessionService.getAll();
}