#include "../../headers/model/Modality.h"

Modality::Modality(const string& name,
                   const string& description,
                   const string& minimumLevel) {

    this->name = name;
    this->description = description;
    this->minimumLevel = minimumLevel;
}

string Modality::getName() const {
    return name;
}

string Modality::getDescription() const {
    return description;
}

string Modality::getMinimumLevel() const {
    return minimumLevel;
}