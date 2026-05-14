#include "../../headers/model/Gym.h"

Gym::Gym(const string& name, const string& location) {
    this->name = name;
    this->location = location;
}

AthleteContainer& Gym::getAthleteContainer() {
    return athleteContainer;
}

InstructorContainer& Gym::getInstructorContainer() {
    return instructorContainer;
}

ModalityContainer& Gym::getModalityContainer() {
    return modalityContainer;
}

RoomContainer& Gym::getRoomContainer() {
    return roomContainer;
}

ClassSessionContainer& Gym::getClassSessionContainer() {
    return classSessionContainer;
}

ClassEnrollmentContainer& Gym::getClassEnrollmentContainer() {
    return classEnrollmentContainer;
}