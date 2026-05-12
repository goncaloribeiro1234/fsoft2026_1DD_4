#include <iostream>

#include "headers/model/Athlete.h"

using namespace std;

int main() {

    try {

        Athlete athlete(
                "Gustavo",
                "A1",
                "gustavo@gmail.com",
                "1234",
                "Intermediate"
        );

        cout << athlete.getName() << endl;
    }
    catch(exception& e) {

        cout << e.what() << endl;
    }

    return 0;
}