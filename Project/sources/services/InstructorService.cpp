#include "../../headers/services/InstructorService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void InstructorService::add(const Instructor& instructor) {

    Gym* model = GymRepositoryMemory::getModel();

    model->getInstructorContainer().add(instructor);
}

list<Instructor*> InstructorService::getAll() {

    Gym* model = GymRepositoryMemory::getModel();

    return model->getInstructorContainer().getAll();
}