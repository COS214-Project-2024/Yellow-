#include "Pet.h"

Pet::Pet() {
    this->animalType = "unidentified creature";
}

Pet::Pet(Citizen* owner) {
    this->owner = owner;
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