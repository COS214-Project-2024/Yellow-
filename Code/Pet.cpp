#include "Pet.h"

Pet::Pet() {
    this->animalName = "unknown";
    this->animalType = "unidentified creature";
}

Pet::Pet(string name, string type) {
    this->animalName = name;
    this->animalType = type;
}

void Pet::setAnimalName(string name) {
    this->animalName = name;
}

string Pet::getAnimalName() {
    return this->animalName;
}

void Pet::setAnimalType(string type) {
    this->animalType = type;
}

string Pet::getAnimalType() {
    return animalType;
}

void Pet::setOwner(Citizen* owner) {
    this->owner = owner;
}

Citizen* Pet::getOwner() const {
    return owner;
}

// virtual void cuteAction() = 0;

Pet::~Pet() = default;