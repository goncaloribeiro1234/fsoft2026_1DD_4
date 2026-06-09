#ifndef CLASSSESSION_H
#define CLASSSESSION_H

#include <string>

using namespace std;

class ClassSession {
private:
    string modality;
    string instructor;
    string room;

    string date;
    string startTime;
    string endTime;

public:
    ClassSession(const string& modality,
                 const string& instructor,
                 const string& room,
                 const string& date,
                 const string& startTime,
                 const string& endTime);

    string getModality() const;
    string getInstructor() const;
    string getRoom() const;

    string getDate() const;
    string getStartTime() const;
    string getEndTime() const;

    int getDuration() const;
};

#endif