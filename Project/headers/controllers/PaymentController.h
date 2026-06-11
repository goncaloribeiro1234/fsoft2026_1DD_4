#ifndef PAYMENTCONTROLLER_H
#define PAYMENTCONTROLLER_H

#include "../services/PaymentService.h"

class PaymentController {
private:

    PaymentService paymentService;

public:

    void registerPayment(
            const string& athleteName,
            double amount,
            const string& date,
            const string& status
    );

    list<Payment*> findAllPayments();
};

#endif