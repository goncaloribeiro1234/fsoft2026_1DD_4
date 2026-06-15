#include <cassert>
#include "../Project/headers/model/Instructor.h"

int main() {

    Instructor instructor(
            "Joao Silva",
            "INS001",
            "joao@gym.pt",
            "1234",
            "Boxe"
    );

    assert(instructor.getName() == "Joao Silva");
    assert(instructor.getEmail() == "joao@gym.pt");
    assert(instructor.getSpecialty() == "Boxe");

    return 0;
}