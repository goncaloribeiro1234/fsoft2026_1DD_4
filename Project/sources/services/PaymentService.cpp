#include "../../headers/services/PaymentService.h"
#include "../../headers/repo/GymRepositoryMemory.h"
#include "../../headers/exceptions/InvalidDataException.h"

void PaymentService::add(const Payment& payment) {

        Gym* model = GymRepositoryMemory::getModel();

        bool found = false;

        for (auto a : model->getAthleteContainer().getAll()) {
                if (a->getName() == payment.getAthleteName()) {
                        found = true;
                        break;
                }
        }

        if (!found) {
                throw InvalidDataException("Atleta nao existe. Pagamento invalido.");
        }

        model->getPaymentContainer().add(payment);

        for (auto p : model->getPaymentContainer().getAll()) {
                if (p->getAthleteName() == payment.getAthleteName() &&
                    p->getDate() == payment.getDate()) {

                        throw InvalidDataException("Ja existe pagamento para este atleta nesta data.");
                    }
        }
}

list<Payment*> PaymentService::getAll() {

        Gym* model = GymRepositoryMemory::getModel();

        return model->getPaymentContainer().getAll();
}