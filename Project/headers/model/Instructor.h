#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"

class Instructor : public User {
private:
    string specialty;

public:
    Instructor(const string& name,
               const string& userId,
               const string& email,
               const string& password,
               const string& specialty);

    string getSpecialty() const;
};

#endif