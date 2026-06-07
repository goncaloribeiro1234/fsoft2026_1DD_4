#include "../../headers/controllers/ModalityController.h"

list<Modality*> ModalityController::findAllModalities() {
    return modalityService.getAll();
}