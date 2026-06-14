#ifndef CLASSSESSIONCONTAINER_H
#define CLASSSESSIONCONTAINER_H

#include <list>

#include "../model/ClassSession.h"

using namespace std;

class ClassSessionContainer {
private:
    list<ClassSession*> sessions;

public:
    void add(const ClassSession& session);

    list<ClassSession*> getAll();

    void remove(ClassSession* session) {
        sessions.remove(session);
    }
};

#endif