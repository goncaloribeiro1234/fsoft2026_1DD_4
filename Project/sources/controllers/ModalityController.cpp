#include "../../headers/controllers/ModalityController.h"

void ModalityController::createModality(const string& name,
                                        const string& description,
                                        const string& minimumLevel) {

    Modality modality(name, description, minimumLevel);

    modalityService.add(modality);
}

list<Modality*> ModalityController::findAllModalities() {

    return modalityService.getAll();
}