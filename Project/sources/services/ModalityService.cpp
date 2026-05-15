#include "../../headers/services/ModalityService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void ModalityService::add(const Modality& modality) {

    Gym* model = GymRepositoryMemory::getModel();

    model->getModalityContainer().add(modality);
}

list<Modality*> ModalityService::getAll() {

    Gym* model = GymRepositoryMemory::getModel();

    return model->getModalityContainer().getAll();
}