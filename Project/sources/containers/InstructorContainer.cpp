#include "../../headers/containers/InstructorContainer.h"

void InstructorContainer::add(const Instructor& instructor) {
    instructors.push_back(new Instructor(instructor));
}

list<Instructor*> InstructorContainer::getAll() {
    return instructors;
}