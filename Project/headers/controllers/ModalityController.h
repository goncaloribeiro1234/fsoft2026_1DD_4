#ifndef MODALITYCONTROLLER_H
#define MODALITYCONTROLLER_H


#include "../services/ModalityService.h"
#include <list>

using namespace std;

class ModalityController {
private:
    ModalityService modalityService;

public:
    list<Modality*> findAllModalities();
};

#endif