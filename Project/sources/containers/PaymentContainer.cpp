#include "../../headers/containers/PaymentContainer.h"

void PaymentContainer::add(
        const Payment& payment) {

    payments.push_back(
            new Payment(payment)
    );
}

list<Payment*> PaymentContainer::getAll() {

    return payments;
}