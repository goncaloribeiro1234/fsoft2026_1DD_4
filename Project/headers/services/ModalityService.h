#ifndef MODALITYSERVICE_H
#define MODALITYSERVICE_H

#include <list>

#include "../model/Modality.h"

using namespace std;

class ModalityService {
public:
    void add(const Modality& modality);

    list<Modality*> getAll();
};

#endif