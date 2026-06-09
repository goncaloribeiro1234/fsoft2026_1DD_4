#ifndef MODALITYCONTROLLER_H
#define MODALITYCONTROLLER_H

#include "../services/ModalityService.h"
#include <list>

using namespace std;

class ModalityController {
private:
    ModalityService modalityService;

public:
    void createModality(const string& name,
                        const string& description,
                        const string& minimumLevel);

    list<Modality*> findAllModalities();
};

#endif