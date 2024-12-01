#ifndef PET_H
#define PET_H
#include <string>
#include "Citizen.h"
using namespace std;

class Pet {
protected:
    string animalType;
    Citizen* owner;
public:
    Pet();
    Pet(Citizen* owner);
    void setAnimalType(string type);
    string getAnimalType();
    void setOwner(Citizen* owner);
    Citizen* getOwner() const;
    virtual void cuteAction() = 0;
    virtual ~Pet();
};

#endif //PET_H
