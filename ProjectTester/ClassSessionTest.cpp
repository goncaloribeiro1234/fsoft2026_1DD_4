#include <cassert>
#include "../Project/headers/model/ClassSession.h"

int main() {

    ClassSession session(
            "Boxe",
            "Joao Silva",
            "Sala A",
            "20/06/2026",
            "13:00",
            "14:00",
            "Iniciante"
    );

    assert(session.getModality() == "Boxe");
    assert(session.getInstructor() == "Joao Silva");
    assert(session.getRoom() == "Sala A");

    assert(session.getduration() == 60);

    return 0;
}