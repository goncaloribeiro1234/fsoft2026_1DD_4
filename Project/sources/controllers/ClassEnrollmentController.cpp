#include "../../headers/controllers/ClassEnrollmentController.h"
#include "../../headers/exceptions/InvalidDataException.h"

void ClassEnrollmentController::enrollAthlete(
        const string& athleteName,
        const string& modality,
        const string& classDate,
        const string& startTime,
        const string& endTime,
        const string& room) {

    if(classEnrollmentService.isAlreadyEnrolled(athleteName, modality, classDate)) {
        throw InvalidDataException("Athlete already enrolled in this class.");
    }

    ClassEnrollment enrollment(athleteName, modality, classDate, startTime, endTime, room);
    classEnrollmentService.add(enrollment);
}

list<ClassEnrollment*> ClassEnrollmentController::findAllEnrollments() {
    return classEnrollmentService.getAll();
}

void ClassEnrollmentController::cancelEnrollment(
        const string& athleteName,
        const string& modality,
        const string& date,
        const string& startTime) {
    classEnrollmentService.cancelEnrollment(athleteName, modality, date, startTime);
}