#include "../../headers/repo/GymRepositoryMemory.h"
#include "../../headers/model/Modality.h"

Gym* GymRepositoryMemory::model = nullptr;

Gym* GymRepositoryMemory::getModel() {
    if (model == nullptr) {
        model = new Gym("ISEP Gym", "Porto");
        model->getModalityContainer().add(Modality("Boxe", "Desporto de combate", "Sem requisitos"));
        model->getModalityContainer().add(Modality("Muay Thai", "Artes Marciais", "Sem requisitos"));
        model->getModalityContainer().add(Modality("Jiu-Jitsu", "Artes Marciais", "Sem requisitos"));
    }
    return model;
}