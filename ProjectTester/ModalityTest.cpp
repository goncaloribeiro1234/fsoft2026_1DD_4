#include <cassert>
#include "../Project/headers/model/Modality.h"

int main() {

    Modality modality(
            "Boxe",
            "Desporto de combate"
    );

    assert(modality.getName() == "Boxe");
    assert(modality.getDescription() == "Desporto de combate");

    return 0;
}