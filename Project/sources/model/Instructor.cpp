#include "../../headers/model/Instructor.h"

Instructor::Instructor(const string& name,
                       const string& userId,
                       const string& email,
                       const string& password,
                       const string& specialty)

        : User(name, userId, email, password) {

    this->specialty = specialty;
}

string Instructor::getSpecialty() const {
    return specialty;
}