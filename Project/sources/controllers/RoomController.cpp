#include "../../headers/controllers/RoomController.h"

void RoomController::addRoom(const string& name, int capacity) {
    if (capacity <= 0) {
        throw invalid_argument("A capacidade da sala deve ser um valor positivo.");
    }
    Room r(name, capacity);
    roomService.add(r);
}

list<Room*> RoomController::findAllRooms() {
    return roomService.getAll();
}