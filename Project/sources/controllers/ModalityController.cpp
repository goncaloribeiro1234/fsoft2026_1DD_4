#include "../../headers/controllers/ModalityController.h"

void ModalityController::createModality(const string& name,
                                        const string& description) {

    Modality modality(name, description);

    modalityService.add(modality);
}

list<Modality*> ModalityController::findAllModalities() {

    return modalityService.getAll();
}