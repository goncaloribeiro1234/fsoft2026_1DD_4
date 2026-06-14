#include "../../headers/model/ClassSession.h"

ClassSession::ClassSession(const string& modality,
                           const string& instructor,
                           const string& room,
                           const string& date,
                           const string& startTime,
                           const string& endTime,
                           const string& minTechnicalLevel) {

    this->modality = modality;
    this->instructor = instructor;
    this->room = room;

    this->date = date;
    this->startTime = startTime;
    this->endTime = endTime;

    this->minTechnicalLevel = minTechnicalLevel;
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

int ClassSession::getduration() const {

    int startHour = stoi(startTime.substr(0, 2));
    int startMinute = stoi(startTime.substr(3, 2));

    int endHour = stoi(endTime.substr(0, 2));
    int endMinute = stoi(endTime.substr(3, 2));

    int startTotal = startHour * 60 + startMinute;
    int endTotal = endHour * 60 + endMinute;

    return endTotal - startTotal;
}

string ClassSession::getMinTechnicalLevel() const {
    return minTechnicalLevel;
}