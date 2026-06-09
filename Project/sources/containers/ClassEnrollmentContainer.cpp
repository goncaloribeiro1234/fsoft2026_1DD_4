#include "../../headers/containers/ClassEnrollmentContainer.h"

void ClassEnrollmentContainer::add(
        const ClassEnrollment& enrollment) {

    enrollments.push_back(
            new ClassEnrollment(enrollment)
    );
}

list<ClassEnrollment*> ClassEnrollmentContainer::getAll() {

    return enrollments;
}