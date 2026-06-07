#include "../../headers/containers/RoomContainer.h"

RoomContainer::~RoomContainer() {
    for (auto r : rooms) {
        delete r;
    }
    rooms.clear();
}

void RoomContainer::addRoom(Room* room) {
    rooms.push_back(room);
}

Room* RoomContainer::findByName(const string& name) {
    for (auto r : rooms) {
        if (r->getName() == name) {
            return r;
        }
    }
    return nullptr;
}

list<Room*> RoomContainer::getAllRooms() const {
    return rooms;
}