#include "../../headers/model/Payment.h"

Payment::Payment(
        const string& athleteName,
        double amount,
        const string& date,
        const string& status) {

    this->athleteName = athleteName;
    this->amount = amount;
    this->date = date;
    this->status = status;
}

string Payment::getAthleteName() const {

    return athleteName;
}

double Payment::getAmount() const {

    return amount;
}

string Payment::getDate() const {

    return date;
}

string Payment::getStatus() const {

    return status;
}