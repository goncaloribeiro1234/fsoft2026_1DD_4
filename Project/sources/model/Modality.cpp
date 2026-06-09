#include "../../headers/model/Modality.h"

Modality::Modality(const string& name,
                   const string& description) {

    this->name = name;
    this->description = description;
}

string Modality::getName() const {
    return name;
}

string Modality::getDescription() const {
    return description;
}
