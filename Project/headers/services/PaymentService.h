#ifndef PAYMENTSERVICE_H
#define PAYMENTSERVICE_H

#include <list>

#include "../model/Payment.h"

using namespace std;

class PaymentService {
public:

    void add(const Payment& payment);

    list<Payment*> getAll();
};

#endif