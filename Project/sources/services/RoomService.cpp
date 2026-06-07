#include "../../headers/services/RoomService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void RoomService::add(const Room& room) {
    if (room.getCapacity() <= 0) {
        throw invalid_argument("A capacidade da sala deve ser um valor positivo e valido.");
    }

    Gym* model = GymRepositoryMemory::getModel();

    if (model->getRoomContainer().findByName(room.getName()) != nullptr) {
        throw invalid_argument("Erro: Ja existe uma sala registada com esse nome");
    }

    Room* newRoom = new Room(room.getName(), room.getCapacity());
    model->getRoomContainer().addRoom(newRoom);
}

list<Room*> RoomService::getAll() {
    Gym* model = GymRepositoryMemory::getModel();
    return model->getRoomContainer().getAllRooms();
}