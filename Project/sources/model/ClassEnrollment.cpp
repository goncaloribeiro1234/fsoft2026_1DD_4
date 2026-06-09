#include "../../headers/model/ClassEnrollment.h"

ClassEnrollment::ClassEnrollment(
        const string& athleteName,
        const string& modality,
        const string& classDate,
        const string& startTime,
        const string& endTime,
        const string& room) {

    this->athleteName = athleteName;
    this->modality = modality;
    this->classDate = classDate;
    this->startTime = startTime;
    this->endTime = endTime;
    this->room = room;
}

string ClassEnrollment::getAthleteName() const {

    return athleteName;
}

string ClassEnrollment::getModality() const {

    return modality;
}

string ClassEnrollment::getClassDate() const {

    return classDate;
}

string ClassEnrollment::getStartTime() const {
    return startTime;
}

string ClassEnrollment::getEndTime() const {
    return endTime;
}

string ClassEnrollment::getRoom() const {

    return room;
}
