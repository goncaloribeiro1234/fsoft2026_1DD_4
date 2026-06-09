#include "../../headers/repo/GymRepositoryMemory.h"
#include "../../headers/model/Modality.h"

Gym* GymRepositoryMemory::model = nullptr;

Gym* GymRepositoryMemory::getModel() {
    if (model == nullptr) {
        model = new Gym("ISEP Gym", "Porto");
        model->getModalityContainer().add(Modality("Boxe", "Desporto de combate", "Iniciante"));
        model->getModalityContainer().add(Modality("Muay Thai", "Artes Marciais", "Intermédio"));
        model->getModalityContainer().add(Modality("Jiu-Jitsu", "Artes Marciais", "Intermédio"));
    }
    return model;
}