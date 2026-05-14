#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    string name;
    string userId;
    string email;
    string password;

    bool isNameValid(const string& name);

public:
    User(const string& name,
         const string& userId,
         const string& email,
         const string& password);

    virtual ~User() = default;

    void setName(const string& name);

    string getName() const;

    string getEmail() const;
};

#endif