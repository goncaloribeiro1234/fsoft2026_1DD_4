#include <cassert>
#include "../Project/headers/model/Athlete.h"

int main() {

    Athlete athlete(
            "Serena",
            "ATL001",
            "serena@gmail.com",
            "1234",
            "Iniciante"
    );

    assert(athlete.getName() == "Serena");
    assert(athlete.getEmail() == "serena@gmail.com");
    assert(athlete.getTechnicalLevel() == "Iniciante");

    return 0;
}