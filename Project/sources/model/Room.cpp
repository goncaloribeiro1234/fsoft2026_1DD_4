#include "../../headers/model/Room.h"

Room::Room(const string& name, int capacity) {
    this->name = name;
    this->capacity = capacity;
}

string Room::getName() const {
    return name;
}

int Room::getCapacity() const {
    return capacity;
}