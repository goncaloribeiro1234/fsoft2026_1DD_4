#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include <string>
#include "../services/RoomService.h"
#include <list>

using namespace std;

class RoomController {
private:
    RoomService roomService;

public:
    void addRoom(const string& name, int capacity);
    list<Room*> findAllRooms();
};

#endif