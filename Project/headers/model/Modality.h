#ifndef MODALITY_H
#define MODALITY_H

#include <string>

using namespace std;

class Modality {
private:
    string name;
    string description;
    string minimumLevel;

public:
    Modality(const string& name,
             const string& description,
             const string& minimumLevel);

    string getName() const;

    string getDescription() const;

    string getMinimumLevel() const;
};

#endif