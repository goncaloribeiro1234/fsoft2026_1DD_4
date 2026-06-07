#ifndef ROOMSERVICE_H
#define ROOMSERVICE_H

#include "../containers/RoomContainer.h"
#include "../model/Room.h"
#include <stdexcept>
#include <string>

class RoomService {
public:
    void add(const Room& room);
    list<Room*> getAll();
};

#endif