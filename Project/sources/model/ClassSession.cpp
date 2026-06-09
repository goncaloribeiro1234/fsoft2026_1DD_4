#include "../../headers/model/ClassSession.h"

ClassSession::ClassSession(const string& modality,
                           const string& instructor,
                           const string& room,
                           const string& date,
                           const string& startTime,
                           const string& endTime,
                           int duration) {

    this->modality = modality;
    this->instructor = instructor;
    this->room = room;

    this->date = date;
    this->startTime = startTime;
    this->endTime = endTime;

    this->duration = duration;
}

string ClassSession::getModality() const {
    return modality;
}

string ClassSession::getInstructor() const {
    return instructor;
}

string ClassSession::getRoom() const {
    return room;
}

string ClassSession::getDate() const {
    return date;
}

string ClassSession::getStartTime() const {
    return startTime;
}

string ClassSession::getEndTime() const {
    return endTime;
}

int ClassSession::getDuration() const {
    return duration;
}