#include "../../headers/model/Athlete.h"

Athlete::Athlete(const string& name,
                 const string& userId,
                 const string& email,
                 const string& password,
                 const string& technicalLevel)

        : User(name, userId, email, password) {

    this->technicalLevel = technicalLevel;
}

string Athlete::getTechnicalLevel() const {
    return technicalLevel;
}

void Athlete::setTechnicalLevel(const string& level) {
    this->technicalLevel = level;
}