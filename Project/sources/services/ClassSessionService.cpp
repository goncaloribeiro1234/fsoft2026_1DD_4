#include "../../headers/services/ClassSessionService.h"
#include "../../headers/repo/GymRepositoryMemory.h"

void ClassSessionService::add(const ClassSession& session) {

    Gym* model = GymRepositoryMemory::getModel();

    model->getClassSessionContainer().add(session);
}

list<ClassSession*> ClassSessionService::getAll() {

    Gym* model = GymRepositoryMemory::getModel();

    return model->getClassSessionContainer().getAll();
}

bool ClassSessionService::hasRoomConflict(
        const string& room,
        const string& date,
        const string& startTime,
        const string& endTime) {

    auto sessions = getAll();

    for(auto s : sessions) {

        bool sameRoom =
                s->getRoom() == room;

        bool sameDate =
                s->getDate() == date;

        bool overlap =
                !(endTime <= s->getStartTime() ||
                  startTime >= s->getEndTime());

        if(sameRoom && sameDate && overlap) {

            return true;
        }
    }

    return false;
}

bool ClassSessionService::hasInstructorConflict(
        const string& instructor,
        const string& date,
        const string& startTime,
        const string& endTime) {

    auto sessions = getAll();

    for(auto s : sessions) {

        bool sameInstructor =
                s->getInstructor() == instructor;

        bool sameDate =
                s->getDate() == date;

        bool overlap =
                !(endTime <= s->getStartTime() ||
                  startTime >= s->getEndTime());

        if(sameInstructor && sameDate && overlap) {

            return true;
        }
    }

    return false;
}