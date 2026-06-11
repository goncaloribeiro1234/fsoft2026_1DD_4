#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>

using namespace std;

class Payment {
private:

    string athleteName;
    double amount;
    string date;
    string status;

public:

    Payment(
            const string& athleteName,
            double amount,
            const string& date,
            const string& status
    );

    string getAthleteName() const;

    double getAmount() const;

    string getDate() const;

    string getStatus() const;
};

#endif