#include "../../headers/controllers/AthleteController.h"

void AthleteController::addAthlete(const string& name, const string& email, const string& password, const string& level) {
    Athlete a(name, "TEMP", email, password, level);
    athleteService.add(a);
}

list<Athlete*> AthleteController::findAllAthletes() {
    return athleteService.getAll();
}

Athlete* AthleteController::login(const string& email, const string& password) {
    return athleteService.authenticate(email, password);
}