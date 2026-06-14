#include "../../headers/services/ClassSessionService.h"
#include "../../headers/repo/GymRepositoryMemory.h"
#include <ctime>
#include <sstream>
#include <stdexcept>

bool isDateValidForScheduling(const string& dateStr) {
    int day, month, year;
    char delimiter;
    stringstream ss(dateStr);

    if (!(ss >> day >> delimiter >> month >> delimiter >> year) || delimiter != '/') {
        throw invalid_argument("Formato de data invalido. Utilize DD/MM/AAAA.");
    }

    time_t t = time(0);
    tm* now = localtime(&t);
    tm today = {0};
    today.tm_mday = now->tm_mday;
    today.tm_mon = now->tm_mon;
    today.tm_year = now->tm_year;
    time_t today_timestamp = mktime(&today);

    tm max_date = today;
    max_date.tm_mday += 14;
    time_t max_timestamp = mktime(&max_date);

    tm input_date = {0};
    input_date.tm_mday = day;
    input_date.tm_mon = month - 1;
    input_date.tm_year = year - 1900;
    time_t input_timestamp = mktime(&input_date);

    if (input_timestamp < today_timestamp) {
        throw invalid_argument("Erro: Nao pode agendar uma aula numa data passada.");
    }
    if (input_timestamp > max_timestamp) {
        throw invalid_argument("Erro: Apenas pode agendar aulas com o maximo de 2 semanas de antecedencia.");
    }

    return true;
}

void ClassSessionService::add(const ClassSession& session) {
    isDateValidForScheduling(session.getDate());

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
        bool sameRoom = s->getRoom() == room;
        bool sameDate = s->getDate() == date;
        bool overlap = !(endTime <= s->getStartTime() || startTime >= s->getEndTime());

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
        bool sameInstructor = s->getInstructor() == instructor;
        bool sameDate = s->getDate() == date;
        bool overlap = !(endTime <= s->getStartTime() || startTime >= s->getEndTime());

        if(sameInstructor && sameDate && overlap) {
            return true;
        }
    }
    return false;
}

void ClassSessionService::cancelSession(const string& modality, const string& date, const string& startTime, const string& room) {
    Gym* model = GymRepositoryMemory::getModel();
    auto sessions = getAll();

    ClassSession* toDelete = nullptr;
    for (auto s : sessions) {
        if (s->getModality() == modality && s->getDate() == date &&
            s->getStartTime() == startTime && s->getRoom() == room) {
            toDelete = s;
            break;
        }
    }

    if (!toDelete) throw invalid_argument("Aula nao encontrada para cancelamento.");

    model->getClassSessionContainer().remove(toDelete);
    delete toDelete;

    auto enrollments = model->getClassEnrollmentContainer().getAll();
    for (auto e : enrollments) {
        if (e->getModality() == modality && e->getClassDate() == date &&
            e->getStartTime() == startTime && e->getRoom() == room) {
            model->getClassEnrollmentContainer().remove(e);
            delete e;
        }
    }
}