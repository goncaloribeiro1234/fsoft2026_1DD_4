#ifndef MODALITY_H
#define MODALITY_H

#include <string>

using namespace std;

class Modality {
private:
    string name;
    string description;

public:
    Modality(const string& name,
             const string& description);

    string getName() const;

    string getDescription() const;

};

#endif