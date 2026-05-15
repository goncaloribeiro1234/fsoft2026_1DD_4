#include "../../headers/containers/ModalityContainer.h"

void ModalityContainer::add(const Modality& modality) {

    modalities.push_back(new Modality(modality));
}

list<Modality*> ModalityContainer::getAll() {

    return modalities;
}