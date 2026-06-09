#include "../../headers/services/ClassEnrollmentService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void ClassEnrollmentService::add(
        const ClassEnrollment& enrollment) {

    Gym* model =
            GymRepositoryMemory::getModel();

    model->getClassEnrollmentContainer()
            .add(enrollment);
}

list<ClassEnrollment*> ClassEnrollmentService::getAll() {

    Gym* model =
            GymRepositoryMemory::getModel();

    return model
            ->getClassEnrollmentContainer()
            .getAll();
}

bool ClassEnrollmentService::isAlreadyEnrolled(
        const string& athleteName,
        const string& modality,
        const string& classDate) {

    auto enrollments = getAll();

    for(auto e : enrollments) {

        if(e->getAthleteName() == athleteName &&
           e->getModality() == modality &&
           e->getClassDate() == classDate) {

            return true;
           }
    }

    return false;
}