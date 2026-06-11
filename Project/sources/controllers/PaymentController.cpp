#include "../../headers/controllers/PaymentController.h"

void PaymentController::registerPayment(
        const string& athleteName,
        double amount,
        const string& date,
        const string& status) {

    Payment payment(
            athleteName,
            amount,
            date,
            status
    );

    paymentService.add(payment);
}

list<Payment*> PaymentController::findAllPayments() {

    return paymentService.getAll();
}