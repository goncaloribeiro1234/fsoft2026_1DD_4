#include "../../headers/controllers/ClassSessionController.h"
#include "../../headers/exceptions/InvalidDataException.h"

void ClassSessionController::createClassSession(
        const string& modality,
        const string& instructor,
        const string& room,
        const string& date,
        const string& startTime,
        const string& endTime,
        const string& minTechnicalLevel) {

    // Horário do ginásio

    if(startTime < "07:00" || endTime > "22:00") {

        throw InvalidDataException(
                "Aula fora do horario de funcionamento do ginasio (07:00-22:00)."
        );
    }

    if(startTime >= endTime) {

        throw InvalidDataException(
                "A hora de fim deve ser posterior a hora de inicio."
        );
    }

    if(classSessionService.hasRoomConflict(
            room,
            date,
            startTime,
            endTime)) {

        throw InvalidDataException(
                "Sala ja ocupada neste momento."
        );
            }

    if(classSessionService.hasInstructorConflict(
            instructor,
            date,
            startTime,
            endTime)) {

        throw InvalidDataException(
                "O instrutor ja tem uma aula neste horario."
        );
            }

    ClassSession session(
            modality,
            instructor,
            room,
            date,
            startTime,
            endTime,
            minTechnicalLevel
    );

    classSessionService.add(session);
}

list<ClassSession*> ClassSessionController::findAllSessions() {

    return classSessionService.getAll();
}

void ClassSessionController::cancelClassSession(
        const string& modality,
        const string& date,
        const string& startTime,
        const string& room) {

    classSessionService.cancelSession(
            modality,
            date,
            startTime,
            room
    );
}