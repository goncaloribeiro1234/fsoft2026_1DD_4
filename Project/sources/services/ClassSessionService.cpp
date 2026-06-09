#include "../../headers/services/ClassSessionService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void ClassSessionService::add(const ClassSession& session) {

    Gym* model = GymRepositoryMemory::getModel();

    model->getClassSessionContainer().add(session);
}

list<ClassSession*> ClassSessionService::getAll() {

    Gym* model = GymRepositoryMemory::getModel();

    return model->getClassSessionContainer().getAll();
}