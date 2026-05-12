#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class InvalidDataException : public exception {
private:
    string msg;

public:
    explicit InvalidDataException(const string& msg);

    const char* what() const noexcept override;
};

#endif