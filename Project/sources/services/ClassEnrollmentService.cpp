#include "../../headers/services/ClassEnrollmentService.h"
#include "../../headers/repo/GymRepositoryMemory.h"
#include <stdexcept>

void ClassEnrollmentService::add(const ClassEnrollment& enrollment) {
    Gym* model = GymRepositoryMemory::getModel();
    model->getClassEnrollmentContainer().add(enrollment);
}

list<ClassEnrollment*> ClassEnrollmentService::getAll() {
    Gym* model = GymRepositoryMemory::getModel();
    return model->getClassEnrollmentContainer().getAll();
}

bool ClassEnrollmentService::isAlreadyEnrolled(const string& athleteName, const string& modality, const string& classDate) {
    auto enrollments = getAll();
    for(auto e : enrollments) {
        if(e->getAthleteName() == athleteName && e->getModality() == modality && e->getClassDate() == classDate) {
            return true;
        }
    }
    return false;
}

void ClassEnrollmentService::cancelEnrollment(const string& athleteName, const string& modality, const string& date, const string& startTime) {
    Gym* model = GymRepositoryMemory::getModel();
    auto enrollments = getAll();

    ClassEnrollment* toDelete = nullptr;
    for (auto e : enrollments) {
        if (e->getAthleteName() == athleteName && e->getModality() == modality &&
            e->getClassDate() == date && e->getStartTime() == startTime) {
            toDelete = e;
            break;
            }
    }

    if (toDelete) {
        model->getClassEnrollmentContainer().remove(toDelete);
        delete toDelete;
    } else {
        throw invalid_argument("Inscricao nao encontrada.");
    }
}