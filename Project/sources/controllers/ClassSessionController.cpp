#include "../../headers/controllers/ClassSessionController.h"
#include "../../headers/exceptions/InvalidDataException.h"

void ClassSessionController::createClassSession(
        const string& modality,
        const string& instructor,
        const string& room,
        const string& date,
        const string& startTime,
        const string& endTime,
        int duration) {

    if(classSessionService.hasRoomConflict(
            room,
            date,
            startTime,
            endTime)) {

        throw InvalidDataException(
                "Room already occupied at this time."
        );
            }

    if(classSessionService.hasInstructorConflict(
            instructor,
            date,
            startTime,
            endTime)) {

        throw InvalidDataException(
                "Instructor already has a class at this time."
        );
            }

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