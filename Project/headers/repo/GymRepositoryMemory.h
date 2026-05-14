#ifndef GYMREPOSITORYMEMORY_H
#define GYMREPOSITORYMEMORY_H

#include "../model/Gym.h"

class GymRepositoryMemory {
private:
    static Gym* model;

public:
    static Gym* getModel();
};

#endif