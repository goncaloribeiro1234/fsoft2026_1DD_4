#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room {
private:
    string name;
    int capacity;

public:
    Room(const string& name, int capacity);

    string getName() const;
    int getCapacity() const;
};

#endif //ROOM_H