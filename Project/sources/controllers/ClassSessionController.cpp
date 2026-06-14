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

    if(classSessionService.hasRoomConflict(room, date, startTime, endTime)) {
        throw InvalidDataException("Sala já ocupada neste momento.");
    }

    if(classSessionService.hasInstructorConflict(instructor, date, startTime, endTime)) {
        throw InvalidDataException("O instrutor já tem uma aula neste horário.");
    }

    ClassSession session(modality, instructor, room, date, startTime, endTime, minTechnicalLevel);
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
    classSessionService.cancelSession(modality, date, startTime, room);
}