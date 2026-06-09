#include "../../headers/containers/ClassSessionContainer.h"

void ClassSessionContainer::add(const ClassSession& session) {

    sessions.push_back(
            new ClassSession(session)
    );
}

list<ClassSession*> ClassSessionContainer::getAll() {

    return sessions;
}