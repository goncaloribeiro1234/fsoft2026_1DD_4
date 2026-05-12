#include "../../headers/model/User.h"
#include "../../headers/exceptions/InvalidDataException.h"

User::User(const string& name,
           const string& userId,
           const string& email,
           const string& password) {

    setName(name);

    this->userId = userId;
    this->email = email;
    this->password = password;
}

bool User::isNameValid(const string& name) {
    return name.length() >= 3;
}

void User::setName(const string& name) {

    if(isNameValid(name)) {
        this->name = name;
    }
    else {
        throw InvalidDataException("Invalid user name.");
    }
}

string User::getName() const {
    return name;
}