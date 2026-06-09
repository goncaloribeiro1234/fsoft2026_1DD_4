#ifndef CLASSENROLLMENT_H
#define CLASSENROLLMENT_H

#include <string>

using namespace std;

class ClassEnrollment {
private:
    string athleteName;
    string modality;
    string classDate;
    string startTime;
    string endTime;
    string room;

public:
    ClassEnrollment(
            const string& athleteName,
            const string& modality,
            const string& classDate,
            const string& startTime,
            const string& endTime,
            const string& room
    );

    string getAthleteName() const;

    string getModality() const;

    string getClassDate() const;

    string getStartTime() const;

    string getEndTime() const;

    string getRoom() const;
};

#endif