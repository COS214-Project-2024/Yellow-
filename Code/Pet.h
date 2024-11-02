#ifndef PET_H
#define PET_H
#include <string>
#include "Citizen.h"
using namespace std;

class Pet {
public:
    string animalType;
    string animalName;
    Citizen* owner;

    Pet();
    Pet(string animalType, string animalName);
    void setOwner(Citizen* owner);
    string getAnimalType();
    string getAnimalName();
    
};

#endif //PET_H
