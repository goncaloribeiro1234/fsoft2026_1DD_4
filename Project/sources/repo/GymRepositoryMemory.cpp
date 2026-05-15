#include "../../headers/repo/GymRepositoryMemory.h"

Gym* GymRepositoryMemory::model = nullptr;

Gym* GymRepositoryMemory::getModel() {
    if (model == nullptr) {
        model = new Gym("ISEP Gym", "Porto");
    }
    return model;
}