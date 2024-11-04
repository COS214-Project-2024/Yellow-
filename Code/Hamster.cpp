#include "Hamster.h"
#include <iostream>

Hamster::Hamster() {
    this->animalType = "hamster";
}

Hamster::Hamster(Citizen* owner) : Pet(owner) {
    this->animalType = "hamster";
}

void Hamster::cuteAction() {
    std::cout << "Squeak! :o" << std::endl;
}
Hamster::~Hamster() = default;
