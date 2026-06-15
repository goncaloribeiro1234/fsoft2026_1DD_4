#include <cassert>
#include "../Project/headers/model/Room.h"

int main() {

    Room room("Sala A", 10);

    assert(room.getName() == "Sala A");
    assert(room.getCapacity() == 10);

    return 0;
}