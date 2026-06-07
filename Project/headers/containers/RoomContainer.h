#ifndef ROOMCONTAINER_H
#define ROOMCONTAINER_H

#include <list>
#include <string>
#include "../model/Room.h"

using namespace std;

class RoomContainer {
private:
    list<Room*> rooms;

public:
    ~RoomContainer();
    void addRoom(Room* room);
    Room* findByName(const string& name);
    list<Room*> getAllRooms() const;

};

#endif