#ifndef PET_H
#define PET_H
#include <string>
#include "Citizen.h"
using namespace std;

class Pet {
protected:
    string animalName;
    string animalType;
    Citizen* owner;
public:
    Pet();
    Pet(string name, string type);
    void setAnimalName(string name);
    string getAnimalName();
    void setAnimalType(string type);
    string getAnimalType();
    void setOwner(Citizen* owner);
    Citizen* getOwner() const;
    virtual void cuteAction() = 0;
    virtual ~Pet();
};

#endif //PET_H
