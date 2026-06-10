#include "../../headers/services/InstructorService.h"
#include "../../headers/repo/GymRepositoryMemory.h"
#include <stdexcept>

using namespace std;

void InstructorService::add(const Instructor& instructor) {
    Gym* model = GymRepositoryMemory::getModel();
    model->getInstructorContainer().add(instructor);
}

list<Instructor*> InstructorService::getAll() {
    Gym* model = GymRepositoryMemory::getModel();
    return model->getInstructorContainer().getAll();
}

Instructor* InstructorService::authenticate(const string& email, const string& password) {
    Gym* model = GymRepositoryMemory::getModel();

    for (auto a : model->getInstructorContainer().getAll()) {
        if (a->getEmail() == email && a->getPassword() == password) {
            return a;
        }
    }
    throw invalid_argument("Credenciais invalidas. Email ou password incorretos.");
}