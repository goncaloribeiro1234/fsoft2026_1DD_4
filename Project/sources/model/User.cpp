#include "../../headers/model/User.h"
#include "../../headers/exceptions/InvalidDataException.h"
#include <cctype>

User::User(const string& name,
           const string& userId,
           const string& email,
           const string& password) {

    setName(name);

    this->userId = userId;
    if(isEmailValid(email)) {
        this->email = email;
    }
    else {
        throw InvalidDataException("Invalid email.");
    }
    this->password = password;
}

bool User::isNameValid(const string& name) {

    if(name.length() < 3) {
        return false;
    }

    if(!isupper(name[0])) {
        return false;
    }

    for(char c : name) {

        if(!isalpha(c) && c != ' ') {
            return false;
        }
    }

    return true;
}

bool User::isEmailValid(const string& email) {

    if(email.find('@') == string::npos) {
        return false;
    }

    if(email.find('.') == string::npos) {
        return false;
    }

    return true;
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

string User::getEmail() const {
    return email;
}