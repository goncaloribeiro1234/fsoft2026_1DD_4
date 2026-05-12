#include "../../headers/exceptions/InvalidDataException.h"

InvalidDataException::InvalidDataException(const string& msg) {
    this->msg = msg;
}

const char* InvalidDataException::what() const noexcept {
    return msg.c_str();
}